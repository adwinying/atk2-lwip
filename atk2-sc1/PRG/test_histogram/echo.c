/*
 * Copyright (c) 2001-2003 Swedish Institute of Computer Science.
 * All rights reserved. 
 * 
 * Redistribution and use in source and binary forms, with or without modification, 
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission. 
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED 
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT 
 * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT 
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING 
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY 
 * OF SUCH DAMAGE.
 *
 * This file is part of the lwIP TCP/IP stack.
 * 
 * Author: Adam Dunkels <adam@sics.se>
 *
 */

#include "lwip/udp.h"
#include "lwip/debug.h"
#include "histogram.h"
#include "test_histogram.h"

/*
 * Histogram variables
 */

#if MEASURE_HISTOGRAM
uint32          histarea[1001] = { 0 };
ObjectIDType    histid = 1;
boolean         measuring_flg = FALSE;
boolean         printed_flg = FALSE;
#endif


void udpecho_recv(void *arg, struct udp_pcb *pcb, struct pbuf *p, struct 
ip_addr *addr, u16_t port)
{
//#if MEASURE_HISTOGRAM
#if 0
    if (histid <= TNUM_HIST && measuring_flg == FALSE) {
        //syslog(LOG_INFO, "[histid: %d] Histogram measuring starting...", histid);
        begin_measure(histid);
        measuring_flg = TRUE;
    }
#endif

    if (p != NULL) {
        /* send received packet back to sender */
        udp_sendto(pcb, p, addr, port);
        /* free the pbuf */
        pbuf_free(p);
    }

#if MEASURE_HISTOGRAM
    // End histogram measure
    if (histid <= TNUM_HIST && measuring_flg == TRUE) {
        //syslog(LOG_INFO, "[histid: %d] Histogram measuring ending...", histid);
        if (end_measure(histid++)) {
            //syslog(LOG_INFO, "%d OK", histid);
        } else {
            //syslog(LOG_INFO, "%d ERR", histid);
        }
        measuring_flg = FALSE;
    }

    // Print histogram results
    if (histid > TNUM_HIST && printed_flg == FALSE) {
        syslog(LOG_INFO, "[histid: %d] Printing...", histid);
        printed_flg = TRUE;
        print_hist(TNUM_HIST);
    }
#endif
}


void udpecho_init(void)
{
    struct udp_pcb * pcb;
    syslog(LOG_INFO, "Initializing udp_init()...");

    /* get new pcb */
    pcb = udp_new();
    if (pcb == NULL) {
        syslog(LOG_INFO, "udp_new failed!\n");
        return;
    }

    /* bind to any IP address on port 7 */
    if (udp_bind(pcb, IP_ADDR_ANY, 7) != ERR_OK) {
        syslog(LOG_INFO, "udp_bind failed!\n");
        return;
    }

    /* set udp_echo_recv() as callback function
       for received packets */
    syslog(LOG_INFO, "Ready to accept UDP packets on port 7");
    udp_recv(pcb, udpecho_recv, NULL);
}
