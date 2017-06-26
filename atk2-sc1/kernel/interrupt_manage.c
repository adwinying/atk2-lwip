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
 *  $Id: interrupt_manage.c 1801 2015-03-27 06:34:43Z t_ishikawa $
 */

/*
 *		����ߴ����⥸�塼��
 */

#include "kernel_impl.h"
#include "check.h"
#include "interrupt.h"

/*
 *  �ȥ졼�����ޥ���Υǥե�������
 */
#ifndef LOG_DISINT_ENTER
#define LOG_DISINT_ENTER()
#endif /* LOG_DISINT_ENTER */

#ifndef LOG_DISINT_LEAVE
#define LOG_DISINT_LEAVE()
#endif /* LOG_DISINT_LEAVE */

#ifndef LOG_ENAINT_ENTER
#define LOG_ENAINT_ENTER()
#endif /* LOG_ENAINT_ENTER */

#ifndef LOG_ENAINT_LEAVE
#define LOG_ENAINT_LEAVE()
#endif /* LOG_ENAINT_LEAVE */

#ifndef LOG_SUSALL_ENTER
#define LOG_SUSALL_ENTER()
#endif /* LOG_SUSALL_ENTER */

#ifndef LOG_SUSALL_LEAVE
#define LOG_SUSALL_LEAVE()
#endif /* LOG_SUSALL_LEAVE */

#ifndef LOG_RSMALL_ENTER
#define LOG_RSMALL_ENTER()
#endif /* LOG_RSMALL_ENTER */

#ifndef LOG_RSMALL_LEAVE
#define LOG_RSMALL_LEAVE()
#endif /* LOG_RSMALL_LEAVE */

#ifndef LOG_SUSOSI_ENTER
#define LOG_SUSOSI_ENTER()
#endif /* LOG_SUSOSI_ENTER */

#ifndef LOG_SUSOSI_LEAVE
#define LOG_SUSOSI_LEAVE()
#endif /* LOG_SUSOSI_LEAVE */

#ifndef LOG_RSMOSI_ENTER
#define LOG_RSMOSI_ENTER()
#endif /* LOG_RSMOSI_ENTER */

#ifndef LOG_RSMOSI_LEAVE
#define LOG_RSMOSI_LEAVE()
#endif /* LOG_RSMOSI_LEAVE */

#ifndef LOG_GETISRID_ENTER
#define LOG_GETISRID_ENTER()
#endif /* LOG_GETISRID_ENTER */

#ifndef LOG_GETISRID_LEAVE
#define LOG_GETISRID_LEAVE(ercd)
#endif /* LOG_GETISRID_LEAVE */

/*
 *  ���٤Ƥγ���ߤζػߡʹ�®�ʰ��ǡ�
 *  ������߶ػ߾��֤ذܹ�
 */
#ifdef TOPPERS_DisableAllInterrupts

#ifndef OMIT_STANDARD_DISALLINT

void
DisableAllInterrupts(void)
{
	LOG_DISINT_ENTER();
	if ((callevel_stat & (TSYS_DISALLINT | TSYS_SUSALLINT | TSYS_SUSOSINT)) == TSYS_NULL) {
		x_lock_all_int();
		ENTER_CALLEVEL(TSYS_DISALLINT);
	}
	LOG_DISINT_LEAVE();
}

#endif /* OMIT_STANDARD_DISALLINT */

#endif /* TOPPERS_DisableAllInterrupts */

/*
 *  ���٤Ƥγ���ߤε��ġʹ�®�ʰ��ǡ�
 *  ������߶ػ߾��֤�������
 */
#ifdef TOPPERS_EnableAllInterrupts

#ifndef OMIT_STANDARD_DISALLINT

void
EnableAllInterrupts(void)
{
	LOG_ENAINT_ENTER();
	if ((callevel_stat & (TSYS_SUSALLINT | TSYS_SUSOSINT)) == TSYS_NULL) {
		if ((callevel_stat & TSYS_DISALLINT) != TSYS_NULL) {
			LEAVE_CALLEVEL(TSYS_DISALLINT);
			x_unlock_all_int();
		}
	}
	LOG_ENAINT_LEAVE();
}

#endif /* OMIT_STANDARD_DISALLINT */

#endif /* TOPPERS_EnableAllInterrupts */

/*
 *  ������߶ػ�
 *  CPU���Ƥγ���ߤ��оݤγ���߶ػ�(�ͥ��ȥ������ͭ��)
 */
#ifdef TOPPERS_SuspendAllInterrupts

void
SuspendAllInterrupts(void)
{
#ifdef CFG_USE_ERRORHOOK
	StatusType ercd;
#endif /* CFG_USE_ERRORHOOK */

	LOG_SUSALL_ENTER();
	S_N_CHECK_DISALLINT();
	/* �ͥ��Ȳ���ξ����Ķ�� */
	S_N_CHECK_LIMIT(sus_all_cnt != UINT8_INVALID);

	if (sus_all_cnt == 0U) {
		x_lock_all_int();
		ENTER_CALLEVEL(TSYS_SUSALLINT);
	}

	sus_all_cnt++;
	sus_all_cnt_ctx++;

  exit_no_errorhook:
	LOG_SUSALL_LEAVE();
	return;

#ifdef CFG_USE_ERRORHOOK
  exit_errorhook:
	if (kerflg != FALSE) {
		x_nested_lock_os_int();
		call_errorhook(ercd, OSServiceId_SuspendAllInterrupts);
		x_nested_unlock_os_int();
		goto exit_no_errorhook;
	}
#endif /* CFG_USE_ERRORHOOK */
}

#endif /* TOPPERS_SuspendAllInterrupts */

/*
 *  ������߶ػ߲��
 *  CPU���Ƥγ���ߤ��оݤγ���ߵ���(�ͥ��ȥ������ͭ��)
 */
#ifdef TOPPERS_ResumeAllInterrupts

void
ResumeAllInterrupts(void)
{
#ifdef CFG_USE_ERRORHOOK
	StatusType ercd;
#endif /* CFG_USE_ERRORHOOK */

	LOG_RSMALL_ENTER();
	S_N_CHECK_DISALLINT();
	S_N_CHECK_STATE(sus_all_cnt_ctx != 0U);

	sus_all_cnt--;
	sus_all_cnt_ctx--;

	if (sus_all_cnt == 0U) {
		LEAVE_CALLEVEL(TSYS_SUSALLINT);
		x_unlock_all_int();
	}

  exit_no_errorhook:
	LOG_RSMALL_LEAVE();
	return;

#ifdef CFG_USE_ERRORHOOK
  exit_errorhook:
	if (kerflg != FALSE) {
		x_nested_lock_os_int();
		call_errorhook(ercd, OSServiceId_ResumeAllInterrupts);
		x_nested_unlock_os_int();
		goto exit_no_errorhook;
	}
#endif /* CFG_USE_ERRORHOOK */
}

#endif /* TOPPERS_ResumeAllInterrupts */

/*
 *  OS����ߤζػ�
 *  C2ISR���оݤγ���߶ػ�(�ͥ��ȥ������ͭ��)
 */
#ifdef TOPPERS_SuspendOSInterrupts

void
SuspendOSInterrupts(void)
{
#ifdef CFG_USE_ERRORHOOK
	StatusType ercd;
#endif /* CFG_USE_ERRORHOOK */

	LOG_SUSOSI_ENTER();
	S_N_CHECK_DISALLINT();
	/* �ͥ��Ȳ���ξ����Ķ�� */
	S_N_CHECK_LIMIT(sus_os_cnt != UINT8_INVALID);

	if (sus_os_cnt == 0U) {
		x_suspend_lock_os_int();
		ENTER_CALLEVEL(TSYS_SUSOSINT);
	}

	sus_os_cnt++;
	sus_os_cnt_ctx++;

  exit_no_errorhook:
	LOG_SUSOSI_LEAVE();
	return;

#ifdef CFG_USE_ERRORHOOK
  exit_errorhook:
	x_nested_lock_os_int();
	call_errorhook(ercd, OSServiceId_SuspendOSInterrupts);
	x_nested_unlock_os_int();
	goto exit_no_errorhook;
#endif /* CFG_USE_ERRORHOOK */
}

#endif /* TOPPERS_SuspendOSInterrupts */

/*
 *  OS����߶ػ߲��
 *  C2ISR���оݤγ���ߵ���(�ͥ��ȥ������ͭ��)
 */
#ifdef TOPPERS_ResumeOSInterrupts

void
ResumeOSInterrupts(void)
{
#ifdef CFG_USE_ERRORHOOK
	StatusType ercd;
#endif /* CFG_USE_ERRORHOOK */

	LOG_RSMOSI_ENTER();
	S_N_CHECK_DISALLINT();
	S_N_CHECK_STATE(sus_os_cnt_ctx != 0U);

	sus_os_cnt--;
	sus_os_cnt_ctx--;

	if (sus_os_cnt == 0U) {
		LEAVE_CALLEVEL(TSYS_SUSOSINT);
		x_resume_unlock_os_int();
	}

  exit_no_errorhook:
	LOG_RSMOSI_LEAVE();
	return;

#ifdef CFG_USE_ERRORHOOK
  exit_errorhook:
	x_nested_lock_os_int();
	call_errorhook(ercd, OSServiceId_ResumeOSInterrupts);
	x_nested_unlock_os_int();
	goto exit_no_errorhook;
#endif /* CFG_USE_ERRORHOOK */
}

#endif /* TOPPERS_ResumeOSInterrupts */

/*
 *  C2ISR ID�μ���
 */
#ifdef TOPPERS_GetISRID

ISRType
GetISRID(void)
{
	ISRType		isrid;
#if defined(CFG_USE_EXTENDEDSTATUS) || defined(CFG_USE_ERRORHOOK)
	StatusType	ercd;
#endif /* CFG_USE_EXTENDEDSTATUS || CFG_USE_ERRORHOOK */

	LOG_GETISRID_ENTER();
	CHECK_CALLEVEL(CALLEVEL_GETISRID);

	isrid = (p_runisr == NULL) ? INVALID_ISR : ISR2ID(p_runisr);

  exit_finish:
	LOG_GETISRID_LEAVE(isrid);
	return(isrid);

#ifdef CFG_USE_ERRORHOOK
  exit_errorhook:
	x_nested_lock_os_int();
	/*
	 *  ���顼ȯ������INVALID_ISRID���֤뤬�����顼��ȯ�������Τ��¹����
	 *  C2ISR��¸�ߤ��ʤ��Τ����̤��뤿�ᡤ���顼�եå���Ƥ�
	 */
	call_errorhook(ercd, OSServiceId_GetISRID);
	x_nested_unlock_os_int();
#endif /* CFG_USE_ERRORHOOK */

  exit_no_errorhook:
	isrid = INVALID_ISR;
	goto exit_finish;
}

#endif /* TOPPERS_GetISRID */
