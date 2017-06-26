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
 *  Copyright (C) 2011-2015 by Witz Corporation
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
 *  $Id: kernel_impl.h 1801 2015-03-27 06:34:43Z t_ishikawa $
 */

/*
 *		ATK2��������ɸ��إå��ե�����
 *
 *  ���Υإå��ե�����ϡ������ͥ��������ץ����Υ������ե�����
 *  ��ɬ�����󥯥롼�ɤ���٤�ɸ��إå��ե�����Ǥ���
 *
 *  ������֥����Υ������ե����뤫�餳�Υե�����򥤥󥯥롼�ɤ����
 *  �ϡ�TOPPERS_MACRO_ONLY��������Ƥ���
 *  ����ˤ�ꡤ�ޥ�������ʳ�������褦�ˤʤäƤ���
 */

#ifndef TOPPERS_KERNEL_IMPL_H
#define TOPPERS_KERNEL_IMPL_H

/*
 *  ���ץꥱ�������ȶ��̤Υإå��ե�����
 */
#define OMIT_INCLUDE_OS_LCFG
#include "Os.h"

/* ̵���ݥ��� */
#ifndef NULL
#define NULL		NULL_PTR
#endif /* NULL */

/*
 *  �����㥹�Ȥ�Ԥ��ޥ�������
 */
#ifndef CAST
#define CAST(type, val)		((type) (val))
#endif /* CAST */

#ifndef TOPPERS_MACRO_ONLY

/* ��Ŭ�����뤿�ᡤ��¸��������Ǥ��뷿 */
#ifndef OMIT_DATA_TYPE
/*
 *  �����ͥ������Υǡ�����
 */
typedef uint32	InterruptNumberType;            /* ������ֹ� */
typedef uint32	AttributeType;                  /* ���֥������Ȥ�°�� */
typedef sint32	PriorityType;                   /* ͥ���� */
#endif /* OMIT_DATA_TYPE */

typedef void (*FunctionRefType)(void);          /* �ץ����ε�ư���� */

/*
 *  ���顼�եå�OFF���������ӥ�ID�����ȥѥ�᡼��������OFF�ˤʤ�
 */
#ifdef CFG_USE_ERRORHOOK

#ifdef CFG_USE_PARAMETERACCESS
extern _ErrorHook_Par	_errorhook_par1;
extern _ErrorHook_Par	_errorhook_par2;
extern _ErrorHook_Par	_errorhook_par3;
#endif /* CFG_USE_PARAMETERACCESS */

#endif /* CFG_USE_ERRORHOOK */

/*
 *  OS���������ShutdownOS�θƤӽФ�
 */
extern void internal_shutdownos(StatusType ercd);

#ifdef CFG_USE_SHUTDOWNHOOK
extern void internal_call_shtdwnhk(StatusType ercd);
#endif /* CFG_USE_SHUTDOWNHOOK */

#endif /* TOPPERS_MACRO_ONLY */

/*
 *  ASSERT�ޥ���
 */
#ifndef NDEBUG
#define ASSERT(exp) do {								\
		if (!(exp)) {									\
			fatal_file_name = __FILE__;					\
			fatal_line_num = __LINE__;					\
			internal_shutdownos(E_OS_SYS_ASSERT_FATAL);	\
		}												\
} while (0)

#else /* NDEBUG */
#define ASSERT(exp)
#endif /* NDEBUG */

/*
 *  �������åȰ�¸��������
 */
#include "target_config.h"

/*
 *  ���٤Ƥδؿ��򥳥�ѥ��뤹�뤿������
 */
#ifdef ALLFUNC
#include "allfunc.h"
#endif /* ALLFUNC */

/*
 *  ���ץꥱ�������⡼���ͤ����
 */
#define APPMODE_NONE	((AppModeType) 0)   /* �⡼�ɤʤ� */

/*
 *  �¹���Υ���ƥ����ȡ�callevel_stat�β���12�ӥåȡˤ��ͤ����
 *  TCL_NULL�λ��ˡ�����θƽв�����ƥ����Ȥ�Ƚ�̤Ǥ��ʤ��ʤ뤳�Ȥ����
 */
#define TCL_NULL		UINT_C(0x0000)      /* �����ƥॵ���ӥ���ƤӽФ��ʤ� */
#define TCL_TASK		UINT_C(0x0001)      /* ������ */
#define TCL_ISR2		UINT_C(0x0002)      /* C2ISR */
#define TCL_PROTECT		UINT_C(0x0004)      /* ProtectionHook */
#define TCL_PREPOST		UINT_C(0x0008)      /* PreTaskHook��PostTaskHook */
#define TCL_STARTUP		UINT_C(0x0010)      /* StartupHook */
#define TCL_SHUTDOWN	UINT_C(0x0020)      /* ShutdownHook */
#define TCL_ERROR		UINT_C(0x0040)      /* ErrorHook */
#define TCL_ALRMCBAK	UINT_C(0x0080)      /* Alarm CallBack routine */
#define TCLMASK			UINT_C(0x0fff)      /* �������٥�򼨤��ӥåȤΥޥ��� */
/*
 *  �����ƥ���� (callevel_stat�ξ��4�ӥå�)���ͤ����
 */
#define TSYS_NULL		UINT_C(0x0000)      /* �����ƥ���֥��ꥢ */
#define TSYS_DISALLINT	UINT_C(0x1000)      /* DisableAllInterruptsȯ���� */
#define TSYS_SUSALLINT	UINT_C(0x2000)      /* SuspendAllInterruptsȯ���� */
#define TSYS_SUSOSINT	UINT_C(0x4000)      /* SuspendOSInterruptsȯ���� */
#define TSYS_ISR1		UINT_C(0x8000)      /* C1ISR��ư�Ѥ� */
#define TSYSMASK		UINT_C(0xf000)      /* �����ƥ���֤򼨤��ӥåȤΥޥ��� */


#ifdef CFG_USE_STACKMONITORING
#ifndef STACK_MAGIC_NUMBER
/*
 *  �����å���˥�����ѥޥ��å��ʥ�С������
 *  �������åȰ�¸���������ͥ�褵���
 */
#define STACK_MAGIC_NUMBER	0x4E434553      /* NCES��ASCII������(0x4E434553) */
#endif /* STACK_MAGIC_NUMBER */

#ifndef TOPPERS_ISTK_MAGIC_REGION
/* ����ߥ����å��ѥޥ��å��ʥ�С��ΰ�����ޥ��� */
#define TOPPERS_ISTK_MAGIC_REGION(stk, stksz)	(stk)
#endif /* TOPPERS_ISTK_MAGIC_REGION */

#ifndef TOPPERS_TSTK_MAGIC_REGION
/* �����������å��ѥޥ��å��ʥ�С��ΰ�����ޥ��� */
#ifndef USE_TSKINICTXB
#define TOPPERS_TSTK_MAGIC_REGION(p_tinib)	((StackType *) ((p_tinib)->stk))
#endif /* USE_TSKINICTXB */
#endif /* TOPPERS_TSTK_MAGIC_REGION */

#endif /* CFG_USE_STACKMONITORING */

/*
 *  callevel_stat�Υӥå����
 */
#define ENTER_CALLEVEL(bit)		(callevel_stat |= (bit))
#define LEAVE_CALLEVEL(bit)		(callevel_stat &= (uint16) ~(bit))


/*
 *  �ƥ����ƥॵ���ӥ���ƤӽФ������ñ��
 */
#define CALLEVEL_ACTIVATETASK				(TCL_TASK | TCL_ISR2)
#define CALLEVEL_TERMINATETASK				(TCL_TASK)
#define CALLEVEL_CHAINTASK					(TCL_TASK)
#define CALLEVEL_SCHEDULE					(TCL_TASK)
#define CALLEVEL_GETTASKID					(TSYS_DISALLINT | TSYS_SUSALLINT | TSYS_SUSOSINT | TCL_TASK | TCL_ISR2 | TCL_ERROR | TCL_PREPOST | TCL_PROTECT)
#define CALLEVEL_GETTASKSTATE				(TSYS_DISALLINT | TSYS_SUSALLINT | TSYS_SUSOSINT | TCL_TASK | TCL_ISR2 | TCL_ERROR | TCL_PREPOST)
#define CALLEVEL_GETRESOURCE				(TCL_TASK | TCL_ISR2)
#define CALLEVEL_RELEASERESOURCE			(TCL_TASK | TCL_ISR2)
#define CALLEVEL_SETEVENT					(TCL_TASK | TCL_ISR2)
#define CALLEVEL_CLEAREVENT					(TCL_TASK)
#define CALLEVEL_GETEVENT					(TCL_TASK | TCL_ISR2 | TCL_ERROR | TCL_PREPOST)
#define CALLEVEL_WAITEVENT					(TCL_TASK)
#define CALLEVEL_GETALARMBASE				(TCL_TASK | TCL_ISR2 | TCL_ERROR | TCL_PREPOST)
#define CALLEVEL_GETALARM					(TCL_TASK | TCL_ISR2 | TCL_ERROR | TCL_PREPOST)
#define CALLEVEL_SETRELALARM				(TCL_TASK | TCL_ISR2)
#define CALLEVEL_SETABSALARM				(TCL_TASK | TCL_ISR2)
#define CALLEVEL_CANCELALARM				(TCL_TASK | TCL_ISR2)
#define CALLEVEL_GETACTIVEAPPMODE			(TCL_TASK | TCL_ISR2 | TCL_ERROR | TCL_PREPOST | TCL_STARTUP | TCL_SHUTDOWN)
#define CALLEVEL_SHUTDOWNOS					(TCL_TASK | TCL_ISR2 | TCL_ERROR | TCL_STARTUP)
#define CALLEVEL_GETISRID					(TSYS_DISALLINT | TSYS_SUSALLINT | TSYS_SUSOSINT | TCL_TASK | TCL_ISR2 | TCL_ERROR | TCL_PROTECT)
#define CALLEVEL_INCREMENTCOUNTER			(TCL_TASK | TCL_ISR2)
#define CALLEVEL_GETCOUNTERVALUE			(TCL_TASK | TCL_ISR2)
#define CALLEVEL_GETELAPSEDVALUE			(TCL_TASK | TCL_ISR2)
#define CALLEVEL_STARTSCHEDULETABLEREL		(TCL_TASK | TCL_ISR2)
#define CALLEVEL_STARTSCHEDULETABLEABS		(TCL_TASK | TCL_ISR2)
#define CALLEVEL_STOPSCHEDULETABLE			(TCL_TASK | TCL_ISR2)
#define CALLEVEL_NEXTSCHEDULETABLE			(TCL_TASK | TCL_ISR2)
#define CALLEVEL_GETSCHEDULETABLESTATUS		(TCL_TASK | TCL_ISR2)
#define CALLEVEL_GETFAULTYCONTEXT			(TCL_PROTECT)

/*
 *  ����¾������͡�ɸ�����ߥ�ǥ��
 */
#define TIPM_ENAALL		UINT_C(0)   /* �����ͥ���٥ޥ�������� */

/*
 *  ���֥�������°���������ɸ�����ߥ�ǥ��
 */
#define ENABLE		UINT_C(0x01)

/*
 *  OS������̵���ʥ����ƥॵ���ӥ�ID
 */
#define OSServiceId_Invalid		((OSServiceIdType) 0xff)

/*
 *  �إå��ե����������ʤ��⥸�塼��δؿ����ѿ������
 */
#ifndef TOPPERS_MACRO_ONLY

#ifdef TOPPERS_StartOS
/*
 *  ���ץꥱ�������⡼�ɤο�
 */
extern const AppModeType	tnum_appmode;

#endif /* TOPPERS_StartOS */

/*
 *  OS�¹�����Τ�����ѿ���osctl_manage.c��
 */
extern uint16				callevel_stat;  /* �¹���Υ���ƥ����� */
extern AppModeType			appmodeid;      /* ���ץꥱ�������⡼��ID */

/*
 *  �����ͥ�ư����֥ե饰
 */
extern boolean				kerflg;

/*
 *  ���顼�եå��ƤӽФ��Τ���������osctl.c��
 */
#ifdef CFG_USE_ERRORHOOK
extern void internal_call_errorhook(StatusType ercd, OSServiceIdType svcid);
#endif /* CFG_USE_ERRORHOOK */

/*
 *  �ݥ��ȥ������եå�/�ץ쥿�����եå�
 *  �����å���˥���󥰵�ǽ�ν����/�ץ�ƥ������եå��ƤӽФ��Τ���������osctl.c��
 */
#ifdef CFG_USE_POSTTASKHOOK
extern void call_posttaskhook(void);
#endif /* CFG_USE_POSTTASKHOOK */

#ifdef CFG_USE_PRETASKHOOK
extern void call_pretaskhook(void);
#endif /* CFG_USE_PRETASKHOOK */

#ifdef CFG_USE_STACKMONITORING
extern void init_stack_magic_region(void);
#endif /* CFG_USE_STACKMONITORING */

extern void call_protectionhk_main(StatusType ercd);

/*
 *  �ƥ⥸�塼��ν������Os_Lcfg.c��
 */
extern void object_initialize(void);

/*
 *  �ƥ⥸�塼��ν�λ������Os_Lcfg.c��
 */
extern void object_terminate(void);

/*
 *  �󥿥�������ƥ������ѤΥ����å��ΰ��Os_Lcfg.c��
 */
extern const MemorySizeType	_ostksz;            /* �����å��ΰ�Υ������ʴݤ᤿�͡� */
extern StackType * const	_ostk;              /* �����å��ΰ����Ƭ���� */
#ifdef TOPPERS_OSTKPT
extern StackType * const	_ostkpt;                /* �����å��ݥ��󥿤ν���� */
#endif /* TOPPERS_OSTKPT */

#endif /* TOPPERS_MACRO_ONLY */

#endif /* TOPPERS_KERNEL_IMPL_H */
