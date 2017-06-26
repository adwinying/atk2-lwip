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
 *  �嵭����Ԥϡ��ʲ���(1)��(4)�ξ������������˸¤ꡤ�ܥ��եȥ���
 *  �����ܥ��եȥ���������Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ������
 *  �ѡ������ۡʰʲ������ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
 *  (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭������
 *      ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ���
 *      ����������˴ޤޤ�Ƥ��뤳�ȡ�
 *  (2) �ܥ��եȥ������򡤥饤�֥������ʤɡ�¾�Υ��եȥ�������ȯ�˻�
 *      �ѤǤ�����Ǻ����ۤ�����ˤϡ������ۤ�ȼ���ɥ�����ȡ�����
 *      �ԥޥ˥奢��ʤɡˤˡ��嵭�����ɽ�����������Ѿ�浪��Ӳ���
 *      ��̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *  (3) �ܥ��եȥ������򡤵�����Ȥ߹���ʤɡ�¾�Υ��եȥ�������ȯ�˻�
 *      �ѤǤ��ʤ����Ǻ����ۤ�����ˤϡ����Τ����줫�ξ�����������
 *      �ȡ�
 *    (a) �����ۤ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭����
 *        �ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *    (b) �����ۤη��֤��̤�������ˡ�ˤ�äơ�TOPPERS�ץ������Ȥ�
 *        ��𤹤뤳�ȡ�
 *  (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
 *      ������⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ����դ��뤳�ȡ�
 *      �ޤ����ܥ��եȥ������Υ桼���ޤ��ϥ���ɥ桼������Τ����ʤ���
 *      ͳ�˴�Ť����ᤫ��⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ�
 *      ���դ��뤳�ȡ�
 *
 *  �ܥ��եȥ������ϡ�AUTOSAR��AUTomotive Open System ARchitecture�˻�
 *  �ͤ˴�Ť��Ƥ��롥�嵭�ε����ϡ�AUTOSAR����Ū�⻺������������Τ�
 *  �Ϥʤ���AUTOSAR�ϡ�AUTOSAR���ͤ˴�Ť������եȥ�����������Ū����
 *  �Ѥ���Ԥ��Ф��ơ�AUTOSAR�ѡ��ȥʡ��ˤʤ뤳�Ȥ���Ƥ��롥
 *
 *  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ�
 *  ���TOPPERS�ץ������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����λ�����Ū
 *  ���Ф���Ŭ������ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ���
 *  �������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤��
 *  ����Ǥ�����ʤ���
 *
 *  $Id: vic.h 1801 2015-03-27 06:34:43Z t_ishikawa $
 */

/*
 *		VIC�ɥ饤��
 */

#ifndef TOPPERS_VIC_H
#define TOPPERS_VIC_H

#include "prc_sil.h"

/*
 *  �٥��������ߥ���ȥ���(VIC)
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
 *  �٥����ơ��֥�(Os_Lcfg.c)
 */
extern void kernel_vectors(void);

/*
 *  VIC�ε�ư����
 *
 *  VIC��������������Ū�ʥ����޳�����׵��ȯ��������
 */
extern void vic_initialize(void);

/*
 *  �Ƴ���ߤ�����
 */
LOCAL_INLINE void
vic_set_int_config(uint8 intno, uint32 config)
{
	sil_wrw_iop((void *) (VIC_BASE + VIC_INT_CONFIG(intno)), config);
}

/*
 *  �Ƴ���ߤ���������
 */
LOCAL_INLINE uint32
vic_get_int_config(uint8 intno)
{
	return(sil_rew_iop((void *) (VIC_BASE + VIC_INT_CONFIG(intno))));
}

/*
 *  �٥����ơ��֥�Υ١������ɥ쥹������
 */
LOCAL_INLINE void
vic_set_vec_tbl_base(uint32 vec_addr)
{
	sil_wrw_iop((void *) (VIC_BASE + VIC_VEC_TBL_BASE), vec_addr);
}

/*
 *  ���ꤵ�줿������׵����Ĥ���
 */
LOCAL_INLINE void
vic_set_int_enable(uint32 enable_set)
{
	sil_wrw_iop((void *) (VIC_BASE + VIC_INT_ENABLE_SET), enable_set);
}

/*
 *  ���ꤵ�줿������׵��ػߤ���
 */
LOCAL_INLINE void
vic_clr_int_enable(uint32 enable_clr)
{
	sil_wrw_iop((void *) (VIC_BASE + VIC_INT_ENABLE_CLR), enable_clr);
}

#endif /* TOPPERS_MACRO_ONLY */
#endif /* TOPPERS_VIC_H */
