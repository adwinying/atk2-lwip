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
 *  $Id: task_manage.c 1801 2015-03-27 06:34:43Z t_ishikawa $
 */

/*
 *		�����������⥸�塼��
 */

#include "kernel_impl.h"
#include "check.h"
#include "task.h"

/*
 *  �ȥ졼�����ޥ���Υǥե�������
 */
#ifndef LOG_TSKSTAT
#define LOG_TSKSTAT(p_tcb)
#endif /* LOG_TSKSTAT */

#ifndef LOG_ACTTSK_ENTER
#define LOG_ACTTSK_ENTER(tskid)
#endif /* LOG_ACTTSK_ENTER */

#ifndef LOG_ACTTSK_LEAVE
#define LOG_ACTTSK_LEAVE(ercd)
#endif /* LOG_ACTTSK_LEAVE */

#ifndef LOG_TERTSK_ENTER
#define LOG_TERTSK_ENTER()
#endif /* LOG_TERTSK_ENTER */

#ifndef LOG_TERTSK_LEAVE
#define LOG_TERTSK_LEAVE(ercd)
#endif /* LOG_TERTSK_LEAVE */

#ifndef LOG_CHNTSK_ENTER
#define LOG_CHNTSK_ENTER(tskid)
#endif /* LOG_CHNTSK_ENTER */

#ifndef LOG_CHNTSK_LEAVE
#define LOG_CHNTSK_LEAVE(ercd)
#endif /* LOG_CHNTSK_LEAVE */

#ifndef LOG_SCHED_LEAVE
#define LOG_SCHED_ENTER()
#endif /* LOG_SCHED_LEAVE */

#ifndef LOG_SCHED_LEAVE
#define LOG_SCHED_LEAVE(ercd)
#endif /* LOG_SCHED_LEAVE */

#ifndef LOG_GETTID_ENTER
#define LOG_GETTID_ENTER()
#endif /* LOG_GETTID_ENTER */

#ifndef LOG_GETTID_LEAVE
#define LOG_GETTID_LEAVE(ercd, p_tskid)
#endif /* LOG_GETTID_LEAVE */

#ifndef LOG_GETTST_ENTER
#define LOG_GETTST_ENTER(tskid)
#endif /* LOG_GETTST_ENTER */

#ifndef LOG_GETTST_LEAVE
#define LOG_GETTST_LEAVE(ercd, p_state)
#endif /* LOG_GETTST_LEAVE */


/*
 *  �������ε�ư
 */
#ifdef TOPPERS_ActivateTask

StatusType
ActivateTask(TaskType TaskID)
{
	StatusType	ercd = E_OK;
	TCB			*p_tcb;

	LOG_ACTTSK_ENTER(TaskID);
	CHECK_DISABLEDINT();
	CHECK_CALLEVEL(CALLEVEL_ACTIVATETASK);
	CHECK_ID(TaskID < tnum_task);
	p_tcb = get_tcb(TaskID);

	x_nested_lock_os_int();
	if (p_tcb->tstat == SUSPENDED) {
		if ((make_active(p_tcb) != FALSE) && (callevel_stat == TCL_TASK)) {
			dispatch();
		}
	}
	else {
		S_D_CHECK_LIMIT(p_tcb->actcnt < p_tcb->p_tinib->maxact);

		p_tcb->actcnt += 1U;
	}

  d_exit_no_errorhook:
	x_nested_unlock_os_int();
  exit_no_errorhook:
	LOG_ACTTSK_LEAVE(ercd);
	return(ercd);

#ifdef CFG_USE_ERRORHOOK
  exit_errorhook:
	x_nested_lock_os_int();
  d_exit_errorhook:
#ifdef CFG_USE_PARAMETERACCESS
	_errorhook_par1.tskid = TaskID;
#endif /* CFG_USE_PARAMETERACCESS */
	call_errorhook(ercd, OSServiceId_ActivateTask);
	goto d_exit_no_errorhook;
#endif /* CFG_USE_ERRORHOOK */
}

#endif /* TOPPERS_ActivateTask */

/*
 *  ���������ν�λ
 */
#ifdef TOPPERS_TerminateTask

StatusType
TerminateTask(void)
{
	StatusType ercd = E_OK;

	LOG_TERTSK_ENTER();
	CHECK_DISABLEDINT();
	CHECK_CALLEVEL(CALLEVEL_TERMINATETASK);
	CHECK_RESOURCE(p_runtsk->p_lastrescb == NULL);

	x_nested_lock_os_int();
	/*
	 *  �����꥽�����β�����ͥ���٤򲼤�������ʤΤǡ������Ǥ�
	 *  ���⤷�ʤ��Ƥ褤
	 */

	suspend();

	LOG_TERTSK_LEAVE(E_OK);
	exit_and_dispatch();
	ASSERT(0);

#ifdef CFG_USE_ERRORHOOK
  exit_errorhook:
	x_nested_lock_os_int();
	call_errorhook(ercd, OSServiceId_TerminateTask);
	x_nested_unlock_os_int();
#endif /* CFG_USE_ERRORHOOK */

  exit_no_errorhook:
	LOG_TERTSK_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_TerminateTask */

/*
 *  ���������ν�λ�ȥ������ε�ư
 */
#ifdef TOPPERS_ChainTask

StatusType
ChainTask(TaskType TaskID)
{
	/*
	 *  �����Ǥ� ercd �ν��������������פǤ��뤬������ѥ���η�
	 *  ���å��������򤱤뤿��˽�������Ƥ���
	 */
	StatusType	ercd = E_OK;
	TCB			*p_tcb;

	LOG_CHNTSK_ENTER(TaskID);
	CHECK_DISABLEDINT();
	CHECK_CALLEVEL(CALLEVEL_CHAINTASK);
	CHECK_RESOURCE(p_runtsk->p_lastrescb == NULL);
	CHECK_ID(TaskID < tnum_task);
	p_tcb = get_tcb(TaskID);

	x_nested_lock_os_int();
	if (p_tcb == p_runtsk) {
		make_non_runnable();
		(void) make_active(p_runtsk);
	}
	else {
		/*
		 *  ���顼���������Ѥ��Ĥ�ʤ��褦�ˡ����顼�����å���
		 *  ��������λ���������˹Ԥ�ɬ�פ�����
		 */
		S_D_CHECK_LIMIT((p_tcb->tstat == SUSPENDED)
						|| (p_tcb->actcnt < p_tcb->p_tinib->maxact));

		suspend();

		if (p_tcb->tstat == SUSPENDED) {
			(void) make_active(p_tcb);
		}
		else {
			p_tcb->actcnt += 1U;
		}
	}

	LOG_CHNTSK_LEAVE(E_OK);
	exit_and_dispatch();
	ASSERT(0);

#ifdef CFG_USE_ERRORHOOK
  exit_errorhook:
	x_nested_lock_os_int();
  d_exit_errorhook:
#ifdef CFG_USE_PARAMETERACCESS
	_errorhook_par1.tskid = TaskID;
#endif /* CFG_USE_PARAMETERACCESS */
	call_errorhook(ercd, OSServiceId_ChainTask);
#endif /* CFG_USE_ERRORHOOK */

  d_exit_no_errorhook:
	x_nested_unlock_os_int();
  exit_no_errorhook:
	LOG_CHNTSK_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_ChainTask */

/*
 *  �������塼��θƤӽФ�
 */
#ifdef TOPPERS_Schedule

StatusType
Schedule(void)
{
	/*
	 *  �����Ǥ� ercd �ν��������������פǤ��뤬������ѥ���η�
	 *  ���å��������򤱤뤿��˽�������Ƥ���
	 */
	StatusType ercd = E_OK;

	LOG_SCHED_ENTER();
	CHECK_DISABLEDINT();
	CHECK_CALLEVEL(CALLEVEL_SCHEDULE);
	CHECK_RESOURCE(p_runtsk->p_lastrescb == NULL);

	x_nested_lock_os_int();
	if (p_runtsk->p_tinib->inipri > nextpri) {
		p_runtsk->curpri = p_runtsk->p_tinib->inipri;
		preempt();
		dispatch();
		p_runtsk->curpri = p_runtsk->p_tinib->exepri;
	}

  d_exit_no_errorhook:
	x_nested_unlock_os_int();
  exit_no_errorhook:
	LOG_SCHED_LEAVE(ercd);
	return(ercd);

#ifdef CFG_USE_ERRORHOOK
  exit_errorhook:
	x_nested_lock_os_int();
	call_errorhook(ercd, OSServiceId_Schedule);
	goto d_exit_no_errorhook;
#endif /* CFG_USE_ERRORHOOK */
}

#endif /* TOPPERS_Schedule */

/*
 *  �¹Ծ��֤Υ�����ID�λ���
 */
#ifdef TOPPERS_GetTaskID

StatusType
GetTaskID(TaskRefType TaskID)
{
	StatusType ercd = E_OK;

	LOG_GETTID_ENTER();
	CHECK_CALLEVEL(CALLEVEL_GETTASKID);
	CHECK_PARAM_POINTER(TaskID);
	*TaskID = (p_runtsk == NULL) ? INVALID_TASK : TSKID(p_runtsk);

  exit_no_errorhook:
	LOG_GETTID_LEAVE(ercd, TaskID);
	return(ercd);

#ifdef CFG_USE_ERRORHOOK
  exit_errorhook:
	x_nested_lock_os_int();
#ifdef CFG_USE_PARAMETERACCESS
	_errorhook_par1.p_tskid = TaskID;
#endif /* CFG_USE_PARAMETERACCESS */
	call_errorhook(ercd, OSServiceId_GetTaskID);
	x_nested_unlock_os_int();
	goto exit_no_errorhook;
#endif /* CFG_USE_ERRORHOOK */
}

#endif /* TOPPERS_GetTaskID */

/*
 *  ���������֤λ���
 */
#ifdef TOPPERS_GetTaskState

StatusType
GetTaskState(TaskType TaskID, TaskStateRefType State)
{
	StatusType	ercd = E_OK;
	TCB			*p_tcb;

	LOG_GETTST_ENTER(TaskID);
	CHECK_CALLEVEL(CALLEVEL_GETTASKSTATE);
	CHECK_ID(TaskID < tnum_task);
	CHECK_PARAM_POINTER(State);
	p_tcb = get_tcb(TaskID);

	*State = (p_tcb == p_runtsk) ? RUNNING : p_tcb->tstat;

  exit_no_errorhook:
	LOG_GETTST_LEAVE(ercd, State);
	return(ercd);

#ifdef CFG_USE_ERRORHOOK
  exit_errorhook:
	x_nested_lock_os_int();
#ifdef CFG_USE_PARAMETERACCESS
	_errorhook_par1.tskid = TaskID;
	_errorhook_par2.p_stat = State;
#endif /* CFG_USE_PARAMETERACCESS */
	call_errorhook(ercd, OSServiceId_GetTaskState);
	x_nested_unlock_os_int();
	goto exit_no_errorhook;
#endif /* CFG_USE_ERRORHOOK */
}

#endif /* TOPPERS_GetTaskState */

/*
 *  ��λ�������ѥ������ε�ư
 *
 *  ��OS����߶ػ߾��֤ǸƤФ��
 */
#ifdef TOPPERS_activate_task_action

StatusType
activate_task_action(TaskType TaskID)
{
	StatusType	ercd = E_OK;
	TCB			*p_tcb;

	LOG_ACTTSK_ENTER(TaskID);
	p_tcb = get_tcb(TaskID);

	if (p_tcb->tstat == SUSPENDED) {
		(void) make_active(p_tcb);
	}
	else if (p_tcb->actcnt < p_tcb->p_tinib->maxact) {
		p_tcb->actcnt += 1U;
	}
	else {
		ercd = E_OS_LIMIT;
#ifdef CFG_USE_ERRORHOOK
#ifdef CFG_USE_PARAMETERACCESS
		_errorhook_par1.tskid = TaskID;
#endif /* CFG_USE_PARAMETERACCESS */
		call_errorhook(ercd, OSServiceId_ActivateTask);
#endif /* CFG_USE_ERRORHOOK */
	}

	LOG_ACTTSK_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_activate_task_action */
