/*
 *  TOPPERS ATK2
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *      Automotive Kernel Version 2
 *
 *  Copyright (C) 2008-2015 by Center for Embedded Computing Systems
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
 *  $Id: target_hw_counter.h 1801 2015-03-27 06:34:43Z t_ishikawa $
 */

/*
 *		�ϡ��ɥ����������󥿤Υ������åȰ�¸�����NIOS2_DEV�ѡ�
 */

#ifndef TOPPERS_TARGET_HW_COUNTER_H
#define TOPPERS_TARGET_HW_COUNTER_H

/*
 *  �����󥿺�����
 */
#define MAX_TIMER_CNT		((uint32) 0xFFFFFFFF)

/*
 *  �����󥿼���������
 */
#define MAX_CNT_CYCLE		((uint32) 0x7FFFFFFF)

/*
 *  �����ޥϡ��ɥ�������¸�Υ١������
 */
#ifdef TOPPERS_NIOS2_DEV_2S180

/*
 *  �����ޡ�����å����ȿ���Hz��50MHz
 */
#define TIMER_CLOCK_HZ		((uint32) 50000000)

/*
 *  NIOS2_DEV_2S180 �Ѥ����������ֹ�
 */
#define TIMER_0_IRQ			UINT_C(16)
#define TIMER_1_IRQ			UINT_C(17)
#define TIMER_2_IRQ			UINT_C(18)
#define TIMER_3_IRQ			UINT_C(19)
#define TIMER_4_IRQ			UINT_C(20)
#define TIMER_5_IRQ			UINT_C(21)
#define TIMER_6_IRQ			UINT_C(22)
#define TIMER_7_IRQ			UINT_C(23)
#define TIMER_8_IRQ			UINT_C(24)
#define TIMER_9_IRQ			UINT_C(25)
#define TIMER_10_IRQ		UINT_C(26)
#define TIMER_11_IRQ		UINT_C(27)
#define TIMER_12_IRQ		UINT_C(28)
#define TIMER_13_IRQ		UINT_C(29)
#define TIMER_14_IRQ		UINT_C(30)
#define TIMER_15_IRQ		UINT_C(31)

/*
 *  NIOS2_DEV_2S180 �Ѥ���������ޥ쥸�����١���
 */
#define TIMER_BASE(INTNO)	(UINT_C(0x01001020) + (UINT_C(0x20) * ((INTNO) - UINT_C(16))))

#elif defined(TOPPERS_NIOS2_DEV_DE2_115)

/*
 *  �����ޡ�����å����ȿ���Hz��60MHz
 */
#define TIMER_CLOCK_HZ		((uint32) 60000000)

/*
 *  NIOS2_DEV_DE2_115 �Ѥ����������ֹ�
 */
#define TIMER_0_IRQ			UINT_C(16)
#define TIMER_1_IRQ			UINT_C(17)
#define TIMER_2_IRQ			UINT_C(18)
#define TIMER_3_IRQ			UINT_C(19)
#define TIMER_4_IRQ			UINT_C(20)
#define TIMER_5_IRQ			UINT_C(21)
#define TIMER_6_IRQ			UINT_C(22)
#define TIMER_7_IRQ			UINT_C(23)
#define TIMER_8_IRQ			UINT_C(24)
#define TIMER_9_IRQ			UINT_C(25)
#define TIMER_10_IRQ		UINT_C(26)
#define TIMER_11_IRQ		UINT_C(27)
#define TIMER_12_IRQ		UINT_C(28)
#define TIMER_13_IRQ		UINT_C(29)
#define TIMER_14_IRQ		UINT_C(30)
#define TIMER_15_IRQ		UINT_C(31)

/*
 *  NIOS2_DEV_DE2_115 �Ѥ���������ޥ쥸�����١���
 */
#define TIMER_BASE(INTNO)	(UINT_C(0x08000000) + (UINT_C(0x00000020) * (INTNO)))

#else /* TOPPERS_NIOS2_DEV_2S180/TOPPERS_NIOS2_DEV_DE2_115 */

/* ����ʳ��Υ������å���� */
#endif /* TOPPERS_NIOS2_DEV_2S180/TOPPERS_NIOS2_DEV_DE2_115 */

/*
 *  ������control�쥸�����Υӥå����
 */
#define TIMER_CONTROL_ITO		(UINT_C(0x00000001))
#define TIMER_CONTROL_CONT		(UINT_C(0x00000002))
#define TIMER_CONTROL_START		(UINT_C(0x00000004))
#define TIMER_CONTROL_STOP		(UINT_C(0x00000008))

/*
 *  TIMER��Ϣ�쥸�������
 */
#define TIMER_STATUS(INTNO)		(TIMER_BASE(INTNO) + UINT_C(0x00000000))
#define TIMER_CONTROL(INTNO)	(TIMER_BASE(INTNO) + UINT_C(0x00000004))
#define TIMER_PERIODL(INTNO)	(TIMER_BASE(INTNO) + UINT_C(0x00000008))
#define TIMER_PERIODH(INTNO)	(TIMER_BASE(INTNO) + UINT_C(0x0000000C))
#define TIMER_SNAPL(INTNO)		(TIMER_BASE(INTNO) + UINT_C(0x00000010))
#define TIMER_SNAPH(INTNO)		(TIMER_BASE(INTNO) + UINT_C(0x00000014))

/* MAIN_HW_COUNTER����� */
extern void init_hwcounter_MAIN_HW_COUNTER(TickType maxval, TimeType nspertick);
extern void start_hwcounter_MAIN_HW_COUNTER(void);
extern void stop_hwcounter_MAIN_HW_COUNTER(void);
extern void set_hwcounter_MAIN_HW_COUNTER(TickType exprtick);
extern TickType get_hwcounter_MAIN_HW_COUNTER(void);
extern void cancel_hwcounter_MAIN_HW_COUNTER(void);
extern void trigger_hwcounter_MAIN_HW_COUNTER(void);
extern void int_clear_hwcounter_MAIN_HW_COUNTER(void);
extern void int_cancel_hwcounter_MAIN_HW_COUNTER(void);
extern void increment_hwcounter_MAIN_HW_COUNTER(void);

/* SUB_HW_COUNTER1����� */
extern void init_hwcounter_SUB_HW_COUNTER1(TickType maxval, TimeType nspertick);
extern void start_hwcounter_SUB_HW_COUNTER1(void);
extern void stop_hwcounter_SUB_HW_COUNTER1(void);
extern void set_hwcounter_SUB_HW_COUNTER1(TickType exprtick);
extern TickType get_hwcounter_SUB_HW_COUNTER1(void);
extern void cancel_hwcounter_SUB_HW_COUNTER1(void);
extern void trigger_hwcounter_SUB_HW_COUNTER1(void);
extern void int_clear_hwcounter_SUB_HW_COUNTER1(void);
extern void int_cancel_hwcounter_SUB_HW_COUNTER1(void);
extern void increment_hwcounter_SUB_HW_COUNTER1(void);

/* SUB_HW_COUNTER2����� */
extern void init_hwcounter_SUB_HW_COUNTER2(TickType maxval, TimeType nspertick);
extern void start_hwcounter_SUB_HW_COUNTER2(void);
extern void stop_hwcounter_SUB_HW_COUNTER2(void);
extern void set_hwcounter_SUB_HW_COUNTER2(TickType exprtick);
extern TickType get_hwcounter_SUB_HW_COUNTER2(void);
extern void cancel_hwcounter_SUB_HW_COUNTER2(void);
extern void trigger_hwcounter_SUB_HW_COUNTER2(void);
extern void int_clear_hwcounter_SUB_HW_COUNTER2(void);
extern void int_cancel_hwcounter_SUB_HW_COUNTER2(void);
extern void increment_hwcounter_SUB_HW_COUNTER2(void);

/*
 *  10ms�Ȱ��פ���ƥ��å���(����ץ�ץ������)
 */
#define TICK_FOR_10MS	TIMER_CLOCK_HZ / 100

#endif /* TOPPERS_TARGET_HW_COUNTER_H */
