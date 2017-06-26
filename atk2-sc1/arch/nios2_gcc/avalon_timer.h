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
 *  $Id: avalon_timer.h 1801 2015-03-27 06:34:43Z t_ishikawa $
 */

/*
 *		�����ޥɥ饤�С�Avalon Timer�ѡ�
 */

#ifndef TOPPERS_AVALON_TIMER_H
#define TOPPERS_AVALON_TIMER_H

#include "prc_sil.h"

/*
 *  Avalon Timer �ϡ��ɥ��������
 */

/*
 *  �쥸����
 */
#define AVALON_TIM_STATUS	(0x00U)
#define AVALON_TIM_CONTROL	(0x04U)
#define AVALON_TIM_PERIODL	(0x08U)
#define AVALON_TIM_PERIODH	(0x0CU)
#define AVALON_TIM_SNAPL	(0x10U)
#define AVALON_TIM_SNAPH	(0x14U)

/*
 *  �ӥå����
 */
#define AVALON_TIM_STATUS_RUN	UINT_C(0x02)
#define AVALON_TIM_STATUS_TO	UINT_C(0x01)

#define AVALON_TIM_CONTROL_STOP		UINT_C(0x08)
#define AVALON_TIM_CONTROL_START	UINT_C(0x04)
#define AVALON_TIM_CONTROL_CONT		UINT_C(0x02)
#define AVALON_TIM_CONTROL_ITO		UINT_C(0x01)


#ifndef TOPPERS_MACRO_ONLY

/*
 *  �������ͤ�����ɽ���ȥޥ�������ñ�̤Ȥ��Ѵ�
 *
 */
#define TO_USEC(clock)	((((SystemTimeUsType) (clock)) * 1000U) / TIMER_CLOCK)

/*
 *  �������ͤ�����ɽ����100�ʥ���ñ�̤Ȥ��Ѵ�
 */
#define TO_100NSEC(clock)	((((SystemTimeUsType) (clock)) * 10000U) / TIMER_CLOCK)

/*
 *  �ޥ�������ñ�̤Ǥλ�������
 */
extern SystemTimeUsType get_tim_utime(void);

/*
 *  100�ʥ���ñ�̤Ǥλ�������
 */
extern SystemTime100NsType get_tim_100ntime(void);

/*
 *  �����ޤε�ư����
 *
 *  �����ޤ�������������Ū�ʥ����޳�����׵��ȯ��������
 */
extern void target_timer_initialize(void);

/*
 *  �����ޤ���߽���
 *
 *  �����ޤ�ư�����ߤ�����
 */
extern void target_timer_terminate(void);

/*
 *  �����ޤθ����ͤ��ɽФ�
 */
LOCAL_INLINE TickType
target_timer_get_current(void)
{
	TickType count;

	/* ���ʥåץ쥸�����˽񤭹�����ͤ�ۡ���ɤ��� */
	sil_wrw_iop((void *) (SYS_CLK_TIMER_BASE + AVALON_TIM_SNAPL), 0x00U);

	/* ��������ͤ��ɤ߹��� */
	count = sil_rew_iop((void *) (SYS_CLK_TIMER_BASE + AVALON_TIM_SNAPL));
	count |= sil_rew_iop((void *) (SYS_CLK_TIMER_BASE + AVALON_TIM_SNAPH)) << 16;

	return(TIMER_CLOCK - (count + 1));
}

/*
 *  �����޳�����׵�Υ����å�
 */
LOCAL_INLINE boolean
target_timer_probe_int(void)
{
	return((sil_rew_iop((void *) (SYS_CLK_TIMER_BASE + AVALON_TIM_STATUS)) & AVALON_TIM_STATUS_TO) != 0U);
}

#endif /* TOPPERS_MACRO_ONLY */
#endif /* TOPPERS_AVALON_TIMER_H */
