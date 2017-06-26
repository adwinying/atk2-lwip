/*
 *  TOPPERS ATK2
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *      Automotive Kernel Version 2
 *
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
 *  $Id: scheduletable.c 1801 2015-03-27 06:34:43Z t_ishikawa $
 */

/*
 *		�������塼��ơ��֥�����⥸�塼��
 */

#include "kernel_impl.h"
#include "check.h"
#include "scheduletable.h"

/*
 *  �ȥ졼�����ޥ���Υǥե�������
 */
#ifndef LOG_STASCHTBLREL_ENTER
#define LOG_STASCHTBLREL_ENTER(schtblid, offset)
#endif /* LOG_STASCHTBLREL_ENTER */

#ifndef LOG_STASCHTBLREL_LEAVE
#define LOG_STASCHTBLREL_LEAVE(ercd)
#endif /* LOG_STASCHTBLREL_LEAVE */

#ifndef LOG_STASCHTBLABS_ENTER
#define LOG_STASCHTBLABS_ENTER(schtblid, start)
#endif /* LOG_STASCHTBLABS_ENTER */

#ifndef LOG_STASCHTBLABS_LEAVE
#define LOG_STASCHTBLABS_LEAVE(ercd)
#endif /* LOG_STASCHTBLABS_LEAVE */

#ifndef LOG_STPSCHTBL_ENTER
#define LOG_STPSCHTBL_ENTER(schtblid)
#endif /* LOG_STPSCHTBL_ENTER */

#ifndef LOG_STPSCHTBL_LEAVE
#define LOG_STPSCHTBL_LEAVE(ercd)
#endif /* LOG_STPSCHTBL_LEAVE */

#ifndef LOG_NXTSCHTBL_ENTER
#define LOG_NXTSCHTBL_ENTER(from, to)
#endif /* LOG_NXTSCHTBL_ENTER */

#ifndef LOG_NXTSCHTBL_LEAVE
#define LOG_NXTSCHTBL_LEAVE(ercd)
#endif /* LOG_NXTSCHTBL_LEAVE */

#ifndef LOG_GETSCHTBLST_ENTER
#define LOG_GETSCHTBLST_ENTER(schtblid)
#endif /* LOG_GETSCHTBLST_ENTER */

#ifndef LOG_GETSCHTBLST_LEAVE
#define LOG_GETSCHTBLST_LEAVE(ercd, p_status)
#endif /* LOG_GETSCHTBLST_LEAVE */

#ifndef LOG_SCHTBL_ENTER
#define LOG_SCHTBL_ENTER(p_schtblcb)
#endif /* LOG_SCHTBL_ENTER */

#ifndef LOG_SCHTBL_LEAVE
#define LOG_SCHTBL_LEAVE(p_schtblcb)
#endif /* LOG_SCHTBL_LEAVE */

/*
 *  �������塼��ơ��֥륪�֥������Ȥν����
 */
#ifdef TOPPERS_schtbl_initialize

void
schtbl_initialize(void)
{
	ScheduleTableType	i;
	SCHTBLCB			*p_schtblcb;
	CNTCB				*p_cntcb;
	TickType			staval;

	for (i = 0U; i < tnum_scheduletable; i++) {
		p_schtblcb = &(schtblcb_table[i]);
		p_schtblcb->p_schtblinib = &(schtblinib_table[i]);

		/*
		 *  STOPPED���֤ˤ������p_nextschtblcb��p_prevschtblcb����������
		 *  RUNNING��NEXT���֤ˤ������expptindex����������
		 */
		p_schtblcb->p_nextschtblcb = NULL;
		p_schtblcb->p_prevschtblcb = NULL;
		(p_schtblcb->cntexpinfo).expirefunc = &schtbl_expire;

		if ((p_schtblcb->p_schtblinib->autosta & ((AppModeType) 1 << appmodeid)) != APPMODE_NONE) {
			if (is_implschtbl(i)) {
				p_schtblcb->status = SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS;
			}
			else {
				p_schtblcb->status = SCHEDULETABLE_RUNNING;
			}
			p_schtblcb->expptindex = EXPPTINDEX_INITIAL;

			p_cntcb = p_schtblcb->p_schtblinib->p_cntcb;
			staval = p_schtblcb->p_schtblinib->staval;
			if (p_schtblcb->p_schtblinib->actatr == ABSOLUTE) {
				/*
				 *  ���л��֤ε�ư
				 *  ��λ���֤�0�ξ�硤���μ�����0�Υ����ߥ󥰤Ȥʤ�
				 *  ��get_abstick�˹�θ�Ѥߡ�
				 */
				(p_schtblcb->cntexpinfo).expiretick = get_abstick(p_cntcb, staval);
			}
			else {
				/* ���л��֤ε�ư */
				(p_schtblcb->cntexpinfo).expiretick = get_reltick(p_cntcb, staval);
			}

			insert_cnt_expr_que(&(p_schtblcb->cntexpinfo), p_cntcb);
		}
		else {
			p_schtblcb->status = SCHEDULETABLE_STOPPED;

			queue_initialize(&(p_schtblcb->cntexpinfo.cntexpque));
		}
	}
}

#endif /* TOPPERS_schtbl_initialize */

/*
 *  ���ꤷ���������塼��ơ��֥�γ���(���л���)
 */
#ifdef TOPPERS_StartScheduleTableRel

StatusType
StartScheduleTableRel(ScheduleTableType ScheduleTableID, TickType Offset)
{
	StatusType	ercd = E_OK;
	SCHTBLCB	*p_schtblcb;
	CNTCB		*p_cntcb;

	LOG_STASCHTBLREL_ENTER(ScheduleTableID, Offset);
	CHECK_DISABLEDINT();
	CHECK_CALLEVEL(CALLEVEL_STARTSCHEDULETABLEREL);
	CHECK_ID(ScheduleTableID < tnum_scheduletable);
	CHECK_ID(ScheduleTableID >= tnum_implscheduletable);

	p_schtblcb = get_schtblcb(ScheduleTableID);
	p_cntcb = p_schtblcb->p_schtblinib->p_cntcb;

	CHECK_VALUE((Offset != 0U) &&
				((p_cntcb->p_cntinib->maxval - p_schtblcb->p_schtblinib->p_exppt->offset) >= Offset));

	x_nested_lock_os_int();

	S_D_CHECK_STATE(p_schtblcb->status == SCHEDULETABLE_STOPPED);

	p_schtblcb->status = SCHEDULETABLE_RUNNING;
	p_schtblcb->expptindex = EXPPTINDEX_INITIAL;
	p_schtblcb->cntexpinfo.expiretick = get_reltick(p_cntcb, Offset);

	insert_cnt_expr_que(&(p_schtblcb->cntexpinfo), p_cntcb);

  d_exit_no_errorhook:
	x_nested_unlock_os_int();
  exit_no_errorhook:
	LOG_STASCHTBLREL_LEAVE(ercd);
	return(ercd);

#ifdef CFG_USE_ERRORHOOK
  exit_errorhook:
	x_nested_lock_os_int();
  d_exit_errorhook:
#ifdef CFG_USE_PARAMETERACCESS
	_errorhook_par1.schtblid = ScheduleTableID;
	_errorhook_par2.offset = Offset;
#endif /* CFG_USE_PARAMETERACCESS */
	call_errorhook(ercd, OSServiceId_StartScheduleTableRel);
	goto d_exit_no_errorhook;
#endif /* CFG_USE_ERRORHOOK */
}

#endif /* TOPPERS_StartScheduleTableRel */

/*
 *  ���ꤷ���������塼��ơ��֥�γ���(���л���)
 */
#ifdef TOPPERS_StartScheduleTableAbs

StatusType
StartScheduleTableAbs(ScheduleTableType ScheduleTableID, TickType Start)
{
	StatusType	ercd = E_OK;
	SCHTBLCB	*p_schtblcb;
	CNTCB		*p_cntcb;

	LOG_STASCHTBLABS_ENTER(ScheduleTableID, Start);
	CHECK_DISABLEDINT();
	CHECK_CALLEVEL(CALLEVEL_STARTSCHEDULETABLEABS);
	CHECK_ID(ScheduleTableID < tnum_scheduletable);

	p_schtblcb = get_schtblcb(ScheduleTableID);
	p_cntcb = p_schtblcb->p_schtblinib->p_cntcb;

	CHECK_VALUE(p_cntcb->p_cntinib->maxval >= Start);

	x_nested_lock_os_int();

	S_D_CHECK_STATE(p_schtblcb->status == SCHEDULETABLE_STOPPED);

	/* ����Ʊ���ξ�硤Ʊ��ư����֤�ư��� */
	if (is_implschtbl(ScheduleTableID)) {
		p_schtblcb->status = SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS;
	}
	else {
		p_schtblcb->status = SCHEDULETABLE_RUNNING;
	}
	p_schtblcb->expptindex = EXPPTINDEX_INITIAL;
	p_schtblcb->cntexpinfo.expiretick = get_abstick(p_cntcb, Start);

	insert_cnt_expr_que(&(p_schtblcb->cntexpinfo), p_cntcb);

  d_exit_no_errorhook:
	x_nested_unlock_os_int();
  exit_no_errorhook:
	LOG_STASCHTBLABS_LEAVE(ercd);
	return(ercd);

#ifdef CFG_USE_ERRORHOOK
  exit_errorhook:
	x_nested_lock_os_int();
  d_exit_errorhook:
#ifdef CFG_USE_PARAMETERACCESS
	_errorhook_par1.schtblid = ScheduleTableID;
	_errorhook_par2.start = Start;
#endif /* CFG_USE_PARAMETERACCESS */
	call_errorhook(ercd, OSServiceId_StartScheduleTableAbs);
	goto d_exit_no_errorhook;
#endif /* CFG_USE_ERRORHOOK */
}

#endif /* TOPPERS_StartScheduleTableAbs */

/*
 *  ���ꤷ���������塼��ơ��֥�����
 */
#ifdef TOPPERS_StopScheduleTable

StatusType
StopScheduleTable(ScheduleTableType ScheduleTableID)
{
	StatusType	ercd = E_OK;
	SCHTBLCB	*p_schtblcb, *p_nextcb;

	LOG_STPSCHTBL_ENTER(ScheduleTableID);
	CHECK_DISABLEDINT();
	CHECK_CALLEVEL(CALLEVEL_STOPSCHEDULETABLE);
	CHECK_ID(ScheduleTableID < tnum_scheduletable);

	p_schtblcb = get_schtblcb(ScheduleTableID);

	x_nested_lock_os_int();

	S_D_CHECK_NOFUNC(p_schtblcb->status != SCHEDULETABLE_STOPPED);

	/*
	 *  ���ꤵ�줿�������塼��ơ��֥뤬SCHEDULETABLE_NEXT�ξ��,
	 *  ��ʬ��Next�ˤ����������塼��ơ��֥뤫�顤��ʬ�򳰤�
	 */
	if (p_schtblcb->status == SCHEDULETABLE_NEXT) {
		p_schtblcb->p_prevschtblcb->p_nextschtblcb = NULL;
		p_schtblcb->p_prevschtblcb = NULL;
	}
	else {
		/*
		 *  Next�������塼��ơ��֥뤬¸�ߤ������,
		 *  Next�������塼��ơ��֥��ͽ��򥭥�󥻥뤹��
		 */
		p_nextcb = p_schtblcb->p_nextschtblcb;
		if (p_nextcb != NULL) {
			p_nextcb->status = SCHEDULETABLE_STOPPED;
			p_nextcb->p_prevschtblcb = NULL;
			p_schtblcb->p_nextschtblcb = NULL;
		}

		/* ��������λ���塼���������Ͽ������λ�������� */
		delete_cnt_expr_que(&(p_schtblcb->cntexpinfo),
							p_schtblcb->p_schtblinib->p_cntcb);
	}

	p_schtblcb->status = SCHEDULETABLE_STOPPED;

  d_exit_no_errorhook:
	x_nested_unlock_os_int();
  exit_no_errorhook:
	LOG_STPSCHTBL_LEAVE(ercd);
	return(ercd);

#ifdef CFG_USE_ERRORHOOK
  exit_errorhook:
	x_nested_lock_os_int();
  d_exit_errorhook:
#ifdef CFG_USE_PARAMETERACCESS
	_errorhook_par1.schtblid = ScheduleTableID;
#endif /* CFG_USE_PARAMETERACCESS */
	call_errorhook(ercd, OSServiceId_StopScheduleTable);
	goto d_exit_no_errorhook;
#endif /* CFG_USE_ERRORHOOK */
}
#endif /* TOPPERS_StopScheduleTable */

/*
 *  �������塼��ơ��֥�����ؤ�
 */
#ifdef TOPPERS_NextScheduleTable

StatusType
NextScheduleTable(ScheduleTableType ScheduleTableID_From,
				  ScheduleTableType ScheduleTableID_To)
{
	StatusType	ercd = E_OK;
	SCHTBLCB	*p_curcb, *p_nextcb;

	LOG_NXTSCHTBL_ENTER(ScheduleTableID_From, ScheduleTableID_To);
	CHECK_DISABLEDINT();
	CHECK_CALLEVEL(CALLEVEL_NEXTSCHEDULETABLE);
	CHECK_ID(ScheduleTableID_From < tnum_scheduletable);
	CHECK_ID(ScheduleTableID_To < tnum_scheduletable);
	CHECK_ID((ScheduleTableID_From < tnum_implscheduletable) ==
			 (ScheduleTableID_To < tnum_implscheduletable));

	p_curcb = get_schtblcb(ScheduleTableID_From);
	p_nextcb = get_schtblcb(ScheduleTableID_To);

	CHECK_ID(p_curcb->p_schtblinib->p_cntcb == p_nextcb->p_schtblinib->p_cntcb);

	x_nested_lock_os_int();

	/* ScheduleTableID_From�ξ��֥����å� */
	S_D_CHECK_NOFUNC((p_curcb->status & (SCHEDULETABLE_STOPPED | SCHEDULETABLE_NEXT)) == 0U);

	/* ScheduleTableID_To�ξ��֥����å� */
	S_D_CHECK_STATE(p_nextcb->status == SCHEDULETABLE_STOPPED);

	/*
	 *  Current���Ф��ƴ���Next��¸�ߤ������,
	 *  ����ޤǤ�Next���Ф��ƥ���󥻥뤹��
	 */
	if (p_curcb->p_nextschtblcb != NULL) {
		p_curcb->p_nextschtblcb->status = SCHEDULETABLE_STOPPED;
		p_curcb->p_nextschtblcb->p_prevschtblcb = NULL;
	}

	p_curcb->p_nextschtblcb = p_nextcb;
	p_nextcb->status = SCHEDULETABLE_NEXT;
	p_nextcb->p_prevschtblcb = p_curcb;

  d_exit_no_errorhook:
	x_nested_unlock_os_int();
  exit_no_errorhook:
	LOG_NXTSCHTBL_LEAVE(ercd);
	return(ercd);

#ifdef CFG_USE_ERRORHOOK
  exit_errorhook:
	x_nested_lock_os_int();
  d_exit_errorhook:
#ifdef CFG_USE_PARAMETERACCESS
	_errorhook_par1.schtblid_from = ScheduleTableID_From;
	_errorhook_par2.schtblid_to = ScheduleTableID_To;
#endif /* CFG_USE_PARAMETERACCESS */
	call_errorhook(ercd, OSServiceId_NextScheduleTable);
	goto d_exit_no_errorhook;
#endif /* CFG_USE_ERRORHOOK */
}

#endif /* TOPPERS_NextScheduleTable */

/*
 *  �������塼��ơ��֥���֤μ���
 */
#ifdef TOPPERS_GetScheduleTableStatus

StatusType
GetScheduleTableStatus(ScheduleTableType ScheduleTableID,
					   ScheduleTableStatusRefType ScheduleStatus)
{
	StatusType	ercd = E_OK;
	SCHTBLCB	*p_schtblcb;

	LOG_GETSCHTBLST_ENTER(ScheduleTableID);
	CHECK_DISABLEDINT();
	CHECK_CALLEVEL(CALLEVEL_GETSCHEDULETABLESTATUS);
	CHECK_ID(ScheduleTableID < tnum_scheduletable);
	CHECK_PARAM_POINTER(ScheduleStatus);

	p_schtblcb = get_schtblcb(ScheduleTableID);

	*ScheduleStatus = p_schtblcb->status;

  exit_no_errorhook:
	LOG_GETSCHTBLST_LEAVE(ercd, ScheduleStatus);
	return(ercd);

#ifdef CFG_USE_ERRORHOOK
  exit_errorhook:
	x_nested_lock_os_int();
#ifdef CFG_USE_PARAMETERACCESS
	_errorhook_par1.schtblid = ScheduleTableID;
	_errorhook_par2.p_schtblstate = ScheduleStatus;
#endif /* CFG_USE_PARAMETERACCESS */
	call_errorhook(ercd, OSServiceId_GetScheduleTableStatus);
	x_nested_unlock_os_int();
	goto exit_no_errorhook;
#endif /* CFG_USE_ERRORHOOK */
}

#endif /* TOPPERS_GetScheduleTableStatus */

/*
 *  �������塼����λ�����ؿ�
 */
#ifdef TOPPERS_schtbl_expire

void
schtbl_expire(CNTEXPINFO *p_cntexpinfo, const CNTCB *p_cntcb)
{
	SCHTBLEXPINFO schtblexpinfo;

	schtblexpinfo.p_schtblcb = (SCHTBLCB *) p_cntexpinfo;

	schtbl_expiry_process(&schtblexpinfo, p_cntcb);

	if (schtblexpinfo.p_schtblcb != NULL) {
		insert_cnt_expr_que(&(schtblexpinfo.p_schtblcb->cntexpinfo), (CNTCB *) p_cntcb);
	}
}

#endif /* TOPPERS_schtbl_expire */

/*
 *  ��λ�����ؿ�����ƥ����ߥ󥰽����μ¹�
 */
#ifdef TOPPERS_schtbl_expiry_process

void
schtbl_expiry_process(SCHTBLEXPINFO *p_schtblexpinfo, const CNTCB *p_cntcb)
{
	boolean		loopcont = FALSE;
	SCHTBLCB	*p_schtblcb;

	/*
	 *  ���ꤷ����λ���ϡ�������λ�����ǽ��������Τǡ�
	 *  �����֤�����ˤ�äƥ롼�׽���
	 */
	do {
		p_schtblcb = p_schtblexpinfo->p_schtblcb;

		if (p_schtblcb->expptindex < p_schtblcb->p_schtblinib->tnum_exppt) {
			/* ����λ���� */
			loopcont = schtbl_exppoint_process(p_schtblcb, p_cntcb);
		}
		else if (p_schtblcb->expptindex == p_schtblcb->p_schtblinib->tnum_exppt) {
			/* �����κǸ�� */
			loopcont = schtbl_tail(p_schtblcb, p_schtblexpinfo, p_cntcb);
		}
		else {
			/*
			 *  �����γ��ϻ�
			 *  p_schtblcb->expptindex == EXPPTINDEX_INITIAL�����������ʤ�
			 */
			loopcont = schtbl_head(p_schtblcb, p_cntcb);
		}
	} while (loopcont != FALSE);
}

#endif /* TOPPERS_schtbl_expiry_process */

/*
 *  �������塼��ơ��֥�γ��Ͻ���
 */
#ifdef TOPPERS_schtbl_head

boolean
schtbl_head(SCHTBLCB *p_schtblcb, const CNTCB *p_cntcb)
{
	boolean				loopcont;
	const SCHTBLEXPPTCB	*p_exppoint;

	p_exppoint = &(p_schtblcb->p_schtblinib->p_exppt[EXPPTINDEX_TOP]);

	if (p_exppoint->offset == 0U) {
		/* ������ե��å�0�ξ�硤������λ�������1���ܤ���λ��������Ԥ� */
		loopcont = TRUE;
	}
	else {
		loopcont = FALSE;
		/* ���˵�ư���٤����֤����� */
		p_schtblcb->cntexpinfo.expiretick = add_tick(p_schtblcb->cntexpinfo.expiretick,
													 p_exppoint->offset, p_cntcb->p_cntinib->maxval2);
	}

	p_schtblcb->expptindex = EXPPTINDEX_TOP;

	return(loopcont);
}

#endif /* TOPPERS_schtbl_head */

/*
 *  �������塼��ơ��֥�γ���λ������
 */
#ifdef TOPPERS_schtbl_exppoint_process

boolean
schtbl_exppoint_process(SCHTBLCB *p_schtblcb, const CNTCB *p_cntcb)
{
	boolean				loopcont = FALSE;
	const SCHTBLEXPPTCB	*p_exppoint;
	TickType			currtime;

	p_exppoint = &(p_schtblcb->p_schtblinib->p_exppt[p_schtblcb->expptindex]);

	/* ��λ�����μ¹� */
	LOG_SCHTBL_ENTER(p_schtblcb);
	(p_exppoint->expptfnt)();
	LOG_SCHTBL_LEAVE(p_schtblcb);

	/* ���߻��֤����� */
	currtime = p_exppoint->offset;
	/* ������λ���� */
	p_schtblcb->expptindex++;
	p_exppoint++;

	if (p_schtblcb->expptindex == p_schtblcb->p_schtblinib->tnum_exppt) {
		/* ���ߤ������κǸ����λ���ξ�� */
		if (p_schtblcb->p_schtblinib->length == currtime) {
			/*
			 *  ñȯ�������塼��ơ��֥�ǽ��ٱ��ͤ�0�ξ�硤Next��¸�ߤ��뤫�⤷��ʤ����ᡤ
			 *  �������塼��ơ��֥�κǸ奿���ߥ󥰽����򤹤�
			 */
			loopcont = TRUE;
		}
		else {
			/* �ǽ��ٱ�����Τ��ᡤ��λ���֤����� */
			p_schtblcb->cntexpinfo.expiretick = add_tick(p_schtblcb->cntexpinfo.expiretick,
														 (p_schtblcb->p_schtblinib->length - currtime), p_cntcb->p_cntinib->maxval2);
		}
	}
	else {
		/* ������λ������λ���֤����� */
		p_schtblcb->cntexpinfo.expiretick = add_tick(p_schtblcb->cntexpinfo.expiretick,
													 (p_exppoint->offset - currtime), p_cntcb->p_cntinib->maxval2);
	}

	return(loopcont);
}

#endif /* TOPPERS_schtbl_exppoint_process */

/*
 *  �������塼��ơ��֥�ν�ü����
 */
#ifdef TOPPERS_schtbl_tail

boolean
schtbl_tail(SCHTBLCB *p_schtblcb, SCHTBLEXPINFO *p_schtblexpinfo, const CNTCB *p_cntcb)
{
	boolean				loopcont = FALSE;
	SCHTBLCB			*p_nextcb;
	const SCHTBLEXPPTCB	*p_exppoint;

	/* �����κǸ�ˤ�Next��¸�ߤ��뤫�����å� */
	if (p_schtblcb->p_nextschtblcb != NULL) {
		p_nextcb = p_schtblcb->p_nextschtblcb;

		/*
		 *  �������塼��ơ��֥���ڤ��ؤ�
		 *
		 *  ����Ʊ��Ʊ�Τ����ؤ��θ�������֤ΰ��Ѥ���ɬ��
		 *  NextScheduleTable��Ʊ����ˡ�����å����Ƥ���Τǡ�
		 *  Ʊ����ˡ�������礬�ʤ�
		 */
		p_nextcb->status = p_schtblcb->status;
		p_nextcb->expptindex = EXPPTINDEX_INITIAL;

		/* Next����λ��������ϡ�Prev����λ����Ȥʤ� */
		p_nextcb->cntexpinfo.expiretick = p_schtblcb->cntexpinfo.expiretick;
		p_nextcb->p_prevschtblcb = NULL;

		/* ���ޤǼ¹Ծ��֤Υ������塼��ơ��֥���Ф��ƽ�λ���� */
		p_schtblcb->status = SCHEDULETABLE_STOPPED;
		p_schtblcb->p_nextschtblcb = NULL;

		/*
		 *  ��ή¦���Next�ν����λ���򥫥�����λ���塼���ɲä������
		 *  ���Ѥ����
		 */
		p_schtblexpinfo->p_schtblcb = p_nextcb;

		loopcont = TRUE;
	}
	else {
		/* ���������̵ͭ�����å� */
		if (p_schtblcb->p_schtblinib->repeat != FALSE) {

			p_schtblcb->expptindex = EXPPTINDEX_TOP;
			p_exppoint = &(p_schtblcb->p_schtblinib->p_exppt[EXPPTINDEX_TOP]);

			if (p_exppoint->offset == 0U) {
				/* ������ե��å�0�ξ�硤������λ�������1���ܤ���λ��������Ԥ� */
				loopcont = TRUE;
			}
			else {
				/* �ǽ��ٱ�����Τ��ᡤ��λ���֤����� */
				p_schtblcb->cntexpinfo.expiretick = add_tick(p_schtblcb->cntexpinfo.expiretick,
															 p_exppoint->offset, p_cntcb->p_cntinib->maxval2);
			}
		}
		else {
			/* ������ư���ʤ��Τǡ���λ���� */
			p_schtblcb->status = SCHEDULETABLE_STOPPED;
			p_schtblexpinfo->p_schtblcb = NULL;
			p_schtblcb->p_prevschtblcb = NULL;
			p_schtblcb->p_nextschtblcb = NULL;
		}
	}

	return(loopcont);
}

#endif /* TOPPERS_schtbl_tail */
