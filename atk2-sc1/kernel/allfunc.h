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
 *  $Id: allfunc.h 1801 2015-03-27 06:34:43Z t_ishikawa $
 */

/*
 *		���٤Ƥδؿ��򥳥�ѥ��뤹�뤿������
 */

#ifndef TOPPERS_ALLFUNC_H
#define TOPPERS_ALLFUNC_H

/* alarm.c */
#define TOPPERS_alarm_initialize
#define TOPPERS_GetAlarmBase
#define TOPPERS_GetAlarm
#define TOPPERS_SetRelAlarm
#define TOPPERS_SetAbsAlarm
#define TOPPERS_CancelAlarm
#define TOPPERS_alarm_expire

/* counter_manage.c */
#define TOPPERS_IncrementCounter
#define TOPPERS_GetCounterValue
#define TOPPERS_GetElapsedValue
#define TOPPERS_notify_hardware_counter
#define TOPPERS_incr_counter_action

/* counter.c */
#define TOPPERS_insert_cnt_expr_que
#define TOPPERS_delete_cnt_expr_que
#define TOPPERS_counter_initialize
#define TOPPERS_counter_terminate
#define TOPPERS_get_reltick
#define TOPPERS_get_abstick
#define TOPPERS_expire_process

/* event.c */
#define TOPPERS_SetEvent
#define TOPPERS_ClearEvent
#define TOPPERS_GetEvent
#define TOPPERS_WaitEvent
#define TOPPERS_set_event_action

/* interrupt.c */
#define TOPPERS_interrupt_initialize
#define TOPPERS_release_interrupts
#define TOPPERS_exit_isr2

/* interrupt_manage.c */
#define TOPPERS_DisableAllInterrupts
#define TOPPERS_EnableAllInterrupts
#define TOPPERS_SuspendAllInterrupts
#define TOPPERS_ResumeAllInterrupts
#define TOPPERS_SuspendOSInterrupts
#define TOPPERS_ResumeOSInterrupts
#define TOPPERS_GetISRID

/* osctl.c */
#define TOPPERS_internal_call_errorhook
#define TOPPERS_call_posttaskhook
#define TOPPERS_call_pretaskhook
#define TOPPERS_call_protectionhk_main
#define TOPPERS_init_stack_magic_region
#define TOPPERS_internal_shutdownos
#define TOPPERS_internal_call_shtdwnhk

/* osctl_manage.c */
#define TOPPERS_StartOS
#define TOPPERS_GetActiveApplicationMode
#define TOPPERS_ShutdownOS
#define TOPPERS_GetFaultyContext

/* resource.c */
#define TOPPERS_resource_initialize
#define TOPPERS_GetResource
#define TOPPERS_ReleaseResource

/* scheduletable.c */
#define TOPPERS_schtbl_initialize
#define TOPPERS_StartScheduleTableRel
#define TOPPERS_StartScheduleTableAbs
#define TOPPERS_StopScheduleTable
#define TOPPERS_NextScheduleTable
#define TOPPERS_GetScheduleTableStatus
#define TOPPERS_schtbl_expire
#define TOPPERS_schtbl_expiry_process
#define TOPPERS_schtbl_head
#define TOPPERS_schtbl_exppoint_process
#define TOPPERS_schtbl_tail

/* task.c */
#define TOPPERS_task_initialize
#define TOPPERS_search_schedtsk
#define TOPPERS_make_runnable
#define TOPPERS_make_non_runnable
#define TOPPERS_make_active
#define TOPPERS_preempt
#define TOPPERS_suspend
#define TOPPERS_exit_task

/* task_manage.c */
#define TOPPERS_ActivateTask
#define TOPPERS_TerminateTask
#define TOPPERS_ChainTask
#define TOPPERS_Schedule
#define TOPPERS_GetTaskID
#define TOPPERS_GetTaskState
#define TOPPERS_activate_task_action

#endif /* TOPPERS_ALLFUNC_H */
