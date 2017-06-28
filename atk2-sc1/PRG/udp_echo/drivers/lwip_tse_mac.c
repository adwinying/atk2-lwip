// -------------------------------------------------------------------------
// -------------------------------------------------------------------------
//
// Revision Control Information
//
// $RCSfile$
// $Source$
//
// $Revision: #1 $
// $Date: 2008/08/09 $
// Check in by : $Author: sc-build $
// Author      : Bill Auerbach - derived from ins_tse_mac.c by Arul Paniandi 
//
// Project     : Triple Speed Ethernet - 10/100/1000 MAC
//
// Description : 
//
// lwIP TSE driver functions
// 
// Legal Notice: (C)2006 Altera Corporation. All rights reserved. Your use 
// of Altera Corporation's design tools, logic functions and other software 
// and tools, and its AMPP partner logic functions, and any output files 
// any of the foregoing (including device programming or simulation files),
// and any associated documentation or information are expressly subject to
// the terms and conditions of the Altera Program License Subscription 
// Agreement, Altera MegaCore Function License Agreement, or other 
// applicable license agreement, including, without limitation, that your 
// use is for the sole purpose of programming logic devices manufactured by
// Altera and sold by Altera or its authorized distributors.  Please refer 
// to the applicable agreement for further details.
//
// -------------------------------------------------------------------------
// -------------------------------------------------------------------------
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <io.h>
#include "system.h"
#include "alt_types.h"

#include "altera_avalon_tse.h"

//#include "sys/alt_irq.h"
#include "sys/alt_cache.h"

#include "alteraTseEthernetif.h"
#include "altera_avalon_sgdma_regs.h"
#include "altera_avalon_sgdma.h"
#include "altera_avalon_sgdma_descriptor.h"

#include "netif/etharp.h"
#include "lwip/stats.h"
#include "lwip/err.h"

#include "t_syslog.h"

/* Base-Structure for all lwIP TSE information */
typedef struct _lwip_tse_info 
{
   tse_mac_trans_info mi; /* MAC base driver data. */

   // Location for the SGDMA Descriptors
   alt_sgdma_descriptor *desc;

   // lwIP Ethernetif structure
   struct ethernetif   *ethernetif;
    
   // Hardware location
   alt_tse_system_info *tse;
    
} lwip_tse_info;

//  Local prototypes
int tse_sgdmaRx_isr(void * context, u_long intnum);
int tse_sgdma_read_init(lwip_tse_info* tse_ptr);
int tse_mac_rcv(struct ethernetif *ethernetif);

#define dprintf(x) syslog(LOG_INFO, x) //tse_dprintf x

#if! defined( ETH_PAD_SIZE ) || ETH_PAD_SIZE != 2
#error The Altera Triple Speed Ethernet lwIP driver requires '#define ETH_PAD_SIZE 2' in lwipopts.h
#endif

#ifdef ALTERA_TSE_IRQ_R
extern int ALTERA_TSE_IRQ_R(void * context, u_long intnum);
#endif

lwip_tse_info tse[MAXNETS];
extern alt_tse_system_info tse_mac_device[MAXNETS];

/* @Function Description: TSE MAC Initialization routine. This function opens the
 *                        device handle, configure the callback function and interrupts ,
 *                        for SGDMA TX and SGDMA RX block associated with the TSE MAC,
 *                        Initialize the MAC Registers for the RX FIFO and TX FIFO
 *                        threshold watermarks, initialize the tse device structure,
 *                        set the MAC address of the device and enable the MAC   
 * 
 * @API TYPE: Internal
 * @Param iface index of the NET structure associated with TSE instance
 * @Return 0 if ok, else -1 if error
 */
int tse_mac_init(int iface, struct ethernetif *ethernetif)
{
   int dat;
   int speed, duplex, result;
   int x;
   
   alt_sgdma_dev *sgdma_tx_dev;
   alt_sgdma_dev *sgdma_rx_dev;
   alt_tse_system_info* tse_hw = (alt_tse_system_info *) tse[iface].tse;
   np_tse_mac *mi_base;
   alt_tse_mac_info *pmac_info;
   
   dprintf(("[tse_mac_init]\n"));
#ifdef PRINTIF
   dprintf(("tse_mac_init %d\n", iface));
#endif    
   // These lines were done in prep_tse_mac 
   tse_hw = &tse_mac_device[iface];	
   tse[iface].tse = tse_hw;
	
   // Store ethernetif for access, and the tse in ethernetif for access in tse_mac_raw_send/tse_mac_rcv
   tse[iface].ethernetif = ethernetif;
   ethernetif->iface = iface;
   ethernetif->tse_info = &tse[iface];

   if (tse_hw->ext_desc_mem == 1)
      tse[iface].desc = (alt_sgdma_descriptor *) tse_hw->desc_mem_base;
   else
      {
      unsigned char *temp_desc = (unsigned char *)alt_uncached_malloc((4+ALTERA_TSE_SGDMA_RX_DESC_CHAIN_SIZE)*(sizeof(alt_sgdma_descriptor)));
    
      while ((((alt_u32)temp_desc) % ALTERA_AVALON_SGDMA_DESCRIPTOR_SIZE) != 0)
         temp_desc++;
      tse[iface].desc = (alt_sgdma_descriptor *) temp_desc;
      }

   
   /* Get the Rx and Tx SGDMA addresses */
   sgdma_tx_dev = alt_avalon_sgdma_open(tse_hw->tse_sgdma_tx);
   if(!sgdma_tx_dev) 
      {
      dprintf(("[triple_speed_ethernet_init] Error opening TX SGDMA\n"));
      return ENP_RESOURCE;
      }
  
   sgdma_rx_dev = alt_avalon_sgdma_open(tse_hw->tse_sgdma_rx);
   if(!sgdma_rx_dev) 
      {
      dprintf(("[triple_speed_ethernet_init] Error opening RX SGDMA\n"));
      return ENP_RESOURCE;
      }


   /* Initialize mtip_mac_trans_info structure with values from <system.h>*/

   tse_mac_initTransInfo2(&tse[iface].mi, (int)tse_hw->tse_mac_base,
                                   (unsigned int)sgdma_tx_dev,            
                                   (unsigned int)sgdma_rx_dev,
                                   0);
   mi_base = tse[iface].mi.base;

   IOWR_ALTERA_AVALON_SGDMA_CONTROL(tse[iface].mi.rx_sgdma->base,ALTERA_AVALON_SGDMA_CONTROL_SOFTWARERESET_MSK);
   IOWR_ALTERA_AVALON_SGDMA_CONTROL(tse[iface].mi.rx_sgdma->base, 0x0);
   
   /* reset the PHY if necessary */
   result = getPHYSpeed(tse[iface].mi.base);
   speed  = (result >> 1) & 0x07;
   duplex = result & 0x01;

   /* reset the mac */ 
   IOWR_ALTERA_TSEMAC_CMD_CONFIG(tse[iface].mi.base,
                             mmac_cc_SW_RESET_mask | 
                             mmac_cc_TX_ENA_mask | 
                             mmac_cc_RX_ENA_mask);
  
   x=0;
   while(IORD_ALTERA_TSEMAC_CMD_CONFIG(tse[iface].mi.base) & 
         ALTERA_TSEMAC_CMD_SW_RESET_MSK) 
      {
      if( x++ > 10000 ) 
         break;
      }
  
   if(x >= 10000)
      dprintf(("TSEMAC SW reset bit never cleared!\n"));

   dat = IORD_ALTERA_TSEMAC_CMD_CONFIG(tse[iface].mi.base);
   if( (dat & 0x03) != 0 ) 
      syslog(LOG_INFO, "WARN: RX/TX not disabled after reset... missing PHY clock? CMD_CONFIG=0x%08x\n", dat);
   else
      syslog(LOG_INFO, "OK, x=%d, CMD_CONFIG=0x%08x\n", x, dat);
  
   /* Initialize MAC registers */
   IOWR_ALTERA_TSEMAC_FRM_LENGTH(mi_base, PBUF_POOL_BUFSIZE+ETH_PAD_SIZE); 
   IOWR_ALTERA_TSEMAC_RX_ALMOST_EMPTY(mi_base, 8);
   IOWR_ALTERA_TSEMAC_RX_ALMOST_FULL(mi_base, 8);
   IOWR_ALTERA_TSEMAC_TX_ALMOST_EMPTY(mi_base, 8);
   IOWR_ALTERA_TSEMAC_TX_ALMOST_FULL(mi_base,  3);
   IOWR_ALTERA_TSEMAC_TX_SECTION_EMPTY(mi_base, tse_hw->tse_tx_depth - 16); //1024/4;  
   IOWR_ALTERA_TSEMAC_TX_SECTION_FULL(mi_base,  0); //32/4; // start transmit when there are 48 bytes
   IOWR_ALTERA_TSEMAC_RX_SECTION_EMPTY(mi_base, tse_hw->tse_rx_depth - 16); //4000/4);
   IOWR_ALTERA_TSEMAC_RX_SECTION_FULL(mi_base,  0);
   
   /* Enable TX shift 16 for removing two bytes from the start of all transmitted frames */
   IOWR_ALTERA_TSEMAC_TX_CMD_STAT(tse[iface].mi.base,ALTERA_TSEMAC_TX_CMD_STAT_TXSHIFT16_MSK);
 
   /*
    * check if the MAC supports the 16-bit shift option allowing us
    * to send BIASed frames without copying. Used by the send function later.
    */
   if((IORD_ALTERA_TSEMAC_TX_CMD_STAT(tse[iface].mi.base) & ALTERA_TSEMAC_TX_CMD_STAT_TXSHIFT16_MSK) == 0)
      {
      dprintf(("[tse_mac_init] Error: Incompatible %d value with TX_CMD_STAT register return TxShift16 value. \n",ETH_PAD_SIZE));
      return ERR_IF;
      }
  
   /* Enable RX shift 16 for alignment of all received frames on 16-bit start address */
   IOWR_ALTERA_TSEMAC_RX_CMD_STAT(tse[iface].mi.base,ALTERA_TSEMAC_RX_CMD_STAT_RXSHIFT16_MSK);
 
   /* check if the MAC supports the 16-bit shift option at the RX CMD STATUS Register  */ 
   if((IORD_ALTERA_TSEMAC_RX_CMD_STAT(tse[iface].mi.base) & ALTERA_TSEMAC_RX_CMD_STAT_RXSHIFT16_MSK) == 0)
      {
      dprintf(("[tse_mac_init] Error: Incompatible %d value with RX_CMD_STAT register return RxShift16 value. \n",ETH_PAD_SIZE));
      return ERR_IF;
      }
   
   /* enable MAC */
   dat = ALTERA_TSEMAC_CMD_TX_ENA_MSK       |
         ALTERA_TSEMAC_CMD_RX_ENA_MSK       |
         mmac_cc_RX_ERR_DISCARD_mask        |
#if ENABLE_PHY_LOOPBACK
         ALTERA_TSEMAC_CMD_PROMIS_EN_MSK    |     // promiscuous mode
         ALTERA_TSEMAC_CMD_LOOPBACK_MSK     |     // promiscuous mode
#endif
         ALTERA_TSEMAC_CMD_TX_ADDR_INS_MSK  |
         ALTERA_TSEMAC_CMD_RX_ERR_DISC_MSK;  /* automatically discard frames with CRC errors */
    
   if((result & ALT_TSE_E_AN_NOT_COMPLETE) == 0) 
      {
	  speed = (result >> 1) & 0x07;
	  duplex = result & 0x01;
  
      /* 1000 Mbps */
      if(speed == 0x01)
         {
         dat |= ALTERA_TSEMAC_CMD_ETH_SPEED_MSK;
         dat &= ~ALTERA_TSEMAC_CMD_ENA_10_MSK;
         tse[iface].ethernetif->link_speed = 1000;
         }
      /* 100 Mbps */
      else if(speed == 0x02)
         {
         dat &= ~ALTERA_TSEMAC_CMD_ETH_SPEED_MSK;
         dat &= ~ALTERA_TSEMAC_CMD_ENA_10_MSK;
         tse[iface].ethernetif->link_speed = 100;
         }
      /* 10 Mbps */
      else if(speed == 0x04)
         {
         dat &= ~ALTERA_TSEMAC_CMD_ETH_SPEED_MSK;
         dat |= ALTERA_TSEMAC_CMD_ENA_10_MSK;
         tse[iface].ethernetif->link_speed = 10;
         }
      }
   /* default to 100 Mbps if returned invalid speed */
   else
      {
      dat &= ~ALTERA_TSEMAC_CMD_ETH_SPEED_MSK;
      dat &= ~ALTERA_TSEMAC_CMD_ENA_10_MSK;
      }
  
   /* Half Duplex */
   if(duplex == TSE_PHY_DUPLEX_HALF)
      {
      dat |= ALTERA_TSEMAC_CMD_HD_ENA_MSK;
      tse[iface].ethernetif->full_duplex = 0;
      }
   /* Full Duplex */
   else
      {
      dat &= ~ALTERA_TSEMAC_CMD_HD_ENA_MSK;
      tse[iface].ethernetif->full_duplex = 1;
      }
          
   IOWR_ALTERA_TSEMAC_CMD_CONFIG(tse[iface].mi.base, dat);
   syslog(LOG_INFO, "\nMAC post-initialization: CMD_CONFIG=0x%08x\n", 
       IORD_ALTERA_TSEMAC_CMD_CONFIG(tse[iface].mi.base));
  
   /* Set the MAC address */
     IOWR_ALTERA_TSEMAC_MAC_0(mi_base,
                             ((int)((unsigned char) ethernetif->ethaddr->addr[0]) |
                              (int)((unsigned char) ethernetif->ethaddr->addr[1] <<  8) |
                              (int)((unsigned char) ethernetif->ethaddr->addr[2] << 16) |
                              (int)((unsigned char) ethernetif->ethaddr->addr[3] << 24)));

     IOWR_ALTERA_TSEMAC_MAC_1(mi_base,
                             (((int)((unsigned char) ethernetif->ethaddr->addr[4]) |
                               (int)((unsigned char) ethernetif->ethaddr->addr[5] <<  8)) & 0xFFFF));
                                
   alt_avalon_sgdma_register_callback(tse[iface].mi.rx_sgdma,
#ifndef ALTERA_TSE_IRQ_R
        (alt_avalon_sgdma_callback)&tse_sgdmaRx_isr,
#else
        (alt_avalon_sgdma_callback)&ALTERA_TSE_IRQ_R,
#endif
        (alt_u16)ALTERA_TSE_SGDMA_INTR_MASK,(void*)(&tse[iface]));
    
   tse_sgdma_read_init(&tse[iface]);
   //tse_sgdma_write_init(&tse[iface]);
   

   pmac_info = alt_tse_get_mac_info(mi_base);
   alt_tse_phy_wr_mdio_addr(pmac_info->pphy_info, pmac_info->pphy_info->mdio_address);
   ethernetif->link_alive = alt_tse_phy_rd_mdio_reg(pmac_info->pphy_info, TSE_PHY_MDIO_STATUS, TSE_PHY_MDIO_STATUS_AN_COMPLETE, 1) != 0;



   //IOWR_ALTERA_AVALON_SGDMA_CONTROL(tse[iface].mi.tx_sgdma->base,ALTERA_AVALON_SGDMA_CONTROL_SOFTWARERESET_MSK);
   //IOWR_ALTERA_AVALON_SGDMA_CONTROL(tse[iface].mi.tx_sgdma->base,ALTERA_AVALON_SGDMA_CONTROL_SOFTWARERESET_MSK);
   //IOWR_ALTERA_AVALON_SGDMA_CONTROL(tse[iface].mi.tx_sgdma->base, 0x0);
   //IOWR_ALTERA_AVALON_SGDMA_CONTROL(tse[iface].mi.tx_sgdma, 0xff);

   //IOWR_ALTERA_AVALON_SGDMA_CONTROL(tse[iface].mi.rx_sgdma->base,ALTERA_AVALON_SGDMA_CONTROL_SOFTWARERESET_MSK);
   //IOWR_ALTERA_AVALON_SGDMA_CONTROL(tse[iface].mi.rx_sgdma->base,ALTERA_AVALON_SGDMA_CONTROL_SOFTWARERESET_MSK);
   //IOWR_ALTERA_AVALON_SGDMA_CONTROL(tse[iface].mi.rx_sgdma->base, 0x0);
   //IOWR_ALTERA_AVALON_SGDMA_CONTROL(tse[iface].mi.rx_sgdma, 0xff);
   

   return ethernetif->link_alive;
}


/* @Function Description -  Init and setup SGDMA Descriptor chain
 *                          
 * 
 * @API TYPE - Internal
 * @return SUCCESS on success 
 */
int tse_sgdma_read_init(lwip_tse_info* tse_ptr)
{     
   struct ethernetif *ethernetif;
  
   ethernetif = tse_ptr->ethernetif;
  
   alt_avalon_sgdma_construct_stream_to_mem_desc(
         (alt_sgdma_descriptor *) &tse_ptr->desc[ALTERA_TSE_FIRST_RX_SGDMA_DESC_OFST],  // descriptor I want to work with
         (alt_sgdma_descriptor *) &tse_ptr->desc[ALTERA_TSE_SECOND_RX_SGDMA_DESC_OFST],  // pointer to "next"
         (alt_u32 *) ethernetif->lwipRxPbuf[tse_ptr->ethernetif->lwipRxIndexIsr]->payload,          // starting write_address
         0,                                  // read until EOP
         0);          // don't write to constant address


   syslog(LOG_INFO, "[tse_sgdma_read_init] RX descriptor chain desc (%d depth) created\n",0); 
   
   tse_mac_aRxRead( &tse_ptr->mi, &tse_ptr->desc[ALTERA_TSE_FIRST_RX_SGDMA_DESC_OFST]);
  
   return SUCCESS;
}

/* @Function Description -  TSE Driver SGDMA RX ISR callback function
 *                          
 * 
 * @API TYPE - callback
 * @param  context  - context of the TSE MAC instance
 * @param  intnum - temporary storage
 */
int tse_sgdmaRx_isr(void * context, u_long intnum)
{
   lwip_tse_info* tse_ptr = (lwip_tse_info *) context;

   IOWR_ALTERA_AVALON_SGDMA_CONTROL(&tse_ptr->mi.rx_sgdma->base,ALTERA_AVALON_SGDMA_CONTROL_CLEAR_INTERRUPT_MSK);
   tse_mac_rcv(tse_ptr->ethernetif);    
   tse_mac_aRxRead( &tse_ptr->mi, &tse_ptr->desc[ALTERA_TSE_FIRST_RX_SGDMA_DESC_OFST]);
   IOWR_ALTERA_AVALON_SGDMA_CONTROL(&tse_ptr->mi.rx_sgdma->base, ALTERA_TSE_SGDMA_INTR_MASK);
  
   return SUCCESS;
}



/* @Function Description -  TSE transmit API to send data to the MAC
 *                          
 * 
 * @API TYPE - Public
 * @param  net  - NET structure associated with the TSE MAC instance
 * @param  data - pointer to the data payload
 * @param  data_bytes - number of bytes of the data payload to be sent to the MAC
 * @return SUCCESS if success, else a negative value
 */

err_t tse_mac_raw_send(struct netif *netif, struct pbuf *pkt)
{
   int                tx_length;
   unsigned           len;
   struct pbuf        *p;
   alt_u32            *data;
   tse_mac_trans_info *mi;
   lwip_tse_info      *tse_ptr;
   struct ethernetif  *ethernetif;
   unsigned int       *ActualData;

   /* Intermediate buffers used for temporary copy of frames that cannot be directrly DMA'ed*/
   char buf2[1560];

   ethernetif = netif->state;
   tse_ptr = ethernetif->tse_info;
   mi = &tse_ptr->mi;
  
   for(p = pkt; p != NULL; p = p->next)
      {
      data = p->payload;
      len = p->len;
       
      if(((unsigned long)data & 0x03) != 0) 
         {
         /* 
          * Copy data to temporary buffer <buf2>. This is done because of allignment 
          * issues. The SGDMA cannot copy the data directly from (data + ETH_PAD_SIZE)
          * because it needs a 32-bit alligned address space. 
          */
         memcpy(buf2,data,len);
         data = (alt_u32 *)buf2;
         }  
       
      ActualData = (void *)alt_remap_uncached (data, len);
      /* Write data to Tx FIFO using the DMA */
      alt_avalon_sgdma_construct_mem_to_stream_desc(
           (alt_sgdma_descriptor *) &tse_ptr->desc[ALTERA_TSE_FIRST_TX_SGDMA_DESC_OFST], // descriptor I want to work with
           (alt_sgdma_descriptor *) &tse_ptr->desc[ALTERA_TSE_SECOND_TX_SGDMA_DESC_OFST],// pointer to "next"
           (alt_u32*)ActualData,                    // starting read address
           (len),                                   // # bytes
           0,                                       // don't read from constant address
           p == pkt,                                // generate sop
           p->next == NULL,                         // generate endofpacket signal
           0);                                      // atlantic channel (don't know/don't care: set to 0)
                  
      tx_length = tse_mac_sTxWrite(mi,&tse_ptr->desc[ALTERA_TSE_FIRST_TX_SGDMA_DESC_OFST]);
      ethernetif->bytes_sent += tx_length;
      }
   LINK_STATS_INC(link.xmit);
   return ERR_OK;
}


/* @Function Description -  TSE Driver SGDMA RX ISR callback function
 *                          
 * 
 * @API TYPE        - callback internal function
 * @return SUCCESS on success
 */
int tse_mac_rcv(struct ethernetif *ethernetif)
{     
   int pklen;
   lwip_tse_info* tse_ptr;
   alt_u32 *uncached_packet_payload;
   struct pbuf *p;
  
   tse_ptr = ethernetif->tse_info;
   pklen = IORD_16DIRECT(&(tse_ptr->desc[ALTERA_TSE_FIRST_RX_SGDMA_DESC_OFST].actual_bytes_transferred),0);
   p = ethernetif->lwipRxPbuf[ethernetif->lwipRxIndexIsr];
   p->tot_len = pklen;
   p->len = pklen;
   if ((IORD_ALTERA_TSE_SGDMA_DESC_STATUS(&tse_ptr->desc[ALTERA_TSE_FIRST_RX_SGDMA_DESC_OFST]) & ( ALTERA_AVALON_SGDMA_DESCRIPTOR_STATUS_E_CRC_MSK | ALTERA_AVALON_SGDMA_DESCRIPTOR_STATUS_E_PARITY_MSK | ALTERA_AVALON_SGDMA_DESCRIPTOR_STATUS_E_OVERFLOW_MSK |ALTERA_AVALON_SGDMA_DESCRIPTOR_STATUS_E_SYNC_MSK | ALTERA_AVALON_SGDMA_DESCRIPTOR_STATUS_E_UEOP_MSK | ALTERA_AVALON_SGDMA_DESCRIPTOR_STATUS_E_MEOP_MSK | ALTERA_AVALON_SGDMA_DESCRIPTOR_STATUS_E_MSOP_MSK )) == 0)
      {
      if( ethernetif->lwipRxCount > LWIP_RX_ETH_BUFFER )
         {    
         LINK_STATS_INC(link.drop);
         dprintf(("No free buffers for rx\n"));
         }
      else 
         {
         ethernetif->bytes_recv += pklen;
         //  Set up DMA for the next pbuf in the buffer
         ++ethernetif->lwipRxCount;
         if( ++ethernetif->lwipRxIndexIsr >= LWIP_RX_ETH_BUFFER )
            ethernetif->lwipRxIndexIsr = 0;
         }
      }      

   uncached_packet_payload = (alt_u32 *) ethernetif->lwipRxPbuf[ethernetif->lwipRxIndexIsr]->payload;
   alt_avalon_sgdma_construct_stream_to_mem_desc(
         (alt_sgdma_descriptor *) &tse_ptr->desc[ALTERA_TSE_FIRST_RX_SGDMA_DESC_OFST],  // descriptor I want to work with
         (alt_sgdma_descriptor *) &tse_ptr->desc[ALTERA_TSE_SECOND_RX_SGDMA_DESC_OFST],  // pointer to "next"
         uncached_packet_payload,            // starting write_address
         0,                                  // read until EOP
         0);          // don't write to constant address

   return ERR_OK;
}
