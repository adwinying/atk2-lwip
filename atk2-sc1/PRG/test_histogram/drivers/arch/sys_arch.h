/* @(#)sys_arch.h
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
 * Author: David Haas
 *
 */

#ifndef _SYS_ARCH_H
#define _SYS_ARCH_H 1

#include "cc.h"

#include <stdlib.h>

#define SYS_MBOX_NULL NULL
#define SYS_SEM_NULL  NULL

#if NO_SYS==0

typedef u32_t sys_sem_t;
struct lwip_mbox;
typedef struct lwip_mbox* sys_mbox_t;
typedef u8_t sys_thread_t;

#include "lwip/sys.h"

/*-----------------------------------------------------------------------------------*/
void
sys_arch_block(u32_t time);
/*-----------------------------------------------------------------------------------*/
u32_t 
sys_arch_mbox_fetch(sys_mbox_t mbox, void **data, u32_t timeout);
/*-----------------------------------------------------------------------------------*/
u32_t
sys_arch_sem_wait(sys_sem_t sem, u32_t timeout);
/*-----------------------------------------------------------------------------------*/
struct sys_timeouts *
sys_arch_timeouts(void);
/*-----------------------------------------------------------------------------------*/

#else

#define	LwipDisableInts(sr) do { sr = __builtin_rdctl(0); __builtin_wrctl(0, 0); } while(0)
#define	LwipEnableInts(sr) do { __builtin_wrctl(0, sr); } while(0)

/** SYS_ARCH_DECL_PROTECT
 * declare a protection variable. This macro will default to defining a variable of
 * type sys_prot_t. If a particular port needs a different implementation, then
 * this macro may be defined in sys_arch.h.
 */
#define SYS_ARCH_DECL_PROTECT(lev) sys_prot_t lev
/** SYS_ARCH_PROTECT
 * Perform a "fast" protect. This could be implemented by
 * disabling interrupts for an embedded system or by using a semaphore or
 * mutex. The implementation should allow calling SYS_ARCH_PROTECT when
 * already protected. The old protection level is returned in the variable
 * "lev". This macro will default to calling the sys_arch_protect() function
 * which should be implemented in sys_arch.c. If a particular port needs a
 * different implementation, then this macro may be defined in sys_arch.h
 */
#define SYS_ARCH_PROTECT(lev) LwipDisableInts(lev)
/** SYS_ARCH_UNPROTECT
 * Perform a "fast" set of the protection level to "lev". This could be
 * implemented by setting the interrupt level to "lev" within the MACRO or by
 * using a semaphore or mutex.  This macro will default to calling the
 * sys_arch_unprotect() function which should be implemented in
 * sys_arch.c. If a particular port needs a different implementation, then
 * this macro may be defined in sys_arch.h
 */
#define SYS_ARCH_UNPROTECT(lev) LwipEnableInts(lev)

#include "lwip/sys.h"

/*-----------------------------------------------------------------------------------*/
#define sys_arch_block(x)
/*-----------------------------------------------------------------------------------*/
#define sys_arch_mbox_fetch(m,d,t) (SYS_ARCH_TIMEOUT+1)
/*-----------------------------------------------------------------------------------*/
#define sys_arch_sem_wait(s,t)
/*-----------------------------------------------------------------------------------*/

#endif

#include "arch/errno.h"

#endif /* _SYS_ARCH_H */

