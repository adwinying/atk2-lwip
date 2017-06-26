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
 *  $Id: counter_manage.c 1801 2015-03-27 06:34:43Z t_ishikawa $
 */

/*
 *		�����󥿴����⥸�塼��
 */

#include "kernel_impl.h"
#include "check.h"
#include "counter.h"

/*
 *  �ȥ졼�����ޥ���Υǥե�������
 */
#ifndef LOG_INCCNT_ENTER
#define LOG_INCCNT_ENTER(cntid)
#endif /* LOG_INCCNT_ENTER */

#ifndef LOG_INCCNT_LEAVE
#define LOG_INCCNT_LEAVE(ercd)
#endif /* LOG_INCCNT_LEAVE */

#ifndef LOG_GETCNT_ENTER
#define LOG_GETCNT_ENTER(cntid)
#endif /* LOG_GETCNT_ENTER */

#ifndef LOG_GETCNT_LEAVE
#define LOG_GETCNT_LEAVE(ercd, p_val)
#endif /* LOG_GETCNT_LEAVE */

#ifndef LOG_GETEPS_ENTER
#define LOG_GETEPS_ENTER(cntid, p_val)
#endif /* LOG_GETEPS_ENTER */

#ifndef LOG_GETEPS_LEAVE
#define LOG_GETEPS_LEAVE(ercd, p_val, p_eval)
#endif /* LOG_GETEPS_LEAVE */

/*
 *  �����󥿤Υ��󥯥����
 */
#ifdef TOPPERS_IncrementCounter

StatusType
IncrementCounter(CounterType CounterID)
{
	StatusType ercd = E_OK;

	CHECK_DISABLEDINT();
	CHECK_CALLEVEL(CALLEVEL_INCREMENTCOUNTER);
	CHECK_ID(CounterID < tnum_counter);
	CHECK_ID(CounterID >= tnum_hardcounter);

	x_nested_lock_os_int();

	/*
	 *  �����󥿤Υ��󥯥����
	 *  ���顼�ξ���incr_counter_action�ǥ��顼�եå��ƤӽФ��Ƥ���Τǡ�
	 *  �����Ǥϡ����顼�եå���ƤӽФ��ʤ�
	 */
	ercd = incr_counter_action(CounterID);

  d_exit_no_errorhook:
	x_nested_unlock_os_int();
  exit_no_errorhook:
	return(ercd);

#ifdef CFG_USE_ERRORHOOK
  exit_errorhook:
	x_nested_lock_os_int();
#ifdef CFG_USE_PARAMETERACCESS
	_errorhook_par1.cntid = CounterID;
#endif /* CFG_USE_PARAMETERACCESS */
	call_errorhook(ercd, OSServiceId_IncrementCounter);
	goto d_exit_no_errorhook;
#endif /* CFG_USE_ERRORHOOK */
}

#endif /* TOPPERS_IncrementCounter */

/*
 *  �������ͤλ���
 */
#ifdef TOPPERS_GetCounterValue

StatusType
GetCounterValue(CounterType CounterID, TickRefType Value)
{
	StatusType	ercd = E_OK;
	CNTCB		*p_cntcb;

	TickType	curval;

	LOG_GETCNT_ENTER(CounterID);
	CHECK_DISABLEDINT();
	CHECK_CALLEVEL(CALLEVEL_GETCOUNTERVALUE);
	CHECK_ID(CounterID < tnum_counter);
	CHECK_PARAM_POINTER(Value);
	p_cntcb = get_cntcb(CounterID);

	/*
	 *  ���������Τ��ᡤ����ե�����졼����������ͤΣ��ܡܣ��ޤǥ������
	 *  ���åפ���Τǥ������ͤ������ͤ����礭�����������ͤ򸺻�����
	 *
	 *  *Value ��ľ�����Ƥ�褤��,�ɽ��ѿ����쥸�����˳����Ƥ��뤳��
	 *  �ˤ��®�٤���Ԥ��Ƥ���
	 */
	x_nested_lock_os_int();
	curval = get_curval(p_cntcb, CounterID);
	x_nested_unlock_os_int();

	if (curval > p_cntcb->p_cntinib->maxval) {
		curval -= (p_cntcb->p_cntinib->maxval + 1U);
	}
	*Value = curval;

  exit_no_errorhook:
	LOG_GETCNT_LEAVE(ercd, Value);
	return(ercd);

#ifdef CFG_USE_ERRORHOOK
  exit_errorhook:
	x_nested_lock_os_int();
#ifdef CFG_USE_PARAMETERACCESS
	_errorhook_par1.cntid = CounterID;
	_errorhook_par2.p_val = Value;
#endif /* CFG_USE_PARAMETERACCESS */
	call_errorhook(ercd, OSServiceId_GetCounterValue);
	x_nested_unlock_os_int();
	goto exit_no_errorhook;
#endif /* CFG_USE_ERRORHOOK */
}

#endif /* TOPPERS_GetCounterValue */

/*
 *  �вᥫ�����ͤλ���
 */
#ifdef TOPPERS_GetElapsedValue

StatusType
GetElapsedValue(CounterType CounterID, TickRefType Value, TickRefType ElapsedValue)
{
	StatusType	ercd = E_OK;
	CNTCB		*p_cntcb;

	TickType	curval;

	LOG_GETEPS_ENTER(CounterID, Value);
	CHECK_DISABLEDINT();
	CHECK_CALLEVEL(CALLEVEL_GETELAPSEDVALUE);
	CHECK_ID(CounterID < tnum_counter);
	CHECK_PARAM_POINTER(Value);
	CHECK_PARAM_POINTER(ElapsedValue);
	p_cntcb = get_cntcb(CounterID);

	CHECK_VALUE(*Value <= p_cntcb->p_cntinib->maxval);

	/*
	 *  ���������Τ��ᡤ����ե�����졼����������ͤΣ��ܡܣ��ޤǥ������
	 *  ���åפ���Τǥ������ͤ������ͤ����礭�����������ͤ򸺻�����
	 */
	x_nested_lock_os_int();
	curval = get_curval(p_cntcb, CounterID);
	x_nested_unlock_os_int();

	if (curval > p_cntcb->p_cntinib->maxval) {
		curval -= (p_cntcb->p_cntinib->maxval + 1U);
	}
	*ElapsedValue = diff_tick(curval, *Value, p_cntcb->p_cntinib->maxval);
	*Value = curval;

  exit_no_errorhook:
	LOG_GETEPS_LEAVE(ercd, Value, ElapsedValue);
	return(ercd);

#ifdef CFG_USE_ERRORHOOK
  exit_errorhook:
	x_nested_lock_os_int();
#ifdef CFG_USE_PARAMETERACCESS
	_errorhook_par1.cntid = CounterID;
	_errorhook_par2.p_val = Value;
	_errorhook_par3.p_eval = ElapsedValue;
#endif /* CFG_USE_PARAMETERACCESS */
	call_errorhook(ercd, OSServiceId_GetElapsedValue);
	x_nested_unlock_os_int();
	goto exit_no_errorhook;
#endif /* CFG_USE_ERRORHOOK */
}

#endif /* TOPPERS_GetElapsedValue */

/*
 *  �ϡ��ɥ�������������λ����
 *
 *  ����ߥ롼������¹Ԥ����
 */
#ifdef TOPPERS_notify_hardware_counter

void
notify_hardware_counter(CounterType cntid)
{
	CNTCB *p_cntcb;

	p_cntcb = get_cntcb(cntid);

	/* ��������λ�������OS����ߤ�ػ� */
	x_nested_lock_os_int();

	/*
	 *  �ϡ��ɥ����������󥿤��б�����C2ISR����ư�����ݤˡ�
	 *  ������׵�Υ��ꥢ������¹Ԥ���
	 */
	(hwcntinib_table[cntid].intclear)();

	expire_process(p_cntcb, cntid);

	x_nested_unlock_os_int();
}

#endif /* TOPPERS_notify_hardware_counter */

/*
 *  �����󥿤Υ��󥯥����
 *
 *  ������߶ػ߾��֤ǸƤФ��
 */
#ifdef TOPPERS_incr_counter_action

StatusType
incr_counter_action(CounterType CounterID)
{
	StatusType	ercd = E_OK;
	TickType	newval;
	CNTCB		*p_cntcb;

	LOG_INCCNT_ENTER(CounterID);
	p_cntcb = get_cntcb(CounterID);

	/*
	 *  �����󥿤������(IncrementCounter�Υͥ��ȡˤξ�票�顼
	 *  ���ȼ�����
	 */
	D_CHECK_STATE(p_cntcb->cstat == CS_NULL);

	p_cntcb->cstat = CS_DOING;

	newval = add_tick(p_cntcb->curval, 1U, p_cntcb->p_cntinib->maxval2);

	p_cntcb->curval = newval;

	expire_process(p_cntcb, CounterID);

	p_cntcb->cstat = CS_NULL;

  d_exit_no_errorhook:
	LOG_INCCNT_LEAVE(ercd);
	return(ercd);

#ifdef CFG_USE_ERRORHOOK
  d_exit_errorhook:
#ifdef CFG_USE_PARAMETERACCESS
	_errorhook_par1.cntid = CounterID;
#endif /* CFG_USE_PARAMETERACCESS */
	call_errorhook(ercd, OSServiceId_IncrementCounter);
	goto d_exit_no_errorhook;
#endif /* CFG_USE_ERRORHOOK */
}

#endif /* TOPPERS_incr_counter_action */
