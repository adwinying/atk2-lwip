/*
 * alt_sys_init.c - HAL initialization source
 *
 * Machine generated for CPU 'cpu' in SOPC Builder design 'DE2_115_SOPC'
 * SOPC Builder design path: C:/cygwin/home/adwinying/FreeLwIP-Nios-II/FPGA/DE2_115_SOPC.sopcinfo
 *
 * Generated: Mon Apr 24 18:15:35 JST 2017
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#include "system.h"
#include "sys/alt_irq.h"
#include "sys/alt_sys_init.h"

#include <stddef.h>

/*
 * Device headers
 */

//#include "altera_vic_irq.h"
//#include "altera_avalon_cfi_flash.h"
//#include "altera_avalon_jtag_uart.h"
//#include "altera_avalon_lcd_16207.h"
#include "altera_avalon_sgdma.h"
//#include "altera_avalon_sysid_qsys.h"
//#include "altera_avalon_timer.h"
//#include "altera_avalon_uart.h"
#include "altera_eth_tse.h"

/*
 * Allocate the device storage
 */

//ALTERA_VIC_IRQ_INSTANCE ( VIC_0, vic_0);
//ALTERA_AVALON_CFI_FLASH_INSTANCE ( EXT_FLASH, ext_flash);
//ALTERA_AVALON_JTAG_UART_INSTANCE ( JTAG_UART, jtag_uart);
//ALTERA_AVALON_LCD_16207_INSTANCE ( LCD, lcd);
ALTERA_AVALON_SGDMA_INSTANCE ( SGDMA_RX, sgdma_rx);
ALTERA_AVALON_SGDMA_INSTANCE ( SGDMA_TX, sgdma_tx);
//ALTERA_AVALON_SYSID_QSYS_INSTANCE ( SYSID, sysid);
//ALTERA_AVALON_TIMER_INSTANCE ( SYS_CLK_TIMER, sys_clk_timer);
//ALTERA_AVALON_TIMER_INSTANCE ( TIMER_0, timer_0);
//ALTERA_AVALON_TIMER_INSTANCE ( TIMER_1, timer_1);
//ALTERA_AVALON_TIMER_INSTANCE ( TIMER_10, timer_10);
//ALTERA_AVALON_TIMER_INSTANCE ( TIMER_11, timer_11);
//ALTERA_AVALON_TIMER_INSTANCE ( TIMER_12, timer_12);
//ALTERA_AVALON_TIMER_INSTANCE ( TIMER_13, timer_13);
//ALTERA_AVALON_TIMER_INSTANCE ( TIMER_14, timer_14);
//ALTERA_AVALON_TIMER_INSTANCE ( TIMER_15, timer_15);
//ALTERA_AVALON_TIMER_INSTANCE ( TIMER_2, timer_2);
//ALTERA_AVALON_TIMER_INSTANCE ( TIMER_3, timer_3);
//ALTERA_AVALON_TIMER_INSTANCE ( TIMER_4, timer_4);
//ALTERA_AVALON_TIMER_INSTANCE ( TIMER_5, timer_5);
//ALTERA_AVALON_TIMER_INSTANCE ( TIMER_6, timer_6);
//ALTERA_AVALON_TIMER_INSTANCE ( TIMER_7, timer_7);
//ALTERA_AVALON_TIMER_INSTANCE ( TIMER_8, timer_8);
//ALTERA_AVALON_TIMER_INSTANCE ( TIMER_9, timer_9);
//ALTERA_AVALON_UART_INSTANCE ( RS232, rs232);
//ALTERA_AVALON_UART_INSTANCE ( UART_0, uart_0);
//ALTERA_AVALON_UART_INSTANCE ( UART_1, uart_1);
ALTERA_ETH_TSE_INSTANCE ( TSE_MAC, tse_mac);

/*
 * Initialize the interrupt controller devices
 * and then enable interrupts in the CPU.
 * Called before alt_sys_init().
 * The "base" parameter is ignored and only
 * present for backwards-compatibility.
 */

void alt_irq_init ( const void* base )
{
//    ALTERA_VIC_IRQ_INIT ( VIC_0, vic_0);
    alt_irq_cpu_enable_interrupts();
}

/*
 * Initialize the non-interrupt controller devices.
 * Called after alt_irq_init().
 */

void alt_sys_init( void )
{
    //ALTERA_AVALON_TIMER_INIT ( SYS_CLK_TIMER, sys_clk_timer);
    //ALTERA_AVALON_TIMER_INIT ( TIMER_0, timer_0);
    //ALTERA_AVALON_TIMER_INIT ( TIMER_1, timer_1);
    //ALTERA_AVALON_TIMER_INIT ( TIMER_10, timer_10);
    //ALTERA_AVALON_TIMER_INIT ( TIMER_11, timer_11);
    //ALTERA_AVALON_TIMER_INIT ( TIMER_12, timer_12);
    //ALTERA_AVALON_TIMER_INIT ( TIMER_13, timer_13);
    //ALTERA_AVALON_TIMER_INIT ( TIMER_14, timer_14);
    //ALTERA_AVALON_TIMER_INIT ( TIMER_15, timer_15);
    //ALTERA_AVALON_TIMER_INIT ( TIMER_2, timer_2);
    //ALTERA_AVALON_TIMER_INIT ( TIMER_3, timer_3);
    //ALTERA_AVALON_TIMER_INIT ( TIMER_4, timer_4);
    //ALTERA_AVALON_TIMER_INIT ( TIMER_5, timer_5);
    //ALTERA_AVALON_TIMER_INIT ( TIMER_6, timer_6);
    //ALTERA_AVALON_TIMER_INIT ( TIMER_7, timer_7);
    //ALTERA_AVALON_TIMER_INIT ( TIMER_8, timer_8);
    //ALTERA_AVALON_TIMER_INIT ( TIMER_9, timer_9);
    //ALTERA_AVALON_CFI_FLASH_INIT ( EXT_FLASH, ext_flash);
    //ALTERA_AVALON_JTAG_UART_INIT ( JTAG_UART, jtag_uart);
    //ALTERA_AVALON_LCD_16207_INIT ( LCD, lcd);
    ALTERA_AVALON_SGDMA_INIT ( SGDMA_RX, sgdma_rx);
    ALTERA_AVALON_SGDMA_INIT ( SGDMA_TX, sgdma_tx);
    //ALTERA_AVALON_SYSID_QSYS_INIT ( SYSID, sysid);
    //ALTERA_AVALON_UART_INIT ( RS232, rs232);
    //ALTERA_AVALON_UART_INIT ( UART_0, uart_0);
    //ALTERA_AVALON_UART_INIT ( UART_1, uart_1);
    ALTERA_ETH_TSE_INIT ( TSE_MAC, tse_mac);
}
