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
 *  $Id: avalon_timer.h 1801 2015-03-27 06:34:43Z t_ishikawa $
 */

/*
 *		タイマドライバ（Avalon Timer用）
 */

#ifndef TOPPERS_AVALON_TIMER_H
#define TOPPERS_AVALON_TIMER_H

#include "prc_sil.h"

/*
 *  Avalon Timer ハードウェア定義
 */

/*
 *  レジスタ
 */
#define AVALON_TIM_STATUS	(0x00U)
#define AVALON_TIM_CONTROL	(0x04U)
#define AVALON_TIM_PERIODL	(0x08U)
#define AVALON_TIM_PERIODH	(0x0CU)
#define AVALON_TIM_SNAPL	(0x10U)
#define AVALON_TIM_SNAPH	(0x14U)

/*
 *  ビット定義
 */
#define AVALON_TIM_STATUS_RUN	UINT_C(0x02)
#define AVALON_TIM_STATUS_TO	UINT_C(0x01)

#define AVALON_TIM_CONTROL_STOP		UINT_C(0x08)
#define AVALON_TIM_CONTROL_START	UINT_C(0x04)
#define AVALON_TIM_CONTROL_CONT		UINT_C(0x02)
#define AVALON_TIM_CONTROL_ITO		UINT_C(0x01)


#ifndef TOPPERS_MACRO_ONLY

/*
 *  タイマ値の内部表現とマイクロ秒単位との変換
 *
 */
#define TO_USEC(clock)	((((SystemTimeUsType) (clock)) * 1000U) / TIMER_CLOCK)

/*
 *  タイマ値の内部表現と100ナノ秒単位との変換
 */
#define TO_100NSEC(clock)	((((SystemTimeUsType) (clock)) * 10000U) / TIMER_CLOCK)

/*
 *  マイクロ秒単位での時刻を取得
 */
extern SystemTimeUsType get_tim_utime(void);

/*
 *  100ナノ秒単位での時刻を取得
 */
extern SystemTime100NsType get_tim_100ntime(void);

/*
 *  タイマの起動処理
 *
 *  タイマを初期化し，周期的なタイマ割込み要求を発生させる
 */
extern void target_timer_initialize(void);

/*
 *  タイマの停止処理
 *
 *  タイマの動作を停止させる
 */
extern void target_timer_terminate(void);

/*
 *  タイマの現在値の読出し
 */
LOCAL_INLINE TickType
target_timer_get_current(void)
{
	TickType count;

	/* スナップレジスタに書き込むと値をホールドする */
	sil_wrw_iop((void *) (SYS_CLK_TIMER_BASE + AVALON_TIM_SNAPL), 0x00U);

	/* カウント値を読み込む */
	count = sil_rew_iop((void *) (SYS_CLK_TIMER_BASE + AVALON_TIM_SNAPL));
	count |= sil_rew_iop((void *) (SYS_CLK_TIMER_BASE + AVALON_TIM_SNAPH)) << 16;

	return(TIMER_CLOCK - (count + 1));
}

/*
 *  タイマ割込み要求のチェック
 */
LOCAL_INLINE boolean
target_timer_probe_int(void)
{
	return((sil_rew_iop((void *) (SYS_CLK_TIMER_BASE + AVALON_TIM_STATUS)) & AVALON_TIM_STATUS_TO) != 0U);
}

#endif /* TOPPERS_MACRO_ONLY */
#endif /* TOPPERS_AVALON_TIMER_H */
