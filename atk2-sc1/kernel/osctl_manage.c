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
 *  $Id: osctl_manage.c 1801 2015-03-27 06:34:43Z t_ishikawa $
 */

/*
 *		OS�����⥸�塼��
 */

#include "kernel_impl.h"
#include "check.h"
#include "interrupt.h"

/*
 *  �ȥ졼�����ޥ���Υǥե�������
 */
#ifndef LOG_GETAAM_ENTER
#define LOG_GETAAM_ENTER()
#endif /* LOG_GETAAM_ENTER */

#ifndef LOG_GETAAM_LEAVE
#define LOG_GETAAM_LEAVE(mode)
#endif /* LOG_GETAAM_LEAVE */

#ifndef LOG_STAOS_ENTER
#define LOG_STAOS_ENTER(mode)
#endif /* LOG_STAOS_ENTER */

#ifndef LOG_STAOS_LEAVE
#define LOG_STAOS_LEAVE()
#endif /* LOG_STAOS_LEAVE */

#ifndef LOG_STAHOOK_ENTER
#define LOG_STAHOOK_ENTER()
#endif /* LOG_STAHOOK_ENTER */

#ifndef LOG_STAHOOK_LEAVE
#define LOG_STAHOOK_LEAVE()
#endif /* LOG_STAHOOK_LEAVE */


#ifdef TOPPERS_StartOS

/*
 *  OS�¹�����Τ�����ѿ�
 */
uint16		callevel_stat = 0U;             /* �¹���Υ���ƥ����� */
AppModeType	appmodeid;                      /* ���ץꥱ�������⡼��ID */

/*
 *  �����ͥ�ư����֥ե饰
 */
boolean		kerflg = FALSE;

/*
 *  �ե�����̾�����ֹ�λ����Ѥ��ѿ�
 */
const char8	*fatal_file_name = NULL;                    /* �ե�����̾ */
sint32		fatal_line_num = 0;                         /* ���ֹ� */

/*
 *  OS�ε�ư
 */

void
StartOS(AppModeType Mode)
{
#ifdef CFG_USE_STARTUPHOOK
	void (*volatile startuphook_adr) (void);
#endif /* CFG_USE_STARTUPHOOK */

	LOG_STAOS_ENTER(Mode);
#ifdef CFG_USE_EXTENDEDSTATUS
	if (kerflg != FALSE) {
		/* OS��ư��ϥ��顼�եå���Ƥ� */
#ifdef CFG_USE_ERRORHOOK
		x_nested_lock_os_int();
#ifdef CFG_USE_PARAMETERACCESS
		_errorhook_par1.mode = Mode;
#endif /* CFG_USE_PARAMETERACCESS */
		call_errorhook(E_OS_ACCESS, OSServiceId_StartOS);
		x_nested_unlock_os_int();
#endif /* CFG_USE_ERRORHOOK */
	}
	else {
#endif /* CFG_USE_EXTENDEDSTATUS */

		/* ������߶ػ߾��֤˰ܹ� */
		x_lock_all_int();

#ifdef CFG_USE_STACKMONITORING
		/*
		 *  �����å���˥���󥰵�ǽ�ν����
		 *  �����å���˥���󥰵�ǽ�Τ���Υޥ��å��ʥ�С��ΰ�ν����
		 */
		init_stack_magic_region();
#endif /* CFG_USE_STACKMONITORING */

		/* ���ץꥱ�������⡼�ɤ����� */
		appmodeid = Mode;

		/* �������åȰ�¸�ν���� */
		target_initialize();

		/* �ƥ⥸�塼��ν���� */
		object_initialize();

		callevel_stat = TCL_NULL;

		/* �����ͥ�ư���� */
		kerflg = TRUE;

		/*
		 *  Mode�������Ǥ��ä���硤OS����åȥ������Ԥ�
		 *  ���λ����������ȥ��åץեå��ϸƤӽФ���ʤ�
		 */
		if (Mode >= tnum_appmode) {
			/*
			 *  internal_shutdownos��Ƥ�����OS����߶ػ߾��֤�
			 *  ������߶ػ߾��ֲ��
			 */
			x_nested_lock_os_int();
			x_unlock_all_int();
			internal_shutdownos(E_OS_MODE);
		}

#ifdef CFG_USE_STARTUPHOOK
		/* OS����߶ػ߾��֤ˤ���������߶ػ߾��ֲ�� */
		x_nested_lock_os_int();
		x_unlock_all_int();

		/*
		 *  StartupHook �θƤӽФ�
		 *
		 *  C����ε��ʤǤϴؿ��Υ��ɥ쥹��0�ˤʤ�ʤ��Ȥ������󤫤�,
		 *  ����ѥ���κ�Ŭ���ˤ��StartupHook�Υ��ɥ쥹Ƚ��ʬ����
		 *  �������Ƥ��ޤ���礬���뤿��, volatile���ꤷ���������ѿ���
		 *  ���ɥ쥹���������Ƥ���Ƚ�ꤷ�Ƥ���
		 */
		startuphook_adr = &StartupHook;

		if (startuphook_adr != NULL) {
			ENTER_CALLEVEL(TCL_STARTUP);
			LOG_STAHOOK_ENTER();
			StartupHook();
			LOG_STAHOOK_LEAVE();
			LEAVE_CALLEVEL(TCL_STARTUP);

			release_interrupts(OSServiceId_HookMissingEnd);
		}

		/* ���γ���ߥޥ���ͥ���٤�������߶ػ߾��֤� */
		x_lock_all_int();
		x_nested_unlock_os_int();
#endif /* CFG_USE_STARTUPHOOK */

		ENTER_CALLEVEL(TCL_TASK);
		LOG_STAOS_LEAVE();
		start_dispatch();
		ASSERT(0);
#ifdef CFG_USE_EXTENDEDSTATUS
	}
#endif /* CFG_USE_EXTENDEDSTATUS */
}

#endif /* TOPPERS_StartOS */

/*
 *  ���ߤΥ��ץꥱ�������⡼�ɤμ���
 */
#ifdef TOPPERS_GetActiveApplicationMode

AppModeType
GetActiveApplicationMode(void)
{
	AppModeType	appmode;
#if defined(CFG_USE_EXTENDEDSTATUS) || defined(CFG_USE_ERRORHOOK)
	StatusType	ercd;
#endif /* CFG_USE_EXTENDEDSTATUS || CFG_USE_ERRORHOOK */

	LOG_GETAAM_ENTER();
	CHECK_DISABLEDINT();
	CHECK_CALLEVEL(CALLEVEL_GETACTIVEAPPMODE);

	appmode = appmodeid;

  exit_finish:
	LOG_GETAAM_LEAVE(appmode);
	return(appmode);

#ifdef CFG_USE_ERRORHOOK
  exit_errorhook:
	x_nested_lock_os_int();
	/*
	 *  ���顼ȯ������INVALID_APPMODETYPE���֤뤬�����顼��ȯ�������Τ��¹����
	 *  C2ISR��¸�ߤ��ʤ��Τ����̤��뤿�ᡤ���顼�եå���Ƥ�
	 */
	call_errorhook(ercd, OSServiceId_GetActiveApplicationMode);
	x_nested_unlock_os_int();
#endif /* CFG_USE_ERRORHOOK */

  exit_no_errorhook:
	appmode = INVALID_APPMODETYPE;
	goto exit_finish;
}

#endif /* TOPPERS_GetActiveApplicationMode */

/*
 *  OS�ν�λ
 */
#ifdef TOPPERS_ShutdownOS

void
ShutdownOS(StatusType Error)
{
	StatusType ercd = Error;

	/*
	 *  �����ʽ���ñ�̤���ƤӽФ������⡤Error��E_OS_SHUTDOWN_FATAL�Ȥ���
	 *  ShutdownOS��ƤӽФ�����ΤȤ��ơ�����åȥ����������Ԥ�
	 */
	if (((callevel_stat & TCLMASK) | (CALLEVEL_SHUTDOWNOS)) != (CALLEVEL_SHUTDOWNOS)) {
		ercd = E_OS_SHUTDOWN_FATAL;
	}

	/*
	 *  OS���������Ƥ��ʤ����顼�����ɤ����ꤵ�줿��硤Error��E_OS_SHUTDOWN_FATAL�Ȥ���
	 *  ShutdownOS��ƤӽФ�����ΤȤ��ơ�����åȥ����������Ԥ�
	 */
	if (ercd > ERRCODE_NUM) {
		ercd = E_OS_SHUTDOWN_FATAL;
	}

	internal_shutdownos(ercd);
}
#endif /* TOPPERS_ShutdownOS */

/*
 *  �ݸ��ȿ�򵯤���������ñ�̤μ���
 */
#ifdef TOPPERS_GetFaultyContext

FaultyContextType
GetFaultyContext(void)
{
	FaultyContextType faultycontext = FC_INVALID;

#ifdef CFG_USE_PROTECTIONHOOK
	if ((callevel_stat & CALLEVEL_GETFAULTYCONTEXT) != 0U) {

		/* C1ISR�ʳ���ȯ�� */
		if ((callevel_stat & TSYS_ISR1) == 0U) {
			/* �եå����ȯ�� */
			if ((callevel_stat & (TCL_ERROR | TCL_PREPOST | TCL_STARTUP | TCL_SHUTDOWN)) != 0U) {
				/* �����ƥ�����եå����ȯ�� */
				faultycontext = FC_SYSTEM_HOOK;
			}
			else if ((callevel_stat & TCL_ISR2) != 0U) {
				if ((callevel_stat & TCL_ALRMCBAK) == 0U) {
					faultycontext = FC_C2ISR;
				}
			}
			else if ((callevel_stat & TCL_TASK) != 0U) {
				if ((callevel_stat & TCL_ALRMCBAK) == 0U) {
					faultycontext = FC_TASK;
				}
			}
			else {
				/* �嵭�ʳ��ξ�硤�����ϹԤ�ʤ�(����͡�FC_INVALID) */
			}
		}
	}
#endif /* CFG_USE_PROTECTIONHOOK */

	return(faultycontext);
}
#endif /* TOPPERS_GetFaultyContext */
