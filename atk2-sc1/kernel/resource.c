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
 *  $Id: resource.c 1801 2015-03-27 06:34:43Z t_ishikawa $
 */

/*
 *		�꥽���������⥸�塼��
 */

#include "kernel_impl.h"
#include "check.h"
#include "task.h"
#include "interrupt.h"
#include "resource.h"

/*
 *  �ȥ졼�����ޥ���Υǥե�������
 */
#ifndef LOG_GETRES_ENTER
#define LOG_GETRES_ENTER(resid)
#endif /* LOG_GETRES_ENTER */

#ifndef LOG_GETRES_LEAVE
#define LOG_GETRES_LEAVE(ercd)
#endif /* LOG_GETRES_LEAVE */

#ifndef LOG_RELRES_ENTER
#define LOG_RELRES_ENTER(resid)
#endif /* LOG_RELRES_ENTER */

#ifndef LOG_RELRES_LEAVE
#define LOG_RELRES_LEAVE(ercd)
#endif /* LOG_RELRES_LEAVE */

/*
 *  �꥽����������ǽ�ν����
 */
#ifdef TOPPERS_resource_initialize

void
resource_initialize(void)
{
	ResourceType	i;
	RESCB			*p_rescb;

	for (i = 0U; i < tnum_stdresource; i++) {
		p_rescb = &(rescb_table[i]);
		p_rescb->p_resinib = &(resinib_table[i]);
		p_rescb->lockflg = FALSE;
	}
}

#endif /* TOPPERS_resource_initialize */

/*
 *  �꥽�����γ���
 */
#ifdef TOPPERS_GetResource

StatusType
GetResource(ResourceType ResID)
{
	StatusType		ercd = E_OK;
	PriorityType	ceilpri, curpri;
	RESCB			*p_rescb;

	LOG_GETRES_ENTER(ResID);
	CHECK_DISABLEDINT();
	CHECK_CALLEVEL(CALLEVEL_GETRESOURCE);
	CHECK_ID(ResID < tnum_stdresource);
	p_rescb = get_rescb(ResID);

	ceilpri = p_rescb->p_resinib->ceilpri;
	if (callevel_stat == TCL_TASK) {
		CHECK_ACCESS(p_runtsk->p_tinib->inipri >= ceilpri);

		x_nested_lock_os_int();
		D_CHECK_ACCESS(p_rescb->lockflg == FALSE);
		curpri = p_runtsk->curpri;
		p_rescb->prevpri = curpri;
		p_rescb->lockflg = TRUE;
		p_rescb->p_prevrescb = p_runtsk->p_lastrescb;
		p_runtsk->p_lastrescb = p_rescb;
		if (ceilpri < curpri) {
			p_runtsk->curpri = ceilpri;
			if (ceilpri <= TPRI_MINISR) {
				x_set_ipm(ceilpri);
			}
		}
	}
	else {
		CHECK_ACCESS(GET_INTPRI(p_runisr) >= ceilpri);

		x_nested_lock_os_int();
		D_CHECK_ACCESS(p_rescb->lockflg == FALSE);
		curpri = x_get_ipm();
		p_rescb->prevpri = curpri;
		p_rescb->lockflg = TRUE;
		p_rescb->p_prevrescb = p_runisr->p_lastrescb;
		p_runisr->p_lastrescb = p_rescb;
		if (ceilpri < curpri) {
			x_set_ipm(ceilpri);
		}
	}

  d_exit_no_errorhook:
	x_nested_unlock_os_int();
  exit_no_errorhook:
	LOG_GETRES_LEAVE(ercd);
	return(ercd);

#ifdef CFG_USE_ERRORHOOK
  exit_errorhook:
	x_nested_lock_os_int();
  d_exit_errorhook:
#ifdef CFG_USE_PARAMETERACCESS
	_errorhook_par1.resid = ResID;
#endif /* CFG_USE_PARAMETERACCESS */
	call_errorhook(ercd, OSServiceId_GetResource);
	goto d_exit_no_errorhook;
#endif /* CFG_USE_ERRORHOOK */
}

#endif /* TOPPERS_GetResource */

/*
 *  �꥽�������ֵ�
 */
#ifdef TOPPERS_ReleaseResource

StatusType
ReleaseResource(ResourceType ResID)
{
	StatusType	ercd = E_OK;
	RESCB		*p_rescb;

	LOG_RELRES_ENTER(ResID);
	CHECK_DISABLEDINT();
	CHECK_CALLEVEL(CALLEVEL_RELEASERESOURCE);
	CHECK_ID(ResID < tnum_stdresource);
	p_rescb = get_rescb(ResID);

	if (callevel_stat == TCL_TASK) {
		CHECK_NOFUNC(p_runtsk->p_lastrescb == p_rescb);

		x_nested_lock_os_int();
		if (p_rescb->prevpri <= TPRI_MINISR) {
			x_set_ipm(p_rescb->prevpri);
		}
		else {
			if (p_runtsk->curpri <= TPRI_MINISR) {
				x_set_ipm((PriorityType) TIPM_ENAALL);
			}
		}
		p_runtsk->curpri = p_rescb->prevpri;
		p_runtsk->p_lastrescb = p_rescb->p_prevrescb;
		p_rescb->lockflg = FALSE;
		if (p_runtsk->curpri > nextpri) {
			preempt();
			dispatch();
		}
	}
	else {
		CHECK_NOFUNC(p_runisr->p_lastrescb == p_rescb);

		x_nested_lock_os_int();
		x_set_ipm(p_rescb->prevpri);
		p_runisr->p_lastrescb = p_rescb->p_prevrescb;
		p_rescb->lockflg = FALSE;
	}

  d_exit_no_errorhook:
	x_nested_unlock_os_int();
  exit_no_errorhook:
	LOG_RELRES_LEAVE(ercd);
	return(ercd);

#ifdef CFG_USE_ERRORHOOK
  exit_errorhook:
	x_nested_lock_os_int();
#ifdef CFG_USE_PARAMETERACCESS
	_errorhook_par1.resid = ResID;
#endif /* CFG_USE_PARAMETERACCESS */
	call_errorhook(ercd, OSServiceId_ReleaseResource);
	goto d_exit_no_errorhook;
#endif /* CFG_USE_ERRORHOOK */
}

#endif /* TOPPERS_ReleaseResource */
