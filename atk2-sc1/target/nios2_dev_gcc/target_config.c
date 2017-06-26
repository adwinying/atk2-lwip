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
 *  $Id: target_config.c 1801 2015-03-27 06:34:43Z t_ishikawa $
 */

/*
 *		ターゲット依存モジュール（NIOS2_DEV用）
 */

#include "kernel_impl.h"
#include "nios2_gcc/prc_sil.h"
#include "target_sysmod.h"
#ifdef ENABLE_RETURN_MAIN
#include "interrupt.h"
#endif /* ENABLE_RETURN_MAIN */
#ifdef TOPPERS_ENABLE_TRACE
#include "logtrace/trace_config.h"
#endif /* TOPPERS_ENABLE_TRACE */

#ifdef USE_UART
#include "nios2_gcc/uart.h"
#else /* USE_UART */
#include "nios2_gcc/jtag_uart.h"
#endif /* USE_UART */

/* 内部関数のプロトタイプ宣言 */
static void hw_version_check(void);

/*
 *  文字列の出力
 */
void
target_fput_str(const char8 *c)
{
	while (*c != '\0') {
		nios2_dev_putc(*c);
		c++;
	}
	nios2_dev_putc('\n');
}

/*
 *  バージョンチェック
 */
static void
hw_version_check(void)
{
	/* コア数を確認 */
	if (sil_rew_iop((void *) (SYSVER_NUM_CORE)) != TNUM_HWCORE) {
		target_fput_str("Number of core is mismatch!!");
		while (1) {
		}
	}

	if (sil_rew_iop((void *) (SYSVER_MAJOR_VAR)) != MAJOR_VAR) {
		target_fput_str("Hardware Major version is mismatch!!");
		while (1) {
		}
	}
}
void
target_hardware_initialize(void)
{
	/*
	 *  ハードウェアバージョンの確認
	 */
	hw_version_check();

	prc_hardware_initialize();
}

/*
 *  ターゲット依存の初期化
 */
void
target_initialize(void)
{
	/*
	 *  Nios2依存の初期化
	 */
	prc_initialize();

#ifdef TOPPERS_ENABLE_TRACE
	/*
	 *  トレースログ機能の初期化
	 */
	trace_initialize((uintptr) (TRACE_AUTOSTOP));
#endif /* TOPPERS_ENABLE_TRACE */
}

/*
 *  ターゲット依存の終了処理
 */
void
target_exit(void)
{
#ifdef TOPPERS_ENABLE_TRACE
	/*
	 *  トレースログのダンプ
	 */
	trace_dump(&target_fput_log);
#endif /* TOPPERS_ENABLE_TRACE */

#ifndef ENABLE_RETURN_MAIN
	/*
	 *  シャットダウン処理の出力
	 */
	target_fput_str("Kernel Exit...");
#else
	target_fput_str("Kernel Shutdown...");
#endif /* ENABLE_RETURN_MAIN */

	/*
	 *  Nios2依存の終了処理
	 */
	prc_terminate();

#ifdef ENABLE_RETURN_MAIN
	kerflg = FALSE;
	except_nest_cnt = 0U;
	nested_lock_os_int_cnt = 0U;
	sus_all_cnt = 0U;
	sus_all_cnt_ctx = 0U;
	sus_os_cnt = 0U;
	sus_os_cnt_ctx = 0U;

	Asm("movia r2, _ostkpt");
	Asm("ldw   sp, 0(r2)");
	Asm("call  main");
#endif /* ENABLE_RETURN_MAIN */

	while (1) {
	}
}

/*
 *  ターゲット依存の文字出力
 */
void
target_fput_log(char8 c)
{
	nios2_dev_putc(c);
}
