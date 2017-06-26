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
 *  $Id: task.c 1801 2015-03-27 06:34:43Z t_ishikawa $
 */

/*
 *		����������⥸�塼��
 */

#include "kernel_impl.h"
#include "check.h"
#include "task.h"
#include "interrupt.h"

/*
 *  �ȥ졼�����ޥ���Υǥե�������
 */
#ifndef LOG_TSKSTAT
#define LOG_TSKSTAT(p_tcb)
#endif /* LOG_TSKSTAT */

/* �����ؿ��Υץ�ȥ�������� */
LOCAL_INLINE uint16 bitmap_search(uint16 bitmap);
LOCAL_INLINE boolean primap_empty(void);
LOCAL_INLINE PriorityType primap_search(void);
LOCAL_INLINE void primap_set(PriorityType pri);
LOCAL_INLINE void primap_clear(PriorityType pri);

#ifdef TOPPERS_task_initialize

/*
 *  �¹Ծ��֤Υ�����
 */
TCB				*p_runtsk;

/*
 *  �ǹ�ͥ���̥�����
 */
TCB				*p_schedtsk;

/*
 *  ��ǥ����塼��κǹ�ͥ����
 */
PriorityType	nextpri;

/*
 *  ��ǥ����塼
 */
QUEUE			ready_queue[TNUM_TPRI];

/*
 *  ��ǥ����塼�������Τ���Υӥåȥޥå�
 */
uint16			ready_primap;

/*
 *  �����������⥸�塼��ν����
 */
void
task_initialize(void)
{
	TaskType	i;
	TCB			*p_tcb;

	p_runtsk = NULL;
	p_schedtsk = NULL;

	for (i = 0U; i < TNUM_TPRI; i++) {
		queue_initialize(&(ready_queue[i]));
	}
	nextpri = TPRI_MINTASK;
	ready_primap = 0U;

	for (i = 0U; i < tnum_task; i++) {
		p_tcb = &(tcb_table[i]);
		p_tcb->p_tinib = &(tinib_table[i]);
		p_tcb->actcnt = 0U;
		p_tcb->curevt = 0U;
		p_tcb->tstat = SUSPENDED;
		if ((p_tcb->p_tinib->autoact & ((AppModeType) 1 << appmodeid)) != APPMODE_NONE) {
			(void) make_active(p_tcb);
		}
	}
}

#endif /* TOPPERS_task_initialize */

/*
 *  �ӥåȥޥåץ������ؿ�
 *
 *  bitmap���1�ΥӥåȤ��⡤�ǤⲼ�̡ʱ��ˤΤ�Τ򥵡����������Υӥ�
 *  ���ֹ���֤�
 *  �ӥå��ֹ�ϡ��ǲ��̥ӥåȤ�0�Ȥ��롥bitmap��0�����
 *  ���ƤϤʤ�ʤ������δؿ��Ǥϡ�bitmap��16�ӥåȤǤ��뤳�Ȥ��ꤷ��
 *  uint16���Ȥ��Ƥ���
 *
 *  �ӥåȥ�����̿�����ĥץ��å��Ǥϡ��ӥåȥ�����̿���Ȥ��褦��
 *  ��ľ����������Ψ���ɤ���礬����
 *  ���Τ褦�ʾ��ˤϡ��������åȰ�¸���ǥӥåȥ�����̿���Ȥä�
 *  bitmap_search���������OMIT_BITMAP_SEARCH��ޥ����������Ф褤
 *  �ޤ����ӥåȥ�����̿��Υ������������դʤɤ���ͳ��ͥ���٤ȥӥå�
 *  �Ȥ��б����ѹ����������ˤϡ�PRIMAP_BIT��ޥ����������Ф褤
 *
 *  �ޤ���ɸ��饤�֥���ffs������ʤ顤���Τ褦���������ɸ��饤��
 *  ����Ȥä�������Ψ���ɤ���ǽ���⤢��
 *		#define	bitmap_search(bitmap) (ffs(bitmap) - 1)
 */
#ifndef PRIMAP_BIT
#define PRIMAP_BIT(pri)		((uint16) ((uint16) 1U << (pri)))
#endif /* PRIMAP_BIT */

#ifndef OMIT_BITMAP_SEARCH

LOCAL_INLINE uint16
bitmap_search(uint16 bitmap)
{
	/*
	 *  �ӥåȥޥåץ������ؿ��ѥơ��֥�
	 */
	const uint8	bitmap_search_table[BITMAP_NUM] = {
		0U, 1U, 0U, 2U, 0U, 1U, 0U,
		3U, 0U, 1U, 0U, 2U, 0U, 1U, 0U
	};

	uint16		n = 0U;

	ASSERT(bitmap != 0U);
	if ((bitmap & 0x00ffU) == 0U) {
		bitmap >>= 8U;
		n += 8U;
	}
	if ((bitmap & 0x0fU) == 0U) {
		bitmap >>= 4U;
		n += 4U;
	}
	return(n + bitmap_search_table[(bitmap & 0x000fU) - 1U]);
}

#endif /* OMIT_BITMAP_SEARCH */

/*
 *  ͥ���٥ӥåȥޥåפ������Υ����å�
 */
LOCAL_INLINE boolean
primap_empty(void)
{
	return(ready_primap == 0U);
}

/*
 *  ͥ���٥ӥåȥޥåפΥ�����
 */
LOCAL_INLINE PriorityType
primap_search(void)
{
	return((PriorityType) bitmap_search(ready_primap));
}

/*
 *  ͥ���٥ӥåȥޥåפΥ��å�
 */
LOCAL_INLINE void
primap_set(PriorityType pri)
{
	ready_primap |= PRIMAP_BIT(pri);
}

/*
 *  ͥ���٥ӥåȥޥåפΥ��ꥢ
 */
LOCAL_INLINE void
primap_clear(PriorityType pri)
{
	ready_primap &= (uint16) ~PRIMAP_BIT(pri);
}

/*
 *  �ǹ�ͥ���̥������Υ�����
 */
#ifdef TOPPERS_search_schedtsk

void
search_schedtsk(void)
{
	if (primap_empty() != FALSE) {
		p_schedtsk = NULL;
	}
	else {
		p_schedtsk = (TCB *) (queue_delete_next(&(ready_queue[nextpri])));
		if (queue_empty(&(ready_queue[nextpri])) != FALSE) {
			primap_clear(nextpri);
			nextpri = (primap_empty() != FALSE) ?
					  TPRI_MINTASK : primap_search();
		}
	}
}

#endif /* TOPPERS_search_schedtsk */

/*
 *  �¹ԤǤ�����֤ؤΰܹ�
 */
#ifdef TOPPERS_make_runnable

boolean
make_runnable(TCB *p_tcb)
{
	PriorityType	pri, schedpri;
	boolean			is_next_schedtsk = TRUE;

	p_tcb->tstat = READY;
	LOG_TSKSTAT(p_tcb);
	if (p_schedtsk != NULL) {
		pri = p_tcb->curpri;
		schedpri = p_schedtsk->curpri;
		if (pri >= schedpri) {
			/*
			 *  schedtsk ������ͥ���٤��⤤��硤p_tcb ���
			 *  �ǥ����塼�κǸ�������
			 */
			queue_insert_prev(&(ready_queue[pri]), &(p_tcb->task_queue));
			primap_set(pri);
			if (pri < nextpri) {
				nextpri = pri;
			}
			is_next_schedtsk = FALSE;
		}
		else {
			/*
			 *  p_tcb ������ͥ���٤��⤤��硤schedtsk ���ǥ����塼
			 *  ����Ƭ�����졤p_tcb �򿷤��� schedtsk �Ȥ���
			 */
			queue_insert_next(&(ready_queue[schedpri]), &(p_schedtsk->task_queue));
			primap_set(schedpri);
			nextpri = schedpri;
		}
	}

	if (is_next_schedtsk != FALSE) {
		p_schedtsk = p_tcb;
	}
	return(is_next_schedtsk);
}

#endif /* TOPPERS_make_runnable */

/*
 *  �¹ԤǤ�����֤���¾�ξ��֤ؤ�����
 *
 *  SC1-MC��make_non_runnable����������뤿��
 *  SC1�ˤ�make_non_runable���������SC1��SC1-MC�δؿ������˹礻��
 *  ��SC1-MC�Ǥϡ�p_runtsk��p_schedtsk�����פ��Ƥ��뤳�Ȥ��ǧ��������������ɬ�פ����뤬��
 *  SC1�Ǥϡ�search_schedtsk�Τ߸ƤӽФ������Ȥ����
 */
#ifdef TOPPERS_make_non_runnable

void
make_non_runnable(void)
{
	search_schedtsk();
}

#endif /* TOPPERS_make_non_runnable */

/*
 *  �������ε�ư
 *
 *  TerminateTask �� ChainTask ����ǡ������������Ф��� make_active ��
 *  �Ƥ־�礬����Τ���դ���
 */
#ifdef TOPPERS_make_active

boolean
make_active(TCB *p_tcb)
{
	p_tcb->curpri = p_tcb->p_tinib->inipri;
	if (TSKID(p_tcb) < tnum_exttask) {
		p_tcb->curevt = EVTMASK_NONE;
		p_tcb->waievt = EVTMASK_NONE;
	}
	p_tcb->p_lastrescb = NULL;
	activate_context(p_tcb);
	return(make_runnable(p_tcb) != FALSE);
}

#endif /* TOPPERS_make_active */

/*
 *  �������Υץꥨ��ץ�
 */
#ifdef TOPPERS_preempt

void
preempt(void)
{
	PriorityType pri;

	ASSERT(p_runtsk == p_schedtsk);
	pri = p_runtsk->curpri;
	queue_insert_next(&(ready_queue[pri]), &(p_runtsk->task_queue));
	primap_set(pri);
	search_schedtsk();
}

#endif /* TOPPERS_preempt */

/*
 *  �¹���Υ�������SUSPENDED���֤ˤ���
 */
#ifdef TOPPERS_suspend

void
suspend(void)
{
	p_runtsk->tstat = SUSPENDED;
	LOG_TSKSTAT(p_runtsk);
	make_non_runnable();
	if (p_runtsk->actcnt > 0U) {
		p_runtsk->actcnt -= 1U;
		(void) make_active(p_runtsk);
	}
}

#endif /* TOPPERS_suspend */

/*
 *  ��������������λ�����ݸ�
 *  TerminateTask()��ChainTask()�ʤ��Ǥμ��������ν�λ
 * �ʥ������δؿ�����꥿����ˤ������ν���
 */
#ifdef TOPPERS_exit_task

/*
 *  �����������꥽�����ֵ�
 */
LOCAL_INLINE void
release_taskresources(TCB *p_tcb)
{
	if (p_tcb->p_lastrescb != NULL) {
		if (p_tcb->curpri <= TPRI_MINISR) {
			/* �꥽������������������г���ߵ��Ĥˤʤ� */
			x_set_ipm((PriorityType) TIPM_ENAALL);
		}
		/* �꥽������������������м¹���ͥ���٤���� */
		p_tcb->curpri = p_tcb->p_tinib->exepri;

		/* OS����߶ػ߾��ְʾ����� */
		do {
			p_tcb->p_lastrescb->lockflg = FALSE;
			p_tcb->p_lastrescb = p_tcb->p_lastrescb->p_prevrescb;
		} while (p_tcb->p_lastrescb != NULL);
	}
}

void
exit_task(void)
{
	x_nested_lock_os_int();

	/* ����߶ػ߾��֤ξ��ϳ���߶ػߤ������� */
	release_interrupts(OSServiceId_Invalid);

	/* �꥽�������ݤ����ޤޤξ��ϥ꥽������������� */
	release_taskresources(p_runtsk);

#ifdef CFG_USE_ERRORHOOK
	/* ���顼�եå���Ƥ� */
	call_errorhook(E_OS_MISSINGEND, OSServiceId_TaskMissingEnd);
#endif /* CFG_USE_ERRORHOOK */

	suspend();

	/* �ݥ��ȥ������եå���ͭ���ʾ��ϥݥ��ȥ������եå����ƤФ�� */
	exit_and_dispatch();
}

#endif /* TOPPERS_exit_task */
