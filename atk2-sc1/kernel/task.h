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
 *  $Id: task.h 1801 2015-03-27 06:34:43Z t_ishikawa $
 */

/*
 *		������������ǽ
 */

#ifndef TOPPERS_TASK_H
#define TOPPERS_TASK_H

#include "queue.h"
#include "resource.h"

/*
 *  ���٥�ȥޥ����ͤ����
 */
#define EVTMASK_NONE	((EventMaskType) 0) /* ���٥�Ȥʤ� */

/*
 *  ͥ���٤��ϰϡʳ���ɽ����
 */
#define TMIN_TPRI		UINT_C(0)       /* ������ͥ���٤κǾ��͡ʺ����͡�*/
#define TMAX_TPRI		UINT_C(15)      /* ������ͥ���٤κ����͡ʺǹ��͡�*/

/*
 *  ͥ���٤��ʳ��������
 */
#define TNUM_TPRI		((TMAX_TPRI - TMIN_TPRI) + 1U)

/*
 *  ͥ�����ͤ����������ɽ����
 */
#define TPRI_MINTASK	((PriorityType) (TNUM_TPRI - 1U))               /* ���㥿����ͥ���� */
#define TPRI_MAXTASK	((PriorityType) (0))                            /* �ǹ⥿����ͥ���� */

/*
 *  ������ID����TCB����Ф�����Υޥ���
 */
#define get_tcb(tskid)		(&(tcb_table[(tskid)]))

/*
 *  TCB���饿����ID����Ф�����Υޥ���
 *  p_tcb ��NULL�ξ��ϻȤ��ʤ�
 */
#define TSKID(p_tcb)	((TaskType) ((p_tcb) - tcb_table))

#ifndef OMIT_BITMAP_SEARCH
#define BITMAP_NUM		15       /* bitmap_search_table�Υ����� */
#endif /* OMIT_BITMAP_SEARCH */

/*
 *  �����������ݻ������ѿ��������Os_Lcfg.c��
 */
extern const TaskType	tnum_task;          /* �������ο� */
extern const TaskType	tnum_exttask;       /* ��ĥ�������ο� */


/*
 *  ������������֥�å�
 *
 *  �������˴ؤ��������ͤ��Ѥ��ʤ������ROM���֤�����ʬ�ʥ�����
 *  ������֥�å��ˤȡ��ͤ��Ѳ����뤿���RAM���֤��ʤ���Фʤ�ʤ���
 *  ʬ�ʥ����������֥�å���TCB�ˤ�ʬΥ����TCB����б����륿���������
 *  �֥�å���ؤ��ݥ��󥿤������
 *  ������������֥�å�����б�����TCB��ؤ��ݥ��󥿤��������ˡ��������
 *  RAM������δ��������˾�ޤ��������¹Ը�Ψ�������ʤ뤿��˺���
 *  ���Ƥ��ʤ�
 *  ¾�Υ��֥������ȤˤĤ��Ƥ�Ʊ�ͤ˰���
 */
typedef struct task_initialization_block {
	FunctionRefType	task;       /* �������ε�ư���� */

#ifdef USE_TSKINICTXB
	TSKINICTXB tskinictxb;           /* ���������������ƥ����ȥ֥�å� */
#else /* USE_TSKINICTXB */
	MemorySizeType	stksz;              /* �����å��ΰ�Υ������ʴݤ᤿�͡� */
	void			*stk;               /* �����å��ΰ����Ƭ���� */
#endif /* USE_TSKINICTXB */

	PriorityType	inipri;         /* ���ͥ���� ������ɽ����*/
	PriorityType	exepri;         /* �¹Գ��ϻ���ͥ���� ������ɽ����*/
	uint8			maxact;         /* ¿�ŵ�ư�׵�κ���� */
	AppModeType		autoact;        /* ��ư����⡼�� */
} TINIB;

/*
 *  �����������֥�å���Os_Lcfg.c��
 */
typedef struct task_control_block {
	QUEUE			task_queue;     /* ���������塼(��¤�Τ���Ƭ������ɬ��) */
	const TINIB		*p_tinib;       /* ������֥�å��ؤΥݥ��� */
	PriorityType	curpri;         /* ���ߤ�ͥ���١�����ɽ����*/
	TaskStateType	tstat;          /* ���������֡�����ɽ����*/
	uint8			actcnt;         /* ¿�ŵ�ư�׵�� */
	EventMaskType	curevt;         /* ���٥�Ȥθ����� */
	EventMaskType	waievt;         /* �ԤäƤ��륤�٥�� */
	RESCB			*p_lastrescb;   /* �Ǹ�˳��������꥽���������֥�å��ؤΥݥ��� */
	TSKCTXB			tskctxb;        /* ����������ƥ����ȥ֥�å� */
} TCB;

/*
 *  �¹Ծ��֤Υ�����
 *
 *  �¹Ծ��֤Υ��������ʤ����ˤϡ�NULL �ˤ���
 */
extern TCB			*p_runtsk;

/*
 *  �ǹ�ͥ���̥�����
 *
 *  �������¹���ϡ�runtsk �Ȱ��פ���
 *  �¹ԤǤ�����֡ʼ¹Ծ��֤ޤ��ϼ¹Բ�ǽ���֡ˤΥ��������ʤ����ˤϡ�
 *  NULL �ˤ���
 */
extern TCB			*p_schedtsk;

/*
 *  ��ǥ����塼��κǹ�ͥ����
 *
 *  ��ǥ����塼�ˤϼ¹Բ�ǽ���֤Υ������Τߤ�ޤ�Τǡ��¹Բ�ǽ���֤�
 *  ����������Ǥκǹ�ͥ���٤��ݻ�����
 *  ��ǥ����塼�����λ��ʼ¹Բ�ǽ���֤Υ�������̵�����ˤ� TPRI_MINTASK�ˤ���
 */
extern PriorityType	nextpri;

/*
 *  ��ǥ����塼
 *
 *  ��ǥ����塼�ϡ��¹ԤǤ�����֤Υ�������������뤿��Υ��塼�Ǥ���
 *  ��ǥ����塼�ϡ�ͥ���٤��ȤΥ��������塼�ǹ�������Ƥ���
 *  ��������TCB�ϡ���������ͥ���٤Υ��塼����Ͽ�����
 */
extern QUEUE		ready_queue[TNUM_TPRI];

/*
 *  ��ǥ����塼�������Τ���Υӥåȥޥå�
 *
 *  ��ǥ����塼�Υ��������Ψ�褯�Ԥ�����ˡ�ͥ���٤��ȤΥ��������塼
 *  �˥����������äƤ��뤫�ɤ����򼨤��ӥåȥޥåפ��Ѱդ��Ƥ���
 *  �ӥåȥޥåפ�Ȥ����Ȥǡ����ꥢ�������β���򸺤餹���Ȥ��Ǥ��뤬��
 *  �ӥå����̿�᤬���¤��Ƥ��ʤ��ץ��å��ǡ�ͥ���٤��ʳ��������ʤ�
 *  ���ˤϡ��ӥåȥޥå����Υ����С��إåɤΤ���ˡ��դ˸�Ψ�����
 *  ���ǽ���⤢��
 *
 *  ͥ���٤�16�ʳ��Ǥ��뤳�Ȥ��ꤷ�Ƥ��뤿�ᡤuint16���Ȥ��Ƥ���
 */
extern uint16		ready_primap;

/*
 *  ������������֥�å��Υ��ꥢ��Os_Lcfg.c��
 */
extern const TINIB	tinib_table[];

/*
 *  TCB�Υ��ꥢ��Os_Lcfg.c��
 */
extern TCB			tcb_table[];

/*
 *  �����������⥸�塼��ν����
 */
extern void task_initialize(void);

/*
 *  �������ε�ư
 *
 *  �оݥ�������p_tcb�ǻ��ꤷ���������ˤ�ư����
 *  �ʵٻ߾��֤���¹ԤǤ�����֤����ܤ������
 *  �������ε�ư����ɬ�פʽ������Ԥ�
 */
extern boolean make_active(TCB *p_tcb);

/*
 *  �¹ԤǤ�����֤ؤΰܹ�
 *
 *  �оݥ�������p_tcb�ǻ��ꤷ���������ˤ�¹ԤǤ�����֤����ܤ�����
 *  �оݥ�������ͥ���٤����ǹ�ͥ���٥�������schedtsk�ˤ�ͥ���٤����
 *  �����ˤϡ��оݥ������򿷤����ǹ�ͥ���٥������Ȥ�������ޤǤκǹ�
 *  ͥ���٥��������ǥ����塼����Ƭ�������
 *  �����Ǥʤ����ˤϡ��оݥ��������ǥ����塼�������������
 *  �оݥ�������ǹ�ͥ���٥������Ȥ������ˡ�TRUE ���֤�
 */
extern boolean make_runnable(TCB *p_tcb);

/*
 *  �¹ԤǤ�����֤���¾�ξ��֤ؤ�����
 */
extern void make_non_runnable(void);

/*
 *  �ǹ�ͥ���̥������Υ�����
 *
 *  ��ǥ����塼��κǹ�ͥ���̤Υ������򥵡�������
 *  ��ǥ����塼�����ξ��ˤϡ����δؿ���ƤӽФ��ƤϤʤ�ʤ�
 */
extern void search_schedtsk(void);

/*
 *  �������Υץꥨ��ץ�
 *
 *  ����������¹Բ�ǽ���֤˰ܹԤ������ǹ�ͥ���٥�������¹Ծ��֤ˤ���
 *  ���δؿ�������ä���ˡ�dispatch ��ƤӽФ���¾�Υ��������ڤ��ؤ���
 *  ���Ȥ����ꤷ�Ƥ���
 */
extern void preempt(void);

/*
 *  �¹���Υ�������SUSPENDED���֤ˤ���
 */
extern void suspend(void);

/*
 *  ��λ�������ѥ������ε�ư
 *
 *  ��OS����߶ػ߾��֤ǸƤФ��
 */
extern StatusType activate_task_action(TaskType TaskID);

/*
 *  ��λ�������ѥ��٥�ȤΥ��å�
 *
 *  ��OS����߶ػ߾��֤ǸƤФ��
 */
extern StatusType set_event_action(TaskType TaskID, EventMaskType Mask);

/*
 *  ������������λ���˸Ƥִؿ�
 */
extern void exit_task(void);

#endif /* TOPPERS_TASK_H_ */
