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
 *  $Id: target_hw_counter.c 1801 2015-03-27 06:34:43Z t_ishikawa $
 */

/*
 *		以下ハードウェアカウンタプログラムのターゲット依存定義（NIOS2_DEV用）
 *
 *  使用するタイマ：
 *    差分タイマ：目的の時間を設定する時の現在時間(現在値タイマ)
 *              と次の満了時間との相対時間をカウントすることで
 *              目的の絶対時間に満了したこととする
 *              count mode:count down once
 *
 *    現在値タイマ：カウンタ周期分のベースタイマを実現
 *              (絶対時間をカウント)
 *              count mode:continuous count down
 *
 *    また上記のタイマは32bitのダウンカウンタタイマである
 *
 *  制御方針：
 *
 *   現在値タイマはユーザ定義カウンタ最大値2倍+1までカウントし，
 *   周期タイマとして連続カウントダウンして，常に現在時刻を
 *   取得する．割込み発生する必要がないため，割込みなしモード
 *
 *   差分タイマは，満了処理を行うため，割込みありモードで動く
 *   アラームなどの満了点とタイマー1で示した現在時刻の差を
 *   現在値タイマに設定する
 *
 *  ポイント：
 *   満了処理は，現在時刻を影響しないため，現在値タイマを設けている
 *
 */
#if defined(TOPPERS_NIOS2_DEV_2S180) || defined(TOPPERS_NIOS2_DEV_DE2_115)

#include "Os.h"
#include "prc_sil.h"
#include "target_hw_counter.h"

/* 内部関数のプロトタイプ宣言 */
static TickType get_curr_time(uint32 irq_no, TickType maxval);
static void init_hwcounter(uint32 irq_no, TickType maxval, TimeType nspertick, TickRefType cycle);
static void start_hwcounter(uint32 irq_no);
static void stop_hwcounter(uint32 irq_no);
static void set_hwcounter(uint32 irq_no, TickType exprtick, TickType maxval);
static TickType get_hwcounter(uint32 irq_no, TickType maxval);
static void cancel_hwcounter(uint32 irq_no);
static void trigger_hwcounter(uint32 irq_no);
static void int_clear_hwcounter(uint32 irq_no);
static void int_cancel_hwcounter(uint32 irq_no);
static void increment_hwcounter(uint32 irq_no);

/*
 *  ハードウェアカウンタ現在ティック値取得
 *  ダウンカウンタタイマのため，変換が必要
 */
static TickType
get_curr_time(uint32 irq_no, TickType maxval)
{
	TickType curr_time = 0U;

	/* スナップレジスタに書き込むと値をホールドする */
	sil_wrw_iop((void *) TIMER_SNAPL(irq_no + 1U), 0x00U);

	/* タイマーからカウント値を読み込む */
	curr_time = sil_rew_iop((void *) TIMER_SNAPL(irq_no + 1U));
	curr_time |= sil_rew_iop((void *) TIMER_SNAPH(irq_no + 1U)) << 16U;

	/* ダウンカウンタの為，現在チック値に変換 */
	curr_time = maxval - curr_time;

	return(curr_time);
}

/*
 *  ハードウェアカウンタの初期化
 */
static void
init_hwcounter(uint32 irq_no, TickType maxval, TimeType nspertick, TickRefType cycle)
{
	*cycle = maxval;

	/* 差分タイマ停止 */
	sil_wrw_iop((void *) TIMER_CONTROL(irq_no), TIMER_CONTROL_STOP);
	/* 差分タイマタイムアウトステータスクリア */
	sil_wrw_iop((void *) TIMER_STATUS(irq_no), 0x00U);

	/* 現在値タイマ停止 */
	sil_wrw_iop((void *) TIMER_CONTROL(irq_no + 1U), TIMER_CONTROL_STOP);
	/* 現在値タイマタイムアウトステータスクリア */
	sil_wrw_iop((void *) TIMER_STATUS(irq_no + 1U), 0x00U);

	/* 現在値タイマカウンターセット 上位16bit */
	sil_wrw_iop((void *) TIMER_PERIODH(irq_no + 1U), (maxval >> 16U));
	/* 現在値タイマカウンターセット 下位16bit */
	sil_wrw_iop((void *) TIMER_PERIODL(irq_no + 1U), (maxval & 0xffffU));
}

/*
 *  ハードウェアカウンタの開始
 */
static void
start_hwcounter(uint32 irq_no)
{
	/*
	 *  現在値タイマ開始(continuous count down mode)
	 *  割込み必要がないため，割込みなしモード
	 */
	sil_wrw_iop((void *) TIMER_CONTROL(irq_no + 1U), TIMER_CONTROL_CONT | TIMER_CONTROL_START);
}

/*
 *  ハードウェアカウンタの停止
 */
static void
stop_hwcounter(uint32 irq_no)
{
	/* 差分タイマ停止 */
	sil_wrw_iop((void *) TIMER_CONTROL(irq_no), TIMER_CONTROL_STOP);

	/* 差分タイマの割込み要求のクリア */
	sil_wrw_iop((void *) TIMER_STATUS(irq_no), 0x00U);

	/* 現在値タイマ停止 */
	sil_wrw_iop((void *) TIMER_CONTROL(irq_no + 1U), TIMER_CONTROL_STOP);

	/* 現在値タイマの割込み要求のクリア */
	sil_wrw_iop((void *) TIMER_STATUS(irq_no + 1U), 0x00U);
}

/*
 *  ハードウェアカウンタへの満了時間の設定
 */
static void
set_hwcounter(uint32 irq_no, TickType exprtick, TickType maxval)
{
	TickType	curr_time;
	TickType	value;

	/* 差分タイマの割込み要求のクリア */
	sil_wrw_iop((void *) TIMER_STATUS(irq_no), 0x00U);

	/* 現在時刻の取得	*/
	curr_time = get_curr_time(irq_no, maxval);

	/* タイマに設定する値を算出	*/
	if (exprtick >= curr_time) {
		value = exprtick - curr_time;
	}
	else {
		value = maxval - curr_time + exprtick + 1U;
	}

	/*
	 *  タイマに0x00を設定し，割込み発生後，再度0を設定した場合，2回目の
	 *  0x00設定後の割込みは発生しないので，0x00設定値を0x01に直して設定
	 *  タイマにセットする値は，期待する周期のカウント値から-1する必要がある
	 */
	if (value <= 0x01U) {
		value = 0x01U;
	}
	else {
		value -= 1U;
	}

	/*
	 *  差分タイマカウンターセット 上位16bit
	 *  注意：下位bitより先に設定しないと，割込み2回発生する可能性がある
	 */
	sil_wrw_iop((void *) TIMER_PERIODH(irq_no), (value >> 16U));
	/* 差分タイマカウンターセット 下位16bit */
	sil_wrw_iop((void *) TIMER_PERIODL(irq_no), (value & 0xffffU));

	/*
	 *  差分タイマ開始(count down once mode)
	 *  割込み必要のため，割込みモードあり
	 */
	sil_wrw_iop((void *) TIMER_CONTROL(irq_no), TIMER_CONTROL_ITO | TIMER_CONTROL_START);
}

/*
 *  ハードウェアカウンタの現在時間の取得
 */
static TickType
get_hwcounter(uint32 irq_no, TickType maxval)
{
	return(get_curr_time(irq_no, maxval));
}

/*
 *  ハードウェアカウンタの設定された満了時間の取消
 */
static void
cancel_hwcounter(uint32 irq_no)
{
	/* 差分タイマ停止 */
	sil_wrw_iop((void *) TIMER_CONTROL(irq_no), TIMER_CONTROL_STOP);
}

/*
 *  ハードウェアカウンタの強制割込み要求
 */
static void
trigger_hwcounter(uint32 irq_no)
{
	/* 差分タイマ停止 */
	sil_wrw_iop((void *) TIMER_CONTROL(irq_no), TIMER_CONTROL_STOP);

	/* 差分タイマの割込み要求のクリア */
	sil_wrw_iop((void *) TIMER_STATUS(irq_no), 0x00U);

	/* 差分タイマカウンターに0x01をセットすることで，すぐ満了 */
	sil_wrw_iop((void *) TIMER_PERIODH(irq_no), 0x00U);
	sil_wrw_iop((void *) TIMER_PERIODL(irq_no), 0x01U);

	/* 差分タイマ開始 */
	sil_wrw_iop((void *) TIMER_CONTROL(irq_no), TIMER_CONTROL_ITO | TIMER_CONTROL_START);
}

/*
 *  割込み要求のクリア
 */
static void
int_clear_hwcounter(uint32 irq_no)
{
	/* 差分タイマの割込み要求のクリア */
	sil_wrw_iop((void *) TIMER_STATUS(irq_no), 0x00U);
}

/*
 *  割込み要求のキャンセル
 *  ペンディングされている割込み要求をキャンセル
 */
static void
int_cancel_hwcounter(uint32 irq_no)
{
	/* 差分タイマの割込み要求のクリア */
	sil_wrw_iop((void *) TIMER_STATUS(irq_no), 0x00U);
}

/*
 *  ハードウェアカウンタのインクリメント
 */
static void
increment_hwcounter(uint32 irq_no)
{
	/* Nios2ターゲットは未サポート */
	return;
}

/*
 *  MAIN_HW_COUNTERの定義
 */
/* カウンタの最大値の2倍+1 */
static TickType MAIN_HW_COUNTER_maxval;

/*
 *  ハードウェアカウンタの初期化
 */
void
init_hwcounter_MAIN_HW_COUNTER(TickType maxval, TimeType nspertick)
{
	init_hwcounter(TIMER_0_IRQ, maxval, nspertick, &MAIN_HW_COUNTER_maxval);
}

/*
 *  ハードウェアカウンタの開始
 */
void
start_hwcounter_MAIN_HW_COUNTER(void)
{
	start_hwcounter(TIMER_0_IRQ);
}

/*
 *  ハードウェアカウンタの停止
 */
void
stop_hwcounter_MAIN_HW_COUNTER(void)
{
	stop_hwcounter(TIMER_0_IRQ);
}

/*
 *  ハードウェアカウンタへの満了時間の設定
 */
void
set_hwcounter_MAIN_HW_COUNTER(TickType exprtick)
{
	set_hwcounter(TIMER_0_IRQ, exprtick, MAIN_HW_COUNTER_maxval);
}

/*
 *  ハードウェアカウンタの現在時間の取得
 */
TickType
get_hwcounter_MAIN_HW_COUNTER(void)
{
	return(get_hwcounter(TIMER_0_IRQ, MAIN_HW_COUNTER_maxval));
}

/*
 *  ハードウェアカウンタの設定された満了時間の取消
 */
void
cancel_hwcounter_MAIN_HW_COUNTER(void)
{
	cancel_hwcounter(TIMER_0_IRQ);
}

/*
 *  ハードウェアカウンタの強制割込み要求
 */
void
trigger_hwcounter_MAIN_HW_COUNTER(void)
{
	trigger_hwcounter(TIMER_0_IRQ);
}

/*
 *  ハードウェアカウンタの設定された満了時間の取消
 */
void
int_clear_hwcounter_MAIN_HW_COUNTER(void)
{
	int_clear_hwcounter(TIMER_0_IRQ);
}

/*
 *  ハードウェアカウンタの設定された満了時間の取消
 */
void
int_cancel_hwcounter_MAIN_HW_COUNTER(void)
{
	int_cancel_hwcounter(TIMER_0_IRQ);
}

/*
 *  ハードウェアカウンタのインクリメント
 */
void
increment_hwcounter_MAIN_HW_COUNTER(void)
{
	increment_hwcounter(TIMER_0_IRQ);
}

/*
 *  SUB_HW_COUNTER1Bの定義
 */
/* カウンタの最大値の2倍+1 */
static TickType SUB_HW_COUNTER1_maxval;

/*
 *  ハードウェアカウンタの初期化
 */
void
init_hwcounter_SUB_HW_COUNTER1(TickType maxval, TimeType nspertick)
{
	init_hwcounter(TIMER_2_IRQ, maxval, nspertick, &SUB_HW_COUNTER1_maxval);
}

/*
 *  ハードウェアカウンタの開始
 */
void
start_hwcounter_SUB_HW_COUNTER1(void)
{
	start_hwcounter(TIMER_2_IRQ);
}

/*
 *  ハードウェアカウンタの停止
 */
void
stop_hwcounter_SUB_HW_COUNTER1(void)
{
	stop_hwcounter(TIMER_2_IRQ);
}

/*
 *  ハードウェアカウンタへの満了時間の設定
 */
void
set_hwcounter_SUB_HW_COUNTER1(TickType exprtick)
{
	set_hwcounter(TIMER_2_IRQ, exprtick, SUB_HW_COUNTER1_maxval);
}

/*
 *  ハードウェアカウンタの現在時間の取得
 */
TickType
get_hwcounter_SUB_HW_COUNTER1(void)
{
	return(get_hwcounter(TIMER_2_IRQ, SUB_HW_COUNTER1_maxval));
}

/*
 *  ハードウェアカウンタの設定された満了時間の取消
 */
void
cancel_hwcounter_SUB_HW_COUNTER1(void)
{
	cancel_hwcounter(TIMER_2_IRQ);
}

/*
 *  ハードウェアカウンタの強制割込み要求
 */
void
trigger_hwcounter_SUB_HW_COUNTER1(void)
{
	trigger_hwcounter(TIMER_2_IRQ);
}

/*
 *  ハードウェアカウンタの設定された満了時間の取消
 */
void
int_clear_hwcounter_SUB_HW_COUNTER1(void)
{
	int_clear_hwcounter(TIMER_2_IRQ);
}

/*
 *  ハードウェアカウンタの設定された満了時間の取消
 */
void
int_cancel_hwcounter_SUB_HW_COUNTER1(void)
{
	int_cancel_hwcounter(TIMER_2_IRQ);
}

/*
 *  ハードウェアカウンタのインクリメント
 */
void
increment_hwcounter_SUB_HW_COUNTER1(void)
{
	increment_hwcounter(TIMER_2_IRQ);
}

/*
 *  SUB_HW_COUNTER2の定義
 */
/* カウンタの最大値の2倍+1 */
static TickType SUB_HW_COUNTER2_maxval;

/*
 *  ハードウェアカウンタの初期化
 */
void
init_hwcounter_SUB_HW_COUNTER2(TickType maxval, TimeType nspertick)
{
	init_hwcounter(TIMER_4_IRQ, maxval, nspertick, &SUB_HW_COUNTER2_maxval);
}

/*
 *  ハードウェアカウンタの開始
 */
void
start_hwcounter_SUB_HW_COUNTER2(void)
{
	start_hwcounter(TIMER_4_IRQ);
}

/*
 *  ハードウェアカウンタの停止
 */
void
stop_hwcounter_SUB_HW_COUNTER2(void)
{
	stop_hwcounter(TIMER_4_IRQ);
}

/*
 *  ハードウェアカウンタへの満了時間の設定
 */
void
set_hwcounter_SUB_HW_COUNTER2(TickType exprtick)
{
	set_hwcounter(TIMER_4_IRQ, exprtick, SUB_HW_COUNTER2_maxval);
}

/*
 *  ハードウェアカウンタの現在時間の取得
 */
TickType
get_hwcounter_SUB_HW_COUNTER2(void)
{
	return(get_hwcounter(TIMER_4_IRQ, SUB_HW_COUNTER2_maxval));
}

/*
 *  ハードウェアカウンタの設定された満了時間の取消
 */
void
cancel_hwcounter_SUB_HW_COUNTER2(void)
{
	cancel_hwcounter(TIMER_4_IRQ);
}

/*
 *  ハードウェアカウンタの強制割込み要求
 */
void
trigger_hwcounter_SUB_HW_COUNTER2(void)
{
	trigger_hwcounter(TIMER_4_IRQ);
}

/*
 *  ハードウェアカウンタの設定された満了時間の取消
 */
void
int_clear_hwcounter_SUB_HW_COUNTER2(void)
{
	int_clear_hwcounter(TIMER_4_IRQ);
}

/*
 *  ハードウェアカウンタの設定された満了時間の取消
 */
void
int_cancel_hwcounter_SUB_HW_COUNTER2(void)
{
	int_cancel_hwcounter(TIMER_4_IRQ);
}

/*
 *  ハードウェアカウンタのインクリメント
 */
void
increment_hwcounter_SUB_HW_COUNTER2(void)
{
	increment_hwcounter(TIMER_4_IRQ);
}

#endif /* defined(TOPPERS_NIOS2_DEV_2S180) || defined(TOPPERS_NIOS2_DEV_DE2_115) */
