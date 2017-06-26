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
 *  $Id: counter.h 1801 2015-03-27 06:34:43Z t_ishikawa $
 */

/*
 *		�����󥿵�ǽ
 */

#ifndef TOPPERS_COUNTER_H
#define TOPPERS_COUNTER_H

#include "queue.h"

/*
 *  �����󥿾��֤����
 *  IncrementCounter�Υͥ����ɻߺ�
 */
#define CS_NULL		(FALSE)         /* ������� */
#define CS_DOING	(TRUE)          /* ����� */

/*
 *  ������ID���饫���󥿴����֥�å�����Ф�����Υޥ���
 */
#define get_cntcb(cntid)	(&(cntcb_table[(cntid)]))

/*
 *  ������ID�ǥϡ��ɥ����������󥿤������å��ѥޥ���
 */
#define is_hwcnt(cntid)		((cntid) < tnum_hardcounter)

/*
 *  CNTCB���饫����ID����Ф�����Υޥ���
 */
#define CNTID(p_cntcb)	((CounterType) ((p_cntcb) - cntcb_table))

/*
 *  ��λ����������°��
 */
#define ACTIVATETASK		UINT_C(0x01)    /* ��������ư */
#define SETEVENT			UINT_C(0x02)    /* ���٥�ȥ��å� */
#define CALLBACK			UINT_C(0x04)    /* ������Хå� */
#define INCREMENTCOUNTER	UINT_C(0x08)    /* �����󥿥��󥯥���� */

/*
 *  ��ư��ư��°��
 */
#define ABSOLUTE			UINT_C(0x10)    /* �����͵�ư */
#define RELATIVE			UINT_C(0x20)    /* �����͵�ư */

/*
 *  �ƥϡ��ɥ����������󥿽����ؿ���
 */
typedef void (*HardwareCounterInitRefType)(TickType maxval, TimeType nspertick);    /* ������ؿ��� */
typedef void (*HardwareCounterStartRefType)(void);                                  /* ���ϴؿ��� */
typedef void (*HardwareCounterStopRefType)(void);                                   /* ��ߴؿ��� */
typedef void (*HardwareCounterSetRefType)(TickType exprtick);                       /* ��������ؿ��� */
typedef TickType (*HardwareCounterGetRefType)(void);                                /* ���ּ����ؿ��� */
typedef void (*HardwareCounterCancelRefType)(void);                                 /* ������ּ�ôؿ��� */
typedef void (*HardwareCounterTriggerRefType)(void);                                /* ����������׵�ؿ��� */
typedef void (*HardwareCounterIntClearRefType)(void);                               /* ������׵᥯�ꥢ�ؿ��� */
typedef void (*HardwareCounterIntCancelRefType)(void);                              /* ������׵��ôؿ��� */
typedef void (*HardwareCounterIncrementRefType)(void);                              /* ���󥯥���ȴؿ��� */

/*
 *  �ϡ��ɥ����������󥿽����ؿ���
 */
typedef struct hardware_counter_initialization_block {
	HardwareCounterInitRefType		init;               /* ������ؿ��ݥ��� */
	HardwareCounterStartRefType		start;              /* ���ϴؿ��ݥ��� */
	HardwareCounterStopRefType		stop;               /* ��ߴؿ��ݥ��� */
	HardwareCounterSetRefType		set;                /* ��������ؿ��ݥ��� */
	HardwareCounterGetRefType		get;                /* ���ּ����ؿ��ݥ���*/
	HardwareCounterCancelRefType	cancel;             /* ���ּ�ôؿ��ݥ��� */
	HardwareCounterTriggerRefType	trigger;            /* ����������׵�ؿ��ݥ��� */
	HardwareCounterIntClearRefType	intclear;           /* ������׵᥯�ꥢ�ؿ��� */
	HardwareCounterIntCancelRefType	intcancel;          /* ������׵��ôؿ��� */
	HardwareCounterIncrementRefType	increment;          /* ���󥯥���ȴؿ��ݥ��� */
	TimeType						nspertick;          /* �ϡ��ɥ����������󥿤Ǥ�1�ƥ��å��νŤ�(nsñ��) */
} HWCNTINIB;

/*
 *  �����󥿽�����֥�å�
 */
typedef struct counter_initialization_block {
	TickType	maxval;                                 /* �����󥿤κ����� */
	TickType	maxval2;                                /* �����󥿤κ����ͤ�2��+1 */
	TickType	tickbase;                               /* OS�����Ǥϻ��Ѥ������桼������ͳ�˻��Ѥ����� */
	TickType	mincyc;                                 /* �����κǾ��� */
} CNTINIB;

/*
 *  �����󥿴����֥�å�
 */
typedef struct counter_control_block {
	QUEUE			cntexpque;                          /* ��������λ���塼 */
	const CNTINIB	*p_cntinib;                         /* �����󥿽�����֥�å��ݥ��� */
	TickType		curval;                             /* �����󥿤θ��ߥƥ��å� */
	boolean			cstat;                              /* �����������ե饰 */
	boolean			hwset;                              /* �ϡ��ɥ����������󥿥��åȥե饰 */
} CNTCB;

/*
 *  ��������λ����
 */
typedef struct counter_expire_info CNTEXPINFO;

/*
 *  ��λ�����ؿ���
 */
typedef void (*EXPFP)(CNTEXPINFO *p_cntexpinfo, const CNTCB *p_cntcb);

/*
 *  ��������λ����
 */
struct counter_expire_info {
	QUEUE		cntexpque;                              /* ��������λ���塼(��¤�Τ���Ƭ������ɬ��) */
	TickType	expiretick;                             /* ��λ���륫���󥿾�Υƥ��å��� */
	EXPFP		expirefunc;                             /* ��λ�����ؿ��ݥ��� */
};


/*
 *  �ϡ��ɥ����������󥿿����ݻ������ѿ��������Os_Lcfg.c��
 */
extern const CounterType	tnum_hardcounter;

/*
 *  �����󥿿����ݻ������ѿ��������Os_Lcfg.c��
 */
extern const CounterType	tnum_counter;

/*
 *  �����󥿽�����֥�å��Υ��ꥢ��Os_Lcfg.c��
 */
extern const CNTINIB		cntinib_table[];

/*
 *  �����󥿴����֥�å��Υ��ꥢ��Os_Lcfg.c��
 */
extern CNTCB				cntcb_table[];

/*
 *  �ϡ��ɥ����������󥿽����ؿ��ơ��֥��Os_Lcfg.c��
 */
extern const HWCNTINIB		hwcntinib_table[];

/*
 *  �ƥ��å��ͤβû�
 */
LOCAL_INLINE TickType
add_tick(TickType val, TickType incr, TickType maxval2)
{
	TickType result;
	/*
	 *  ��ľ�ʾ�Ｐ�� val + incr <= maxval2 �Ǥ��뤬�����ξ�Ｐ��
	 *  �ϡ�val + incr �� TickType ��ɽ�����ϰϤ�Ķ�������������
	 *  Ƚ��Ǥ��ʤ��ʤ뤿�ᡤ���ξ�Ｐ�Ȥ��Ƥ���
	 */
	if (incr <= (maxval2 - val)) {
		result = val + incr;
	}
	else {
		/*
		 *  ���η׻����ǡ�val + incr �� maxval2 + 1 �� TickType ��ɽ
		 *  �����ϰϤ�Ķ�����礬���뤬�������Хե����Ƥ��ޤ��ͤ�
		 *  ���������ẹ���٤��ʤ�
		 */
		result = (val + incr) - (maxval2 + 1U);
	}
	return(result);
}

/*
 *  �ƥ��å��ͤκ�
 */
LOCAL_INLINE TickType
diff_tick(TickType val1, TickType val2, TickType maxval2)
{
	TickType result;

	if (val1 >= val2) {
		result = val1 - val2;
	}
	else {
		/*
		 *  ���η׻����ǡ�val1 - val2 �� maxval2 + 1 �� TickType ��ɽ��
		 *  ���ϰϤ�Ķ�����礬���뤬�������Хե����Ƥ��ޤ��ͤ���
		 *  �������ẹ���٤��ʤ�
		 */
		result = (val1 - val2) + (maxval2 + 1U);
	}
	return(result);
}

/*
 *  �����󥿤θ����ͼ���
 *  ���եȥ����������󥿤ξ��, CNTCB��curval�ǡ������֤�
 *  �ϡ��ɥ����������󥿤ξ��, �ǿ��θ��߻��֤��֤�
 */
LOCAL_INLINE TickType
get_curval(const CNTCB *p_cntcb, CounterType cntid)
{
	TickType curval;

	/* �������ͤμ��� */
	if (is_hwcnt(cntid)) {
		curval = (hwcntinib_table[cntid].get)();
	}
	else {
		curval = p_cntcb->curval;
	}

	return(curval);
}

/*
 *  ���ꤷ�����л��֤���Υ������ͼ���(API����μ���)
 */
extern TickType get_reltick(const CNTCB *p_cntcb, TickType relval);

/*
 *  ���ꤷ�����л��֤���Υ������ͼ���(API����μ���)
 */
extern TickType get_abstick(const CNTCB *p_cntcb, TickType absval);

/*
 *  �����󥿵�ǽ�ν����
 */
extern void counter_initialize(void);

/*
 *  �����󥿵�ǽ�ν�λ����
 */
extern void counter_terminate(void);

/*
 *  ��������λ���塼�ؤ�����
 */
extern void insert_cnt_expr_que(CNTEXPINFO *p_cntexpinfo, CNTCB *p_cntcb);

/*
 *  ��������λ���塼������
 */
extern void delete_cnt_expr_que(CNTEXPINFO *p_cntexpinfo, CNTCB *p_cntcb);

/*
 *  �����󥿤���λ����
 */
extern void expire_process(CNTCB *p_cntcb, CounterType cntid);

/*
 *  �ϡ��ɥ�������������λ����
 */
extern void notify_hardware_counter(CounterType cntid);

/*
 *  �����󥿤Υ��󥯥����
 *
 *  ������߶ػ߾��֤ǸƤФ��
 */
extern StatusType incr_counter_action(CounterType CounterID);

#endif /* TOPPERS_COUNTER_H */
