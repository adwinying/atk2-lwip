/* Os_Lcfg.c */
#include "kernel/kernel_int.h"
#include "Os_Lcfg.h"

#ifndef TOPPERS_EMPTY_LABEL
#define TOPPERS_EMPTY_LABEL(x, y) x y[0]
#endif

/*
 *  Default Definitions of Trace Log Macros
 */

#ifndef LOG_ISR_ENTER
#define LOG_ISR_ENTER(isrid)
#endif /* LOG_ISR_ENTER */

#ifndef LOG_ISR_LEAVE
#define LOG_ISR_LEAVE(isrid)
#endif /* LOG_ISR_LEAVE */

/*
 *  Include Directives (#include)
 */

#include "lwip_test.h"
#include "target_timer.h"
#include "target_hw_counter.h"

const AlarmType					tnum_alarm				= TNUM_ALARM;
const CounterType				tnum_counter			= TNUM_COUNTER;
const CounterType				tnum_hardcounter		= TNUM_HARDCOUNTER;
const ISRType					tnum_isr2				= TNUM_ISR2;
const ResourceType				tnum_stdresource		= TNUM_STD_RESOURCE;
const TaskType					tnum_task				= TNUM_TASK;
const TaskType					tnum_exttask			= TNUM_EXTTASK;
const AppModeType				tnum_appmode			= TNUM_APP_MODE;
const ScheduleTableType			tnum_scheduletable		= TNUM_SCHEDULETABLE;
const ScheduleTableType			tnum_implscheduletable	= TNUM_IMPLSCHEDULETABLE;


/****** Object TASK ******/

static StackType _kernel_shared_stack_10[COUNT_STK_T(USRV_STACK_SIZE)];

const TINIB tinib_table[TNUM_TASK] = {
	{
		&TASKNAME(USRV_TASK),
		ROUND_STK_T(USRV_STACK_SIZE),
		_kernel_shared_stack_10,
		5,
		5,
		(1U) - 1U,
		0x00000001U
	}
};

TCB tcb_table[TNUM_TASK];


/****** Object COUNTER ******/

const CNTINIB cntinib_table[TNUM_COUNTER] = {
	{ 536870911, (536870911 * 2U) + 1U, 10, 4000 },
	{ 999U, (999U * 2U) + 1U, 1U, 1 }
};

CNTCB cntcb_table[TNUM_COUNTER];
const HWCNTINIB hwcntinib_table[TNUM_HARDCOUNTER] = 
{
	{
		&init_hwcounter_MAIN_HW_COUNTER,
		&start_hwcounter_MAIN_HW_COUNTER,
		&stop_hwcounter_MAIN_HW_COUNTER,
		&set_hwcounter_MAIN_HW_COUNTER,
		&get_hwcounter_MAIN_HW_COUNTER,
		&cancel_hwcounter_MAIN_HW_COUNTER,
		&trigger_hwcounter_MAIN_HW_COUNTER,
		&int_clear_hwcounter_MAIN_HW_COUNTER,
		&int_cancel_hwcounter_MAIN_HW_COUNTER,
		&increment_hwcounter_MAIN_HW_COUNTER,
		1.666666e-08 * 1000000000
	}
};


/****** Object ALARM ******/


const ALMINIB alminib_table[TNUM_ALARM] = {
	{ &(cntcb_table[MAIN_HW_COUNTER]), ALARMCALLBACKNAME(LWIP_ALARM_CALLBACK), 0x00000000U, 0U, 0U, CALLBACK & CALLBACK }
};

ALMCB	almcb_table[TNUM_ALARM];

/****** Object SCHEDULETABLE ******/


TOPPERS_EMPTY_LABEL(const SCHTBLINIB, schtblinib_table);
TOPPERS_EMPTY_LABEL(SCHTBLCB, schtblcb_table);


/****** Object RESOURCE ******/

TOPPERS_EMPTY_LABEL(const RESINIB, resinib_table);
TOPPERS_EMPTY_LABEL(RESCB, rescb_table);


/****** Object ISR ******/


ISRCB isrcb_table[TNUM_ISR2];


void
object_initialize(void)
{
	interrupt_initialize();
	task_initialize();
	counter_initialize();
	alarm_initialize();
}


void
object_terminate(void)
{
	counter_terminate();
}


/*
 *  Interrupt Management Functions
 */

void
_kernel_inthdr_16(void)
{
	i_begin_int(16);
	LOG_ISR_ENTER(C2ISR_for_MAIN_HW_COUNTER);
	ISRNAME(C2ISR_for_MAIN_HW_COUNTER)();
	LOG_ISR_LEAVE(C2ISR_for_MAIN_HW_COUNTER);
	i_end_int(16);
}
void
_kernel_inthdr_0(void)
{
	i_begin_int(INTNO_TIMER);
	LOG_ISR_ENTER(target_timer_hdr);
	ISRNAME(target_timer_hdr)();
	LOG_ISR_LEAVE(target_timer_hdr);
	i_end_int(INTNO_TIMER);
}

/* HardWare Counter Interrupt Handler(C2ISR) */
ISR(C2ISR_for_MAIN_HW_COUNTER)
{
	notify_hardware_counter(MAIN_HW_COUNTER);
}

/*
 *  Stack Area for Non-task Context
 */

#define TNUM_INTNO	UINT_C(2)
const InterruptNumberType tnum_intno = TNUM_INTNO;

const INTINIB intinib_table[TNUM_INTNO] = {
	{ (16), ENABLE, (-1), 0x6a0U},
	{ (INTNO_TIMER), ENABLE, (-5), 0x450U}
};

static StackType			_kernel_ostack[COUNT_STK_T(0x7a0U)];
#define TOPPERS_OSTKSZ		ROUND_STK_T(0x7a0U)
#define TOPPERS_OSTK		_kernel_ostack

const MemorySizeType	_ostksz = TOPPERS_OSTKSZ;
StackType * const		_ostk = (StackType *) TOPPERS_OSTK;

#ifdef TOPPERS_OSTKPT
StackType * const	_ostkpt = TOPPERS_OSTKPT(TOPPERS_OSTK, TOPPERS_OSTKSZ);
#endif /* TOPPERS_OSTKPT */


#ifdef TOPPERS_ENABLE_TRACE
const char8 *
atk2_appid_str(AppModeType id)
{
	const char8	*appid_str;
	switch (id) {
	case AppMode:
		appid_str = "AppMode";
		break;
	default:
		appid_str = "";
		break;
	}
	return(appid_str);
}
const char8 *
atk2_tskid_str(TaskType id)
{
	const char8	*tskid_str;
	switch (id) {
	case USRV_TASK:
		tskid_str = "USRV_TASK";
		break;
	case INVALID_TASK:
		tskid_str = "INVALID_TASK";
		break;
	default:
		tskid_str = "";
		break;
	}
	return(tskid_str);
}

const char8 *
atk2_isrid_str(ISRType id)
{
	const char8	*isrid_str;
	switch (id) {
	case C2ISR_for_MAIN_HW_COUNTER:
		isrid_str = "C2ISR_for_MAIN_HW_COUNTER";
		break;
	case target_timer_hdr:
		isrid_str = "target_timer_hdr";
		break;
	case INVALID_ISR:
		isrid_str = "INVALID_ISR";
		break;
	default:
		isrid_str = "";
		break;
	}
	return(isrid_str);
}

const char8 *
atk2_cntid_str(CounterType id)
{
	const char8	*cntid_str;
	switch (id) {
	case MAIN_HW_COUNTER:
		cntid_str = "MAIN_HW_COUNTER";
		break;
	case SysTimerCnt:
		cntid_str = "SysTimerCnt";
		break;
	default:
		cntid_str = "";
		break;
	}
	return(cntid_str);
}

const char8 *
atk2_almid_str(AlarmType id)
{
	const char8	*almid_str;
	switch (id) {
	case LWIP_ALARM:
		almid_str = "LWIP_ALARM";
		break;
	default:
		almid_str = "";
		break;
	}
	return(almid_str);
}

const char8 *
atk2_resid_str(ResourceType id)
{
	return("");
}

const char8 *
atk2_schtblid_str(ScheduleTableType id)
{
	return("");
}

const char8 *
atk2_evtid_str(TaskType task, EventMaskType event)
{
	const char8	*evtid_str;
	switch (task) {
	case USRV_TASK:
		evtid_str = NULL;
		break;
	default:
		evtid_str = NULL;
		break;
	}
	if (evtid_str == NULL) {
	}
	return(evtid_str);
}
#endif /* TOPPERS_ENABLE_TRACE */

const uint32 tmin_status_il = ((uint32) INT_IPM(-5) << STATUS_IL_OFFSET);

const FunctionRefType isr_tbl[TNUM_INT] = {
	&_kernel_inthdr_0,	/* 0 */
	&default_int_handler,	/* 1 */
	&default_int_handler,	/* 2 */
	&default_int_handler,	/* 3 */
	&default_int_handler,	/* 4 */
	&default_int_handler,	/* 5 */
	&default_int_handler,	/* 6 */
	&default_int_handler,	/* 7 */
	&default_int_handler,	/* 8 */
	&default_int_handler,	/* 9 */
	&default_int_handler,	/* 10 */
	&default_int_handler,	/* 11 */
	&default_int_handler,	/* 12 */
	&default_int_handler,	/* 13 */
	&default_int_handler,	/* 14 */
	&default_int_handler,	/* 15 */
	&_kernel_inthdr_16,	/* 16 */
	&default_int_handler,	/* 17 */
	&default_int_handler,	/* 18 */
	&default_int_handler,	/* 19 */
	&default_int_handler,	/* 20 */
	&default_int_handler,	/* 21 */
	&default_int_handler,	/* 22 */
	&default_int_handler,	/* 23 */
	&default_int_handler,	/* 24 */
	&default_int_handler,	/* 25 */
	&default_int_handler,	/* 26 */
	&default_int_handler,	/* 27 */
	&default_int_handler,	/* 28 */
	&default_int_handler,	/* 29 */
	&default_int_handler,	/* 30 */
	&default_int_handler	/* 31 */
};

ISRCB * const isr_p_isrcb_tbl[TNUM_INT] = {
	&(isrcb_table[1]),	/* 0 */
	NULL,	/* 1 */
	NULL,	/* 2 */
	NULL,	/* 3 */
	NULL,	/* 4 */
	NULL,	/* 5 */
	NULL,	/* 6 */
	NULL,	/* 7 */
	NULL,	/* 8 */
	NULL,	/* 9 */
	NULL,	/* 10 */
	NULL,	/* 11 */
	NULL,	/* 12 */
	NULL,	/* 13 */
	NULL,	/* 14 */
	NULL,	/* 15 */
	&(isrcb_table[0]),	/* 16 */
	NULL,	/* 17 */
	NULL,	/* 18 */
	NULL,	/* 19 */
	NULL,	/* 20 */
	NULL,	/* 21 */
	NULL,	/* 22 */
	NULL,	/* 23 */
	NULL,	/* 24 */
	NULL,	/* 25 */
	NULL,	/* 26 */
	NULL,	/* 27 */
	NULL,	/* 28 */
	NULL,	/* 29 */
	NULL,	/* 30 */
	NULL	/* 31 */
};

void
int_handler_entry_0(void)
{
	Asm("movi  et, 0");
	Asm("jmpi  interrupt");
}

void
int_handler_entry_16(void)
{
	Asm("movi  et, 16");
	Asm("jmpi  interrupt");
}

void __attribute__((naked))
kernel_vectors(void)
{
	Asm("jmpi int_handler_entry_0"); /* 0 */
	Asm("jmpi default_int_handler"); /* 1 */
	Asm("jmpi default_int_handler"); /* 2 */
	Asm("jmpi default_int_handler"); /* 3 */
	Asm("jmpi default_int_handler"); /* 4 */
	Asm("jmpi default_int_handler"); /* 5 */
	Asm("jmpi default_int_handler"); /* 6 */
	Asm("jmpi default_int_handler"); /* 7 */
	Asm("jmpi default_int_handler"); /* 8 */
	Asm("jmpi default_int_handler"); /* 9 */
	Asm("jmpi default_int_handler"); /* 10 */
	Asm("jmpi default_int_handler"); /* 11 */
	Asm("jmpi default_int_handler"); /* 12 */
	Asm("jmpi default_int_handler"); /* 13 */
	Asm("jmpi default_int_handler"); /* 14 */
	Asm("jmpi default_int_handler"); /* 15 */
	Asm("jmpi int_handler_entry_16"); /* 16 */
	Asm("jmpi default_int_handler"); /* 17 */
	Asm("jmpi default_int_handler"); /* 18 */
	Asm("jmpi default_int_handler"); /* 19 */
	Asm("jmpi default_int_handler"); /* 20 */
	Asm("jmpi default_int_handler"); /* 21 */
	Asm("jmpi default_int_handler"); /* 22 */
	Asm("jmpi default_int_handler"); /* 23 */
	Asm("jmpi default_int_handler"); /* 24 */
	Asm("jmpi default_int_handler"); /* 25 */
	Asm("jmpi default_int_handler"); /* 26 */
	Asm("jmpi default_int_handler"); /* 27 */
	Asm("jmpi default_int_handler"); /* 28 */
	Asm("jmpi default_int_handler"); /* 29 */
	Asm("jmpi default_int_handler"); /* 30 */
	Asm("jmpi default_int_handler"); /* 31 */
}
