/*
 *  TOPPERS ATK2
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *      Automotive Kernel Version 2
 *
 *  Copyright (C) 2011-2015 by Center for Embedded Computing Systems
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
 *  $Id: Os.h 1801 2015-03-27 06:34:43Z t_ishikawa $
 */

/*
 *		ATK2 OS�إå��ե�����
 *
 *  ATK2�����ݡ��Ȥ��륷���ƥॵ���ӥ�������ȡ�ɬ�פʥǡ�
 *  ������������ޥ���������ޤ�إå��ե�����
 *
 *  ������֥����Υ������ե����뤫�餳�Υե�����򥤥󥯥롼�ɤ����
 *  �ϡ�TOPPERS_MACRO_ONLY��������Ƥ���
 *  ����ˤ�ꡤ�ޥ�������ʳ�������褦�ˤʤäƤ���
 *
 *  ���Υե�����򥤥󥯥롼�ɤ������˥��󥯥롼�ɤ��Ƥ����٤��ե�����
 *  �Ϥʤ�
 */

#ifndef TOPPERS_OS_H
#define TOPPERS_OS_H

/*
 *  ���̤Υǡ�������������ޥ���
 */
#include "Std_Types.h"
#include "MemMap.h"
#include "Rte_Os_Type.h"

#if !defined(TOPPERS_CFG1_OUT) && !defined(OMIT_INCLUDE_OS_CFG)
#include "Os_Cfg.h"
#endif

/*
 *  �������åȰ�¸��
 */
#include "target_kernel.h"

#ifndef TOPPERS_MACRO_ONLY

/*
 *  �ǡ����������
 */

/*
 *  ���֥��������ֹ�η����
 */
typedef uint8	TaskStateType;              /* ���������� */
typedef uint32	EventMaskType;              /* ���٥�ȥޥ��� */
typedef uint32	TickType;                   /* �������͡ʥƥ��å���*/
typedef uint32	AppModeType;                /* ���ץꥱ�������⡼�� */
typedef uint8	OSServiceIdType;            /* �����ƥॵ���ӥ�ID */
typedef uint8	ScheduleTableStatusType;    /* �������塼��ơ��֥���� */
typedef uint8	ProtectionReturnType;       /* �ץ�ƥ������եå�������֤��� */
typedef uintptr	MemorySizeType;             /* �����ΰ襵���� */

typedef struct {
	TickType	maxallowedvalue;            /* �����󥿻���κ����� */
	TickType	ticksperbase;               /* OS�Ǥϻ��Ѥ������桼������ͳ�˻��Ѥ����� */
	TickType	mincycle;                   /* �����������κǾ��� */
} AlarmBaseType;

/*
 *  ��Ŭ�����뤿�ᡤ��¸��������Ǥ��뷿
 */
#ifndef OMIT_DATA_TYPE
typedef uint32	TimeType;                   /* ���� */
typedef uint32	AlarmType;                  /* ���顼��ID */
typedef uint32	ResourceType;               /* �꥽����ID */
typedef uint32	TaskType;                   /* ������ID */
typedef uint32	ISRType;                    /* ISR ID */
typedef uint32	CounterType;                /* ������ID */
typedef uint32	ScheduleTableType;          /* �������塼��ơ��֥�ID */
typedef float32	PhysicalTimeType;           /* �ʥƥ��å�������֤˴����ѡ˻��� */
#endif /* OMIT_DATA_TYPE */

typedef AlarmBaseType *				AlarmBaseRefType;
typedef TaskType *					TaskRefType;
typedef TaskStateType *				TaskStateRefType;
typedef EventMaskType *				EventMaskRefType;
typedef TickType *					TickRefType;
typedef ScheduleTableStatusType *	ScheduleTableStatusRefType;

/*
 *  �ݸ��ȿ�򵯤���������ñ�̤η�
 */
typedef uint8 FaultyContextType;

/*
 *  OS���֥�����������ѤΥޥ���
 */
#define DeclareTask(TaskIdentifier)
#define DeclareResource(ResourceIdentifier)
#define DeclareEvent(EventIdentifier)
#define DeclareAlarm(AlarmIdentifier)

/*
 *  �ᥤ��롼��������ѤΥޥ���
 */
#define TASK(TaskName)		void TaskMain ## TaskName(void)
#define ISR(ISRName)		void ISRMain ## ISRName(void)
#ifndef C1ISR
#define C1ISR(ISRName)		void C1ISRMain ## ISRName(void)
#endif /* C1ISR */
#define ALARMCALLBACK(AlarmCallBackName) \
	void AlarmMain ## AlarmCallBackName(void)

/*
 *  �����ΰ���ݤΤ���η����
 */
#ifndef TOPPERS_STK_T
#define TOPPERS_STK_T	sintptr
#endif /* TOPPERS_STK_T */
typedef	TOPPERS_STK_T StackType;    /* �����å��ΰ����ݤ��뤿��η� */

/*
 *  �����ƥॵ���ӥ��ѥ�᡼�������Τ�������
 */
typedef union {
	TaskType					tskid;
	TaskRefType					p_tskid;
	TaskStateRefType			p_stat;
	ResourceType				resid;
	EventMaskType				mask;
	EventMaskRefType			p_mask;
	AlarmType					almid;
	AlarmBaseRefType			p_info;
	TickRefType					p_tick;
	TickRefType					p_val;
	TickRefType					p_eval;
	TickType					incr;
	TickType					cycle;
	TickType					start;
	AppModeType					mode;
	CounterType					cntid;
	ScheduleTableType			schtblid;
	TickType					offset;
	ScheduleTableType			schtblid_from;
	ScheduleTableType			schtblid_to;
	ScheduleTableStatusRefType	p_schtblstate;
} _ErrorHook_Par;

/*
 *  �����ΰ���ݤΤ���Υޥ���
 *
 *  �ʲ���TOPPERS_COUNT_SZ��TOPPERS_ROUND_SZ������ϡ�unit��2�ζҾ�Ǥ�
 *  �뤳�Ȥ��ꤷ�Ƥ��롥
 */
#ifndef TOPPERS_COUNT_SZ
#define TOPPERS_COUNT_SZ(sz, unit)	(((sz) + (unit) - (1U)) / (unit))
#endif /* TOPPERS_COUNT_SZ */
#ifndef TOPPERS_ROUND_SZ
#define TOPPERS_ROUND_SZ(sz, unit)	(((sz) + (unit) - (1U)) & (~((unit) - (1U))))
#endif /* TOPPERS_ROUND_SZ */

#define COUNT_STK_T(sz)		(TOPPERS_COUNT_SZ((sz), sizeof(StackType)))
#define ROUND_STK_T(sz)		(TOPPERS_ROUND_SZ((sz), sizeof(StackType)))

/*
 *  �����ƥॵ���ӥ�API�����
 */

/*
 *  OS����
 */
extern AppModeType GetActiveApplicationMode(void);
extern void StartOS(AppModeType Mode);
extern void ShutdownOS(StatusType Error);
extern FaultyContextType GetFaultyContext(void);

/*
 *  ����������
 */
extern StatusType ActivateTask(TaskType TaskID);
extern StatusType TerminateTask(void);
extern StatusType ChainTask(TaskType TaskID);
extern StatusType Schedule(void);
extern StatusType GetTaskID(TaskRefType TaskID);
extern StatusType GetTaskState(TaskType TaskID, TaskStateRefType State);

/*
 *  ����ߴ���
 */
extern void EnableAllInterrupts(void);
extern void DisableAllInterrupts(void);
extern void ResumeAllInterrupts(void);
extern void SuspendAllInterrupts(void);
extern void ResumeOSInterrupts(void);
extern void SuspendOSInterrupts(void);
extern ISRType GetISRID(void);

/*
 *  ���٥�ȴ���
 */
extern StatusType SetEvent(TaskType TaskID, EventMaskType Mask);
extern StatusType ClearEvent(EventMaskType Mask);
extern StatusType GetEvent(TaskType TaskID, EventMaskRefType Event);
extern StatusType WaitEvent(EventMaskType Mask);

/*
 *  �꥽��������
 */
extern StatusType GetResource(ResourceType ResID);
extern StatusType ReleaseResource(ResourceType ResID);

/*
 *  ����������
 */
extern StatusType IncrementCounter(CounterType CounterID);

/*
 *  ���եȥ������ե꡼��󥿥�������
 */
extern StatusType GetCounterValue(CounterType CounterID, TickRefType Value);
extern StatusType GetElapsedValue(CounterType CounterID, TickRefType Value, TickRefType ElapsedValue);

/*
 *  ���顼������
 */
extern StatusType GetAlarmBase(AlarmType AlarmID, AlarmBaseRefType Info);
extern StatusType GetAlarm(AlarmType AlarmID, TickRefType Tick);
extern StatusType SetRelAlarm(AlarmType AlarmID, TickType increment, TickType cycle);
extern StatusType SetAbsAlarm(AlarmType AlarmID, TickType start, TickType cycle);
extern StatusType CancelAlarm(AlarmType AlarmID);

/*
 *  �������塼��ơ��֥�����
 */
extern StatusType StartScheduleTableRel(ScheduleTableType ScheduleTableID, TickType Offset);
extern StatusType StartScheduleTableAbs(ScheduleTableType ScheduleTableID, TickType Start);
extern StatusType StopScheduleTable(ScheduleTableType ScheduleTableID);
extern StatusType NextScheduleTable(ScheduleTableType ScheduleTableID_From, ScheduleTableType ScheduleTableID_To);
extern StatusType GetScheduleTableStatus(ScheduleTableType ScheduleTableID, ScheduleTableStatusRefType ScheduleStatus);

#if !defined(TOPPERS_CFG1_OUT) && !defined(OMIT_INCLUDE_OS_CFG) && !defined(OMIT_INCLUDE_OS_LCFG)
#include "Os_Lcfg.h"
#endif

/*
 *  �եå��롼����
 */
#ifdef CFG_USE_ERRORHOOK
extern void ErrorHook(StatusType Error);
#endif /* CFG_USE_ERRORHOOK */

#ifdef CFG_USE_PRETASKHOOK
extern void PreTaskHook(void);
#endif /* CFG_USE_PRETASKHOOK */

#ifdef CFG_USE_POSTTASKHOOK
extern void PostTaskHook(void);
#endif /* CFG_USE_POSTTASKHOOK */

#ifdef CFG_USE_STARTUPHOOK
extern void StartupHook(void);
#endif /* CFG_USE_STARTUPHOOK */

#ifdef CFG_USE_SHUTDOWNHOOK
extern void ShutdownHook(StatusType Error);
#endif /* CFG_USE_SHUTDOWNHOOK */

#ifdef CFG_USE_PROTECTIONHOOK
extern ProtectionReturnType ProtectionHook(StatusType FatalError);
#endif /* CFG_USE_PROTECTIONHOOK */

/*
 *  �ե�����̾�����ֹ�λ����Ѥ��ѿ�
 */
extern const char8	*fatal_file_name;   /* �ե�����̾ */
extern sint32		fatal_line_num;     /* ���ֹ� */

#endif /* TOPPERS_MACRO_ONLY */

/*
 *  OS�Υ��顼������
 */
#define E_OS_ACCESS							UINT_C(1)
#define E_OS_CALLEVEL						UINT_C(2)
#define E_OS_ID								UINT_C(3)
#define E_OS_LIMIT							UINT_C(4)
#define E_OS_NOFUNC							UINT_C(5)
#define E_OS_RESOURCE						UINT_C(6)
#define E_OS_STATE							UINT_C(7)
#define E_OS_VALUE							UINT_C(8)
#define E_OS_SERVICEID						UINT_C(9)
#define E_OS_ILLEGAL_ADDRESS				UINT_C(10)
#define E_OS_MISSINGEND						UINT_C(11)
#define E_OS_DISABLEDINT					UINT_C(12)
#define E_OS_STACKFAULT						UINT_C(13)
#define E_OS_PROTECTION_MEMORY				UINT_C(14)
#define E_OS_PROTECTION_TIME_TASK			UINT_C(15)
#define E_OS_PROTECTION_TIME_ISR			UINT_C(16)
#define E_OS_PROTECTION_ARRIVAL_TASK		UINT_C(17)
#define E_OS_PROTECTION_ARRIVAL_ISR			UINT_C(18)
#define E_OS_PROTECTION_LOCKED_RESOURCE		UINT_C(19)
#define E_OS_PROTECTION_LOCKED_OSINT		UINT_C(20)
#define E_OS_PROTECTION_LOCKED_ALLINT		UINT_C(21)
#define E_OS_PROTECTION_EXCEPTION			UINT_C(22)
#define E_OS_PROTECTION_FATAL				UINT_C(23)
#define E_OS_MODE							UINT_C(24)
#define E_OS_SHUTDOWN_FATAL					UINT_C(25)
#define E_OS_PARAM_POINTER					UINT_C(26)
#define E_OS_SYS_ASSERT_FATAL				UINT_C(27)

/* AUTOSAR����R4.0.3�Ȥθߴ�����θ */
#define OS_E_PARAM_POINTER					E_OS_PARAM_POINTER

#define ERRCODE_NUM							UINT_C(27) /* ���顼�����ɿ� */

/*
 *  ����¾�������
 */
#define UINT32_INVALID		UINT_C(0xffffffff)
#define UINT8_INVALID		UINT_C(0xff)

#define SUSPENDED			((TaskStateType) 0) /* �ٻ߾��� */
#define RUNNING				((TaskStateType) 1) /* �¹Ծ��� */
#define READY				((TaskStateType) 2) /* �¹Բ�ǽ���� */
#define WAITING				((TaskStateType) 3) /* �Ԥ����� */

/*
 *  ��Ŭ�����뤿�ᡤ��¸���Ǥκ������ɬ��
 */
#ifndef OMIT_DATA_TYPE
#define INVALID_TASK			((TaskType) UINT32_INVALID)
#define INVALID_ISR				((ISRType) UINT32_INVALID)
#endif /* OMIT_DATA_TYPE */
#define INVALID_APPMODETYPE	((AppModeType) UINT32_INVALID)

/*
 *  �������塼��ơ��֥�Υ��ơ��������
 */
#define SCHEDULETABLE_STOPPED					((ScheduleTableStatusType) 0x01)
#define SCHEDULETABLE_NEXT						((ScheduleTableStatusType) 0x02)
#define SCHEDULETABLE_WAITING					((ScheduleTableStatusType) 0x04)
#define SCHEDULETABLE_RUNNING					((ScheduleTableStatusType) 0x08)
#define SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS	((ScheduleTableStatusType) 0x10)

/*
 *  �����ƥॵ���ӥ�ID
 */
#define OSServiceId_GetISRID					((OSServiceIdType) 0x01)
#define OSServiceId_StartScheduleTableRel		((OSServiceIdType) 0x07)
#define OSServiceId_StartScheduleTableAbs		((OSServiceIdType) 0x08)
#define OSServiceId_StopScheduleTable			((OSServiceIdType) 0x09)
#define OSServiceId_NextScheduleTable			((OSServiceIdType) 0x0a)
#define OSServiceId_GetScheduleTableStatus		((OSServiceIdType) 0x0e)
#define OSServiceId_IncrementCounter			((OSServiceIdType) 0x0f)
#define OSServiceId_GetCounterValue				((OSServiceIdType) 0x10)
#define OSServiceId_GetElapsedValue				((OSServiceIdType) 0x11)

#define OSServiceId_TaskMissingEnd				((OSServiceIdType) 0xaf)
#define OSServiceId_ISRMissingEnd				((OSServiceIdType) 0xb0)
#define OSServiceId_HookMissingEnd				((OSServiceIdType) 0xb1)

#define OSServiceId_ActivateTask				((OSServiceIdType) 0xe0)
#define OSServiceId_TerminateTask				((OSServiceIdType) 0xe1)
#define OSServiceId_ChainTask					((OSServiceIdType) 0xe2)
#define OSServiceId_Schedule					((OSServiceIdType) 0xe3)
#define OSServiceId_GetTaskID					((OSServiceIdType) 0xe4)
#define OSServiceId_GetTaskState				((OSServiceIdType) 0xe5)
#define OSServiceId_EnableAllInterrupts			((OSServiceIdType) 0xe6)
#define OSServiceId_DisableAllInterrupts		((OSServiceIdType) 0xe7)
#define OSServiceId_ResumeAllInterrupts			((OSServiceIdType) 0xe8)
#define OSServiceId_SuspendAllInterrupts		((OSServiceIdType) 0xe9)
#define OSServiceId_ResumeOSInterrupts			((OSServiceIdType) 0xea)
#define OSServiceId_SuspendOSInterrupts			((OSServiceIdType) 0xeb)
#define OSServiceId_GetResource					((OSServiceIdType) 0xec)
#define OSServiceId_ReleaseResource				((OSServiceIdType) 0xed)
#define OSServiceId_SetEvent					((OSServiceIdType) 0xee)
#define OSServiceId_ClearEvent					((OSServiceIdType) 0xef)
#define OSServiceId_GetEvent					((OSServiceIdType) 0xf0)
#define OSServiceId_WaitEvent					((OSServiceIdType) 0xf1)
#define OSServiceId_GetAlarmBase				((OSServiceIdType) 0xf2)
#define OSServiceId_GetAlarm					((OSServiceIdType) 0xf3)
#define OSServiceId_SetRelAlarm					((OSServiceIdType) 0xf4)
#define OSServiceId_SetAbsAlarm					((OSServiceIdType) 0xf5)
#define OSServiceId_CancelAlarm					((OSServiceIdType) 0xf6)
#define OSServiceId_GetActiveApplicationMode	((OSServiceIdType) 0xf7)
#define OSServiceId_StartOS						((OSServiceIdType) 0xf8)
#define OSServiceId_ShutdownOS					((OSServiceIdType) 0xf9)

/*
 *  �ݸ��ȿ�򵯤���������ñ�̤����
 */
#define FC_INVALID			UINT_C(0x00)        /* �ݸ��ȿ�򵯤���������ñ�̤�����Ǥ��ʤ� */
#define FC_TASK				UINT_C(0x01)        /* �ݸ��ȿ�򵯤���������ñ�̤������� */
#define FC_C2ISR			UINT_C(0x02)        /* �ݸ��ȿ�򵯤���������ñ�̤�C2ISR */
#define FC_SYSTEM_HOOK		UINT_C(0x03)        /* �ݸ��ȿ�򵯤���������ñ�̤������ƥ�����Υեå� */

/*
 *  �����ƥॵ���ӥ��ѥ�᡼�������Τ�������
 */
#ifndef TOPPERS_MACRO_ONLY

/*
 *  ���顼�եå�OFF���������ӥ�ID�����ȥѥ�᡼��������OFF�ˤʤ�
 */
#ifdef CFG_USE_ERRORHOOK

#ifdef CFG_USE_GETSERVICEID
extern OSServiceIdType	_errorhook_svcid;
#endif /* CFG_USE_GETSERVICEID */

#ifdef CFG_USE_PARAMETERACCESS
extern _ErrorHook_Par	errorhook_par1;
extern _ErrorHook_Par	errorhook_par2;
extern _ErrorHook_Par	errorhook_par3;
#endif /* CFG_USE_PARAMETERACCESS */

#endif /* CFG_USE_ERRORHOOK */

#endif /* TOPPERS_MACRO_ONLY */

/*
 *  ���顼�եå�OFF���������ӥ�ID�����ȥѥ�᡼��������OFF�ˤʤ�
 */
#ifdef CFG_USE_ERRORHOOK

/*
 *  �ޥ�������
 */
#ifdef CFG_USE_GETSERVICEID
#define OSErrorGetServiceId()				(_errorhook_svcid)
#endif /* CFG_USE_GETSERVICEID */

/*
 *  ���顼������������������ƥॵ���ӥ�ID
 */
#ifdef CFG_USE_PARAMETERACCESS
#define OSError_StartOS_Mode()									(errorhook_par1.mode)
#define OSError_ActivateTask_TaskID()							(errorhook_par1.tskid)
#define OSError_ChainTask_TaskID()								(errorhook_par1.tskid)
#define OSError_GetTaskID_TaskID()								(errorhook_par1.p_tskid)
#define OSError_GetTaskState_TaskID()							(errorhook_par1.tskid)
#define OSError_GetTaskState_State()							(errorhook_par2.p_stat)
#define OSError_GetResource_ResID()								(errorhook_par1.resid)
#define OSError_ReleaseResource_ResID()							(errorhook_par1.resid)
#define OSError_SetEvent_TaskID()								(errorhook_par1.tskid)
#define OSError_SetEvent_Mask()									(errorhook_par2.mask)
#define OSError_ClearEvent_Mask()								(errorhook_par1.mask)
#define OSError_GetEvent_TaskID()								(errorhook_par1.tskid)
#define OSError_GetEvent_Event()								(errorhook_par2.p_mask)
#define OSError_WaitEvent_Mask()								(errorhook_par1.mask)
#define OSError_GetAlarmBase_AlarmID()							(errorhook_par1.almid)
#define OSError_GetAlarmBase_Info()								(errorhook_par2.p_info)
#define OSError_GetAlarm_AlarmID()								(errorhook_par1.almid)
#define OSError_GetAlarm_Tick()									(errorhook_par2.p_tick)
#define OSError_SetRelAlarm_AlarmID()							(errorhook_par1.almid)
#define OSError_SetRelAlarm_increment()							(errorhook_par2.incr)
#define OSError_SetRelAlarm_cycle()								(errorhook_par3.cycle)
#define OSError_SetAbsAlarm_AlarmID()							(errorhook_par1.almid)
#define OSError_SetAbsAlarm_start()								(errorhook_par2.start)
#define OSError_SetAbsAlarm_cycle()								(errorhook_par3.cycle)
#define OSError_CancelAlarm_AlarmID()							(errorhook_par1.almid)
#define OSError_IncrementCounter_CounterID()					(errorhook_par1.cntid)
#define OSError_GetCounterValue_CounterID()						(errorhook_par1.cntid)
#define OSError_GetCounterValue_Value()							(errorhook_par2.p_val)
#define OSError_GetElapsedValue_CounterID()						(errorhook_par1.cntid)
#define OSError_GetElapsedValue_Value()							(errorhook_par2.p_val)
#define OSError_GetElapsedValue_ElapsedValue()					(errorhook_par3.p_eval)
#define OSError_StartScheduleTableRel_ScheduleTableID()			(errorhook_par1.schtblid)
#define OSError_StartScheduleTableRel_Offset()					(errorhook_par2.offset)
#define OSError_StartScheduleTableAbs_ScheduleTableID()			(errorhook_par1.schtblid)
#define OSError_StartScheduleTableAbs_Start()					(errorhook_par2.start)
#define OSError_StopScheduleTable_ScheduleTableID()				(errorhook_par1.schtblid)
#define OSError_NextScheduleTable_ScheduleTableID_From()		(errorhook_par1.schtblid_from)
#define OSError_NextScheduleTable_ScheduleTableID_To()			(errorhook_par2.schtblid_to)
#define OSError_GetScheduleTableStatus_ScheduleTableID()		(errorhook_par1.schtblid)
#define OSError_GetScheduleTableStatus_ScheduleStatus()			(errorhook_par2.p_schtblstate)


#endif /* CFG_USE_PARAMETERACCESS */

#endif /* CFG_USE_ERRORHOOK */

/*
 *  �ץ�ƥ������եå��ط��Υޥ���
 */
#define PRO_IGNORE					UINT_C(0x00)
#define PRO_SHUTDOWN				UINT_C(0x01)

/*
 *  �С���������
 */
#define OS_SW_MAJOR_VERSION				UINT_C(1)   /* ���ץ饤�䡼�С������ */
#define OS_SW_MINOR_VERSION				UINT_C(3)
#define OS_SW_PATCH_VERSION				UINT_C(2)

#define OS_AR_RELEASE_MAJOR_VERSION		UINT_C(4)   /* AUTOSAR��꡼���С������ */
#define OS_AR_RELEASE_MINOR_VERSION		UINT_C(0)
#define OS_AR_RELEASE_REVISION_VERSION	UINT_C(3)

#define TKERNEL_NAME	"TOPPERS/ATK2-SC1"  /* �����ͥ�̾�Ρ��ȼ����͡� */

#endif /* TOPPERS_OS_H */
