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
 *  $Id: prc_config.c 1801 2015-03-27 06:34:43Z t_ishikawa $
 */

/*
 *		プロセッサ依存モジュール（Nios2用）
 */
#include "kernel_impl.h"
/*
 *  例外（割込み/CPU例外）のネスト回数のカウント
 *  コンテキスト参照のために使用
 */
uint32			except_nest_cnt;

#ifdef CFG_USE_PROTECTIONHOOK
uint32			nios2_cpu_exp_no;
uint32			nios2_cpu_exp_pc;
uint32			nios2_cpu_exp_bad_addr;
uint32			nios2_cpu_exp_sp;
#endif /* CFG_USE_PROTECTIONHOOK */

/*
 *  x_nested_lock_os_int()のネスト回数
 */
volatile uint8	nested_lock_os_int_cnt;

/*
 *  OS割込み禁止状態の時に割込み優先度マスクを保存する変数
 */
volatile uint32	saved_status_il;

void
prc_hardware_initialize(void)
{
	vic_initialize();
}

/*
 *  プロセッサ依存の初期化
 */
void
prc_initialize(void)
{
	/*
	 *  カーネル起動時は非タスクコンテキストとして動作させるため1に
	 */
	except_nest_cnt = 1U;
}

/*
 *  プロセッサ依存の終了処理
 */
void
prc_terminate(void)
{
}

/*
 *  割込み要求ラインの属性の設定
 */
void
x_config_int(InterruptNumberType intno, AttributeType intatr, PriorityType intpri)
{
	ASSERT(VALID_INTNO(intno));

	/* 割込み優先度設定，設定しない場合最低優先度0となる */
	vic_set_int_config((uint8) intno, INT_IPM(intpri));

	/* SC1では起動時は割込み許可 */
	vic_set_int_enable(INTNO_BITPAT(intno));
}

#ifndef OMIT_DEFAULT_INT_HANDLER

/*
 *  未定義の割込みが入った場合の処理
 */
void
default_int_handler(void)
{
	target_fput_str("Unregistered Interrupt occurs.");
	ASSERT(0);
}

#endif /* OMIT_DEFAULT_INT_HANDLER */
