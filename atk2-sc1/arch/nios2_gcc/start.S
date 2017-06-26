/*
 *  TOPPERS ATK2
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *      Automotive Kernel Version 2
 *
 *  Copyright (C) 2008-2015 by Center for Embedded Computing Systems
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *  Copyright (C) 2011-2015 by FUJI SOFT INCORPORATED, JAPAN
 *  Copyright (C) 2011-2013 by Spansion LLC, USA
 *  Copyright (C) 2011-2015 by NEC Communication Systems, Ltd., JAPAN
 *  Copyright (C) 2011-2015 by Panasonic Advanced Technology Development Co., Ltd., JAPAN
 *  Copyright (C) 2011-2014 by Renesas Electronics Corporation, JAPAN
 *  Copyright (C) 2011-2015 by Sunny Giken Inc., JAPAN
 *  Copyright (C) 2011-2015 by TOSHIBA CORPORATION, JAPAN
 *  Copyright (C) 2011-2015 by Witz Corporation
 *  Copyright (C) 2014-2015 by AISIN COMCRUISE Co., Ltd., JAPAN
 *  Copyright (C) 2014-2015 by eSOL Co.,Ltd., JAPAN
 *  Copyright (C) 2014-2015 by SCSK Corporation, JAPAN
 *
 *  上記著作権者は，以下の(1)〜(4)の条件を満たす場合に限り，本ソフトウェ
 *  ア（本ソフトウェアを改変したものを含む．以下同じ）を使用・複製・改
 *  変・再配布（以下，利用と呼ぶ）することを無償で許諾する．
 *  (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
 *      権表示，この利用条件および下記の無保証規定が，そのままの形でソー
 *      スコード中に含まれていること．
 *  (2) 本ソフトウェアを，ライブラリ形式など，他のソフトウェア開発に使
 *      用できる形で再配布する場合には，再配布に伴うドキュメント（利用
 *      者マニュアルなど）に，上記の著作権表示，この利用条件および下記
 *      の無保証規定を掲載すること．
 *  (3) 本ソフトウェアを，機器に組み込むなど，他のソフトウェア開発に使
 *      用できない形で再配布する場合には，次のいずれかの条件を満たすこ
 *      と．
 *    (a) 再配布に伴うドキュメント（利用者マニュアルなど）に，上記の著
 *        作権表示，この利用条件および下記の無保証規定を掲載すること．
 *    (b) 再配布の形態を，別に定める方法によって，TOPPERSプロジェクトに
 *        報告すること．
 *  (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
 *      害からも，上記著作権者およびTOPPERSプロジェクトを免責すること．
 *      また，本ソフトウェアのユーザまたはエンドユーザからのいかなる理
 *      由に基づく請求からも，上記著作権者およびTOPPERSプロジェクトを
 *      免責すること．
 *
 *  本ソフトウェアは，AUTOSAR（AUTomotive Open System ARchitecture）仕
 *  様に基づいている．上記の許諾は，AUTOSARの知的財産権を許諾するもので
 *  はない．AUTOSARは，AUTOSAR仕様に基づいたソフトウェアを商用目的で利
 *  用する者に対して，AUTOSARパートナーになることを求めている．
 *
 *  本ソフトウェアは，無保証で提供されているものである．上記著作権者お
 *  よびTOPPERSプロジェクトは，本ソフトウェアに関して，特定の使用目的
 *  に対する適合性も含めて，いかなる保証も行わない．また，本ソフトウェ
 *  アの利用により直接的または間接的に生じたいかなる損害に関しても，そ
 *  の責任を負わない．
 *
 *  $Id: start.S 1801 2015-03-27 06:34:43Z t_ishikawa $
 */

/*
 *		カーネル対応のスタートアップモジュール（Nios2用）
 */

#define OMIT_INCLUDE_OS_CFG		/* Os_Cfg.hインクルード抑止 */
#define TOPPERS_MACRO_ONLY
#define UINT_C(val)			(val)		/* 符号無し整数型の定数を作るマクロ */
#define CAST(type, val)		(val)		/* 型キャストを行うマクロ */
#include "kernel_impl.h"

	 .section .entry, "xa"
	 .global __reset
	 .balign  FUNCTION_ALIGN_SIZE
__reset:
#if NIOS2_ICACHE_SIZE > 0
	/*
	 * The assumption here is that the instruction cache size is always
	 * a power of two.
	 */

#if NIOS2_ICACHE_SIZE > 0x8000
	movhi r2, %hi(NIOS2_ICACHE_SIZE)
#else
	movui r2, NIOS2_ICACHE_SIZE
#endif
0:
	initi r2
	addi r2, r2, -NIOS2_ICACHE_LINE_SIZE
	bgt r2, zero, 0b
1:

	.pushsection .debug_alt_sim_info
	.int 1, 1, 0b, 1b
	.popsection
#endif /* NIOS2_ICACHE_SIZE > 0 */

#ifndef BOOT_ROM
	movia r3, start
	jmp r3
#else
	movia r3, _boot_rom
	jmp r3
#endif  /* BOOT_ROM */


#ifdef BOOT_ROM
	.section .text
	.global _boot_rom
	.balign  FUNCTION_ALIGN_SIZE
	.type _boot_rom, @function
_boot_rom:
#if NIOS2_DCACHE_SIZE > 0
#if NIOS2_DCACHE_SIZE > 0x8000
	movhi r2, %hi(NIOS2_DCACHE_SIZE)
#else
	movui r2, NIOS2_DCACHE_SIZE
#endif
0:
	initd 0(r2)
	addi r2, r2, -NIOS2_DCACHE_LINE_SIZE
	bgt r2, zero, 0b
1:
	.pushsection .debug_alt_sim_info
	.int 2, 1, 0b, 1b
	.popsection
#endif /* NIOS2_DCACHE_SIZE > 0 */

_boot_rom_1:
	movia   r3, ROM_BASE	/* r3 source */
	movia   r4, RAM_BASE	/* r4 destination */
	movia   r2, _edata

_flash_copy:
	ldw     r5, 0(r3)
	addi    r3, r3, 4
	stw     r5, 0(r4)
	addi    r4, r4, 4
	bgtu    r2, r4, _flash_copy

	movia r2, start
	jmp   r2
	nop

#endif /* BOOT_ROM */

	.section .text
	.global start
	.balign  FUNCTION_ALIGN_SIZE
	.type start, @function
start:
#if NIOS2_DCACHE_SIZE > 0
#if NIOS2_DCACHE_SIZE > 0x8000
	movhi r2, %hi(NIOS2_DCACHE_SIZE)
#else
	movui r2, NIOS2_DCACHE_SIZE
#endif
0:
	initd 0(r2)
	addi r2, r2, -NIOS2_DCACHE_LINE_SIZE
	bgt r2, zero, 0b
1:
	.pushsection .debug_alt_sim_info
	.int 2, 1, 0b, 1b
	.popsection
#endif /* NIOS2_DCACHE_SIZE > 0 */

	/*
	 *  STATUSレジスタの初期化（全割込み禁止）
	 */
	wrctl status, zero

	/*
	 * set up the global pointer.
	 */
	movia gp, _gp

	/*
	 *  スタックの設定
	 */
	ldw   sp, %gprel(_ostkpt)(gp)

start_0:
	movia r2, hardware_init_hook
	beq   zero, r2, start_1
	callr r2

	/*
	 * Clear bss.
	 */
start_1:
	movia r3, __bss_start

	movia r2, __bss_end

	beq   r3, r2, start_3
start_2:
	stw  zero, (r3)
	addi r3, r3, 4
	bltu r3, r2, start_2

start_3:
	movia r2, software_init_hook
	beq   zero, r2, start_4
	callr r2

start_4:
	call target_hardware_initialize
	call main

crt0_end:
	br crt0_end
