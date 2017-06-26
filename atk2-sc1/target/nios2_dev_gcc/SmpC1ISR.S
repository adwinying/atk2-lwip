/*
 *  TOPPERS ATK2
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *      Automotive Kernel Version 2
 *
 *  Copyright (C) 2011-2015 by Center for Embedded Computing Systems
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
 *  $Id: SmpC1ISR.S 1801 2015-03-27 06:34:43Z t_ishikawa $
 */

#define TOPPERS_MACRO_ONLY

#define UINT_C(val)	(val)
#define CAST(type, val)	(val)	/* 型キャストを行うマクロ */

#include "kernel/kernel_impl.h"
#include "vic.h"
#include "nios2.h"
#include "target_test.h"

.global C1ISRMainSmpC1ISR
.set noat

C1ISRMainSmpC1ISR:
	addi	ea,	ea,	-4	/* 戻り番地をデクリメント */

	/* レジスタの保存 */
	addi	sp,	sp,	-76
	stw		at,		0(sp)
	stw		r2,		4(sp)
	stw		r3,		8(sp)
	stw		r4,		12(sp)
	stw		r5,		16(sp)
	stw		r6,		20(sp)
	stw		r7,		24(sp)
	stw		r8,		28(sp)
	stw		r9,		32(sp)
	stw		r10,	36(sp)
	stw		r11,	40(sp)
	stw		r12,	44(sp)
	stw		r13,	48(sp)
	stw		r14,	52(sp)
	stw		r15,	56(sp)
	stw		ra,		60(sp)
	stw		ea,		64(sp)
	rdctl	et,		estatus
	stw		et,		68(sp)

	rdctl   r2, status
	ori     r2, r2, STATUS_PIE
	wrctl   status, r2

	/* 割込み発生前のcallevel_statをスタックに保存 */
	ldh		r2,		%gprel(callevel_stat)(gp)
	stw		r2,		72(sp)


	/* callevel_statにC1ISRをセット */
	ldhu	et,		%gprel(callevel_stat)(gp)
	ori		et,		et,	TSYS_ISR1
	sth		et,		%gprel(callevel_stat)(gp)

	/*
	 *  タイマ割込みをクリア
	 */
	movia	et,		TIMER_STATUS(TIMER_5_IRQ)
	stwio	zero,	0(et)

	call	c1isr_syslog

	ldw		r2,		72(sp)
	sth		r2,		%gprel(callevel_stat)(gp)

	rdctl r2, status
	movi  r3, ~STATUS_PIE
	and   r2, r2, r3
	wrctl status, r2

	/* レジスタの復帰 */
	ldw		at,		0(sp)
	ldw		r2,		4(sp)
	ldw		r3,		8(sp)
	ldw		r4,		12(sp)
	ldw		r5,		16(sp)
	ldw		r6,		20(sp)
	ldw		r7,		24(sp)
	ldw		r8,		28(sp)
	ldw		r9,		32(sp)
	ldw		r10,	36(sp)
	ldw		r11,	40(sp)
	ldw		r12,	44(sp)
	ldw		r13,	48(sp)
	ldw		r14,	52(sp)
	ldw		r15,	56(sp)
	ldw		ra,		60(sp)
	ldw		ea,		64(sp)
	ldw		et,		68(sp)
	wrctl	estatus,	et
	addi	sp,	sp,	76

	eret
