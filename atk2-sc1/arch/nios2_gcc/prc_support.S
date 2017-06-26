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
 *  $Id: prc_support.S 1801 2015-03-27 06:34:43Z t_ishikawa $
 */

/*
 *		ターゲット依存情報の定義
 */
#define TOPPERS_MACRO_ONLY
#define UINT_C(val)			(val)		/* 符号無し整数型の定数を作るマクロ */
#define CAST(type, val)		(val)		/* 型キャストを行うマクロ */

#include "kernel_impl.h"
#include "offset.h"

/*
 *  全割込み禁止マクロ
 */
.macro LOCK_ALL_INT sc_reg1, sc_reg2
	rdctl \sc_reg1, status
	movi  \sc_reg2, ~STATUS_PIE
	and   \sc_reg1, \sc_reg1, \sc_reg2
	wrctl status, \sc_reg1
.endm

/*
 *  全割込み禁止解除マクロ
 */
.macro UNLOCK_ALL_INT sc_reg
	rdctl \sc_reg, status
	ori   \sc_reg, \sc_reg, %lo(STATUS_PIE)
	wrctl status, \sc_reg
.endm

/*
 *  OS割込み禁止マクロ
 *  ネストの一番外側で呼び出されることを想定している
 */
.macro OUTER_LOCK_OS_INT sc_reg1, sc_reg2
	rdctl \sc_reg1, status
	movi  \sc_reg2, ~STATUS_IL
	and   \sc_reg1, \sc_reg1, \sc_reg2
	ldw   \sc_reg2, %gprel(tmin_status_il)(gp)
	or    \sc_reg1, \sc_reg1, \sc_reg2
	wrctl status, \sc_reg1
	movi  \sc_reg1, 1
	stb   \sc_reg1, %gprel(nested_lock_os_int_cnt)(gp)
	stw   zero, %gprel(saved_status_il)(gp)
.endm

/*
 *  OS割込み禁止解除マクロ
 *  ネストの一番外側で呼び出されることを想定している
 */
.macro OUTER_UNLOCK_OS_INT sc_reg1, sc_reg2
	stb   zero, %gprel(nested_lock_os_int_cnt)(gp)
	rdctl \sc_reg1, status
	movi  \sc_reg2, ~STATUS_IL
	and   \sc_reg1, \sc_reg1, \sc_reg2
	wrctl status, \sc_reg1
.endm

 /*
  * スタック操作 : プッシュ
  */
.macro PUSH reg
	addi  sp, sp, -4
	stw   \reg, 0(sp)
.endm

 /*
  * スタック操作 : ポップ
  */
.macro POP reg
	ldw   \reg, 0(sp)
	addi  sp, sp, 4
.endm

/*
 *  例外エントリ
 *  プロセッサの状態は，
 *    ・status.PIEがクリアされ全割り込み禁止
 *    ・status.ILは例外発生前の値
 *    ・estatusに例外発生前のstatusの内容が入っている
 */
	.set noat
	.section .exceptions, "xa"
	.global exception_entry
	.balign  FUNCTION_ALIGN_SIZE
exception_entry:

	/*
	 *  Trapかを判定
	 */
check_trap:
	ldw   et, -4(ea)               /* 例外を出した命令を取得 */
	xorhi et, et, 0x003b           /*  上位16bit             */
	xori  et, et, 0x683a           /*  下位16bit             */
	beq   et, zero, trap_handler   /* trap命令のバイナリ 0x003b683a */

	/*
	 *  例外エントリ
	 */
exception:
	/*
	 *  コンテキストの保存
	 */
	addi  sp, sp, -72    /* レジスタの保存 */
	stw   at,   0(sp)
	stw   r2,   4(sp)
	stw   r3,   8(sp)
	stw   r4,  12(sp)
	stw   r5,  16(sp)
	stw   r6,  20(sp)
	stw   r7,  24(sp)
	stw   r8,  28(sp)
	stw   r9,  32(sp)
	stw   r10, 36(sp)
	stw   r11, 40(sp)
	stw   r12, 44(sp)
	stw   r13, 48(sp)
	stw   r14, 52(sp)
	stw   r15, 56(sp)
	stw   ra,  60(sp)
	stw   ea,  64(sp)
	rdctl et,  estatus
	stw   et,  68(sp)

	/*
	 *  プロテクションフックはOS処理レベルで実行するためOS割込み禁止状態にする
	 *  OS割込み禁止状態で例外が発生する可能性があるため，ネスト管理を行う
	 *  C1ISR実行時に発生した場合は，優先度マスクがOS割込み禁止状態より高いため，
	 *  status.ILは変更しない
	 *  例外は次の条件で発生する
	 *   ・C1ISR実行状態で発生した場合
	 *   ・C1ISR実行状態以外で発生した場合
	 *    ・OS割込み解除状態で発生した場合
	 *    ・OS割込み禁止状態で発生した場合
	 */

	/*
	 *  C1ISR実行状態で発生した場合は何も行わない
	 *  OS割込み禁止状態のILの値よりstatus.ILが高優先度ならC1ISRで例外が発生
	 *  r2，r7を保持して，スタックポインタの入れ替え判定時にも使用
	 */
	rdctl r4,status
	andi  r7, r4, STATUS_IL
	ldw   r2, %gprel(tmin_status_il)(gp)
	bltu  r2, r7, exception_1

	/*
	 *  C1ISR実行状態以外で発生した場合
	 */
	ldbu  r3, %gprel(nested_lock_os_int_cnt)(gp)
	addi  r1, r3, 1
	stb   r1, %gprel(nested_lock_os_int_cnt)(gp)

	/*
	 *  OS割込み禁止状態で発生した場合はstatusを変更しない
	 */
	bne   zero, r3, exception_1

	/*
	 *  OS割込み解除状態で発生した場合
	 *  OS割込み禁止状態とする
	 *  例外の出口のリターン(eret)によりstatus.ILは例外前に戻るため，
	 *  saved_status_ilには保存しない
	 */
	movi  r3, ~STATUS_IL
	and   r3, r4, r3
	or    r3, r3, r2
	wrctl status, r3

exception_1:
	/*
	 *  CPU例外番号, badaddr
	 *  割込み発生時に変更されるので割込み禁止解除前に取得
	 */
	rdctl r5, exception
	rdctl r8, badaddr

	/*
	 *  例外発生時に全割込み禁止状態でなければ全割込み禁止解除状態とする
	 */
	rdctl r3, estatus
	andi  r3, r3, STATUS_PIE
	beq   r3, zero, exception_2

	UNLOCK_ALL_INT r1

exception_2:
	/*
	 *  カーネル起動していない場合に起きたCPU例外は，無限ループへ
	 */
	ldb   r3, %gprel(kerflg)(gp)  /* kerflgを取得FALSEなら無限ループ */
	beq   zero, r3, infinity_loop

	/*
	 *  割込み・例外のネスト回数のインクリメント
	 */
	ldw   r3, %gprel(except_nest_cnt)(gp)
	addi  r4, r3, 1
	stw   r4, %gprel(except_nest_cnt)(gp)

	mov   r4, sp        /* r4にspを退避 */

	/*
	 *  多重割込みか判定
	 */
	bltu  zero, r3, exception_3

	/*
	 *  C1ISR実行状態で発生した場合はスタックポインタの入れ替えしない
	 *  r2にtmin_status_il，r7にSTATUS_ILが保持されている
	 */
	bltu  r2, r7, exception_3

	/*
	 *  スタックポインタの入れ替え
	 */
	ldw   r2, %gprel(_ostkpt)(gp)
	addi  r2, r2, -4
	stw   sp, 0(r2)     /* スタックポインタの保存 */
	mov   sp, r2        /* スタックポインタの入れ替え */

exception_3:
#ifdef CFG_USE_PROTECTIONHOOK
	/*
	 *  CPU例外がネストして発生した場合に，CPU例外情報を正しく取得できるように
	 *  するため，プロテクションフック実行前にCPU例外情報を退避し，
	 *  プロテクションフックを実行後，退避したCPU例外情報を復帰する．
	 *  CPU例外情報を保存復帰しない場合，CPU例外処理中(※1)にC1ISRが発生し，
	 *  そのC1ISR実行中にCPU例外が発生したとき(※2)，(※2)のCPU例外処理により，
	 *  (※1)のCPU例外情報が上書きされ，(※1)のCPU例外処理に戻ったとき，
	 *  (※1)のプロテクションフックから観測されるCPU例外情報が，(※2)のものと
	 *  なり，正しくない情報が取得されてしまう．
	 */
	/* nios2_cpu_exp_*を退避するスペースを確保 */
	addi  sp, sp, -16

	/* nios2_cpu_exp_noを退避 */
	ldw   r6, %gprel(nios2_cpu_exp_no)(gp)
	stw   r6, 12(sp)

	/*
	 *  exception / 4が例外番号
	 */
	andi  r5, r5, ((1 << 7) - 1)
	srli  r5, r5, 2

	stw   r5, %gprel(nios2_cpu_exp_no)(gp)

	/* nios2_cpu_exp_pcを退避 */
	ldw   r6, %gprel(nios2_cpu_exp_pc)(gp)
	stw   r6, 8(sp)

	/*
	 *  例外発生時のPC - 4を取得
	 *  r4に前のspが入っている
	 */
	ldw   r6, 64(r4)
	addi  r6, r6, -4
	stw   r6, %gprel(nios2_cpu_exp_pc)(gp)

	/* nios2_cpu_exp_bad_addrを退避 */
	ldw   r6, %gprel(nios2_cpu_exp_bad_addr)(gp)
	stw   r6, 4(sp)

	stw   r8, %gprel(nios2_cpu_exp_bad_addr)(gp)

	/* nios2_cpu_exp_bad_spを退避 */
	ldw   r6, %gprel(nios2_cpu_exp_sp)(gp)
	stw   r6, 0(sp)

	/* r4に前のspが入っている */
	stw   r4, %gprel(nios2_cpu_exp_sp)(gp)
#endif /* CFG_USE_PROTECTIONHOOK */

	/*
	 *  CPU例外が発生した場合，OSはE_OS_PROTECTION_EXCEPTIONをパラメータとして
	 *  プロテクションフックを呼び出す
	 */
	movi  r4,  E_OS_PROTECTION_EXCEPTION 	/* call_protectionhk_mainの引数設定 */
	call  call_protectionhk_main		/* プロテクションフックの呼び出し */

#ifdef CFG_USE_PROTECTIONHOOK
	/* nios2_cpu_exp_noを復帰 */
	ldw   r6, 12(sp)
	stw   r6, %gprel(nios2_cpu_exp_no)(gp)

	/* nios2_cpu_exp_pcを復帰 */
	ldw   r6, 8(sp)
	stw   r6, %gprel(nios2_cpu_exp_pc)(gp)

	/* nios2_cpu_exp_bad_addrを復帰 */
	ldw   r6, 4(sp)
	stw   r6, %gprel(nios2_cpu_exp_bad_addr)(gp)

	/* nios2_cpu_exp_bad_spを復帰 */
	ldw   r6, 0(sp)
	stw   r6, %gprel(nios2_cpu_exp_sp)(gp)

	/* nios2_cpu_exp_*を退避したスペースを戻す */
	addi  sp, sp, 16
#endif /* CFG_USE_PROTECTIONHOOK */

ret_exc:
	/*
	 *  プロテクションフックはOS割込み禁止状態で実行する
	 *  ret_int_1 の eret で esatus -> status で解除される
	 */

	/*
	 *  割込み・例外のネスト回数のデクリメント
	 */
	ldw   r3, %gprel(except_nest_cnt)(gp)
	addi  r3, r3, -1
	stw   r3, %gprel(except_nest_cnt)(gp)

	/*
	 *  OS割込み禁止状態の解除
	 */
	/*
	 *  C1ISR実行状態で発生した場合は
	 *  (1)スタックポインタの入れ替えをしない
	 *  (2)OS割込み禁止状態の解除をしない
	 *  OS割込み禁止状態のILの値よりstatus.ILが高優先度ならC1ISRで発生した例外
	 *  r4のstatusを保持してret_exc_2でも使用
	 */
	rdctl r4,status
	andi  r5, r4, STATUS_IL
	ldw   r6, %gprel(tmin_status_il)(gp)
	bltu  r6, r5, ret_exc_2

	/*
	 *  ネスト回数が1以上なら割込み元がISRなため例外発生元へ復帰
	 *  スタックポインタの入れ替えしない
	 */
	bne  zero, r3, ret_exc_1

	/*
	 *  戻り先がタスクなためスタックを戻す
	 */
	ldw   r2, 0(sp)              /* スタックポインタを戻す    */
	mov   sp, r2

ret_exc_1:
	/*
	 *  C1ISR実行状態以外で発生した場合，OS割込み禁止状態の解除
	 *  例外からのリターンによりstatus.ILは例外前に戻るため，status.ILの更新はしない
	 */
	ldbu  r3, %gprel(nested_lock_os_int_cnt)(gp)
	addi  r3, r3, -1
	stb   r3, %gprel(nested_lock_os_int_cnt)(gp)

	/*
	 *  例外発生元へ復帰
	 *  ret_int_1 は全割込み禁止状態で呼び出す必要がある
	 */
ret_exc_2:
	andi  r4, r4, STATUS_PIE		/* statusのPIEだけを残す */
	ldw   r1, 68(sp)				/* CPU例外発生時のstatus(estatus) */
	movi  r2, ~STATUS_PIE
	and   r1, r1, r2				/* etatusのPIEをクリア */
	or    r1, r1, r4				/* estatusのPIEをstatusのPIEにする */
	stw   r1, 68(sp)

	LOCK_ALL_INT  r1, r2
	br ret_int_1

	/*
	 *  カーネル起動していない場合に起きたCPU例外の無限ループ
	 */
infinity_loop:
	br infinity_loop

	/*
	 *  割り込みエントリ
	 *  ベクターテーブルから Os_Lcfg.c に生成される各割込みの割込みエントリ
	 *  からジャンプし，etに割込み番号が保存された状態で実行される
	 *  プロセッサの状態は，
	 *    ・status.PIEがクリアされ全割込み禁止
	 *    ・status.ILに受け付けた割込みの割込み優先度がセット
	 *    ・estatusに割込み前のstatusの内容が入っている
	 */
	.global interrupt
	.balign  FUNCTION_ALIGN_SIZE
interrupt:
	addi  ea, ea, -4     /* 戻り番地をデクリメント */
	addi  sp, sp, -72    /* レジスタの保存 */
	stw   at,   0(sp)
	stw   r2,   4(sp)
	stw   r3,   8(sp)
	stw   r4,  12(sp)
	stw   r5,  16(sp)
	stw   r6,  20(sp)
	stw   r7,  24(sp)
	stw   r8,  28(sp)
	stw   r9,  32(sp)
	stw   r10, 36(sp)
	stw   r11, 40(sp)
	stw   r12, 44(sp)
	stw   r13, 48(sp)
	stw   r14, 52(sp)
	stw   r15, 56(sp)
	stw   ra,  60(sp)
	stw   ea,  64(sp)
	mov   r4,  et        /* 割込み要因をr4に移動 */
	rdctl et, estatus
	stw   et,  68(sp)

	/*
	 *  多重割込みか判定
	 */
	ldw   r3, %gprel(except_nest_cnt)(gp)

	/*
	 *  割込み・例外のネスト回数のインクリメント
	 */
	addi  r5, r3, 1
	stw   r5, %gprel(except_nest_cnt)(gp)

	bltu  zero, r3,  interrupt_1		/* ネストしている場合はスタック切替無し */

	/*
	 *  タスクに割込んだ場合
	 *  スタックポインタの入れ替え
	 */
	ldw   r2, %gprel(_ostkpt)(gp)
	addi  r2, r2, -4
	stw   sp, 0(r2)     /* スタックポインタの保存     */
	mov   sp, r2        /* スタックポインタの入れ替え */

interrupt_1:
	UNLOCK_ALL_INT r1

	/*
	 *  タスクスタックのオーバフローチェック
	 */
#ifdef CFG_USE_STACKMONITORING

	/*
	 *  多重割込みの場合はタスクスタックのスタックモニタリングを行わない
	 */
	bltu  zero, r3,  int_nested

	/*
	 *  スタックポインタチェック方式
	 */
	ldw   r7,   0(sp)								/* 保存したタスクスタックポインタを取得 */
	ldw   r6,   %gprel(p_runtsk)(gp)				/* 管理ブロックの先頭アドレス取得 */
	ldw   r6,   TCB_p_tinib(r6)						/* タスク初期化ブロック先頭アドレス取得 */
	ldw   r6,   TINIB_stk(r6)						/* タスクスタック先頭アドレス取得 */
	bleu  r7,   r6,  stack_monitoring_error_isr		/* スタックポインタ <= スタックの先頭の場合NG  */
	/*
	 *  マジックナンバーチェック方式
	 */
	ldw   r8,  0(r6)								/* タスクスタックの先頭アドレスからマジック領域の値取得 */
	movia r6,  STACK_MAGIC_NUMBER					/* マジックナンバーの取得 */
	/*
	 *  マジックナンバー未破壊なら，割込み処理に飛ぶ
	 *  タスクに割込んだ場合，割込みスタックをチェックしない
	 */
	beq   r8,  r6,  stack_monitoring_exit
	br    stack_monitoring_error_isr				/* タスクスタックマジックナンバー破壊した場合NG  */

	/*
	 *  多重割込みの場合
	 */
int_nested:
	/*
	 *  割込みスタックのオーバフローチェック
	 */
	/*
	 *  スタック残量チェック方式
	 */
	movia r2,	isr_p_isrcb_tbl					/* ISR管理ブロックテーブル呼出し */
	slli  r3,	r4,  2							/* 割込み番号を4倍してオフセットを生成 */
	add	  r2,	r2,	 r3
	ldw	  r5,	0(r2)
	ldw   r7,	ISRCB_p_intinib(r5)				/* 割込み番号に対応したISRCBのアドレス取得 */
	ldw   r7,   INTINIB_remain_stksz(r7)		/* 割込み番号に対応したスタックサイズの初期化アドレス取得 */
	ldw   r6,   %gprel(_ostk)(gp)				/* 割込みスタックの先頭アドレス取得 */
	add   r7,   r7,	 r6							/* 先頭アドレス＋ISRの使用するスタックサイズ */
	bleu  sp,   r7,  stack_monitoring_error_isr	/* SP <= 先頭アドレス＋ISRの使用するスタックサイズ の場合NG  */

	/*
	 *  マジックナンバーチェック方式
	 */
	ldw   r7,   0(r6)							/* マジック領域の値取得 */
	movia r6,   STACK_MAGIC_NUMBER				/* マジックナンバーの取得 */
	bne   r7,   r6, stack_monitoring_error_isr	/* マジックナンバーと比較 */
stack_monitoring_exit:
#endif /* CFG_USE_STACKMONITORING */

	/*
	 *  callevel_stat 保存
	 */
	ldh   r3, %gprel(callevel_stat)(gp)
	PUSH  r3

	/*
	 *  callevel_stat 設定
	 */
	ori   r6, r3, TCL_ISR2
	sth   r6, %gprel(callevel_stat)(gp)

	/*
	 *  p_runisr 保存
	 */
	ldw   r3, %gprel(p_runisr)(gp)
	PUSH  r3

	/*
	 *  p_runisr 設定
	 */
	movia r2, isr_p_isrcb_tbl
	slli  r3, r4, 2                 /* 割込み番号を4倍してオフセットを生成  */
	add   r2, r2, r3
	ldw   r5,0(r2)
	stw   r5, %gprel(p_runisr)(gp)

	/*
	 *  割込みハンドラのアドレスを読み込む
	 */
	movia r2, isr_tbl
	add   r2, r2, r3
	ldw   r6, 0(r2)

	/*
	 *  割込みハンドラ呼び出し
	 */
	callr r6

	/*
	 *  割込みスタックのオーバフローチェック
	 *  割込みから戻った時，スタックポインタも戻ったはずなので，
	 *  マジックナンバーチェック方式のみ実施
	 */
#ifdef CFG_USE_STACKMONITORING
	/*
	 *  マジックナンバーチェック方式
	 */
	ldw   r6, %gprel(_ostk)(gp)				/* 割込みスタックの先頭アドレス取得 */
	ldw   r7, 0(r6)								/* マジック領域の値取得 */
	movia r6, STACK_MAGIC_NUMBER				/* マジックナンバーの取得 */
	bne   r7, r6, stack_monitoring_error_isr	/* マジックナンバーと比較 */
#endif /* CFG_USE_STACKMONITORING */

	/*
	 *  C2ISRの不正終了チェック
	 */
	call  exit_isr2

	/*
	 *  p_runisr の復帰
	 */
	POP   r3
	stw   r3, %gprel(p_runisr)(gp)

	/*
	 *  callevel_stat の復帰
	 */
	POP   r3
	sth   r3, %gprel(callevel_stat)(gp)

/*
 *  割込みハンドラ出口処理
 */
ret_int:
	/*
	 *  except_nest_cntの操作とスタック切り替えの間はOS割込み禁止にする
	 *  必要がある
	 *  この先，割込み先へのリターンか，遅延ディスパッチに分岐する
	 *  割込み先へのリターンには全割込みが必要であり，遅延ディスパッチ時には
	 *  ネスト管理のOS割込み禁止にする必要があるため，ここでは一旦全割込み禁
	 *  止とする
	 */
	LOCK_ALL_INT  r1, r2

	/*
	 *  割込み・例外のネスト回数のデクリメント
	 */
	ldw   r3, %gprel(except_nest_cnt)(gp)
	addi  r3, r3, -1
	stw   r3, %gprel(except_nest_cnt)(gp)

	/*
	 *  ネスト回数が0なら，割込み元がタスク
	 */
	beq  zero, r3, ret_int_task

	/*
	 *  C2ISR割込みからのリターン時は割込み元が
	 *  C2ISRであるためそのままリターン
	 */
	br    ret_int_1

	/*
	 *  割込み元がタスクの場合
	 */
ret_int_task:
	ldw   r2, 0(sp)              /* スタックポインタを戻す    */
	mov   sp, r2

	/*
	 *  戻り先がタスクの場合，ディスパッチの必要があるかチェック
	 */
	ldw   r4, %gprel(p_runtsk)(gp)
	ldw   r5, %gprel(p_schedtsk)(gp)
	beq   r4, r5, ret_int_1      /* ディスパッチの必要がなければ割込み元へ戻る */

	/*
	 *  ここでは，戻り先がタスクであり，スタックは，タスクスタックに
	 *  スクラッチレジスタのみが保存された状態になっている．また，
	 *  全割込みを禁止した状態となっている
	 */

	/*
	 *  OS割込み禁止状態に移行する
	 *
	 *  この時点でOS割込み禁止状態とするのは，dispatcherを実行する際に
	 *  OS割込み禁止状態になっている必要があるためである
	 *
	 *  (モデル上の)割込み優先度マスクは0であるため，C1ISR以外の割込みは全て禁止する
	 */
	OUTER_LOCK_OS_INT  r1, r2
	/* ret_int で全割込み禁止状態としたため解除 */
	UNLOCK_ALL_INT r1

	/*
	 *  r4にはp_runtskが入っている
	 */
	addi  sp,   sp, -36                /* 残りのレジスタを保存 */
	stw   r16,  0(sp)
	stw   r17,  4(sp)
	stw   r18,  8(sp)
	stw   r19, 12(sp)
	stw   r20, 16(sp)
	stw   r21, 20(sp)
	stw   r22, 24(sp)
	stw   r23, 28(sp)
	stw   fp,  32(sp)
	stw   sp,  TCB_sp(r4)         /* タスクスタックをTCBに保存 */
	movia r2,  ret_int_r          /* 実行再開番地をTCBに保存   */
	stw   r2,  TCB_pc(r4)
	br    dispatcher

	/*
	 *  割込み・例外でコンテキスト保存した場合の復帰ルーチン
	 */
ret_int_r:
	ldw   r16,  0(sp)       /* レジスタを復帰 */
	ldw   r17,  4(sp)
	ldw   r18,  8(sp)
	ldw   r19, 12(sp)
	ldw   r20, 16(sp)
	ldw   r21, 20(sp)
	ldw   r22, 24(sp)
	ldw   r23, 28(sp)
	ldw   fp,  32(sp)
	addi  sp, sp, 36

	/*
	 *  プリタスクフックでDisableAllInterrupts()をした場合は，
	 *  estatusにSTATUS_PIEを反映させる
	 */
	rdctl r2, status
	andi  r2, r2, STATUS_PIE
	ldw   r1, 68(sp)
	movi  r3, %lo(~STATUS_PIE)
	and   r1, r1, r3
	or    r1, r1, r2
	stw   r1, 68(sp)

	/*
	 *  esatus を使うため全割込み禁止とする
	 */
	LOCK_ALL_INT  r1, r2

	OUTER_UNLOCK_OS_INT  r1, r2

	/*
	 *  割込みからの復帰ルーチン
	 *  estatusを用いるため全割込み禁止状態で呼び出すこと．
	 *  全割込み禁止状態は，eretにより解除される
	 *  eret で estatus -> status となるため，ILは元の値，PIEは割り込み許可
	 *  に設定される
	 */
ret_int_1:
	/*
	 *  レジスタを復帰
	 */
	ldw   at,   0(sp)
	ldw   r2,   4(sp)
	ldw   r3,   8(sp)
	ldw   r4,  12(sp)
	ldw   r5,  16(sp)
	ldw   r6,  20(sp)
	ldw   r7,  24(sp)
	ldw   r8,  28(sp)
	ldw   r9,  32(sp)
	ldw   r10, 36(sp)
	ldw   r11, 40(sp)
	ldw   r12, 44(sp)
	ldw   r13, 48(sp)
	ldw   r14, 52(sp)
	ldw   r15, 56(sp)
	ldw   ra,  60(sp)
	ldw   ea,  64(sp)
	ldw   et,  68(sp)
	wrctl estatus, et
	addi  sp, sp, 72
	eret

	/*
	 *  Trapハンドラ
	 */
trap_handler:
	eret

/*
 *  タスクディスパッチ
 */
	.global dispatch
	.balign  FUNCTION_ALIGN_SIZE
dispatch:
	/*
	 *  このルーチンは，タスクコンテキスト・OS割込み禁止状態・ディスパッチ
	 *  許可状態・（モデル上の）割込み優先度マスク全解除状態で呼び出さ
	 *  れる
	 */
	addi  sp, sp, -40                /* レジスタを保存 */
	stw   r16,  0(sp)
	stw   r17,  4(sp)
	stw   r18,  8(sp)
	stw   r19, 12(sp)
	stw   r20, 16(sp)
	stw   r21, 20(sp)
	stw   r22, 24(sp)
	stw   r23, 28(sp)
	stw   fp,  32(sp)
	stw   ra,  36(sp)
	ldw   r4,  %gprel(p_runtsk)(gp) /* r4 <- runtsk              */
	stw   sp,  TCB_sp(r4)           /* タスクスタックをTCBに保存 */
	movia r5,  dispatch_r			/* 実行開始番地を保存        */
	stw   r5,  TCB_pc(r4)           /* 実行再開番地をTCBに保存   */

#ifdef CFG_USE_STACKMONITORING
	/*
	 *  実行中タスクのタスクスタックのオーバフローチェック
	 */
	/*
	 *  スタックポインタチェック方式
	 */
	ldw   r6,  %gprel(p_runtsk)(gp)				/* 管理ブロックの先頭アドレス取得 */
	ldw   r6,  TCB_p_tinib(r6)					/* タスク初期化ブロック先頭アドレス取得 */
	ldw   r6,  TINIB_stk(r6)					/* タスクスタック先頭アドレス取得 */
	bleu  sp,  r6,  stack_monitoring_error		/* スタックポインタ <= スタックの先頭の場合NG  */
	/*
	 * マジックナンバーチェック方式
	 */
	ldw   r7,  0(r6)							/* タスクスタックの先頭アドレスからマジック領域の値取得 */
	movia r6,  STACK_MAGIC_NUMBER				/* マジックナンバーの取得 */
	bne   r7,  r6,  stack_monitoring_error		/* マジックナンバーと比較 */
#endif /* CFG_USE_STACKMONITORING */

	br    dispatcher

dispatch_r:
	ldw   r16,  0(sp)               /* レジスタを復帰 */
	ldw   r17,  4(sp)
	ldw   r18,  8(sp)
	ldw   r19, 12(sp)
	ldw   r20, 16(sp)
	ldw   r21, 20(sp)
	ldw   r22, 24(sp)
	ldw   r23, 28(sp)
	ldw   fp,  32(sp)
	ldw   ra,  36(sp)
	addi  sp, sp, 40
	ret

/*
 *  ディスパッチャの動作開始
 */
	.global start_dispatch
	.balign  FUNCTION_ALIGN_SIZE
start_dispatch:
	/*
	 *  このルーチンは，カーネル起動時に，すべての割込みを禁止した状態
	 *  で呼び出される．また，sp＝非タスクコンテキスト用スタックポイン
	 *  タの状態で呼び出されることを想定している
	 *
	 *  dispatcherは，OS割込み禁止状態で呼び出す
	 */
	/* OS割込み禁止状態 */
	OUTER_LOCK_OS_INT r1, r2
	/* 全割込み禁止解除状態へ */
	UNLOCK_ALL_INT  r1
	br    dispatcher_0

	/*
	 *  現在のコンテキストを捨ててディスパッチ
	 */
	.global exit_and_dispatch
	.balign  FUNCTION_ALIGN_SIZE
exit_and_dispatch:
#ifdef CFG_USE_STACKMONITORING
	/*
	 *  実行中タスクのタスクスタックのオーバフローチェック
	 */
	/*
	 *  スタックポインタチェック方式
	 */
	ldw   r6,  %gprel(p_runtsk)(gp)				/* 管理ブロックの先頭アドレス取得 */
	ldw   r6,  TCB_p_tinib(r6)					/* タスク初期化ブロック先頭アドレス取得 */
	ldw   r6,  TINIB_stk(r6)					/* タスクスタック先頭アドレス取得 */
	bleu  sp,  r6,  stack_monitoring_error		/* スタックポインタ <= スタックの先頭の場合NG  */
	/*
	 *  マジックナンバーチェック方式
	 */
	ldw   r7,  0(r6)							/* タスクスタックの先頭アドレスからマジック領域の値取得 */
	movia r6,  STACK_MAGIC_NUMBER				/* マジックナンバーの取得 */
	bne   r7,  r6,  stack_monitoring_error		/* マジックナンバーと比較 */
#endif /* CFG_USE_STACKMONITORING */
	/* ディスパッチャ本体（dispatcher）へ */

dispatcher:
	/*
	 *  PostTaskHookの呼び出し
	 */
#ifdef CFG_USE_POSTTASKHOOK
	movia r2, PostTaskHook
	beq   r2, zero, dispatcher_0
posttaskhook_call:
	movia r4, call_posttaskhook
	call  stack_change_and_call_func_1
#endif /* CFG_USE_POSTTASKHOOK */

dispatcher_0:
	/*
	 *  このルーチンは，タスクコンテキスト・OS割込み禁止状態・ディスパッチ
	 *  許可状態・（モデル上の）割込み優先度マスク全解除状態で呼び出さ
	 *  れる．実行再開番地へもこの状態のまま分岐する
	 */
#ifdef LOG_DSP_ENTER
	ldw   r4,  %gprel(p_runtsk)(gp)
	beq   r4, zero, 1f
	call  log_dsp_enter
1:
#endif /* LOG_DSP_ENTER */

	ldh   r5, %gprel(callevel_stat)(gp)
	andi  r4, r5, TSYS_DISALLINT
	beq   r4, zero, dispatcher_1

	andi  r5, r5, %lo(~TSYS_DISALLINT)
	sth	  r5, %gprel(callevel_stat)(gp)
	UNLOCK_ALL_INT    r2    /* 全割込み禁止解除状態へ */

	/*
	 *  例外（割込み/CPU例外）のネスト回数はstart_dispatchや，dispatcher_3:
	 *  から来た場合は'1'となっているため，タスクスタックに切り換え後，
	 *  '0'に初期化する
	 */
dispatcher_1:
	ldw   r5,   %gprel(p_schedtsk)(gp) /* r5 <- schedtsk              */
	stw   r5,   %gprel(p_runtsk)(gp)   /* schedtsk を runtskに        */
	beq   r5,   zero, dispatcher_3     /* schedtskがあるか            */
	ldw   sp,   TCB_sp(r5)             /* TCBからタスクスタックを復帰 */
	stw   zero, %gprel(except_nest_cnt)(gp) /* 例外ネスト回数を'0'へ */

#ifdef LOG_DSP_LEAVE
	ldw   r4,  %gprel(p_runtsk)(gp)
	call  log_dsp_leave
#endif /* LOG_DSP_LEAVE */

#ifdef CFG_USE_PRETASKHOOK
	movia r2, PreTaskHook
	beq   r2, zero, dispatcher_2
pretaskhook_call:
	movia r4, call_pretaskhook
	call  stack_change_and_call_func_1
#endif /* CFG_USE_PRETASKHOOK */

dispatcher_2:
	ldw   r5, %gprel(p_runtsk)(gp)
	ldw   r5, TCB_pc(r5)			/* TCB から実行再開番地を復帰   */
	jmp   r5

dispatcher_3:
	/*
	 *  OS割込み禁止状態の解除と，非タスクコンテキスト実行状態への
	 *  準備をする
	 *
	 *  ここで非タスクコンテキストに切り替える（sp＝非タスクコンテキス
	 *  ト用スタックポインタ，except_nest_cnt＝1)のは，OS割込み禁止解
	 *  除後に発生する割込み処理にどのスタックを使うかという問題の解決
	 *  と，割込みハンドラ内でのタスクディスパッチの防止という2つの意
	 *  味がある
	 */
	ldw   r2, %gprel(_ostkpt)(gp)	/* 非タスクコンテキスト用のスタックの読み込み */
	mov   sp, r2							/* スタックポインタの入れ替え */
	movi  r5, 1								/* except_nest_cnt を1に */
	stw   r5, %gprel(except_nest_cnt)(gp)

	/*
	 *  OS割込み禁止解除状態へ
	 *  割込みを許可し，非タスクコンテキスト実行状態とし割込みを待つ
	 *
	 *  プロセッサを割込み待ちに移行させる処理と，割込み許可とは，不可
	 *  分に行なう必要がある
	 *  これを不可分に行なわない場合，割込みを許可した直後に割込
	 *  みが入り，その中でタスクが実行可能状態になると，実行すべきタス
	 *  クがあるにもかかわらずプロセッサが割込み待ちになってしまう
	 *
	 *  割込み待ちの間は，p_runtskをNULL（＝0）に設定しなければならない
	 *  このように設定しないと，割込みハンドラからGetTaskIDを呼び出
	 *  した際の動作が仕様に合致しなくなる
	 */
	OUTER_UNLOCK_OS_INT r1, r2

	nop
	nop
	nop
	nop

	/*
	 *  OS割込み禁止状態へ
	 *  (モデル上の)割込み優先度マスクは0であるため，C1ISR以外の割込みは全て禁止する
	 *  スタックは非タスクコンテキストのスタックを使用しているため，except_nest_cntは，
	 *  '1'のままとする
	 */
	OUTER_LOCK_OS_INT r1, r2
	br    dispatcher_1

	/*
	 *  スタックオーバフロー時の処理
	 */
#ifdef CFG_USE_STACKMONITORING
	/*
	 *  スタックオーバフロー時プロテクションフックを呼び出し
	 *  スタックを更に壊さないため，割込みスタックの初期値を使用する
	 */
stack_monitoring_error_isr:
	OUTER_LOCK_OS_INT r1, r2					/* ISRから来た場合はOS割込み禁止になっていない */

stack_monitoring_error:
	ldw   r2, %gprel(except_nest_cnt)(gp)		/* _ostkptを使う場合はexcept_nest_cntをインクリメントする */
	addi  r2, r2, 1
	stw   r2, %gprel(except_nest_cnt)(gp)
	ldw   sp,  %gprel(_ostkpt)(gp)		/* スタックを更に壊さないため，割込みスタックの初期値を使用する */

	movi  r4,  E_OS_STACKFAULT					/* プロテクションフックの引数を設定 */
	call  call_protectionhk_main				/* プロテクションフックを呼び出し */
	/*
	 *  プロテクションフックからは戻ってこない
	 */
#endif /* CFG_USE_STACKMONITORING */

/*
 *  タスク開始時処理
 *
 *  dispatcherから呼び出される
 */
	.text
	.global start_r
	.balign  FUNCTION_ALIGN_SIZE
start_r:

	/*
	 *  OS割込み禁止解除前に現在優先度(TCB.curpri)を実行優先度(TINIB.exepri)に
	 *  変更(内部リソースを獲得)
	 */
	ldw   r4, %gprel(p_runtsk)(gp)		/* r4 <- runtsk */
	ldw   r6, TCB_p_tinib(r4)
	ldb   r5, TINIB_exepri(r6)			/* TINIB.exepri -> TCB.curpri */
	stb   r5, TCB_curpri(r4)

	/*
	 *  OS割込み禁止解除状態へ
	 *  (モデル上の)割込み優先度マスクは0であるため，有効な割込みは全て許可する
	 */
	OUTER_UNLOCK_OS_INT r2, r3

	/*
	 *  タスクが不正終了した場合は保護処理を行うよう
	 *  戻りアドレスにexit_taskを設定
	 */
	movia ra, exit_task					/* ra(戻り番地） <- exit_task */

	ldw   r3, TCB_p_tinib(r4)			/* r3  <- p_runtsk->p_tinib */
	ldw   r2, TINIB_task(r3)			/* r2 <- タスクの実行番地 */
	jmp   r2							/* タスクの実行開始 */

	.global stack_change_and_call_func_1
	.global stack_change_and_call_func_2
	.balign  FUNCTION_ALIGN_SIZE
stack_change_and_call_func_1:
stack_change_and_call_func_2:

	PUSH  ra

	ldw   r2, %gprel(except_nest_cnt)(gp)
	addi  r3, r2, 1
	stw   r3, %gprel(except_nest_cnt)(gp)
	bne   zero, r2, 1f

	ldw   r2, %gprel(_ostkpt)(gp)
	addi  r2, r2, -4
	stw   sp, 0(r2)     /* スタックポインタの保存     */
	mov   sp, r2        /* スタックポインタの入れ替え */
1:

	mov   r2, r4
	mov   r4, r5
	mov   r5, r6
	callr r2

	ldw   r2, %gprel(except_nest_cnt)(gp)
	subi  r2, r2, 1
	stw   r2, %gprel(except_nest_cnt)(gp)
	bne   zero, r2, 1f

	ldw   sp, 0(sp)     /* スタックポインタの復帰     */
1:
	POP   ra
	ret
