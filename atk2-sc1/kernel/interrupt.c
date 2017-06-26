/*
 *  TOPPERS ATK2
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *      Automotive Kernel Version 2
 *
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2004-2015 by Center for Embedded Computing Systems
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *  Copyright (C) 2011-2015 by FUJI SOFT INCORPORATED, JAPAN
 *  Copyright (C) 2011-2013 by Spansion LLC, USA
 *  Copyright (C) 2011-2015 by NEC Communication Systems, Ltd., JAPAN
 *  Copyright (C) 2011-2015 by Panasonic Advanced Technology Development Co., Ltd., JAPAN
 *  Copyright (C) 2011-2014 by Renesas Electronics Corporation, JAPAN
 *  Copyright (C) 2011-2015 by Sunny Giken Inc., JAPAN
 *  Copyright (C) 2011-2015 by TOSHIBA CORPORATION, JAPAN
 *  Copyright (C) 2004-2015 by Witz Corporation
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
 *  $Id: interrupt.c 1801 2015-03-27 06:34:43Z t_ishikawa $
 */

/*
 *		���������⥸�塼��
 */

#include "kernel_impl.h"
#include "interrupt.h"

#ifdef TOPPERS_interrupt_initialize
/*
 *  �¹����C2ISR
 */
ISRCB	*p_runisr;

/*
 *  ����ߴ�����ǽ�����ǻ��Ѥ����ѿ������
 */

/*
 *  SuspendAllInterrupts �Υͥ��Ȳ��
 *
 *  sus_all_cnt�ϥ����ƥ����ΤǤΥͥ��Ȳ��
 *  sus_all_cnt_ctx�Ͻ���ñ�̤��Ĥ����ͥ��Ȳ��
 */
uint8	sus_all_cnt = 0U;
uint8	sus_all_cnt_ctx = 0U;

/*
 *  SuspendOSInterrupts �Υͥ��Ȳ��
 *
 *  sus_os_cnt�ϥ����ƥ����ΤǤΥͥ��Ȳ��
 *  sus_os_cnt_ctx�Ͻ���ñ�̤��Ĥ����ͥ��Ȳ��
 */
uint8	sus_os_cnt = 0U;
uint8	sus_os_cnt_ctx = 0U;

/*
 *  ����ߴ�����ǽ�ν����
 */
#ifndef OMIT_INITIALIZE_INTERRUPT

void
interrupt_initialize(void)
{
	ISRType				i;
	InterruptNumberType	j;
	ISRCB				*p_isrcb;
	const INTINIB		*p_intinib;

	p_runisr = NULL;

	sus_all_cnt = 0U;
	sus_all_cnt_ctx = 0U;
	sus_os_cnt = 0U;
	sus_os_cnt_ctx = 0U;

	for (i = 0U; i < tnum_isr2; i++) {
		p_isrcb = &(isrcb_table[i]);
		p_isrcb->p_intinib = &(intinib_table[i]);
		p_isrcb->p_lastrescb = NULL;
	}

	for (j = 0U; j < tnum_intno; j++) {
		p_intinib = &(intinib_table[j]);
		x_config_int(p_intinib->intno, p_intinib->intatr, p_intinib->intpri);
	}
}

#endif /* OMIT_INITIALIZE_INTERRUPT */
#endif /* TOPPERS_interrupt_initialize */

/*
 *  ����߶ػߤβ��
 */
#ifdef TOPPERS_release_interrupts

void
release_interrupts(OSServiceIdType serviceId)
{
#ifdef CFG_USE_ERRORHOOK
	boolean call_error_hook = FALSE;
#endif /* CFG_USE_ERRORHOOK */

	if (sus_os_cnt_ctx > 0U) {
		sus_os_cnt -= sus_os_cnt_ctx;
		sus_os_cnt_ctx = 0U;

		if (sus_os_cnt == 0U) {
			LEAVE_CALLEVEL(TSYS_SUSOSINT);
			x_nested_unlock_os_int();
		}
#ifdef CFG_USE_ERRORHOOK
		call_error_hook = TRUE;
#endif /* CFG_USE_ERRORHOOK */
	}

	if (sus_all_cnt_ctx > 0U) {
		sus_all_cnt -= sus_all_cnt_ctx;
		sus_all_cnt_ctx = 0U;
		if (sus_all_cnt == 0U) {
			LEAVE_CALLEVEL(TSYS_SUSALLINT);
			ASSERT((callevel_stat & TSYS_DISALLINT) == TSYS_NULL);
			x_unlock_all_int();
		}
#ifdef CFG_USE_ERRORHOOK
		call_error_hook = TRUE;
#endif /* CFG_USE_ERRORHOOK */
	}

	/* C2ISR�ξ��Τ�DisAll�������� */
	if (serviceId == OSServiceId_ISRMissingEnd) {
		if ((callevel_stat & TSYS_DISALLINT) != TSYS_NULL) {
			LEAVE_CALLEVEL(TSYS_DISALLINT);
			x_unlock_all_int();
#ifdef CFG_USE_ERRORHOOK
			call_error_hook = TRUE;
#endif /* CFG_USE_ERRORHOOK */
		}
	}

#ifdef CFG_USE_ERRORHOOK
	if ((serviceId != OSServiceId_Invalid) && (call_error_hook != FALSE)) {
		call_errorhook(E_OS_DISABLEDINT, serviceId);
	}
#endif /* CFG_USE_ERRORHOOK */
}

#endif /* TOPPERS_release_interrupts */

/*
 *  C2ISR��λ���Υ����å��ؿ�
 */
#ifdef TOPPERS_exit_isr2

LOCAL_INLINE void
release_isrresources(ISRCB *p_isrcb)
{

	/* OS����߶ػ߾��ְʾ�����Ϥ� */
	if (p_isrcb->p_lastrescb != NULL) {
		do {
			x_set_ipm(p_isrcb->p_lastrescb->prevpri);
			p_isrcb->p_lastrescb->lockflg = FALSE;
			p_isrcb->p_lastrescb = p_isrcb->p_lastrescb->p_prevrescb;
		} while (p_isrcb->p_lastrescb != NULL);

#ifdef CFG_USE_ERRORHOOK
		call_errorhook(E_OS_RESOURCE, OSServiceId_ISRMissingEnd);
#endif /* CFG_USE_ERRORHOOK */
	}
}

void
exit_isr2(void)
{
	x_nested_lock_os_int();

	release_interrupts(OSServiceId_ISRMissingEnd);

	/* �꥽�������ݾ��֤ξ�� */
	release_isrresources(p_runisr);

	x_nested_unlock_os_int();
}

#endif /* TOPPERS_exit_isr2 */
