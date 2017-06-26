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
 *  $Id: interrupt.h 1801 2015-03-27 06:34:43Z t_ishikawa $
 */

/*
 *		����ߴ�����ǽ
 */

#ifndef TOPPERS_INTERRUPT_H
#define TOPPERS_INTERRUPT_H

#include "resource.h"

/*
 *  ͥ�����ͤ����������ɽ����
 */
#define TPRI_MINISR		(-1)                /* ��������ͥ���� */

/*
 *  ISRCB����ISRID����Ф�����Υޥ���
 */
#define ISR2ID(p_isrcb)	((ISRType) ((p_isrcb) - isrcb_table))

#ifndef OMIT_INITIALIZE_INTERRUPT

/*
 *  ������׵�饤�������֥�å�
 */
typedef struct interrupt_request_initialization_block {
	InterruptNumberType	intno;          /* ������ֹ� */
	AttributeType		intatr;         /* �����°�� */
	PriorityType		intpri;         /* �����ͥ���� */
#if defined(TOPPERS_CFG1_OUT) || defined(CFG_USE_STACKMONITORING)
	MemorySizeType remain_stksz;        /* �����å����̥����å������ѥ����å������� */
#endif /* defined(TOPPERS_CFG1_OUT) && defined(CFG_USE_STACKMONITORING) */
} INTINIB;

/*
 *  ������׵�饤��ο���Os_Lcfg.c��
 */
extern const InterruptNumberType	tnum_intno;

/*
 *  ������׵�饤�������֥�å��Υ��ꥢ��Os_Lcfg.c��
 */
extern const INTINIB				intinib_table[];

/*
 *  ISRCB��������ͥ���٤��Ф��ޥ���
 */
#define GET_INTPRI(p_isrcb)	((p_isrcb)->p_intinib->intpri)

#endif /* OMIT_INITIALIZE_INTERRUPT */

/*
 *  C2ISR�����ݻ������ѿ��������Os_Lcfg.c��
 */
extern const ISRType				tnum_isr2; /* C2ISR�ο� */

typedef struct isr_control_block {
	const INTINIB	*p_intinib;
	RESCB			*p_lastrescb;   /* �Ǹ�˳��������꥽���������֥�å��ؤΥݥ��� */
} ISRCB;

/*
 *  C2ISR�δ����֥�å��Υ��ꥢ��Os_Lcfg.c��
 */
extern ISRCB						isrcb_table[];

/*
 *  �¹����C2ISR
 *
 *  C2ISR��¹Ԥ��Ƥ��ʤ����ϡ�NULL �ˤ���
 */
extern ISRCB						*p_runisr;

/*
 *  SuspendAllInterrupts �Υͥ��Ȳ��
 */
extern uint8						sus_all_cnt;
extern uint8						sus_all_cnt_ctx;
/*
 *  SuspendOSInterrupts �Υͥ��Ȳ��
 */
extern uint8						sus_os_cnt;
extern uint8						sus_os_cnt_ctx;

/*
 *  ����ߴ�����ǽ�ν����
 */
extern void interrupt_initialize(void);

/*
 *  ����߶ػߤζ������
 */

extern void release_interrupts(OSServiceIdType serviceId);

/*
 *  C2ISR��λ���Υ����å��ؿ�
 */
extern void exit_isr2(void);

#endif /* TOPPERS_INTERRUPT_H */
