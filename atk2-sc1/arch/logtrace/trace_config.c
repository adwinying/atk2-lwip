/*
 *  TOPPERS ATK2
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *      Automotive Kernel Version 2
 *
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2005-2015 by Center for Embedded Computing Systems
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
 *  $Id: trace_config.c 1801 2015-03-27 06:34:43Z t_ishikawa $
 */

/*
 *		�ȥ졼������ǽ
 */

#include "kernel_impl.h"
#include "task.h"

#include "target_timer.h"

/*
 *  �����trace_config.h�˥ץ�ȥ�����������֤��٤�������TCB��
 *  �����������ʤΤǡ�����ѥ��뤬�̤�ʤ����ᤳ�����֤�
 */
extern void log_dsp_enter(const TCB *p_tcb);
extern void log_dsp_leave(const TCB *p_tcb);

/*
 *  �����ؿ��ץ�ȥ��������
 */
static StatusType trace_wri_log(TRACE *p_trace);

/*
 *  �ȥ졼�����Хåե��Ȥ���˥����������뤿��Υݥ���
 */
static TRACE			trace_buffer[TCNT_TRACE_BUFFER];    /* �ȥ졼�����Хåե� */
static uint32			trace_count;                        /* �ȥ졼�����Хåե���Υ��ο� */
static uint32			trace_head;                         /* ��Ƭ�Υȥ졼�����γ�Ǽ���� */
static uint32			trace_tail;                         /* ���Υȥ졼�����γ�Ǽ���� */
static TraceModeType	trace_mode = TRACE_AUTOSTOP;        /* �ȥ졼���⡼�� */

/*
 *  �ȥ졼������ǽ�ν����
 */
void
trace_initialize(uintptr exinf)
{
	TraceModeType mode = ((TraceModeType) exinf);

	trace_count = 0U;
	trace_head = 0U;
	trace_tail = 0U;
	trace_mode = mode;
}

/*
 *  �ȥ졼�����γ���
 */
StatusType
trace_sta_log(TraceModeType mode)
{
	if ((mode & TRACE_CLEAR) != 0U) {
		trace_count = 0U;
		trace_head = 0U;
		trace_tail = 0U;
	}
	trace_mode = mode;
	return(E_OK);
}

/*
 *  �ȥ졼�����ν����
 */
static StatusType
trace_wri_log(TRACE *p_trace)
{
	SIL_PRE_LOC;

	if (trace_mode != TRACE_STOP) {
		SIL_LOC_INT();

		/*
		 *  �ȥ졼�����������
		 *
		 *  LOG_WRI_LOG_ENTER����ƤФ줿����p_trace->logtim��񤭴�
		 *  ���Ƥ��ޤ��Τϵ���������������wri_log�����Ǿ�񤭤��뤿����
		 *  ��Ϥʤ�
		 */
		p_trace->logtim = GET_UTIM();

		/*
		 *  �ȥ졼���Хåե��˵�Ͽ
		 */
		trace_buffer[trace_tail] = *p_trace;
		trace_tail++;
		if (trace_tail >= TCNT_TRACE_BUFFER) {
			trace_tail = 0U;
		}
		if (trace_count < TCNT_TRACE_BUFFER) {
			trace_count++;
			if ((trace_count >= TCNT_TRACE_BUFFER)
				&& ((trace_mode & TRACE_AUTOSTOP) != 0U)) {
				trace_mode = TRACE_STOP;
			}
		}
		else {
			trace_head = trace_tail;
		}

		SIL_UNL_INT();
	}
	return(E_OK);
}

/*
 *  �ȥ졼�������ɽФ�
 */
StatusType
trace_rea_log(TRACE *p_trace)
{
	StatusType ercd;
	SIL_PRE_LOC;

	SIL_LOC_INT();

	/*
	 *  �ȥ졼�����Хåե�����μ�Ф�
	 */
	if (trace_count > 0U) {
		*p_trace = trace_buffer[trace_head];
		trace_count--;
		trace_head++;
		if (trace_head >= TCNT_TRACE_BUFFER) {
			trace_head = 0U;
		}
		ercd = E_OK;
	}
	else {
		ercd = E_NOT_OK;
	}

	SIL_UNL_INT();
	return(ercd);
}

/*
 *  �ȥ졼��������Ϥ��뤿��Υ饤�֥��ؿ�
 */

void
trace_write_0(uint32 type)
{
	TRACE trace;

	trace.logtype = type;
	(void) trace_wri_log(&trace);
}

void
trace_write_1(uint32 type, const uintptr arg1)
{
	TRACE trace;

	trace.logtype = type;
	trace.loginfo[0] = arg1;
	(void) trace_wri_log(&trace);
}

void
trace_write_2(uint32 type, uintptr arg1, uintptr arg2)
{
	TRACE trace;

	trace.logtype = type;
	trace.loginfo[0] = arg1;
	trace.loginfo[1] = arg2;
	(void) trace_wri_log(&trace);
}

void
trace_write_3(uint32 type, uintptr arg1, uintptr arg2, uintptr arg3)
{
	TRACE trace;

	trace.logtype = type;
	trace.loginfo[0] = arg1;
	trace.loginfo[1] = arg2;
	trace.loginfo[2] = arg3;
	(void) trace_wri_log(&trace);
}

void
trace_write_4(uint32 type, uintptr arg1, uintptr arg2, uintptr arg3,
			  uintptr arg4)
{
	TRACE trace;

	trace.logtype = type;
	trace.loginfo[0] = arg1;
	trace.loginfo[1] = arg2;
	trace.loginfo[2] = arg3;
	trace.loginfo[3] = arg4;
	(void) trace_wri_log(&trace);
}

void
trace_write_5(uint32 type, uintptr arg1, uintptr arg2, uintptr arg3,
			  uintptr arg4, uintptr arg5)
{
	TRACE trace;

	trace.logtype = type;
	trace.loginfo[0] = arg1;
	trace.loginfo[1] = arg2;
	trace.loginfo[2] = arg3;
	trace.loginfo[3] = arg4;
	trace.loginfo[4] = arg5;
	(void) trace_wri_log(&trace);
}

/*
 *  ������֥����ǵ��Ҥ���륳���ɤ���ȥ졼��������Ϥ��뤿��δ�
 *  ��
 */
void
log_dsp_enter(const TCB *p_tcb)
{
	trace_1(LOG_TYPE_DSP | LOG_ENTER, (const uintptr) p_tcb);
}

void
log_dsp_leave(const TCB *p_tcb)
{
	trace_1(LOG_TYPE_DSP | LOG_LEAVE, (const uintptr) p_tcb);
}
