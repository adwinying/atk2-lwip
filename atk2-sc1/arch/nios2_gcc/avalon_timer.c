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
 *  $Id: avalon_timer.c 1801 2015-03-27 06:34:43Z t_ishikawa $
 */

/*
 *		�����ޥɥ饤�С�Avalon Timer��
 */

#include "kernel_impl.h"
#include "target_timer.h"
#include "avalon_timer.h"
#include "Os_Lcfg.h"

/*
 *  ���ߤΥ����ƥ�����ñ��: �ߥ��á�
 *
 *  ��̩�ˤϡ����Υ�����ƥ��å��Υ����ƥ����
 */
static SystemTimeMsType current_time;

/*
 *  �ޥ�������ñ�̤Ǥλ�������
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
 *  100�ʥ���ñ�̤Ǥλ�������
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
 *  �����ޤε�ư����
 */
void
target_timer_initialize(void)
{
	current_time = 0U;

	/* �����ޡ����ȥå� */
	sil_wrw_iop((void *) (SYS_CLK_TIMER_BASE + AVALON_TIM_CONTROL), AVALON_TIM_CONTROL_STOP);
	/* �����ॢ���ȥ��ơ��������ꥢ */
	sil_wrw_iop((void *) (SYS_CLK_TIMER_BASE + AVALON_TIM_STATUS), 0x00U);

	sil_wrw_iop((void *) (SYS_CLK_TIMER_BASE + AVALON_TIM_PERIODL), ((TIMER_CLOCK - 1) & 0xffffU));         /* �����󥿡����å� ����16bit */
	sil_wrw_iop((void *) (SYS_CLK_TIMER_BASE + AVALON_TIM_PERIODH), ((uint32) (TIMER_CLOCK - 1) >> 16));    /* �����󥿡����å� ���16bit */

	/*
	 * �����ޡ��������ȡ������ȥ���ɡ�����ߵ���
	 */
	sil_wrw_iop((void *) (SYS_CLK_TIMER_BASE + AVALON_TIM_CONTROL), AVALON_TIM_CONTROL_START
				| AVALON_TIM_CONTROL_CONT | AVALON_TIM_CONTROL_ITO);
}

/*
 *  �����ޤ���߽���
 */
void
target_timer_terminate(void)
{
	/* ��������� */
	sil_wrw_iop((void *) (SYS_CLK_TIMER_BASE + AVALON_TIM_CONTROL), AVALON_TIM_CONTROL_STOP);

	/* ������׵�Υ��ꥢ */
	sil_wrw_iop((void *) (SYS_CLK_TIMER_BASE + AVALON_TIM_STATUS), 0x00U);
}

/*
 *  target_timer.arxml����Ѥ��ʤ������н�
 */
#ifndef SysTimerCnt
#define SysTimerCnt		UINT_C(0)
#endif /* SysTimerCnt */

/*
 *  �����޳���ߥϥ�ɥ�
 */
ISR(target_timer_hdr)
{
	StatusType ercd;

	/* TO�ӥåȤΥ��ꥢ */
	sil_wrw_iop((void *) (SYS_CLK_TIMER_BASE + AVALON_TIM_STATUS), 0x00U);

	/* current_time�򹹿����� */
	current_time++;

	/*
	 *  �����󥿲û����ν����¹�
	 */
	ercd = IncrementCounter(SysTimerCnt);
	/* ���顼�꥿����ξ��ϥ���åȥ����� */
	if (ercd != E_OK) {
		ShutdownOS(ercd);
	}
}
