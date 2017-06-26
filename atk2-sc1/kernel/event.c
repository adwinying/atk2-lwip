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
 *  $Id: event.c 1801 2015-03-27 06:34:43Z t_ishikawa $
 */

/*
 *		���٥�ȴ����⥸�塼��
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

#ifndef LOG_SETEVT_ENTER
#define LOG_SETEVT_ENTER(tskid, mask)
#endif /* LOG_SETEVT_ENTER */

#ifndef LOG_SETEVT_LEAVE
#define LOG_SETEVT_LEAVE(ercd)
#endif /* LOG_SETEVT_LEAVE */

#ifndef LOG_CLREVT_ENTER
#define LOG_CLREVT_ENTER(p_runtsk, mask)
#endif /* LOG_CLREVT_ENTER */

#ifndef LOG_CLREVT_LEAVE
#define LOG_CLREVT_LEAVE(ercd)
#endif /* LOG_CLREVT_LEAVE */

#ifndef LOG_GETEVT_ENTER
#define LOG_GETEVT_ENTER(tskid)
#endif /* LOG_GETEVT_ENTER */

#ifndef LOG_GETEVT_LEAVE
#define LOG_GETEVT_LEAVE(ercd, tskid, p_mask)
#endif /* LOG_GETEVT_LEAVE */

#ifndef LOG_WAIEVT_ENTER
#define LOG_WAIEVT_ENTER(p_runtsk, mask)
#endif /* LOG_WAIEVT_ENTER */

#ifndef LOG_WAIEVT_LEAVE
#define LOG_WAIEVT_LEAVE(ercd)
#endif /* LOG_WAIEVT_LEAVE */

/*
 *  ���٥�ȤΥ��å�
 */
#ifdef TOPPERS_SetEvent

StatusType
SetEvent(TaskType TaskID, EventMaskType Mask)
{
	StatusType	ercd = E_OK;
	TCB			*p_tcb;

	LOG_SETEVT_ENTER(TaskID, Mask);
	CHECK_DISABLEDINT();
	CHECK_CALLEVEL(CALLEVEL_SETEVENT);
	CHECK_ID(TaskID < tnum_task);
	CHECK_ACCESS(TaskID < tnum_exttask);
	p_tcb = get_tcb(TaskID);

	x_nested_lock_os_int();
	D_CHECK_STATE(p_tcb->tstat != SUSPENDED);

	p_tcb->curevt |= Mask;
	if ((p_tcb->curevt & p_tcb->waievt) != EVTMASK_NONE) {
		p_tcb->waievt = EVTMASK_NONE;
		if ((make_runnable(p_tcb) != FALSE) && (callevel_stat == TCL_TASK)) {
			dispatch();
		}
	}

  d_exit_no_errorhook:
	x_nested_unlock_os_int();
  exit_no_errorhook:
	LOG_SETEVT_LEAVE(ercd);
	return(ercd);

#ifdef CFG_USE_ERRORHOOK
  exit_errorhook:
	x_nested_lock_os_int();
  d_exit_errorhook:
#ifdef CFG_USE_PARAMETERACCESS
	_errorhook_par1.tskid = TaskID;
	_errorhook_par2.mask = Mask;
#endif /* CFG_USE_PARAMETERACCESS */
	call_errorhook(ercd, OSServiceId_SetEvent);
	goto d_exit_no_errorhook;
#endif /* CFG_USE_ERRORHOOK */
}

#endif /* TOPPERS_SetEvent */

/*
 *  ���٥�ȤΥ��ꥢ
 */
#ifdef TOPPERS_ClearEvent

StatusType
ClearEvent(EventMaskType Mask)
{
	StatusType ercd = E_OK;

	LOG_CLREVT_ENTER(p_runtsk, Mask);
	CHECK_DISABLEDINT();
	CHECK_CALLEVEL(CALLEVEL_CLEAREVENT);
	CHECK_ACCESS(TSKID(p_runtsk) < tnum_exttask);

	x_nested_lock_os_int();
	p_runtsk->curevt &= ~Mask;

  d_exit_no_errorhook:
	x_nested_unlock_os_int();
  exit_no_errorhook:
	LOG_CLREVT_LEAVE(ercd);
	return(ercd);

#ifdef CFG_USE_ERRORHOOK
  exit_errorhook:
	x_nested_lock_os_int();
#ifdef CFG_USE_PARAMETERACCESS
	_errorhook_par1.mask = Mask;
#endif /* CFG_USE_PARAMETERACCESS */
	call_errorhook(ercd, OSServiceId_ClearEvent);
	goto d_exit_no_errorhook;
#endif /* CFG_USE_ERRORHOOK */
}

#endif /* TOPPERS_ClearEvent */

/*
 *  ���٥�Ȥξ��ֻ���
 */
#ifdef TOPPERS_GetEvent

StatusType
GetEvent(TaskType TaskID, EventMaskRefType Event)
{
	StatusType	ercd = E_OK;
	TCB			*p_tcb;

	LOG_GETEVT_ENTER(TaskID);
	CHECK_DISABLEDINT();
	CHECK_CALLEVEL(CALLEVEL_GETEVENT);
	CHECK_ID(TaskID < tnum_task);
	CHECK_ACCESS(TaskID < tnum_exttask);
	CHECK_PARAM_POINTER(Event);
	p_tcb = get_tcb(TaskID);

	x_nested_lock_os_int();

	/* �оݥ��������ٻ߾��֤ξ��ϥ��顼�Ȥ��� */
	D_CHECK_STATE((p_tcb->tstat != SUSPENDED) || (p_tcb == p_runtsk));

	*Event = p_tcb->curevt;

  d_exit_no_errorhook:
	x_nested_unlock_os_int();
  exit_no_errorhook:
	LOG_GETEVT_LEAVE(ercd, TaskID, Event);
	return(ercd);

#ifdef CFG_USE_ERRORHOOK
  exit_errorhook:
	x_nested_lock_os_int();
  d_exit_errorhook:
#ifdef CFG_USE_PARAMETERACCESS
	_errorhook_par1.tskid = TaskID;
	_errorhook_par2.p_mask = Event;
#endif /* CFG_USE_PARAMETERACCESS */
	call_errorhook(ercd, OSServiceId_GetEvent);
	goto d_exit_no_errorhook;
#endif /* CFG_USE_ERRORHOOK */
}

#endif /* TOPPERS_GetEvent */

/*
 *  ���٥���Ԥ�
 */
#ifdef TOPPERS_WaitEvent

StatusType
WaitEvent(EventMaskType Mask)
{
	StatusType ercd = E_OK;

	LOG_WAIEVT_ENTER(p_runtsk, Mask);
	CHECK_DISABLEDINT();
	CHECK_CALLEVEL(CALLEVEL_WAITEVENT);
	CHECK_ACCESS(TSKID(p_runtsk) < tnum_exttask);
	CHECK_RESOURCE(p_runtsk->p_lastrescb == NULL);

	x_nested_lock_os_int();
	if ((p_runtsk->curevt & Mask) == EVTMASK_NONE) {
		p_runtsk->curpri = p_runtsk->p_tinib->inipri;
		p_runtsk->tstat = WAITING;
		LOG_TSKSTAT(p_runtsk);
		p_runtsk->waievt = Mask;
		make_non_runnable();
		dispatch();
		p_runtsk->curpri = p_runtsk->p_tinib->exepri;
	}

  d_exit_no_errorhook:
	x_nested_unlock_os_int();
  exit_no_errorhook:
	LOG_WAIEVT_LEAVE(ercd);
	return(ercd);

#ifdef CFG_USE_ERRORHOOK
  exit_errorhook:
	x_nested_lock_os_int();
#ifdef CFG_USE_PARAMETERACCESS
	_errorhook_par1.mask = Mask;
#endif /* CFG_USE_PARAMETERACCESS */
	call_errorhook(ercd, OSServiceId_WaitEvent);
	goto d_exit_no_errorhook;
#endif /* CFG_USE_ERRORHOOK */
}

#endif /* TOPPERS_WaitEvent */

/*
 *  ��λ�������ѥ��٥�ȤΥ��å�
 *
 *  ��OS����߶ػ߾��֤ǸƤФ��
 */
#ifdef TOPPERS_set_event_action

StatusType
set_event_action(TaskType TaskID, EventMaskType Mask)
{
	StatusType	ercd;
	TCB			*p_tcb;

	LOG_SETEVT_ENTER(TaskID, Mask);
	p_tcb = get_tcb(TaskID);

	D_CHECK_STATE(p_tcb->tstat != SUSPENDED);
	ercd = E_OK;

	p_tcb->curevt |= Mask;
	if ((p_tcb->curevt & p_tcb->waievt) != EVTMASK_NONE) {
		p_tcb->waievt = EVTMASK_NONE;
		(void) make_runnable(p_tcb);
	}

  d_exit_no_errorhook:
	LOG_SETEVT_LEAVE(ercd);
	return(ercd);

#ifdef CFG_USE_ERRORHOOK
  d_exit_errorhook:
#ifdef CFG_USE_PARAMETERACCESS
	_errorhook_par1.tskid = TaskID;
	_errorhook_par2.mask = Mask;
#endif /* CFG_USE_PARAMETERACCESS */
	call_errorhook(ercd, OSServiceId_SetEvent);
	goto d_exit_no_errorhook;
#endif /* CFG_USE_ERRORHOOK */
}

#endif /* TOPPERS_set_event_action */
