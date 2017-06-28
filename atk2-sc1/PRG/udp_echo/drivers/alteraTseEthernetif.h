#ifndef ALTERATSEETHERNETIF_H_
#define ALTERATSEETHERNETIF_H_

#include "lwip/netif.h"
#include "lwip/err.h"

//  This times PBUF_POOL_BUFSIZE+4 is the amount of memory used to buffer incoming packets.
//  This can be small if you dedicate sufficient time to process incoming packets.
//  If it's too small, lwIP will run - only incoming packets will be dropped.
#define LWIP_RX_ETH_BUFFER  12

struct ethernetif;
int tse_mac_init(int iface, struct ethernetif *ethernetif);

/**
 * Private data used to operate your ethernet interface.
 */
struct ethernetif {
    struct eth_addr *ethaddr;
    int             iface;
    int             link_alive;
    int             link_speed;
    int             full_duplex;
    
    //  Extra stats
    unsigned        bytes_sent;
    unsigned        bytes_recv;

    //  lwIP pbuf circular buffer.  A list of pbufs that are used to store
    //  incoming Ethernet packets
    struct pbuf     *lwipRxPbuf[LWIP_RX_ETH_BUFFER];
    int             lwipRxIndexIsr;
    int             lwipRxIndex;
    int             lwipRxCount;
    
    //  Pointer to TSE hardware descriptor - needed to send packets
    struct _lwip_tse_info   *tse_info;
};

err_t ethernetif_init(struct netif *netif);
void ethernetif_input(struct netif *netif);

#endif /*ALTERATSEETHERNETIF_H_*/
