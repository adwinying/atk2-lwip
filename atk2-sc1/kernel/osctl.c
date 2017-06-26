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
 *  $Id: osctl.c 1801 2015-03-27 06:34:43Z t_ishikawa $
 */

/*
 *		OS����⥸�塼��
 */

#include "kernel_impl.h"
#include "interrupt.h"
#include "task.h"

/*
 *  �ȥ졼�����ޥ���Υǥե�������
 */

#ifndef LOG_ERRHOOK_ENTER
#define LOG_ERRHOOK_ENTER(ercd)
#endif /* LOG_ERRHOOK_ENTER */

#ifndef LOG_ERRHOOK_LEAVE
#define LOG_ERRHOOK_LEAVE()
#endif /* LOG_ERRHOOK_LEAVE */

#ifndef LOG_PROHOOK_ENTER
#define LOG_PROHOOK_ENTER(ercd)
#endif /* LOG_PROHOOK_ENTER */

#ifndef LOG_PROHOOK_LEAVE
#define LOG_PROHOOK_LEAVE(pret)
#endif /* LOG_PROHOOK_LEAVE */

#ifndef LOG_SHUTHOOK_ENTER
#define LOG_SHUTHOOK_ENTER(ercd)
#endif /* LOG_SHUTHOOK_ENTER */

#ifndef LOG_SHUTHOOK_LEAVE
#define LOG_SHUTHOOK_LEAVE()
#endif /* LOG_SHUTHOOK_LEAVE */

#ifndef LOG_STUTOS_ENTER
#define LOG_STUTOS_ENTER(ercd)
#endif /* LOG_STUTOS_ENTER */

#ifndef LOG_STUTOS_LEAVE
#define LOG_STUTOS_LEAVE()
#endif /* LOG_STUTOS_LEAVE */

#ifdef CFG_USE_ERRORHOOK
/*
 *  ���顼�եå����Ϥ�������Ǽ�����ѿ�
 */
#ifdef TOPPERS_internal_call_errorhook

#ifdef CFG_USE_GETSERVICEID
OSServiceIdType	_errorhook_svcid;
#endif /* CFG_USE_GETSERVICEID */

#ifdef CFG_USE_PARAMETERACCESS
_ErrorHook_Par	_errorhook_par1;
_ErrorHook_Par	_errorhook_par2;
_ErrorHook_Par	_errorhook_par3;
_ErrorHook_Par	errorhook_par1;
_ErrorHook_Par	errorhook_par2;
_ErrorHook_Par	errorhook_par3;
#endif /* CFG_USE_PARAMETERACCESS */

/*
 *  ���顼�եå��θƤӽФ�
 */
void
internal_call_errorhook(StatusType ercd, OSServiceIdType svcid)
{
	void (*volatile errorhook_adr) (StatusType Error);
	uint8	saved_sus_all_cnt_ctx;
	uint8	saved_sus_os_cnt_ctx;

	/*
	 *  C����ε��ʤǤϴؿ��Υ��ɥ쥹��0�ˤʤ�ʤ��Ȥ������󤫤�,
	 *  ����ѥ���κ�Ŭ���ˤ��ErrorHook�Υ��ɥ쥹Ƚ��ʬ����
	 *  �������Ƥ��ޤ���礬���뤿��, volatile���ꤷ���������ѿ���
	 *  ���ɥ쥹���������Ƥ���Ƚ�ꤷ�Ƥ���
	 */
	errorhook_adr = &ErrorHook;

	if (errorhook_adr != NULL) {
		if ((callevel_stat & (TCL_ERROR | TSYS_ISR1)) == TCL_NULL) {

#ifdef CFG_USE_GETSERVICEID
			_errorhook_svcid = svcid;
#endif /* CFG_USE_GETSERVICEID */

#ifdef CFG_USE_PARAMETERACCESS
			errorhook_par1 = _errorhook_par1;
			errorhook_par2 = _errorhook_par2;
			errorhook_par3 = _errorhook_par3;
#endif /* CFG_USE_PARAMETERACCESS */

			saved_sus_all_cnt_ctx = sus_all_cnt_ctx;
			saved_sus_os_cnt_ctx = sus_os_cnt_ctx;

			sus_all_cnt_ctx = 0U;
			sus_os_cnt_ctx = 0U;

			ENTER_CALLEVEL(TCL_ERROR);
			LOG_ERRHOOK_ENTER(ercd);
			ErrorHook(ercd);
			LOG_ERRHOOK_LEAVE();
			LEAVE_CALLEVEL(TCL_ERROR);

			release_interrupts(OSServiceId_HookMissingEnd);

			sus_all_cnt_ctx = saved_sus_all_cnt_ctx;
			sus_os_cnt_ctx = saved_sus_os_cnt_ctx;
		}
	}
}

#endif /* TOPPERS_internal_call_errorhook */

#endif /* CFG_USE_ERRORHOOK */

#ifdef CFG_USE_POSTTASKHOOK
/*
 *  �ݥ��ȥ������եå��θƤӽФ�
 */
#ifdef TOPPERS_call_posttaskhook

void
call_posttaskhook(void)
{
	ENTER_CALLEVEL(TCL_PREPOST);
	PostTaskHook();
	LEAVE_CALLEVEL(TCL_PREPOST);

	release_interrupts(OSServiceId_HookMissingEnd);
}

#endif /* TOPPERS_call_posttaskhook */

#endif /* CFG_USE_POSTTASKHOOK */

#ifdef CFG_USE_PRETASKHOOK
/*
 *  �ץ쥿�����եå��θƤӽФ�
 */
#ifdef TOPPERS_call_pretaskhook

void
call_pretaskhook(void)
{
	ENTER_CALLEVEL(TCL_PREPOST);
	PreTaskHook();
	LEAVE_CALLEVEL(TCL_PREPOST);

	release_interrupts(OSServiceId_HookMissingEnd);
}

#endif /* TOPPERS_call_pretaskhook */

#endif /* CFG_USE_PRETASKHOOK */

#ifdef CFG_USE_STACKMONITORING

#ifdef TOPPERS_init_stack_magic_region

/*
 *  �����å���˥���󥰵�ǽ�ν����
 *  �����å���˥���󥰵�ǽ�Τ���Υޥ��å��ʥ�С��ΰ�ν����
 */
void
init_stack_magic_region(void)
{
	TaskType	i;
	StackType	*p_stack_magic_region;

	/*
	 *  �����å���˥���󥰵�ǽ�Τ��ᡤ�����å���Ĺ������θ����
	 *  �󥿥��������å��Υޥ��å��ʥ�С��ΰ�ν����
	 */
	p_stack_magic_region = TOPPERS_ISTK_MAGIC_REGION(_ostk, _ostksz);
	*p_stack_magic_region = STACK_MAGIC_NUMBER;

	/*
	 *  �����å���˥���󥰵�ǽ�Τ��ᡤ�����å���Ĺ������θ����
	 *  �ƥ����������å��Υޥ��å��ʥ�С��ΰ�ν����
	 *  �����å���ͭ�����������Υޥ��å��ʥ�С��ΰ褬��碌�äƤ���
	 */
	for (i = 0U; i < tnum_task; i++) {
		p_stack_magic_region =
			TOPPERS_TSTK_MAGIC_REGION(&tinib_table[i]);
		*p_stack_magic_region = STACK_MAGIC_NUMBER;
	}
}

#endif /* TOPPERS_init_stack_magic_region */

#endif /* CFG_USE_STACKMONITORING */

/*
 *  �ץ�ƥ������եå��θƤӽФ�
 */
#ifdef TOPPERS_call_protectionhk_main

void
call_protectionhk_main(StatusType ercd)
{

#ifdef CFG_USE_PROTECTIONHOOK

	ProtectionReturnType	pret;
	ProtectionReturnType	(*volatile protectionhook_adr) (StatusType FatalError);
	uint8					saved_sus_all_cnt_ctx;
	uint8					saved_sus_os_cnt_ctx;

	/* �ץ�ƥ������եå��¹�����ݸ��ȿ��ȯ��������� */
	if ((callevel_stat & TCL_PROTECT) == TCL_PROTECT) {
		internal_shutdownos(E_OS_PROTECTION_FATAL);
	}

	/*
	 *  C����ε��ʤǤϴؿ��Υ��ɥ쥹��0�ˤʤ�ʤ��Ȥ������󤫤�,
	 *  ����ѥ���κ�Ŭ���ˤ��ProtectionHook�Υ��ɥ쥹Ƚ��ʬ����
	 *  �������Ƥ��ޤ���礬���뤿��, volatile���ꤷ���������ѿ���
	 *  ���ɥ쥹���������Ƥ���Ƚ�ꤷ�Ƥ���
	 */
	protectionhook_adr = &ProtectionHook;

	/* �ʲ� �����ƥ�����Υץ�ƥ������եå���ƽФ����� */
	if (protectionhook_adr != NULL) {

		saved_sus_all_cnt_ctx = sus_all_cnt_ctx;
		saved_sus_os_cnt_ctx = sus_os_cnt_ctx;

		sus_all_cnt_ctx = 0U;
		sus_os_cnt_ctx = 0U;

		ENTER_CALLEVEL(TCL_PROTECT);
		LOG_PROHOOK_ENTER(ercd);
		pret = protectionhook_adr(ercd);
		LOG_PROHOOK_LEAVE(pret);

		LEAVE_CALLEVEL(TCL_PROTECT);

		release_interrupts(OSServiceId_HookMissingEnd);

		sus_all_cnt_ctx = saved_sus_all_cnt_ctx;
		sus_os_cnt_ctx = saved_sus_os_cnt_ctx;

		/* �ʲ� ProtectionHook �¹Ը�ν��� */
		switch (pret) {
		case PRO_SHUTDOWN:
			internal_shutdownos(ercd);
			break;
		case PRO_IGNORE:
			if (ercd != E_OS_PROTECTION_EXCEPTION) {
				internal_shutdownos(E_OS_PROTECTION_FATAL);
			}
			break;
		default:
			/* ProtectionHook�����������ͤ��֤ä���� */
			internal_shutdownos(E_OS_PROTECTION_FATAL);
			break;
		}
	}
	else {
		internal_shutdownos(ercd);
	}

#else /* CFG_USE_PROTECTIONHOOK */

	/*
	 *  �ץ�ƥ������եå�������ե�����졼��������̵����
	 *  ����Ƥ����硤OS���ݸ��ȿ�������Ȥ���OS����åȥ������
	 *  �Ԥ�
	 *  ���ΤȤ���OS����åȥ�����Υѥ�᡼���Ȥ��ơ�
	 *  ��ȿ�ζ��̤򼨤����顼�����ɤ���ꤹ��
	 */
	internal_shutdownos(ercd);
#endif /* CFG_USE_PROTECTIONHOOK */

}

#endif /* TOPPERS_call_protectionhk_main */

/*
 *  OS���������ShutdownOS�θƤӽФ�
 */
#ifdef TOPPERS_internal_shutdownos

void
internal_shutdownos(StatusType ercd)
{
	LOG_STUTOS_ENTER(ercd);

	x_nested_lock_os_int();

#ifdef CFG_USE_SHUTDOWNHOOK
	call_shutdownhook(ercd);
#endif /* CFG_USE_SHUTDOWNHOOK */

	/* �ƥ⥸�塼��ν�λ���� */
	object_terminate();

	/* ������߶ػ߾��֤˰ܹ� */
	x_lock_all_int();

	LOG_STUTOS_LEAVE();

	/* �������åȰ�¸�ν�λ���� */
	target_exit();

	/*
	 * �������åȰ�¸������������֤äƤ�����硤
	 * ̵�¥롼�פ�Ԥ�
	 */
	while (1) {
	}

}

#endif /* TOPPERS_internal_shutdownos */

#ifdef TOPPERS_internal_call_shtdwnhk

#ifdef CFG_USE_SHUTDOWNHOOK

void
internal_call_shtdwnhk(StatusType ercd)
{

	void (*volatile shutdownhook_adr) (StatusType Error);

	/*
	 *  ����åȥ�����եå���Υ���åȥ�����Ǥϥ���åȥ�����եå�
	 *  �ϸƤӽФ��ʤ�
	 */
	if ((callevel_stat & TCL_SHUTDOWN) == TCL_NULL) {
		/*
		 *  ShutdownHook �θƤӽФ�
		 *
		 *  C����ε��ʤǤϴؿ��Υ��ɥ쥹��0�ˤʤ�ʤ��Ȥ������󤫤�,
		 *  ����ѥ���κ�Ŭ���ˤ��ShutdownHook�Υ��ɥ쥹Ƚ��ʬ����
		 *  �������Ƥ��ޤ���礬���뤿��, volatile���ꤷ���������ѿ���
		 *  ���ɥ쥹���������Ƥ���Ƚ�ꤷ�Ƥ���
		 */
		shutdownhook_adr = &ShutdownHook;

		if (shutdownhook_adr != NULL) {
			sus_all_cnt_ctx = 0U;
			sus_os_cnt_ctx = 0U;

			ENTER_CALLEVEL(TCL_SHUTDOWN);
			LOG_SHUTHOOK_ENTER(ercd);
			ShutdownHook(ercd);
			LOG_SHUTHOOK_LEAVE();
			LEAVE_CALLEVEL(TCL_SHUTDOWN);

			release_interrupts(OSServiceId_HookMissingEnd);
		}
	}
}
#endif /* CFG_USE_SHUTDOWNHOOK */

#endif /* TOPPERS_internal_call_shtdwnhk */
