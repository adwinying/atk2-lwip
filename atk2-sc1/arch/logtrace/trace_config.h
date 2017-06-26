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
 *  $Id: trace_config.h 1801 2015-03-27 06:34:43Z t_ishikawa $
 */

/*
 *		�ȥ졼�����˴ؤ�������
 */

#ifndef TOPPERS_TRACE_CONFIG_H
#define TOPPERS_TRACE_CONFIG_H

#ifdef TOPPERS_ENABLE_TRACE
/*
 *  ��ǽ�����ɤ��ɤ߹���
 */
#include "kernel_fncode.h"

/*
 *  �ȥ졼�����Хåե��Υ�����
 */
#ifndef TCNT_TRACE_BUFFER
#define TCNT_TRACE_BUFFER	UINT_C(8192)

#endif /* TCNT_TRACE_BUFFER */

/*
 *  �ȥ졼������μ�����ˡ
 */
#ifndef GET_UTIM
#define GET_UTIM()		(get_tim_utime())
#endif /* GET_UTIM */

#ifndef TOPPERS_MACRO_ONLY

/*
 *  �ȥ졼�����Υǡ�����¤
 *
 *  �����ƥ����ǽ�Υ�����Υǡ�����¤��Ʊ����Τ��Ѥ���
 */
#include "t_syslog.h"
typedef	SYSLOG TRACE;

typedef	uint32 TraceModeType;                 /* �����ӥ��������ư��⡼�� */

#endif /* TOPPERS_MACRO_ONLY */

/*
 *  �ȥ졼���⡼�ɤ����
 */
#define TRACE_STOP			UINT_C(0x00)    /* �ȥ졼����� */
#define TRACE_RINGBUF		UINT_C(0x01)    /* ��󥰥Хåե��⡼�� */
#define TRACE_AUTOSTOP		UINT_C(0x02)    /* ��ư��ߥ⡼�� */
#define TRACE_CLEAR			UINT_C(0x04)    /* �ȥ졼�����Υ��ꥢ */

#ifndef TOPPERS_MACRO_ONLY

/*
 *  �ȥ졼������ǽ�ν����
 *
 *  �ȥ졼������ǽ���������롥������롼����Ȥ�����Ͽ���뤳�Ȥ���
 *  �ꤷ�Ƥ��롥�����ˤ�꼡��ư���Ԥ�
 *
 *  TRACE_STOP��������Τߤǥȥ졼���ϳ��Ϥ��ʤ�
 *  TRACE_RINGBUF����󥰥Хåե��⡼�ɤǥȥ졼���򳫻�
 *  TRACE_AUTOSTOP����ư��ߥ⡼�ɤǥȥ졼���򳫻�
 */
extern void trace_initialize(uintptr exinf);

/*
 *  �ȥ졼�����γ���
 *
 *  �ȥ졼�����ε�Ͽ�򳫻ϡ���ߤ��롥�����ˤ�꼡��ư���Ԥ�
 *
 *  TRACE_STOP���ȥ졼�������
 *  TRACE_RINGBUF����󥰥Хåե��⡼�ɤǥȥ졼���򳫻�
 *  TRACE_AUTOSTOP����ư��ߥ⡼�ɤǥȥ졼���򳫻�
 *  TRACE_CLEAR���ȥ졼�����򥯥ꥢ
 */
extern StatusType trace_sta_log(TraceModeType mode);

/*
 *  �ȥ졼�������ɽФ�
 */
extern StatusType trace_rea_log(TRACE *p_trace);

/*
 *  �ȥ졼�����Υ���ס�trace_dump.c��
 *
 *  �ȥ졼���������פ��롥��λ�����롼����Ȥ�����Ͽ���뤳�Ȥ�����
 *  ���Ƥ��롥�����Ȥ��ơ��������Ȥʤ�ʸ�����ϴؿ��ؤΥݥ��󥿤��Ϥ�
 *  �������åȰ�¸�����٥�ʸ�����Ϥ����Ѥ�����ˤϡ�target_putc����
 *  ��
 */
extern void trace_dump(void (*exinf)(char8 c));

/*
 *  �ȥ졼��������Ϥ��뤿��Υ饤�֥��ؿ�
 */
extern void trace_write_0(uint32 type);
extern void trace_write_1(uint32 type, const uintptr arg1);
extern void trace_write_2(uint32 type, uintptr arg1, uintptr arg2);
extern void trace_write_3(uint32 type, uintptr arg1, uintptr arg2, uintptr arg3);
extern void trace_write_4(uint32 type, uintptr arg1, uintptr arg2, uintptr arg3, uintptr arg4);
extern void trace_write_5(uint32 type, uintptr arg1, uintptr arg2, uintptr arg3, uintptr arg4, uintptr arg5);

/*
 *  �ȥ졼��������Ϥ��뤿��Υޥ���
 */

#define trace_0(type)								trace_write_0((type))
#define trace_1(type, arg1)							trace_write_1((type), (arg1))
#define trace_2(type, arg1, arg2)					trace_write_2((type), (arg1), (arg2))
#define trace_3(type, arg1, arg2, arg3)				trace_write_3((type), (arg1), (arg2), (arg3))
#define trace_4(type, arg1, arg2, arg3, arg4)		trace_write_4((type), (arg1), (arg2), (arg3), (arg4))
#define trace_5(type, arg1, arg2, arg3, arg4, arg5)	trace_write_5((type), (arg1), (arg2), (arg3), (arg4), (arg5))

#endif /* TOPPERS_MACRO_ONLY */

/*
 *  �ȥ졼������ˡ������
 */

/*
 *  ����ߥ����ӥ��롼���������
 */
#define LOG_ISR_ENTER(isrid)	trace_1(LOG_TYPE_ISR | LOG_ENTER, (isrid))
#define LOG_ISR_LEAVE(isrid)	trace_1(LOG_TYPE_ISR | LOG_LEAVE, (isrid))

/*
 *  ���顼��ϥ�ɥ������
 */
#define LOG_ALM_ENTER(p_almcb)	trace_1(LOG_TYPE_ALM | LOG_ENTER, (uintptr) (p_almcb))
#define LOG_ALM_LEAVE(p_almcb)	trace_1(LOG_TYPE_ALM | LOG_LEAVE, (uintptr) (p_almcb))

/*
 *  �������塼��ơ��֥���λ����������
 */
#define LOG_SCHTBL_ENTER(p_schtblcb)	trace_1(LOG_TYPE_SCHTBL | LOG_ENTER, (uintptr) (p_schtblcb))
#define LOG_SCHTBL_LEAVE(p_schtblcb)	trace_1(LOG_TYPE_SCHTBL | LOG_LEAVE, (uintptr) (p_schtblcb))

/*
 *  �������ξ����ѹ�
 */
#define LOG_TSKSTAT(p_tcb)	trace_2(LOG_TYPE_TSKSTAT, (uintptr) (p_tcb), (uintptr) (p_tcb)->tstat)

/*
 *  �ǥ����ѥå��������
 */
#define LOG_DSP_ENTER(p_tcb)	trace_1(LOG_TYPE_DSP | LOG_ENTER, (p_tcb))
#define LOG_DSP_LEAVE(p_tcb)	trace_1(LOG_TYPE_DSP | LOG_LEAVE, (p_tcb))

/*
 * �桼�����ޡ���
 */
#define LOG_TYPE_USER_MARK	UINT_C(0x100)
#define LOG_USER_MARK(str)	trace_1(LOG_TYPE_USER_MARK, &(str))


/*
 *  �����ƥॳ����
 */

/*
 *  ������������ǽ
 */

#define LOG_ACTTSK_ENTER(tskid)			trace_2(LOG_TYPE_SVC | LOG_ENTER, TFN_ACTIVATETASK, (uintptr) (tskid))
#define LOG_ACTTSK_LEAVE(ercd)			trace_2(LOG_TYPE_SVC | LOG_LEAVE, TFN_ACTIVATETASK, (uintptr) (ercd))
#define LOG_TERTSK_ENTER()				trace_1(LOG_TYPE_SVC | LOG_ENTER, TFN_TERMINATETASK)
#define LOG_TERTSK_LEAVE(ercd)			trace_2(LOG_TYPE_SVC | LOG_LEAVE, TFN_TERMINATETASK, (uintptr) (ercd))
#define LOG_CHNTSK_ENTER(tskid)			trace_2(LOG_TYPE_SVC | LOG_ENTER, TFN_CHAINTASK, (uintptr) (tskid))
#define LOG_CHNTSK_LEAVE(ercd)			trace_2(LOG_TYPE_SVC | LOG_LEAVE, TFN_CHAINTASK, (uintptr) (ercd))
#define LOG_SCHED_ENTER()				trace_1(LOG_TYPE_SVC | LOG_ENTER, TFN_SCHEDULE)
#define LOG_SCHED_LEAVE(ercd)			trace_2(LOG_TYPE_SVC | LOG_LEAVE, TFN_SCHEDULE, (uintptr) (ercd))
#define LOG_GETTID_ENTER()				trace_1(LOG_TYPE_SVC | LOG_ENTER, TFN_GETTASKID)
#define LOG_GETTID_LEAVE(ercd, p_tskid)	trace_3(LOG_TYPE_SVC | LOG_LEAVE, TFN_GETTASKID, (uintptr) (ercd), ((ercd) == E_OK ? (uintptr) (*(p_tskid)) : 0U))
#define LOG_GETTST_ENTER(tskid)			trace_2(LOG_TYPE_SVC | LOG_ENTER, TFN_GETTASKSTATE, (uintptr) (tskid))
#define LOG_GETTST_LEAVE(ercd, p_state)	trace_3(LOG_TYPE_SVC | LOG_LEAVE, TFN_GETTASKSTATE, (uintptr) (ercd), ((ercd) == E_OK ? (uintptr) (*(p_state)) : 0U))

/*
 * ���٥�ȵ�ǽ
 */
#define LOG_SETEVT_ENTER(tskid, mask)			trace_3(LOG_TYPE_SVC | LOG_ENTER, TFN_SETEVENT, (uintptr) (tskid), (uintptr) (mask))
#define LOG_SETEVT_LEAVE(ercd)					trace_2(LOG_TYPE_SVC | LOG_LEAVE, TFN_SETEVENT, (uintptr) (ercd))
#define LOG_CLREVT_ENTER(p_runtsk, mask)		trace_3(LOG_TYPE_SVC | LOG_ENTER, TFN_CLEAREVENT, (uintptr) (p_runtsk), (uintptr) (mask))
#define LOG_CLREVT_LEAVE(ercd)					trace_2(LOG_TYPE_SVC | LOG_LEAVE, TFN_CLEAREVENT, (uintptr) (ercd))
#define LOG_GETEVT_ENTER(tskid)					trace_2(LOG_TYPE_SVC | LOG_ENTER, TFN_GETEVENT, (uintptr) (tskid))
#define LOG_GETEVT_LEAVE(ercd, tskid, p_mask)	trace_4(LOG_TYPE_SVC | LOG_LEAVE, TFN_GETEVENT, (uintptr) (ercd), (uintptr) (tskid), ((ercd) == E_OK ? (uintptr) (*(p_mask)) : 0U))
#define LOG_WAIEVT_ENTER(p_runtsk, mask)		trace_3(LOG_TYPE_SVC | LOG_ENTER, TFN_WAITEVENT, (uintptr) (p_runtsk), (uintptr) (mask))
#define LOG_WAIEVT_LEAVE(ercd)					trace_2(LOG_TYPE_SVC | LOG_LEAVE, TFN_WAITEVENT, (uintptr) (ercd))

/*
 * �꥽������ǽ
 */
#define LOG_GETRES_ENTER(resid)	trace_2(LOG_TYPE_SVC | LOG_ENTER, TFN_GETRESOURCE, (uintptr) (resid))
#define LOG_GETRES_LEAVE(ercd)	trace_2(LOG_TYPE_SVC | LOG_LEAVE, TFN_GETRESOURCE, (uintptr) (ercd))
#define LOG_RELRES_ENTER(resid)	trace_2(LOG_TYPE_SVC | LOG_ENTER, TFN_RELEASERESOURCE, (uintptr) (resid))
#define LOG_RELRES_LEAVE(ercd)	trace_2(LOG_TYPE_SVC | LOG_LEAVE, TFN_RELEASERESOURCE, (uintptr) (ercd))

/*
 * ���顼�ൡǽ
 */
#define LOG_GETALB_ENTER(almid)					trace_2(LOG_TYPE_SVC | LOG_ENTER, TFN_GETALARMBASE, (uintptr) (almid))
#define LOG_GETALB_LEAVE(ercd, info)			trace_5(LOG_TYPE_SVC | LOG_LEAVE, TFN_GETALARMBASE, (uintptr) (ercd), ((ercd) == E_OK ? ((info)->maxallowedvalue) : (0U)), ((ercd) == E_OK ? ((info)->ticksperbase) : (0U)), ((ercd) == E_OK ? ((info)->mincycle) : (0U)))
#define LOG_GETALM_ENTER(almid)					trace_2(LOG_TYPE_SVC | LOG_ENTER, TFN_GETALARM, (uintptr) (almid))
#define LOG_GETALM_LEAVE(ercd, p_tick)			trace_3(LOG_TYPE_SVC | LOG_LEAVE, TFN_GETALARM, (uintptr) (ercd), ((ercd) == E_OK ? (uintptr) (*(p_tick)) : 0U))
#define LOG_SETREL_ENTER(almid, incr, cycle)	trace_4(LOG_TYPE_SVC | LOG_ENTER, TFN_SETRELALARM, (uintptr) (almid), (uintptr) (incr), (uintptr) (cycle))
#define LOG_SETREL_LEAVE(ercd)					trace_2(LOG_TYPE_SVC | LOG_LEAVE, TFN_SETRELALARM, (uintptr) (ercd))
#define LOG_SETABS_ENTER(almid, start, cycle)	trace_4(LOG_TYPE_SVC | LOG_ENTER, TFN_SETABSALARM, (uintptr) (almid), (uintptr) (start), (uintptr) (cycle))
#define LOG_SETABS_LEAVE(ercd)					trace_2(LOG_TYPE_SVC | LOG_LEAVE, TFN_SETABSALARM, (uintptr) (ercd))
#define LOG_CANALM_ENTER(almid)					trace_2(LOG_TYPE_SVC | LOG_ENTER, TFN_CANCELALARM, (uintptr) (almid))
#define LOG_CANALM_LEAVE(ercd)					trace_2(LOG_TYPE_SVC | LOG_LEAVE, TFN_CANCELALARM, (uintptr) (ercd))

/*
 * �����󥿵�ǽ
 */
#define LOG_INCCNT_ENTER(cntid)					trace_2(LOG_TYPE_SVC | LOG_ENTER, TFN_INCREMENTCOUNTER, (uintptr) (cntid))
#define LOG_INCCNT_LEAVE(ercd)					trace_2(LOG_TYPE_SVC | LOG_LEAVE, TFN_INCREMENTCOUNTER, (uintptr) (ercd))
#define LOG_GETCNT_ENTER(cntid)					trace_2(LOG_TYPE_SVC | LOG_ENTER, TFN_GETCOUNTERVALUE, (uintptr) (cntid))
#define LOG_GETCNT_LEAVE(ercd, p_val)			trace_3(LOG_TYPE_SVC | LOG_LEAVE, TFN_GETCOUNTERVALUE, (uintptr) (ercd), ((ercd) == E_OK ? (uintptr) (*(p_val)) : 0U))
#define LOG_GETEPS_ENTER(cntid, p_val)			trace_3(LOG_TYPE_SVC | LOG_ENTER, TFN_GETELAPSEDVALUE, (uintptr) (cntid), ((p_val) == NULL ? 0U : *(p_val)))
#define LOG_GETEPS_LEAVE(ercd, p_val, p_eval)	trace_4(LOG_TYPE_SVC | LOG_LEAVE, TFN_GETELAPSEDVALUE, (uintptr) (ercd), ((ercd) == E_OK ? (uintptr) (*(p_val)) : 0U), ((ercd) == E_OK ? (uintptr) (*(p_eval)) : 0U))

/*
 * �������塼��ơ��֥뵡ǽ
 */
#define LOG_STASCHTBLREL_ENTER(schtblid, offset)	trace_3(LOG_TYPE_SVC | LOG_ENTER, TFN_STARTSCHEDULETABLEREL, (uintptr) (schtblid), (uintptr) (offset))
#define LOG_STASCHTBLREL_LEAVE(ercd)				trace_2(LOG_TYPE_SVC | LOG_LEAVE, TFN_STARTSCHEDULETABLEREL, (uintptr) (ercd))
#define LOG_STASCHTBLABS_ENTER(schtblid, start)		trace_3(LOG_TYPE_SVC | LOG_ENTER, TFN_STARTSCHEDULETABLEABS, (uintptr) (schtblid), (uintptr) (start))
#define LOG_STASCHTBLABS_LEAVE(ercd)				trace_2(LOG_TYPE_SVC | LOG_LEAVE, TFN_STARTSCHEDULETABLEABS, (uintptr) (ercd))
#define LOG_STPSCHTBL_ENTER(schtblid)				trace_2(LOG_TYPE_SVC | LOG_ENTER, TFN_STOPSCHEDULETABLE, (uintptr) (schtblid))
#define LOG_STPSCHTBL_LEAVE(ercd)					trace_2(LOG_TYPE_SVC | LOG_LEAVE, TFN_STOPSCHEDULETABLE, (uintptr) (ercd))
#define LOG_NXTSCHTBL_ENTER(from, to)				trace_3(LOG_TYPE_SVC | LOG_ENTER, TFN_NEXTSCHEDULETABLE, (uintptr) (from), (uintptr) (to))
#define LOG_NXTSCHTBL_LEAVE(ercd)					trace_2(LOG_TYPE_SVC | LOG_LEAVE, TFN_NEXTSCHEDULETABLE, (uintptr) (ercd))
#define LOG_GETSCHTBLST_ENTER(schtblid)				trace_2(LOG_TYPE_SVC | LOG_ENTER, TFN_GETSCHEDULETABLESTATUS, (uintptr) (schtblid))
#define LOG_GETSCHTBLST_LEAVE(ercd, p_status)		trace_3(LOG_TYPE_SVC | LOG_LEAVE, TFN_GETSCHEDULETABLESTATUS, (uintptr) (ercd), ((ercd) == E_OK ? (uintptr) (*(p_status)) : 0U))

/*
 *  ����ߴ�����ǽ
 */
#define LOG_DISINT_ENTER()			trace_1(LOG_TYPE_SVC | LOG_ENTER, TFN_DISABLEALLINTERRUPTS)
#define LOG_DISINT_LEAVE()			trace_1(LOG_TYPE_SVC | LOG_LEAVE, TFN_DISABLEALLINTERRUPTS)
#define LOG_ENAINT_ENTER()			trace_1(LOG_TYPE_SVC | LOG_ENTER, TFN_ENABLEALLINTERRUPTS)
#define LOG_ENAINT_LEAVE()			trace_1(LOG_TYPE_SVC | LOG_LEAVE, TFN_ENABLEALLINTERRUPTS)
#define LOG_SUSALL_ENTER()			trace_1(LOG_TYPE_SVC | LOG_ENTER, TFN_SUSPENDALLINTERRUPTS)
#define LOG_SUSALL_LEAVE()			trace_1(LOG_TYPE_SVC | LOG_LEAVE, TFN_SUSPENDALLINTERRUPTS)
#define LOG_RSMALL_ENTER()			trace_1(LOG_TYPE_SVC | LOG_ENTER, TFN_RESUMEALLINTERRUPTS)
#define LOG_RSMALL_LEAVE()			trace_1(LOG_TYPE_SVC | LOG_LEAVE, TFN_RESUMEALLINTERRUPTS)
#define LOG_SUSOSI_ENTER()			trace_1(LOG_TYPE_SVC | LOG_ENTER, TFN_SUSPENDOSINTERRUPTS)
#define LOG_SUSOSI_LEAVE()			trace_1(LOG_TYPE_SVC | LOG_LEAVE, TFN_SUSPENDOSINTERRUPTS)
#define LOG_RSMOSI_ENTER()			trace_1(LOG_TYPE_SVC | LOG_ENTER, TFN_RESUMEOSINTERRUPTS)
#define LOG_RSMOSI_LEAVE()			trace_1(LOG_TYPE_SVC | LOG_LEAVE, TFN_RESUMEOSINTERRUPTS)
#define LOG_GETISRID_ENTER()		trace_1(LOG_TYPE_SVC | LOG_ENTER, TFN_GETISRID)
#define LOG_GETISRID_LEAVE(isrid)	trace_2(LOG_TYPE_SVC | LOG_LEAVE, TFN_GETISRID, (uintptr) (isrid))
#define LOG_DISINTSRC_ENTER(isrid)	trace_2(LOG_TYPE_SVC | LOG_ENTER, TFN_DISABLEINTERRUPTSOURCE, (uintptr) (isrid))
#define LOG_DISINTSRC_LEAVE(ercd)	trace_2(LOG_TYPE_SVC | LOG_LEAVE, TFN_DISABLEINTERRUPTSOURCE, (uintptr) (ercd))
#define LOG_ENAINTSRC_ENTER(isrid)	trace_2(LOG_TYPE_SVC | LOG_ENTER, TFN_ENABLEINTERRUPTSOURCE, (uintptr) (isrid))
#define LOG_ENAINTSRC_LEAVE(ercd)	trace_2(LOG_TYPE_SVC | LOG_LEAVE, TFN_ENABLEINTERRUPTSOURCE, (uintptr) (ercd))

/*
 *  �����ͥ�ν�����Ƚ�λ����
 */
#define LOG_STAOS_ENTER(mode)
#define LOG_STAOS_LEAVE()
#define LOG_STUTOS_ENTER(ercd)		trace_2(LOG_TYPE_SVC | LOG_ENTER, TFN_SHUTDOWNOS, (uintptr) (ercd))
#define LOG_STUTOS_LEAVE()
#define LOG_GETAAM_ENTER()			trace_1(LOG_TYPE_SVC | LOG_ENTER, TFN_GETACTIVEAPPLICATIONMODE)
#define LOG_GETAAM_LEAVE(mode)		trace_2(LOG_TYPE_SVC | LOG_LEAVE, TFN_GETACTIVEAPPLICATIONMODE, (uintptr) (mode))
#define LOG_STAHOOK_ENTER()			trace_0(LOG_TYPE_STAHOOK | LOG_ENTER)
#define LOG_STAHOOK_LEAVE()			trace_0(LOG_TYPE_STAHOOK | LOG_LEAVE)
#define LOG_ERRHOOK_ENTER(ercd)		trace_1(LOG_TYPE_ERRHOOK | LOG_ENTER, (uintptr) (ercd))
#define LOG_ERRHOOK_LEAVE()			trace_0(LOG_TYPE_ERRHOOK | LOG_LEAVE)
#define LOG_PROHOOK_ENTER(ercd)		trace_1(LOG_TYPE_PROHOOK | LOG_ENTER, (uintptr) (ercd))
#define LOG_PROHOOK_LEAVE(pret)		trace_1(LOG_TYPE_PROHOOK | LOG_LEAVE, (uintptr) (pret))
#define LOG_SHUTHOOK_ENTER(ercd)	trace_1(LOG_TYPE_SHUTHOOK | LOG_ENTER, (uintptr) (ercd))
#define LOG_SHUTHOOK_LEAVE()		trace_0(LOG_TYPE_SHUTHOOK | LOG_LEAVE)

/*
 *  �����ƥ����ǽ
 */
#define LOG_SYSLOG_WRI_LOG_LEAVE(ercd)
#define LOG_SYSLOG_REA_LOG_ENTER(p_syslog)
#define LOG_SYSLOG_REA_LOG_LEAVE(ercd, p_syslog)
#define LOG_SYSLOG_MSK_LOG_ENTER(lowmask)
#define LOG_SYSLOG_MSK_LOG_LEAVE(ercd)
#define LOG_SYSLOG_REF_LOG_ENTER(pk_rlog)
#define LOG_SYSLOG_REF_LOG_LEAVE(pk_rlog)

#endif /* TOPPERS_ENABLE_TRACE */

#endif /* TOPPERS_TRACE_CONFIG_H */
