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
 *  $Id: avalon_timer.c 1801 2015-03-27 06:34:43Z t_ishikawa $
 */

/*
 *		タイマドライバ（Avalon Timer）
 */

#include "kernel_impl.h"
#include "target_timer.h"
#include "avalon_timer.h"
#include "Os_Lcfg.h"

/*
 *  現在のシステム時刻（単位: ミリ秒）
 *
 *  厳密には，前のタイムティックのシステム時刻
 */
static SystemTimeMsType current_time;

/*
 *  マイクロ秒単位での時刻を取得
 */
SystemTimeUsType
get_tim_utime(void)
{
	SystemTimeUsType	utime;
	SystemTimeMsType	mtime;
	TickType			clock1, clock2;
	boolean				ireq;
	SIL_PRE_LOC;

	SIL_LOC_INT();
	mtime = current_time;
	clock1 = target_timer_get_current();
	ireq = target_timer_probe_int();
	clock2 = target_timer_get_current();
	SIL_UNL_INT();
	utime = ((SystemTimeUsType) mtime) * 1000U;

	if ((ireq != FALSE) && (clock2 >= clock1)) {
		utime += 1000U;
	}
	utime += TO_USEC(clock1);
	return(utime);
}

/*
 *  100ナノ秒単位での時刻を取得
 */
SystemTime100NsType
get_tim_100ntime(void)
{
	SystemTime100NsType	ntime;
	SystemTimeMsType	mtime;
	TickType			clock1, clock2;
	boolean				ireq;
	SIL_PRE_LOC;

	SIL_LOC_INT();
	mtime = current_time;
	clock1 = target_timer_get_current();
	ireq = target_timer_probe_int();
	clock2 = target_timer_get_current();
	SIL_UNL_INT();
	ntime = ((SystemTime100NsType) mtime) * 10000U;

	if ((ireq != FALSE) && (clock2 >= clock1)) {
		ntime += 10000U;
	}
	ntime += TO_100NSEC(clock1);
	return(ntime);
}

/*
 *  タイマの起動処理
 */
void
target_timer_initialize(void)
{
	current_time = 0U;

	/* タイマーストップ */
	sil_wrw_iop((void *) (SYS_CLK_TIMER_BASE + AVALON_TIM_CONTROL), AVALON_TIM_CONTROL_STOP);
	/* タイムアウトステータスクリア */
	sil_wrw_iop((void *) (SYS_CLK_TIMER_BASE + AVALON_TIM_STATUS), 0x00U);

	sil_wrw_iop((void *) (SYS_CLK_TIMER_BASE + AVALON_TIM_PERIODL), ((TIMER_CLOCK - 1) & 0xffffU));         /* カウンターセット 下位16bit */
	sil_wrw_iop((void *) (SYS_CLK_TIMER_BASE + AVALON_TIM_PERIODH), ((uint32) (TIMER_CLOCK - 1) >> 16));    /* カウンターセット 上位16bit */

	/*
	 * タイマースタート，オートリロード，割込み許可
	 */
	sil_wrw_iop((void *) (SYS_CLK_TIMER_BASE + AVALON_TIM_CONTROL), AVALON_TIM_CONTROL_START
				| AVALON_TIM_CONTROL_CONT | AVALON_TIM_CONTROL_ITO);
}

/*
 *  タイマの停止処理
 */
void
target_timer_terminate(void)
{
	/* タイマ停止 */
	sil_wrw_iop((void *) (SYS_CLK_TIMER_BASE + AVALON_TIM_CONTROL), AVALON_TIM_CONTROL_STOP);

	/* 割込み要求のクリア */
	sil_wrw_iop((void *) (SYS_CLK_TIMER_BASE + AVALON_TIM_STATUS), 0x00U);
}

/*
 *  target_timer.arxmlを使用しない場合の対処
 */
#ifndef SysTimerCnt
#define SysTimerCnt		UINT_C(0)
#endif /* SysTimerCnt */

/*
 *  タイマ割込みハンドラ
 */
ISR(target_timer_hdr)
{
	StatusType ercd;

	/* TOビットのクリア */
	sil_wrw_iop((void *) (SYS_CLK_TIMER_BASE + AVALON_TIM_STATUS), 0x00U);

	/* current_timeを更新する */
	current_time++;

	/*
	 *  カウンタ加算通知処理実行
	 */
	ercd = IncrementCounter(SysTimerCnt);
	/* エラーリターンの場合はシャットダウン */
	if (ercd != E_OK) {
		ShutdownOS(ercd);
	}
}
