/*
 *  TOPPERS ATK2
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *      Automotive Kernel Version 2
 *
 *  Copyright (C) 2007-2015 by Center for Embedded Computing Systems
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
 *  $Id: trace_dump.c 1801 2015-03-27 06:34:43Z t_ishikawa $
 */

/*
 *		�ȥ졼�����Υ����
 */

#include "kernel_impl.h"
#include "task.h"
#include "alarm.h"
#include "scheduletable.h"
#include "log_output.h"
#include "Os_Lcfg.h"
#include "t_stdlib.h" /* atk2_strerror */

/*
 *  ����ñ�̤μ���
 */
typedef enum {
	PR_UNIT_TASK,       /* ������ */
	PR_UNIT_ALARM,      /* ���顼����λ���� */
	PR_UNIT_ISR,        /* C2ISR */
	PR_UNIT_SCHTBL,     /* �������塼��ơ��֥���λ���� */
	PR_UNIT_STA,        /* �������ȥ��åץեå� */
	PR_UNIT_ERR,        /* ���顼�եå� */
	PR_UNIT_PRO,        /* �ץ�ƥ������եå� */
	PR_UNIT_SHUT        /* ����åȥ�����եå� */
} PR_UNIT_TYPE;

/*
 *  ����ñ�̤�ID
 */
typedef struct {
	PR_UNIT_TYPE	type;   /* ����ñ�̤μ��� */
	ObjectIDType	id;     /* ����ñ�̤�ID */
} OBJ_ID;


/* �����ؿ��Υץ�ȥ�������� */
static const char8 *trace_proret_str(ProtectionReturnType ret);
static const char8 *trace_schtblstatus_str(ScheduleTableStatusType status);
static const char8 *atk2_task_state_str(TaskStateType state);
static uintptr trace_get_tskid(uintptr info);
static const char8 *trace_print_tskenter(const TRACE *trace, uintptr info[]);
static const char8 *trace_print_tskleave(const TRACE *trace, uintptr info[]);
static const char8 *trace_print_evententer(const TRACE *trace, uintptr info[]);
static const char8 *trace_print_eventleave(const TRACE *trace, uintptr info[]);
static const char8 *trace_print_resenter(const TRACE *trace, uintptr info[]);
static const char8 *trace_print_resleave(const TRACE *trace, uintptr info[]);
static const char8 *trace_print_almenter(const TRACE *trace, uintptr info[]);
static const char8 *trace_print_almleave(const TRACE *trace, uintptr info[]);
static const char8 *trace_print_schtblenter(const TRACE *trace, uintptr info[]);
static const char8 *trace_print_schtblleave(const TRACE *trace, uintptr info[]);
static const char8 *trace_print_intenter(const TRACE *trace, uintptr info[]);
static const char8 *trace_print_intleave(const TRACE *trace, uintptr info[]);
static const char8 *trace_print_sysenter(const TRACE *trace, uintptr info[]);
static const char8 *trace_print_sysleave(const TRACE *trace, uintptr info[]);
static const char8 *trace_print_kerenter(const TRACE *trace, uintptr info[], void (*outputc)(char8 c));
static const char8 *trace_print_svcenter(const TRACE *trace, uintptr info[], void (*outputc)(char8 c));
static const char8 *trace_print_svcleave(const TRACE *trace, uintptr info[]);
static void trace_set_context(PR_UNIT_TYPE type, ObjectIDType id);
static void trace_push_context(PR_UNIT_TYPE type, ObjectIDType id);
static void trace_get_context(uintptr *p_obj_type_str, uintptr *p_id);
static void trace_pop_context(uintptr *p_obj_type_str, uintptr *p_id);
static void trace_change_context(PR_UNIT_TYPE type, ObjectIDType id);
static void trace_resume_context(void);
static void trace_print(const TRACE *p_trace, void (*outputc)(char8 c));

/*
 *  �ץ�ƥ������եå����֤��ͤ�ʸ�����Ѵ�
 */
static const char8 *
trace_proret_str(ProtectionReturnType ret)
{
	const char8 *proretstr;

	switch (ret) {
	case PRO_IGNORE:
		proretstr = "IGNORE";
		break;
	case PRO_SHUTDOWN:
		proretstr = "SHUTDOWN";
		break;
	default:
		proretstr = "";
		break;
	}
	return(proretstr);
}

/*
 *  �������塼��ơ��֥�ξ��֤�ʸ�����Ѵ�
 */
static const char8 *
trace_schtblstatus_str(ScheduleTableStatusType status)
{
	const char8 *schtblstr;

	switch (status) {
	case SCHEDULETABLE_STOPPED:
		schtblstr = "STOPPED";
		break;
	case SCHEDULETABLE_NEXT:
		schtblstr = "NEXT";
		break;
	case SCHEDULETABLE_WAITING:
		schtblstr = "WAITING";
		break;
	case SCHEDULETABLE_RUNNING:
		schtblstr = "RUNNING";
		break;
	case SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS:
		schtblstr = "RUNNING_AND_SYNCHRONOUS";
		break;
	default:
		schtblstr = "";
		break;
	}
	return(schtblstr);
}

/*
 *  ���������֤�ʸ�����Ѵ�
 */
static const char8 *
atk2_task_state_str(TaskStateType state)
{
	const char8 *taskstatstr;

	switch (state) {
	case SUSPENDED:
		taskstatstr = "SUSPENDED";
		break;
	case RUNNING:
		taskstatstr = "RUNNING";
		break;
	case READY:
		taskstatstr = "READY";
		break;
	case WAITING:
		taskstatstr = "WAITING";
		break;
	default:
		taskstatstr = "unknown state";
		break;
	}
	return(taskstatstr);
}

/*
 *  PR_UNIT_TYPE�ν���ñ�̼��̤��б�����ʸ����
 */
static const char8	*obj_type_to_str[] = {
	"task",
	"alarm",
	"isr",
	"schtbl",
	"sta",
	"err",
	"pro",
	"shut"
};

/*
 *  2�Ĥΰ������礭�������֤�
 */
#define MAX(a, b)	((a) < (b) ? (b) : (a))

/*
 *  ����ñ�̤Υͥ��Ȥ�������륹���å�
 */
static OBJ_ID		context_stack[MAX(4U, 1U + TNUM_ISR2)];

/*
 *  ���������¹Ԥ��Ƥ��륢�顼����λ�������������塼��ơ��֥���λ����
 *  ���������
 *  ���顼����λ������IncrementCounter�ˤ��ͥ��Ȥ����礬����
 *  �������塼��ơ��֥���λ�����Υͥ��ȤϤʤ�
 */
static OBJ_ID		task_exec[TNUM_TASK][TNUM_ALARM + 1U];

/*
 *  �����������顼����λ�������������塼��ơ��֥���λ������¹Ԥ��Ƥ�
 *  ����Ρ�task_exec[task_id][index]��index�򼨤�
 *  ��λ������¹Ԥ��Ƥ��ʤ�����-1�ˤ���
 */
static sint32		task_context_index[TNUM_TASK];

/*
 *  task_exec��C2ISR��
 */
static OBJ_ID		isr_exec[TNUM_ISR2][TNUM_ALARM + 1U];

/*
 *  task_context_index��C2ISR��
 */
static sint32		isr_context_index[TNUM_ISR2];

/*
 *  context_stack�θ��ߤΥ���ǥå���(�ͥ��ȿ�)�򼨤�
 */
static uint32		context_index;

/*
 *  tcb���饿����ID�����
 */
static uintptr
trace_get_tskid(uintptr info)
{
	TCB			*p_tcb;
	TaskType	tskid;

	p_tcb = (TCB *) info;
	if (p_tcb == NULL) {
		tskid = 0U;
	}
	else {
		tskid = TSKID(p_tcb);
	}
	return((uintptr) tskid);
}


/*
 *  ���������� - ������
 */
static const char8 *
trace_print_tskenter(const TRACE *trace, uintptr info[])
{
	uint32		type;
	const char8	*tracemsg;

	type = (const uint32) trace->loginfo[0];

	switch (type) {

	case TFN_ACTIVATETASK:
		info[0] = (uintptr) atk2_tskid_str((TaskType) trace->loginfo[1]);
		info[1] = trace->loginfo[1];
		tracemsg = "enter to ActivateTask TaskID=%s(%d).";
		break;

	case TFN_TERMINATETASK:
		tracemsg = "enter to TerminateTask.";
		break;

	case TFN_CHAINTASK:
		info[0] = (uintptr) atk2_tskid_str((TaskType) trace->loginfo[1]);
		info[1] = trace->loginfo[1];
		tracemsg = "enter to ChainTask TaskID=%s(%d).";
		break;

	case TFN_SCHEDULE:
		tracemsg = "enter to Schedule.";
		break;

	default:
		tracemsg = "unknown service call";
		break;
	}

	return(tracemsg);
}


/*
 *  ���������� - �и���
 */
static const char8 *
trace_print_tskleave(const TRACE *trace, uintptr info[])
{
	uint32		type;
	const char8	*tracemsg;

	type = (const uint32) trace->loginfo[0];

	switch (type) {

	case TFN_ACTIVATETASK:
		info[0] = (uintptr) atk2_strerror((StatusType) trace->loginfo[1]);
		tracemsg = "leave from ActivateTask %s.";
		break;

	case TFN_TERMINATETASK:
		info[0] = (uintptr) atk2_strerror((StatusType) trace->loginfo[1]);
		tracemsg = "leave from TerminateTask %s.";
		break;

	case TFN_CHAINTASK:
		info[0] = (uintptr) atk2_strerror((StatusType) trace->loginfo[1]);
		tracemsg = "leave from ChainTask %s.";
		break;

	case TFN_SCHEDULE:
		info[0] = (uintptr) atk2_strerror((StatusType) trace->loginfo[1]);
		tracemsg = "leave from Schedule %s.";
		break;

	default:
		tracemsg = "unknown tsk service call";
		break;
	}

	return(tracemsg);
}


/*
 *  ���٥�ȵ�ǽ - ������
 */
static const char8 *
trace_print_evententer(const TRACE *trace, uintptr info[])
{
	uint32		type;
	const char8	*tracemsg;

	type = (const uint32) trace->loginfo[0];

	switch (type) {
	case TFN_SETEVENT:
		info[0] = (uintptr) atk2_tskid_str((TaskType) trace->loginfo[1]);
		info[1] = trace->loginfo[1];
		info[2] = (uintptr) atk2_evtid_str((TaskType) trace->loginfo[1], (EventMaskType) trace->loginfo[2]);
		info[3] = trace->loginfo[2];
		tracemsg = "enter to SetEvent TaskID=%s(%d)/Mask=%s(0x%x).";
		break;

	case TFN_CLEAREVENT:
		info[0] = (uintptr) atk2_evtid_str((TaskType) trace_get_tskid(trace->loginfo[1]), (EventMaskType) trace->loginfo[2]);
		info[1] = trace->loginfo[2];
		tracemsg = "enter to ClearEvent Mask=%s(0x%x).";
		break;

	case TFN_GETEVENT:
		info[0] = (uintptr) atk2_tskid_str((TaskType) trace->loginfo[1]);
		info[1] = trace->loginfo[1];
		tracemsg = "enter to GetEvent TaskID=%s(%d).";
		break;

	case TFN_WAITEVENT:
		info[0] = (uintptr) atk2_evtid_str((TaskType) trace_get_tskid(trace->loginfo[1]), (EventMaskType) trace->loginfo[2]);
		info[1] = trace->loginfo[2];
		tracemsg = "enter to WaitEvent Mask=%s(0x%x).";
		break;

	default:
		tracemsg = "unknown service call";
		break;
	}

	return(tracemsg);
}


/*
 *  ���٥�ȵ�ǽ - �и���
 */
static const char8 *
trace_print_eventleave(const TRACE *trace, uintptr info[])
{
	uint32		type;
	const char8	*tracemsg;

	type = (const uint32) trace->loginfo[0];

	switch (type) {
	case TFN_SETEVENT:
		info[0] = (uintptr) atk2_strerror((StatusType) trace->loginfo[1]);
		tracemsg = "leave from SetEvent %s.";
		break;

	case TFN_CLEAREVENT:
		info[0] = (uintptr) atk2_strerror((StatusType) trace->loginfo[1]);
		tracemsg = "leave from ClearEvent %s.";
		break;

	case TFN_GETEVENT:
		info[0] = (uintptr) atk2_strerror((StatusType) trace->loginfo[1]);
		/* �֤��ͤ�E_OK�ξ��Τߡ�ͭ���ͤ����� */
		if (trace->loginfo[1] == E_OK) {
			info[1] = (uintptr) atk2_evtid_str((TaskType) trace->loginfo[2], (EventMaskType) trace->loginfo[3]);
			info[2] = trace->loginfo[3];
			tracemsg = "leave from GetEvent %s/Mask=%s(0x%x).";
		}
		else {
			tracemsg = "leave from GetEvent %s.";
		}
		break;

	case TFN_WAITEVENT:
		info[0] = (uintptr) atk2_strerror((StatusType) trace->loginfo[1]);
		tracemsg = "leave from WaitEvent %s.";
		break;

	default:
		tracemsg = "unknown servic call";
		break;
	}

	return(tracemsg);
}


/*
 *  �꥽������ǽ - ������
 */
static const char8 *
trace_print_resenter(const TRACE *trace, uintptr info[])
{
	uint32		type;
	const char8	*tracemsg;

	type = (const uint32) trace->loginfo[0];

	switch (type) {
	case TFN_GETRESOURCE:
		info[0] = (uintptr) atk2_resid_str((ResourceType) trace->loginfo[1]);
		info[1] = trace->loginfo[1];
		tracemsg = "enter to GetResource ResID=%s(%d).";
		break;

	case TFN_RELEASERESOURCE:
		info[0] = (uintptr) atk2_resid_str((ResourceType) trace->loginfo[1]);
		info[1] = trace->loginfo[1];
		tracemsg = "enter to ReleaseResource ResID=%s(%d).";
		break;

	default:
		tracemsg = "unknown service call";
		break;
	}

	return(tracemsg);
}


/*
 *  �꥽������ǽ - �и���
 */
static const char8 *
trace_print_resleave(const TRACE *trace, uintptr info[])
{
	uint32		type;
	const char8	*tracemsg;

	type = (const uint32) trace->loginfo[0];

	switch (type) {
	case TFN_GETRESOURCE:
		info[0] = (uintptr) atk2_strerror((StatusType) trace->loginfo[1]);
		tracemsg = "leave from GetResource %s.";
		break;

	case TFN_RELEASERESOURCE:
		info[0] = (uintptr) atk2_strerror((StatusType) trace->loginfo[1]);
		tracemsg = "leave from ReleaseResource %s.";
		break;

	default:
		tracemsg = "unknown servic call";
		break;
	}

	return(tracemsg);
}

/*
 *  ���顼�ൡǽ - ������
 */
static const char8 *
trace_print_almenter(const TRACE *trace, uintptr info[])
{
	uint32		type;
	const char8	*tracemsg;

	type = (const uint32) trace->loginfo[0];

	switch (type) {
	case TFN_GETALARMBASE:
		info[0] = (uintptr) atk2_almid_str((AlarmType) trace->loginfo[1]);
		info[1] = trace->loginfo[1];
		tracemsg = "enter to GetAlarmBase AlarmID=%s(%d).";
		break;

	case TFN_GETALARM:
		info[0] = (uintptr) atk2_almid_str((AlarmType) trace->loginfo[1]);
		info[1] = trace->loginfo[1];
		tracemsg = "enter to GetAlarm AlarmID=%s(%d).";
		break;

	case TFN_SETRELALARM:
		info[0] = (uintptr) atk2_almid_str((AlarmType) trace->loginfo[1]);
		info[1] = trace->loginfo[1];
		info[2] = trace->loginfo[2];
		info[3] = trace->loginfo[3];
		tracemsg = "enter to SetRelAlarm AlarmID=%s(%d)/increment=%d/cycle=%d.";
		break;

	case TFN_SETABSALARM:
		info[0] = (uintptr) atk2_almid_str((AlarmType) trace->loginfo[1]);
		info[1] = trace->loginfo[1];
		info[2] = trace->loginfo[2];
		info[3] = trace->loginfo[3];
		tracemsg = "enter to SetAbsAlarm AlarmID=%s(%d)/start=%d/cycle=%d.";
		break;

	case TFN_CANCELALARM:
		info[0] = (uintptr) atk2_almid_str((AlarmType) trace->loginfo[1]);
		info[1] = trace->loginfo[1];
		tracemsg = "enter to CancelAlarm AlarmID=%s(%d).";
		break;

	case TFN_INCREMENTCOUNTER:
		info[0] = (uintptr) atk2_cntid_str((CounterType) trace->loginfo[1]);
		info[1] = trace->loginfo[1];
		tracemsg = "enter to IncrementCounter CounterID=%s(%d).";
		break;

	case TFN_GETCOUNTERVALUE:
		info[0] = (uintptr) atk2_cntid_str((CounterType) trace->loginfo[1]);
		info[1] = trace->loginfo[1];
		tracemsg = "enter to GetCounterValue CounterID=%s(%d).";
		break;

	case TFN_GETELAPSEDVALUE:
		info[0] = (uintptr) atk2_cntid_str((CounterType) trace->loginfo[1]);
		info[1] = trace->loginfo[1];
		info[2] = trace->loginfo[2];
		tracemsg = "enter to GetElapsedValue CounterID=%s(%d) Value=%d.";
		break;

	default:
		tracemsg = "unknown service call";
		break;
	}

	return(tracemsg);
}


/*
 *  ���顼�ൡǽ - �и���
 */
static const char8 *
trace_print_almleave(const TRACE *trace, uintptr info[])
{
	uint32		type;
	const char8	*tracemsg;

	type = (const uint32) trace->loginfo[0];

	switch (type) {
	case TFN_GETALARMBASE:
		info[0] = (uintptr) atk2_strerror((StatusType) trace->loginfo[1]);
		/* �֤��ͤ�E_OK�ξ��Τߡ�ͭ���ͤ����� */
		if (trace->loginfo[1] == E_OK) {
			info[1] = trace->loginfo[2];
			info[2] = trace->loginfo[3];
			info[3] = trace->loginfo[4];
			tracemsg = "leave from GetAlarmBase %s/maxval=%d/tickbase=%d/mincyc=%d.";
		}
		else {
			tracemsg = "leave from GetAlarmBase %s.";
		}
		break;

	case TFN_GETALARM:
		info[0] = (uintptr) atk2_strerror((StatusType) trace->loginfo[1]);
		/* �֤��ͤ�E_OK�ξ��Τߡ�ͭ���ͤ����� */
		if (trace->loginfo[1] == E_OK) {
			info[1] = trace->loginfo[2];
			tracemsg = "leave from GetAlarm %s/Tick=%d.";
		}
		else {
			tracemsg = "leave from GetAlarm %s.";
		}
		break;

	case TFN_SETRELALARM:
		info[0] = (uintptr) atk2_strerror((StatusType) trace->loginfo[1]);
		tracemsg = "leave from SetRelAlarm %s.";
		break;

	case TFN_SETABSALARM:
		info[0] = (uintptr) atk2_strerror((StatusType) trace->loginfo[1]);
		tracemsg = "leave from SetAbsAlarm %s.";
		break;

	case TFN_CANCELALARM:
		info[0] = (uintptr) atk2_strerror((StatusType) trace->loginfo[1]);
		tracemsg = "leave from CancelAlarm %s.";
		break;

	case TFN_INCREMENTCOUNTER:
		info[0] = (uintptr) atk2_strerror((StatusType) trace->loginfo[1]);
		tracemsg = "leave from IncrementCounter %s.";
		break;

	case TFN_GETCOUNTERVALUE:
		info[0] = (uintptr) atk2_strerror((StatusType) trace->loginfo[1]);
		/* �֤��ͤ�E_OK�ξ��Τߡ�ͭ���ͤ����� */
		if (trace->loginfo[1] == E_OK) {
			info[1] = trace->loginfo[2];
			tracemsg = "leave from GetCounterValue %s/Value=%d.";
		}
		else {
			tracemsg = "leave from GetCounterValue %s.";
		}
		break;

	case TFN_GETELAPSEDVALUE:
		info[0] = (uintptr) atk2_strerror((StatusType) trace->loginfo[1]);
		/* �֤��ͤ�E_OK�ξ��Τߡ�ͭ���ͤ����� */
		if (trace->loginfo[1] == E_OK) {
			info[1] = trace->loginfo[2];
			info[2] = trace->loginfo[3];
			tracemsg = "leave from GetElapsedValue %s/Value=%d/ElapsedValue=%d.";
		}
		else {
			tracemsg = "leave from GetElapsedValue %s.";
		}
		break;

	default:
		tracemsg = "unknown servic call";
		break;
	}

	return(tracemsg);
}

/*
 *  �������塼��ơ��֥뵡ǽ - ������
 */
static const char8 *
trace_print_schtblenter(const TRACE *trace, uintptr info[])
{
	uint32		type;
	const char8	*tracemsg;

	type = (const uint32) trace->loginfo[0];

	switch (type) {
	case TFN_STARTSCHEDULETABLEREL:
		info[0] = (uintptr) atk2_schtblid_str((ScheduleTableType) trace->loginfo[1]);
		info[1] = trace->loginfo[1];
		info[2] = trace->loginfo[2];
		tracemsg = "enter to StartScheduleTableRel SchtblID=%s(%d)/offset=%d.";
		break;

	case TFN_STARTSCHEDULETABLEABS:
		info[0] = (uintptr) atk2_schtblid_str((ScheduleTableType) trace->loginfo[1]);
		info[1] = trace->loginfo[1];
		info[2] = trace->loginfo[2];
		tracemsg = "enter to StartScheduleTableAbs SchtblID=%s(%d)/start=%d.";
		break;

	case TFN_STOPSCHEDULETABLE:
		info[0] = (uintptr) atk2_schtblid_str((ScheduleTableType) trace->loginfo[1]);
		info[1] = trace->loginfo[1];
		tracemsg = "enter to StopScheduleTable SchtblID=%s(%d).";
		break;

	case TFN_NEXTSCHEDULETABLE:
		info[0] = (uintptr) atk2_schtblid_str((ScheduleTableType) trace->loginfo[1]);
		info[1] = trace->loginfo[1];
		info[2] = (uintptr) atk2_schtblid_str((ScheduleTableType) trace->loginfo[2]);
		info[3] = trace->loginfo[2];
		tracemsg = "enter to NextScheduleTable From_ID=%s(%d)/To_ID=%s(%d).";
		break;

	case TFN_GETSCHEDULETABLESTATUS:
		info[0] = (uintptr) atk2_schtblid_str((ScheduleTableType) trace->loginfo[1]);
		info[1] = trace->loginfo[1];
		tracemsg = "enter to GetScheduleTableStatus SchtblID=%s(%d).";
		break;

	default:
		tracemsg = "unknown service call";
		break;
	}

	return(tracemsg);
}

/*
 *  �������塼��ơ��֥� - �и���
 */
static const char8 *
trace_print_schtblleave(const TRACE *trace, uintptr info[])
{
	uint32		type;
	const char8	*tracemsg;

	type = (const uint32) trace->loginfo[0];

	switch (type) {
	case TFN_STARTSCHEDULETABLEREL:
		info[0] = (uintptr) atk2_strerror((StatusType) trace->loginfo[1]);
		tracemsg = "leave from StartScheduleTableRel %s.";
		break;

	case TFN_STARTSCHEDULETABLEABS:
		info[0] = (uintptr) atk2_strerror((StatusType) trace->loginfo[1]);
		tracemsg = "leave from StartScheduleTableAbs %s.";
		break;

	case TFN_STOPSCHEDULETABLE:
		info[0] = (uintptr) atk2_strerror((StatusType) trace->loginfo[1]);
		tracemsg = "leave from StopScheduleTable %s.";
		break;

	case TFN_NEXTSCHEDULETABLE:
		info[0] = (uintptr) atk2_strerror((StatusType) trace->loginfo[1]);
		tracemsg = "leave from NextScheduleTable %s.";
		break;

	case TFN_GETSCHEDULETABLESTATUS:
		info[0] = (uintptr) atk2_strerror((StatusType) trace->loginfo[1]);
		/* �֤��ͤ�E_OK�ξ��Τߡ�ͭ���ͤ����� */
		if (trace->loginfo[1] == E_OK) {
			info[1] = (uintptr) trace_schtblstatus_str((ScheduleTableStatusType) trace->loginfo[2]);
			tracemsg = "leave from GetScheduleTableStatus %s/status=%s.";
		}
		else {
			tracemsg = "leave from GetScheduleTableStatus %s.";
		}
		break;

	default:
		tracemsg = "unknown servic call";
		break;
	}

	return(tracemsg);
}

/*
 *  ����ߴ�����ǽ - ������
 */
static const char8 *
trace_print_intenter(const TRACE *trace, uintptr info[])
{
	uint32		type;
	const char8	*tracemsg;

	type = (const uint32) trace->loginfo[0];

	switch (type) {
	case TFN_DISABLEALLINTERRUPTS:
		tracemsg = "enter to DisableAllInterrupts.";
		break;

	case TFN_SUSPENDALLINTERRUPTS:
		tracemsg = "enter to SuspendAllInterrupts.";
		break;

	case TFN_SUSPENDOSINTERRUPTS:
		tracemsg = "enter to SuspendOSInterrupts.";
		break;

	case TFN_ENABLEALLINTERRUPTS:
		tracemsg = "enter to EnableAllInterrupts.";
		break;

	case TFN_RESUMEALLINTERRUPTS:
		tracemsg = "enter to ResumeAllInterrupts.";
		break;

	case TFN_RESUMEOSINTERRUPTS:
		tracemsg = "enter to ResumeOSInterrupts.";
		break;

	case TFN_GETISRID:
		tracemsg = "enter to GetISRID.";
		break;

	default:
		tracemsg = "unknown service call";
		break;
	}

	return(tracemsg);
}


/*
 *  ����ߴ�����ǽ - �и���
 */
static const char8 *
trace_print_intleave(const TRACE *trace, uintptr info[])
{
	uint32		type;
	const char8	*tracemsg;

	type = (const uint32) trace->loginfo[0];

	switch (type) {
	case TFN_DISABLEALLINTERRUPTS:
		tracemsg = "leave from DisableAllInterrupts.";
		break;

	case TFN_SUSPENDALLINTERRUPTS:
		tracemsg = "leave from SuspendAllInterrupts.";
		break;

	case TFN_SUSPENDOSINTERRUPTS:
		tracemsg = "leave from SuspendOSInterrupts.";
		break;

	case TFN_ENABLEALLINTERRUPTS:
		tracemsg = "leave from EnableAllInterrupts.";
		break;

	case TFN_RESUMEALLINTERRUPTS:
		tracemsg = "leave from ResumeAllInterrupts.";
		break;

	case TFN_RESUMEOSINTERRUPTS:
		tracemsg = "leave from ResumeOSInterrupts.";
		break;

	case TFN_GETISRID:
		info[0] = (uintptr) atk2_isrid_str((ISRType) trace->loginfo[1]);
		info[1] = (const uintptr) trace->loginfo[1];
		tracemsg = "leave from GetISRID id=%s(%d).";
		break;

	default:
		tracemsg = "unknown servic call";
		break;
	}

	return(tracemsg);
}


/*
 *  �����ƥ���ִ�����ǽ - ������
 */
static const char8 *
trace_print_sysenter(const TRACE *trace, uintptr info[])
{
	uint32		type;
	const char8	*tracemsg;

	type = (const uint32) trace->loginfo[0];

	switch (type) {
	case TFN_GETTASKID:
		tracemsg = "enter to GetTaskID.";
		break;

	case TFN_GETTASKSTATE:
		info[0] = (uintptr) atk2_tskid_str((TaskType) trace->loginfo[1]);
		info[1] = trace->loginfo[1];
		tracemsg = "enter to GetTaskState TaskID=%s(%d).";
		break;

	case TFN_GETACTIVEAPPLICATIONMODE:
		tracemsg = "enter to GetActiveApplicationMode.";
		break;

	default:
		tracemsg = "unknown servic call";
		break;
	}

	return(tracemsg);
}


/*
 * �����ƥ���ִ�����ǽ - �и���
 */
static const char8 *
trace_print_sysleave(const TRACE *trace, uintptr info[])
{
	uint32		type;
	const char8	*tracemsg;

	type = (const uint32) trace->loginfo[0];

	switch (type) {
	case TFN_GETTASKID:
		info[0] = (uintptr) atk2_strerror((StatusType) trace->loginfo[1]);
		/* �֤��ͤ�E_OK�ξ��Τߡ�ͭ���ͤ����� */
		if (trace->loginfo[1] == E_OK) {
			info[1] = (uintptr) atk2_tskid_str(trace->loginfo[2]);
			tracemsg = "leave from GetTaskID %s/TaskID=%s.";
		}
		else {
			tracemsg = "leave from GetTaskID %s.";
		}
		break;

	case TFN_GETTASKSTATE:
		info[0] = (uintptr) atk2_strerror((StatusType) trace->loginfo[1]);
		/* �֤��ͤ�E_OK�ξ��Τߡ�ͭ���ͤ����� */
		if (trace->loginfo[1] == E_OK) {
			info[1] = (uintptr) atk2_task_state_str((TaskStateType) trace->loginfo[2]);
			tracemsg = "leave from GetTaskState %s/State=%s.";
		}
		else {
			tracemsg = "leave from GetTaskState %s.";
		}
		break;

	case TFN_GETACTIVEAPPLICATIONMODE:
		info[0] = (uintptr) atk2_appid_str((AppModeType) trace->loginfo[1]);
		info[1] = trace->loginfo[1];
		tracemsg = "leave from GetActiveApplicationMode mode=%s(%d).";
		break;

	default:
		tracemsg = "unknown servic call";
		break;
	}

	return(tracemsg);
}


/*
 *  �����ͥ�ν�����Ƚ�λ����
 */
static const char8 *
trace_print_kerenter(const TRACE *trace, uintptr info[], void (*outputc)(char8 c))
{
	uint32		type;
	const char8	*tracemsg;
	uintptr		traceinfo[TMAX_LOGINFO + 1U];
	uint32		i;

	type = (const uint32) trace->loginfo[0];

	/* ����åȥ�������ˤ��٤ƤΥ�������SUSPENDED���֤Ȥʤ�褦�ˤ��� */
	for (i = 0U; i < TNUM_TASK; i++) {
		traceinfo[0] = (uintptr) i;
		syslog_printf("task %d becomes SUSPENDED.\n", traceinfo, outputc);
		traceinfo[0] = (uintptr) (trace->logtim);
		syslog_printf("[%d] ", traceinfo, outputc);
	}

	if (type == TFN_SHUTDOWNOS) {
		info[0] = trace->loginfo[1];
		tracemsg = "enter to ShutdownOS Error=%d.";
	}
	else {
		tracemsg = "unknown service call";
	}

	return(tracemsg);
}


/*
 *  �����ƥॳ�����������(LOG_TYPE_SVC|ENTER)
 */
static const char8 *
trace_print_svcenter(const TRACE *trace, uintptr info[], void (*outputc)(char8 c))
{
	uint32		type;
	const char8	*tracemsg;

	type = (const uint32) trace->loginfo[0];

	switch (type) {

	/*���������� */
	case TFN_ACTIVATETASK:
	case TFN_TERMINATETASK:
	case TFN_CHAINTASK:
	case TFN_SCHEDULE:
		tracemsg = trace_print_tskenter(trace, info);
		break;

	/* ���٥�ȵ�ǽ */
	case TFN_SETEVENT:
	case TFN_CLEAREVENT:
	case TFN_GETEVENT:
	case TFN_WAITEVENT:
		tracemsg = trace_print_evententer(trace, info);
		break;

	/* �꥽������ǽ */
	case TFN_RELEASERESOURCE:
	case TFN_GETRESOURCE:
		tracemsg = trace_print_resenter(trace, info);
		break;

	/* ���顼�ൡǽ */
	case TFN_GETALARMBASE:
	case TFN_GETALARM:
	case TFN_SETRELALARM:
	case TFN_SETABSALARM:
	case TFN_CANCELALARM:
	case TFN_INCREMENTCOUNTER:
	case TFN_GETCOUNTERVALUE:
	case TFN_GETELAPSEDVALUE:
		tracemsg = trace_print_almenter(trace, info);
		break;

	/* �������塼��ơ��֥뵡ǽ */
	case TFN_STARTSCHEDULETABLEREL:
	case TFN_STARTSCHEDULETABLEABS:
	case TFN_STOPSCHEDULETABLE:
	case TFN_NEXTSCHEDULETABLE:
	case TFN_GETSCHEDULETABLESTATUS:
		tracemsg = trace_print_schtblenter(trace, info);
		break;

	/* ����ߴ�����ǽ */
	case TFN_DISABLEALLINTERRUPTS:
	case TFN_SUSPENDALLINTERRUPTS:
	case TFN_SUSPENDOSINTERRUPTS:
	case TFN_ENABLEALLINTERRUPTS:
	case TFN_RESUMEALLINTERRUPTS:
	case TFN_RESUMEOSINTERRUPTS:
	case TFN_GETISRID:
		tracemsg = trace_print_intenter(trace, info);
		break;

	/* �����ƥ���ִ�����ǽ */
	case TFN_GETTASKID:
	case TFN_GETTASKSTATE:
	case TFN_GETACTIVEAPPLICATIONMODE:
		tracemsg = trace_print_sysenter(trace, info);
		break;

	/* �����ͥ�ν�����Ƚ�λ���� */
	case TFN_SHUTDOWNOS:
		tracemsg = trace_print_kerenter(trace, info, outputc);
		break;

	default:
		tracemsg = "unknown LOG_TYPE_SVC|ENTER service call";
		break;
	}
	return(tracemsg);
}


/*
 *  �����ƥॳ����νи���(LOG_TYPE_SVC|LEAVE)
 */
static const char8 *
trace_print_svcleave(const TRACE *trace, uintptr info[])
{
	uint32		type;
	const char8	*tracemsg;

	type = (const uint32) trace->loginfo[0];

	switch (type) {
	case TFN_ACTIVATETASK:
	case TFN_TERMINATETASK:
	case TFN_CHAINTASK:
	case TFN_SCHEDULE:
		/* ���������� */
		tracemsg = trace_print_tskleave(trace, info);
		break;

	/* ���٥�ȵ�ǽ */
	case TFN_SETEVENT:
	case TFN_CLEAREVENT:
	case TFN_GETEVENT:
	case TFN_WAITEVENT:
		tracemsg = trace_print_eventleave(trace, info);
		break;

	/* �꥽������ǽ */
	case TFN_RELEASERESOURCE:
	case TFN_GETRESOURCE:
		tracemsg = trace_print_resleave(trace, info);
		break;

	/* ���顼�ൡǽ */
	case TFN_GETALARMBASE:
	case TFN_GETALARM:
	case TFN_SETRELALARM:
	case TFN_SETABSALARM:
	case TFN_CANCELALARM:
	case TFN_INCREMENTCOUNTER:
	case TFN_GETCOUNTERVALUE:
	case TFN_GETELAPSEDVALUE:
		tracemsg = trace_print_almleave(trace, info);
		break;

	/* �������塼��ơ��֥뵡ǽ */
	case TFN_STARTSCHEDULETABLEREL:
	case TFN_STARTSCHEDULETABLEABS:
	case TFN_STOPSCHEDULETABLE:
	case TFN_NEXTSCHEDULETABLE:
	case TFN_GETSCHEDULETABLESTATUS:
		tracemsg = trace_print_schtblleave(trace, info);
		break;

	/* ����ߴ�����ǽ */
	case TFN_DISABLEALLINTERRUPTS:
	case TFN_SUSPENDALLINTERRUPTS:
	case TFN_SUSPENDOSINTERRUPTS:
	case TFN_ENABLEALLINTERRUPTS:
	case TFN_RESUMEALLINTERRUPTS:
	case TFN_RESUMEOSINTERRUPTS:
	case TFN_GETISRID:
		tracemsg = trace_print_intleave(trace, info);
		break;

	/* �����ƥ���ִ�����ǽ */
	case TFN_GETTASKID:
	case TFN_GETTASKSTATE:
	case TFN_GETACTIVEAPPLICATIONMODE:
		tracemsg = trace_print_sysleave(trace, info);
		break;

	default:
		tracemsg = "unknown LOG_TYPE_SVC|LEAVE servic call";
		break;
	}

	return(tracemsg);
}

/*
 *  ����ñ�̤��ڤ��ؤ���
 *  �̾��trace_push_context����ƤФ�뤬��
 *  trace_push_context���ͳ���ʤ����⤢��(���������������ȥ��åץեå�)
 */
static void
trace_set_context(PR_UNIT_TYPE type, ObjectIDType id)
{
	context_stack[context_index].type = type;
	context_stack[context_index].id = id;
}

/*
 *  ����ñ�̥����å���type, id�ǻ��ꤵ������ñ�̤�ץå��夹��
 */
static void
trace_push_context(PR_UNIT_TYPE type, ObjectIDType id)
{
	context_index++;
	trace_set_context(type, id);
}

/*
 *  ���ߤν���ñ�̤��֤�
 *  p_obj_type_str�ˤϽ���ñ�̼��̤�ʸ����������
 *  p_id�ˤϽ���ñ�̤�ID�������
 *  ��������C2ISR�¹���ξ��ǡ����顼����λ������
 *  �������塼��ơ��֥���λ������ԤʤäƤ�����ϡ�������
 *  ���ߤν���ñ�̤Ȥ����֤�
 */
static void
trace_get_context(uintptr *p_obj_type_str, uintptr *p_id)
{
	PR_UNIT_TYPE	type;
	ObjectIDType	id;
	sint32			index;

	type = context_stack[context_index].type;
	id = context_stack[context_index].id;
	if (type == PR_UNIT_TASK) {
		index = task_context_index[id];
		if (index >= 0) {
			id = task_exec[id][index].id;
			type = task_exec[id][index].type;
		}
	}
	else if (type == PR_UNIT_ISR) {
		index = isr_context_index[id];
		if (index >= 0) {
			id = isr_exec[id][index].id;
			type = isr_exec[id][index].type;
		}
	}
	else {
		/* type���嵭�ʳ��ξ�硤�����ϹԤ�ʤ� */
	}
	*p_obj_type_str = (const uintptr) obj_type_to_str[type];
	*p_id = (uintptr) id;
}

/*
 *  trace_push_context�ǥץå��夷������ñ�̤�ݥåסʼ������ˤ���
 *  1�����ν���ñ�̤��֤�
 */
static void
trace_pop_context(uintptr *p_obj_type_str, uintptr *p_id)
{
	context_index--;
	trace_get_context(p_obj_type_str, p_id);
}

/*
 *  ��������C2ISR�¹���˥��顼����λ�������������塼��ơ���
 *  ����λ������ȯ���������ˡ����ߤν���ñ�̤򤽤�����λ�����ˤ���
 */
static void
trace_change_context(PR_UNIT_TYPE type, ObjectIDType id)
{
	sint32		index;
	TaskType	tskid;
	ISRType		isrid;
	if (context_stack[context_index].type == PR_UNIT_TASK) {
		tskid = context_stack[context_index].id;
		task_context_index[tskid]++;
		index = task_context_index[tskid];
		task_exec[tskid][index].id = id;
		task_exec[tskid][index].type = type;
	}
	else if (context_stack[context_index].type == PR_UNIT_ISR) {
		isrid = context_stack[context_index].id;
		isr_context_index[isrid]++;
		index = isr_context_index[isrid];
		isr_exec[isrid][index].id = id;
		isr_exec[isrid][index].type = type;
	}
	else {
		/* �����ˤ���ʤ����������褿��硤�ʹߤΥ����Ƥ�̤�ݾڤȤʤ� */
	}
}

/*
 *  ��������C2ISR�¹���Υ��顼����λ�������������塼��ơ���
 *  ����λ�����ν�λ���˸ƤӽФ�������ñ�̤��᤹
 */
static void
trace_resume_context(void)
{
	TaskType	tskid;
	ISRType		isrid;
	if (context_stack[context_index].type == PR_UNIT_TASK) {
		tskid = context_stack[context_index].id;
		task_context_index[tskid]--;
	}
	else if (context_stack[context_index].type == PR_UNIT_ISR) {
		isrid = context_stack[context_index].id;
		isr_context_index[isrid]--;
	}
	else {
		/* �����ˤ���ʤ����������褿��硤�ʹߤΥ����Ƥ�̤�ݾڤȤʤ� */
	}
}

/*
 *  �ȥ졼������ɽ��
 */
static void
trace_print(const TRACE *p_trace, void (*outputc)(char8 c))
{
	uintptr				traceinfo[TMAX_LOGINFO + 1U];
	const char8			*tracemsg;
	uint32				i;
	TaskType			tskid;
	AlarmType			almid;
	ISRType				isrid;
	ScheduleTableType	schtblid;

	traceinfo[0] = (uintptr) (p_trace->logtim);
	syslog_printf("[%d] ", traceinfo, outputc);

	switch (p_trace->logtype) {
	/* C2ISR�γ��� */
	case LOG_TYPE_ISR | LOG_ENTER:
		isrid = p_trace->loginfo[0];
		trace_push_context(PR_UNIT_ISR, isrid);

		traceinfo[0] = (uintptr) isrid;
		tracemsg = "enter to isr %d.";
		break;

	/* C2ISR�ν�λ */
	case LOG_TYPE_ISR | LOG_LEAVE:
		isrid = p_trace->loginfo[0];

		traceinfo[0] = (uintptr) isrid;
		trace_pop_context(&(traceinfo[1]), &(traceinfo[2]));
		tracemsg = "leave from isr %d, context is %s %d.";
		break;

	/* ���顼����λ�����γ��� */
	case LOG_TYPE_ALM | LOG_ENTER:
		almid = (uintptr) (((ALMCB *) (p_trace->loginfo[0])) - almcb_table);
		trace_change_context(PR_UNIT_ALARM, almid);

		traceinfo[0] = (uintptr) almid;
		tracemsg = "enter to alarm %d.";
		break;

	/* ���顼����λ�����ν�λ */
	case LOG_TYPE_ALM | LOG_LEAVE:
		almid = (uintptr) (((ALMCB *) (p_trace->loginfo[0])) - almcb_table);
		trace_resume_context();

		traceinfo[0] = (uintptr) almid;
		trace_get_context(&(traceinfo[1]), &(traceinfo[2]));
		tracemsg = "leave from alarm %d, context is %s %d.";
		break;

	/* �������塼��ơ��֥���λ�����γ��� */
	case LOG_TYPE_SCHTBL | LOG_ENTER:
		schtblid = (uintptr) (((SCHTBLCB *) (p_trace->loginfo[0])) - schtblcb_table);
		trace_change_context(PR_UNIT_SCHTBL, schtblid);

		traceinfo[0] = (uintptr) schtblid;
		tracemsg = "enter to scheduletable %d.";
		break;

	/* �������塼��ơ��֥���λ�����ν�λ */
	case LOG_TYPE_SCHTBL | LOG_LEAVE:
		schtblid = (uintptr) (((SCHTBLCB *) (p_trace->loginfo[0])) - schtblcb_table);
		trace_resume_context();

		traceinfo[0] = (uintptr) schtblid;
		trace_get_context(&(traceinfo[1]), &(traceinfo[2]));
		tracemsg = "leave from scheduletable %d, context is %s %d.";
		break;

	/* �������ȥ��åץեå��γ��� */
	case LOG_TYPE_STAHOOK | LOG_ENTER:
		trace_set_context(PR_UNIT_STA, 0U);
		tracemsg = "enter to startup hook.";
		break;

	/* �������ȥ��åץեå��ν�λ */
	case LOG_TYPE_STAHOOK | LOG_LEAVE:
		tracemsg = "leave from startup hook.";
		break;

	/* ���顼�եå��γ��� */
	case LOG_TYPE_ERRHOOK | LOG_ENTER:
		trace_push_context(PR_UNIT_ERR, 0U);

		traceinfo[0] = (uintptr) atk2_strerror((StatusType) p_trace->loginfo[0]);
		tracemsg = "enter to error hook ercd=%s.";
		break;

	/* ���顼�եå��ν�λ */
	case LOG_TYPE_ERRHOOK | LOG_LEAVE:
		trace_pop_context(&(traceinfo[0]), &(traceinfo[1]));
		tracemsg = "leave from error hook, context is %s %d.";
		break;

	/* �ץ�ƥ������եå��γ��� */
	case LOG_TYPE_PROHOOK | LOG_ENTER:
		trace_push_context(PR_UNIT_PRO, 0U);

		traceinfo[0] = (uintptr) atk2_strerror((StatusType) p_trace->loginfo[0]);
		tracemsg = "enter to protection hook ercd=%s.";
		break;

	/* �ץ�ƥ������եå��ν�λ */
	case LOG_TYPE_PROHOOK | LOG_LEAVE:
		traceinfo[0] = (uintptr) trace_proret_str((ProtectionReturnType) p_trace->loginfo[0]);
		trace_pop_context(&(traceinfo[1]), &(traceinfo[2]));
		tracemsg = "leave from protection hook ercd=%s, context is %s %d.";
		break;

	/* ����åȥ�����եå��γ��� */
	case LOG_TYPE_SHUTHOOK | LOG_ENTER:
		trace_push_context(PR_UNIT_SHUT, 0U);

		traceinfo[0] = (uintptr) atk2_strerror((StatusType) p_trace->loginfo[0]);
		tracemsg = "enter to shutdown hook ercd=%s.";
		break;

	/* ����åȥ�����եå��ν�λ */
	case LOG_TYPE_SHUTHOOK | LOG_LEAVE:
		trace_pop_context(&(traceinfo[0]), &(traceinfo[1]));
		tracemsg = "leave from shutdown hook.";
		break;

	/* ���������֤��Ѳ� */
	case LOG_TYPE_TSKSTAT:
		traceinfo[0] = trace_get_tskid(p_trace->loginfo[0]);
		traceinfo[1] = (uintptr) atk2_task_state_str((TaskStateType) p_trace->loginfo[1]);
		tracemsg = "task %d becomes %s.";
		break;

	/* �ǥ����ѥå�������� */
	case LOG_TYPE_DSP | LOG_ENTER:
		traceinfo[0] = trace_get_tskid(p_trace->loginfo[0]);
		tracemsg = "dispatch from task %d.";
		break;

	/* �ǥ����ѥå���νи� */
	case LOG_TYPE_DSP | LOG_LEAVE:
		tskid = (TaskType) trace_get_tskid(p_trace->loginfo[0]);
		traceinfo[0] = (uintptr) tskid;
		trace_set_context(PR_UNIT_TASK, tskid);
		/* ��λ�����򤷤Ƥ��뤫�⤷��ʤ��Τǡ����ߤν���ñ�̤�������� */
		trace_get_context(&(traceinfo[1]), &(traceinfo[2]));

		if (traceinfo[1] != (const uintptr) obj_type_to_str[PR_UNIT_TASK]) {
			tracemsg = "dispatch to task %d, executing %s %d.";
		}
		else {
			tracemsg = "dispatch to task %d.";
		}
		break;

	/* �����ƥॵ���ӥ������� */
	case LOG_TYPE_SVC | LOG_ENTER:
		tracemsg = trace_print_svcenter(p_trace, traceinfo, outputc);
		break;

	/* �����ƥॵ���ӥ��νи� */
	case LOG_TYPE_SVC | LOG_LEAVE:
		tracemsg = trace_print_svcleave(p_trace, traceinfo);
		break;

	case LOG_TYPE_COMMENT:
		for (i = 1U; i < TMAX_LOGINFO; i++) {
			traceinfo[i - 1U] = p_trace->loginfo[i];
		}
		tracemsg = (const char8 *) (p_trace->loginfo[0]);
		break;

	case LOG_TYPE_ASSERT:
		traceinfo[0] = p_trace->loginfo[0];
		traceinfo[1] = p_trace->loginfo[1];
		traceinfo[2] = p_trace->loginfo[2];
		tracemsg = "%s:%u: Assertion '%s' failed.";
		break;

	case LOG_TYPE_USER_MARK:
		traceinfo[0] = p_trace->loginfo[0];
		tracemsg = "user mark=%s.";
		break;

	default:
		traceinfo[0] = p_trace->logtype;
		tracemsg = "unknown trace log type: %d.";
		break;
	}
	syslog_printf(tracemsg, traceinfo, outputc);
	(*outputc)('\n');
}

/*
 *  �ȥ졼�����Υ����
 */
void
trace_dump(void (*exinf)(char8 c))
{
	TRACE	trace;
	void	(*outputc)(char8 c);
	uint32	i;

	for (i = 0U; i < TNUM_TASK; i++) {
		task_context_index[i] = -1;
	}
	for (i = 0U; i < TNUM_ISR2; i++) {
		isr_context_index[i] = -1;
	}

	outputc = exinf;
	while (trace_rea_log(&trace) == E_OK) {
		trace_print(&trace, outputc);
	}
	syslog(LOG_NOTICE, "sizeof TRACE=%d", sizeof(TRACE));

}
