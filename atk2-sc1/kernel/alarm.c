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
 *  $Id: alarm.c 1801 2015-03-27 06:34:43Z t_ishikawa $
 */

/*
 *		���顼������⥸�塼��
 */

#include "kernel_impl.h"
#include "check.h"
#include "alarm.h"

/*
 *  �ȥ졼�����ޥ���Υǥե�������
 */
#ifndef LOG_GETALB_ENTER
#define LOG_GETALB_ENTER(almid)
#endif /* LOG_GETALB_ENTER */

#ifndef LOG_GETALB_LEAVE
#define LOG_GETALB_LEAVE(ercd, info)
#endif /* LOG_GETALB_LEAVE */

#ifndef LOG_GETALM_ENTER
#define LOG_GETALM_ENTER(almid)
#endif /* LOG_GETALM_ENTER */

#ifndef LOG_GETALM_LEAVE
#define LOG_GETALM_LEAVE(ercd, p_tick)
#endif /* LOG_GETALM_LEAVE */

#ifndef LOG_SETREL_ENTER
#define LOG_SETREL_ENTER(almid, incr, cycle)
#endif /* LOG_SETREL_ENTER */

#ifndef LOG_SETREL_LEAVE
#define LOG_SETREL_LEAVE(ercd)
#endif /* LOG_SETREL_LEAVE */

#ifndef LOG_SETABS_ENTER
#define LOG_SETABS_ENTER(almid, start, cycle)
#endif /* LOG_SETABS_ENTER */

#ifndef LOG_SETABS_LEAVE
#define LOG_SETABS_LEAVE(ercd)
#endif /* LOG_SETABS_LEAVE */

#ifndef LOG_CANALM_ENTER
#define LOG_CANALM_ENTER(almid)
#endif /* LOG_CANALM_ENTER */

#ifndef LOG_CANALM_LEAVE
#define LOG_CANALM_LEAVE(ercd)
#endif /* LOG_CANALM_LEAVE */

#ifndef LOG_ALM_ENTER
#define LOG_ALM_ENTER(p_cntexpinfo)
#endif /* LOG_ALM_ENTER */

#ifndef LOG_ALM_LEAVE
#define LOG_ALM_LEAVE(p_cntexpinfo)
#endif /* LOG_ALM_LEAVE */

/*
 *  ���顼�ൡǽ�ν����
 */
#ifdef TOPPERS_alarm_initialize

void
alarm_initialize(void)
{
	AlarmType	i;
	ALMCB		*p_almcb;

	for (i = 0U; i < tnum_alarm; i++) {
		p_almcb = &(almcb_table[i]);

		p_almcb->p_alminib = &(alminib_table[i]);
		(p_almcb->cntexpinfo).expirefunc = &alarm_expire;
		if ((p_almcb->p_alminib->autosta & ((AppModeType) 1 << appmodeid)) != APPMODE_NONE) {
			if ((p_almcb->p_alminib->actatr & ABSOLUTE) == ABSOLUTE) {
				/*
				 *  ���л��֤ε�ư
				 *  ��λ���֤�0�ξ�硤���μ�����0�Υ����ߥ󥰤Ȥʤ�
				 *  ��get_abstick�˹�θ�Ѥߡ�
				 */
				(p_almcb->cntexpinfo).expiretick =
					get_abstick(p_almcb->p_alminib->p_cntcb, p_almcb->p_alminib->almval);
			}
			else {
				/* ���л��֤ε�ư */
				(p_almcb->cntexpinfo).expiretick =
					get_reltick(p_almcb->p_alminib->p_cntcb, p_almcb->p_alminib->almval);
			}
			p_almcb->cycle = p_almcb->p_alminib->cycle;

			insert_cnt_expr_que(&(p_almcb->cntexpinfo), p_almcb->p_alminib->p_cntcb);
		}
		else {
			queue_initialize(&(p_almcb->cntexpinfo.cntexpque));
		}
	}
}

#endif /* TOPPERS_alarm_initialize */

/*
 *  ���顼�����μ���
 */
#ifdef TOPPERS_GetAlarmBase

StatusType
GetAlarmBase(AlarmType AlarmID, AlarmBaseRefType Info)
{
	StatusType	ercd = E_OK;
	ALMCB		*p_almcb;
	CNTCB		*p_cntcb;

	LOG_GETALB_ENTER(AlarmID);
	CHECK_DISABLEDINT();
	CHECK_CALLEVEL(CALLEVEL_GETALARMBASE);
	CHECK_ID(AlarmID < tnum_alarm);
	CHECK_PARAM_POINTER(Info);
	p_almcb = get_almcb(AlarmID);
	p_cntcb = p_almcb->p_alminib->p_cntcb;

	Info->maxallowedvalue = p_cntcb->p_cntinib->maxval;
	Info->ticksperbase = p_cntcb->p_cntinib->tickbase;
	Info->mincycle = p_cntcb->p_cntinib->mincyc;

  exit_no_errorhook:
	LOG_GETALB_LEAVE(ercd, Info);
	return(ercd);

#ifdef CFG_USE_ERRORHOOK
  exit_errorhook:
	x_nested_lock_os_int();
#ifdef CFG_USE_PARAMETERACCESS
	_errorhook_par1.almid = AlarmID;
	_errorhook_par2.p_info = Info;
#endif /* CFG_USE_PARAMETERACCESS */
	call_errorhook(ercd, OSServiceId_GetAlarmBase);
	x_nested_unlock_os_int();
	goto exit_no_errorhook;
#endif /* CFG_USE_ERRORHOOK */
}

#endif /* TOPPERS_GetAlarmBase */

/*
 *  ���顼��ξ��ֻ���
 */
#ifdef TOPPERS_GetAlarm

StatusType
GetAlarm(AlarmType AlarmID, TickRefType Tick)
{
	StatusType	ercd = E_OK;
	TickType	curval;
	ALMCB		*p_almcb;
	CNTCB		*p_cntcb;

	LOG_GETALM_ENTER(AlarmID);
	CHECK_DISABLEDINT();
	CHECK_CALLEVEL(CALLEVEL_GETALARM);
	CHECK_ID(AlarmID < tnum_alarm);
	CHECK_PARAM_POINTER(Tick);
	p_almcb = get_almcb(AlarmID);
	p_cntcb = p_almcb->p_alminib->p_cntcb;

	x_nested_lock_os_int();
	S_D_CHECK_NOFUNC(queue_empty(&(p_almcb->cntexpinfo.cntexpque)) == FALSE);

	/*
	 *  �����󥿤θ����ͤ����
	 *  �ϡ��ɥ����������󥿤ξ�硤������λ���Ƥ����ǽ��������
	 */
	curval = get_curval(p_cntcb, CNTID(p_cntcb));

	*Tick = diff_tick(p_almcb->cntexpinfo.expiretick, curval, p_cntcb->p_cntinib->maxval2);

  d_exit_no_errorhook:
	x_nested_unlock_os_int();
  exit_no_errorhook:
	LOG_GETALM_LEAVE(ercd, Tick);
	return(ercd);

#ifdef CFG_USE_ERRORHOOK
  exit_errorhook:
	x_nested_lock_os_int();
  d_exit_errorhook:
#ifdef CFG_USE_PARAMETERACCESS
	_errorhook_par1.almid = AlarmID;
	_errorhook_par2.p_tick = Tick;
#endif /* CFG_USE_PARAMETERACCESS */
	call_errorhook(ercd, OSServiceId_GetAlarm);
	goto d_exit_no_errorhook;
#endif /* CFG_USE_ERRORHOOK */
}

#endif /* TOPPERS_GetAlarm */

/*
 *  ���顼�������������͡�
 */
#ifdef TOPPERS_SetRelAlarm

StatusType
SetRelAlarm(AlarmType AlarmID, TickType increment, TickType cycle)
{
	StatusType	ercd = E_OK;
#if defined(CFG_USE_EXTENDEDSTATUS)
	TickType	maxval;
#endif /* CFG_USE_EXTENDEDSTATUS */
	ALMCB		*p_almcb;
	CNTCB		*p_cntcb;

	LOG_SETREL_ENTER(AlarmID, increment, cycle);
	CHECK_DISABLEDINT();
	CHECK_CALLEVEL(CALLEVEL_SETRELALARM);
	CHECK_ID(AlarmID < tnum_alarm);
	p_almcb = get_almcb(AlarmID);
	p_cntcb = p_almcb->p_alminib->p_cntcb;

#if defined(CFG_USE_EXTENDEDSTATUS)
	maxval = p_cntcb->p_cntinib->maxval;
	CHECK_VALUE((0U < increment) && (increment <= maxval));
	CHECK_VALUE((cycle == 0U)
				|| ((p_cntcb->p_cntinib->mincyc <= cycle) && (cycle <= maxval)));
#endif /* CFG_USE_EXTENDEDSTATUS */

	x_nested_lock_os_int();
	S_D_CHECK_STATE(queue_empty(&(p_almcb->cntexpinfo.cntexpque)) != FALSE);

	p_almcb->cntexpinfo.expiretick = get_reltick(p_cntcb, increment);
	p_almcb->cycle = cycle;

	insert_cnt_expr_que(&(p_almcb->cntexpinfo), p_cntcb);

  d_exit_no_errorhook:
	x_nested_unlock_os_int();
  exit_no_errorhook:
	LOG_SETREL_LEAVE(ercd);
	return(ercd);

#ifdef CFG_USE_ERRORHOOK
  exit_errorhook:
	x_nested_lock_os_int();
  d_exit_errorhook:
#ifdef CFG_USE_PARAMETERACCESS
	_errorhook_par1.almid = AlarmID;
	_errorhook_par2.incr = increment;
	_errorhook_par3.cycle = cycle;
#endif /* CFG_USE_PARAMETERACCESS */
	call_errorhook(ercd, OSServiceId_SetRelAlarm);
	goto d_exit_no_errorhook;
#endif /* CFG_USE_ERRORHOOK */
}

#endif /* TOPPERS_SetRelAlarm */

/*
 *  ���顼�������������͡�
 */
#ifdef TOPPERS_SetAbsAlarm

StatusType
SetAbsAlarm(AlarmType AlarmID, TickType start, TickType cycle)
{
	StatusType	ercd = E_OK;
#if defined(CFG_USE_EXTENDEDSTATUS)
	TickType	maxval;
#endif /* CFG_USE_EXTENDEDSTATUS */
	ALMCB		*p_almcb;
	CNTCB		*p_cntcb;

	LOG_SETABS_ENTER(AlarmID, start, cycle);
	CHECK_DISABLEDINT();
	CHECK_CALLEVEL(CALLEVEL_SETABSALARM);
	CHECK_ID(AlarmID < tnum_alarm);
	p_almcb = get_almcb(AlarmID);
	p_cntcb = p_almcb->p_alminib->p_cntcb;

#if defined(CFG_USE_EXTENDEDSTATUS)
	maxval = p_cntcb->p_cntinib->maxval;
	CHECK_VALUE(start <= maxval);
	CHECK_VALUE((cycle == 0U)
				|| ((p_cntcb->p_cntinib->mincyc <= cycle) && (cycle <= maxval)));
#endif /* CFG_USE_EXTENDEDSTATUS */

	x_nested_lock_os_int();
	S_D_CHECK_STATE(queue_empty(&(p_almcb->cntexpinfo.cntexpque)) != FALSE);

	p_almcb->cntexpinfo.expiretick = get_abstick(p_cntcb, start);
	p_almcb->cycle = cycle;

	insert_cnt_expr_que(&(p_almcb->cntexpinfo), p_cntcb);

  d_exit_no_errorhook:
	x_nested_unlock_os_int();
  exit_no_errorhook:
	LOG_SETABS_LEAVE(ercd);
	return(ercd);

#ifdef CFG_USE_ERRORHOOK
  exit_errorhook:
	x_nested_lock_os_int();
  d_exit_errorhook:
#ifdef CFG_USE_PARAMETERACCESS
	_errorhook_par1.almid = AlarmID;
	_errorhook_par2.start = start;
	_errorhook_par3.cycle = cycle;
#endif /* CFG_USE_PARAMETERACCESS */
	call_errorhook(ercd, OSServiceId_SetAbsAlarm);
	goto d_exit_no_errorhook;
#endif /* CFG_USE_ERRORHOOK */
}

#endif /* TOPPERS_SetAbsAlarm */

/*
 *  ���顼��Υ���󥻥�
 */
#ifdef TOPPERS_CancelAlarm

StatusType
CancelAlarm(AlarmType AlarmID)
{
	StatusType	ercd = E_OK;
	ALMCB		*p_almcb;

	LOG_CANALM_ENTER(AlarmID);
	CHECK_DISABLEDINT();
	CHECK_CALLEVEL(CALLEVEL_CANCELALARM);
	CHECK_ID(AlarmID < tnum_alarm);
	p_almcb = get_almcb(AlarmID);

	x_nested_lock_os_int();
	S_D_CHECK_NOFUNC(queue_empty(&(p_almcb->cntexpinfo.cntexpque)) == FALSE);

	delete_cnt_expr_que(&(p_almcb->cntexpinfo), p_almcb->p_alminib->p_cntcb);

  d_exit_no_errorhook:
	x_nested_unlock_os_int();
  exit_no_errorhook:
	LOG_CANALM_LEAVE(ercd);
	return(ercd);

#ifdef CFG_USE_ERRORHOOK
  exit_errorhook:
	x_nested_lock_os_int();
  d_exit_errorhook:
#ifdef CFG_USE_PARAMETERACCESS
	_errorhook_par1.almid = AlarmID;
#endif /* CFG_USE_PARAMETERACCESS */
	call_errorhook(ercd, OSServiceId_CancelAlarm);
	goto d_exit_no_errorhook;
#endif /* CFG_USE_ERRORHOOK */
}

#endif /* TOPPERS_CancelAlarm */

/*
 *  ���顼����λ�������������Ѵؿ�
 */
#ifdef TOPPERS_alarm_expire

void
alarm_expire(CNTEXPINFO *p_cntexpinfo, const CNTCB *p_cntcb)
{
	ALMCB *p_almcb;

	p_almcb = (ALMCB *) p_cntexpinfo;

	/* ��������λ���塼�ؤκ������ʼ������顼��ξ��� */
	if (p_almcb->cycle > 0U) {
		p_cntexpinfo->expiretick = add_tick(p_cntexpinfo->expiretick, p_almcb->cycle,
											p_cntcb->p_cntinib->maxval2);
		insert_cnt_expr_que(p_cntexpinfo, (CNTCB *) p_cntcb);
	}

	/*
	 *  ���顼�ॳ����Хå��Τ�OS������٥�Ǽ¹Ԥ���
	 *  ����ʳ��ϸƤӽФ����ν�����٥�Ǽ¹Ԥ���
	 *
	 *  ���顼�ॳ����Хå��ξ�硤����ߤ���Ĥ�����
	 *  �¹���Υ���ƥ����Ȥ�TCL_ALRMCBAK�ˤ���
	 */
	LOG_ALM_ENTER(p_almcb);
	if ((p_almcb->p_alminib->actatr & CALLBACK) == CALLBACK) {
		ENTER_CALLEVEL(TCL_ALRMCBAK);
	}

	/* ���顼����λ���������θƽФ� */
	(p_almcb->p_alminib->action)();

	if ((p_almcb->p_alminib->actatr & CALLBACK) == CALLBACK) {
		LEAVE_CALLEVEL(TCL_ALRMCBAK);
	}
	LOG_ALM_LEAVE(p_almcb);
}

#endif /* TOPPERS_alarm_expire */
