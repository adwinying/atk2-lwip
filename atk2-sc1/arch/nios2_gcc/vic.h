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
 *  $Id: vic.h 1801 2015-03-27 06:34:43Z t_ishikawa $
 */

/*
 *		VICドライバ
 */

#ifndef TOPPERS_VIC_H
#define TOPPERS_VIC_H

#include "prc_sil.h"

/*
 *  ベクタ割り込みコントローラ(VIC)
 */
#define VIC_INT_CONFIG(n)		((uint32) (n) << 2)
#define VIC_INT_ENABLE			UINT_C(0x80)
#define VIC_INT_ENABLE_SET		UINT_C(0x84)
#define VIC_INT_ENABLE_CLR		UINT_C(0x88)
#define VIC_INT_PENDING			UINT_C(0x8c)
#define VIC_INT_RAW_STATUS		UINT_C(0x90)
#define VIC_SW_INTERRUPT		UINT_C(0x94)
#define VIC_SW_INTERRUPT_SET	UINT_C(0x98)
#define VIC_SW_INTERRUPT_CLR	UINT_C(0x9c)
#define VIC_VIC_CONFIG			UINT_C(0xa0)
#define VIC_VIC_STATUS			UINT_C(0xa4)
#define VIC_VEC_TBL_BASE		UINT_C(0xa8)
#define VIC_VEC_TBL_ADDR		UINT_C(0xac)

#ifndef TOPPERS_MACRO_ONLY

/*
 *  ベクタテーブル(Os_Lcfg.c)
 */
extern void kernel_vectors(void);

/*
 *  VICの起動処理
 *
 *  VICを初期化し，周期的なタイマ割込み要求を発生させる
 */
extern void vic_initialize(void);

/*
 *  各割込みの設定
 */
LOCAL_INLINE void
vic_set_int_config(uint8 intno, uint32 config)
{
	sil_wrw_iop((void *) (VIC_BASE + VIC_INT_CONFIG(intno)), config);
}

/*
 *  各割込みの設定を取得
 */
LOCAL_INLINE uint32
vic_get_int_config(uint8 intno)
{
	return(sil_rew_iop((void *) (VIC_BASE + VIC_INT_CONFIG(intno))));
}

/*
 *  ベクタテーブルのベースアドレスの設定
 */
LOCAL_INLINE void
vic_set_vec_tbl_base(uint32 vec_addr)
{
	sil_wrw_iop((void *) (VIC_BASE + VIC_VEC_TBL_BASE), vec_addr);
}

/*
 *  指定された割込み要求を許可する
 */
LOCAL_INLINE void
vic_set_int_enable(uint32 enable_set)
{
	sil_wrw_iop((void *) (VIC_BASE + VIC_INT_ENABLE_SET), enable_set);
}

/*
 *  指定された割込み要求を禁止する
 */
LOCAL_INLINE void
vic_clr_int_enable(uint32 enable_clr)
{
	sil_wrw_iop((void *) (VIC_BASE + VIC_INT_ENABLE_CLR), enable_clr);
}

#endif /* TOPPERS_MACRO_ONLY */
#endif /* TOPPERS_VIC_H */
