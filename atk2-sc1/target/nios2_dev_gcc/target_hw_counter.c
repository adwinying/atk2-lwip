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
 *  $Id: target_hw_counter.c 1801 2015-03-27 06:34:43Z t_ishikawa $
 */

/*
 *		�ʲ��ϡ��ɥ����������󥿥ץ����Υ������åȰ�¸�����NIOS2_DEV�ѡ�
 *
 *  ���Ѥ��륿���ޡ�
 *    ��ʬ�����ޡ���Ū�λ��֤����ꤹ����θ��߻���(�����ͥ�����)
 *              �ȼ�����λ���֤Ȥ����л��֤򥫥���Ȥ��뤳�Ȥ�
 *              ��Ū�����л��֤���λ�������ȤȤ���
 *              count mode:count down once
 *
 *    �����ͥ����ޡ������󥿼���ʬ�Υ١��������ޤ�¸�
 *              (���л��֤򥫥����)
 *              count mode:continuous count down
 *
 *    �ޤ��嵭�Υ����ޤ�32bit�Υ����󥫥��󥿥����ޤǤ���
 *
 *  �������ˡ�
 *
 *   �����ͥ����ޤϥ桼����������󥿺�����2��+1�ޤǥ�����Ȥ���
 *   ���������ޤȤ���Ϣ³������ȥ����󤷤ơ���˸��߻����
 *   �������롥�����ȯ������ɬ�פ��ʤ����ᡤ����ߤʤ��⡼��
 *
 *   ��ʬ�����ޤϡ���λ������Ԥ����ᡤ����ߤ���⡼�ɤ�ư��
 *   ���顼��ʤɤ���λ���ȥ����ޡ�1�Ǽ��������߻���κ���
 *   �����ͥ����ޤ����ꤹ��
 *
 *  �ݥ���ȡ�
 *   ��λ�����ϡ����߻����ƶ����ʤ����ᡤ�����ͥ����ޤ��ߤ��Ƥ���
 *
 */
#if defined(TOPPERS_NIOS2_DEV_2S180) || defined(TOPPERS_NIOS2_DEV_DE2_115)

#include "Os.h"
#include "prc_sil.h"
#include "target_hw_counter.h"

/* �����ؿ��Υץ�ȥ�������� */
static TickType get_curr_time(uint32 irq_no, TickType maxval);
static void init_hwcounter(uint32 irq_no, TickType maxval, TimeType nspertick, TickRefType cycle);
static void start_hwcounter(uint32 irq_no);
static void stop_hwcounter(uint32 irq_no);
static void set_hwcounter(uint32 irq_no, TickType exprtick, TickType maxval);
static TickType get_hwcounter(uint32 irq_no, TickType maxval);
static void cancel_hwcounter(uint32 irq_no);
static void trigger_hwcounter(uint32 irq_no);
static void int_clear_hwcounter(uint32 irq_no);
static void int_cancel_hwcounter(uint32 irq_no);
static void increment_hwcounter(uint32 irq_no);

/*
 *  �ϡ��ɥ����������󥿸��ߥƥ��å��ͼ���
 *  �����󥫥��󥿥����ޤΤ��ᡤ�Ѵ���ɬ��
 */
static TickType
get_curr_time(uint32 irq_no, TickType maxval)
{
	TickType curr_time = 0U;

	/* ���ʥåץ쥸�����˽񤭹�����ͤ�ۡ���ɤ��� */
	sil_wrw_iop((void *) TIMER_SNAPL(irq_no + 1U), 0x00U);

	/* �����ޡ����饫������ͤ��ɤ߹��� */
	curr_time = sil_rew_iop((void *) TIMER_SNAPL(irq_no + 1U));
	curr_time |= sil_rew_iop((void *) TIMER_SNAPH(irq_no + 1U)) << 16U;

	/* �����󥫥��󥿤ΰ١����ߥ��å��ͤ��Ѵ� */
	curr_time = maxval - curr_time;

	return(curr_time);
}

/*
 *  �ϡ��ɥ����������󥿤ν����
 */
static void
init_hwcounter(uint32 irq_no, TickType maxval, TimeType nspertick, TickRefType cycle)
{
	*cycle = maxval;

	/* ��ʬ��������� */
	sil_wrw_iop((void *) TIMER_CONTROL(irq_no), TIMER_CONTROL_STOP);
	/* ��ʬ�����ޥ����ॢ���ȥ��ơ��������ꥢ */
	sil_wrw_iop((void *) TIMER_STATUS(irq_no), 0x00U);

	/* �����ͥ�������� */
	sil_wrw_iop((void *) TIMER_CONTROL(irq_no + 1U), TIMER_CONTROL_STOP);
	/* �����ͥ����ޥ����ॢ���ȥ��ơ��������ꥢ */
	sil_wrw_iop((void *) TIMER_STATUS(irq_no + 1U), 0x00U);

	/* �����ͥ����ޥ����󥿡����å� ���16bit */
	sil_wrw_iop((void *) TIMER_PERIODH(irq_no + 1U), (maxval >> 16U));
	/* �����ͥ����ޥ����󥿡����å� ����16bit */
	sil_wrw_iop((void *) TIMER_PERIODL(irq_no + 1U), (maxval & 0xffffU));
}

/*
 *  �ϡ��ɥ����������󥿤γ���
 */
static void
start_hwcounter(uint32 irq_no)
{
	/*
	 *  �����ͥ����޳���(continuous count down mode)
	 *  �����ɬ�פ��ʤ����ᡤ����ߤʤ��⡼��
	 */
	sil_wrw_iop((void *) TIMER_CONTROL(irq_no + 1U), TIMER_CONTROL_CONT | TIMER_CONTROL_START);
}

/*
 *  �ϡ��ɥ����������󥿤����
 */
static void
stop_hwcounter(uint32 irq_no)
{
	/* ��ʬ��������� */
	sil_wrw_iop((void *) TIMER_CONTROL(irq_no), TIMER_CONTROL_STOP);

	/* ��ʬ�����ޤγ�����׵�Υ��ꥢ */
	sil_wrw_iop((void *) TIMER_STATUS(irq_no), 0x00U);

	/* �����ͥ�������� */
	sil_wrw_iop((void *) TIMER_CONTROL(irq_no + 1U), TIMER_CONTROL_STOP);

	/* �����ͥ����ޤγ�����׵�Υ��ꥢ */
	sil_wrw_iop((void *) TIMER_STATUS(irq_no + 1U), 0x00U);
}

/*
 *  �ϡ��ɥ����������󥿤ؤ���λ���֤�����
 */
static void
set_hwcounter(uint32 irq_no, TickType exprtick, TickType maxval)
{
	TickType	curr_time;
	TickType	value;

	/* ��ʬ�����ޤγ�����׵�Υ��ꥢ */
	sil_wrw_iop((void *) TIMER_STATUS(irq_no), 0x00U);

	/* ���߻���μ���	*/
	curr_time = get_curr_time(irq_no, maxval);

	/* �����ޤ����ꤹ���ͤ򻻽�	*/
	if (exprtick >= curr_time) {
		value = exprtick - curr_time;
	}
	else {
		value = maxval - curr_time + exprtick + 1U;
	}

	/*
	 *  �����ޤ�0x00�����ꤷ�������ȯ���塤����0�����ꤷ����硤2���ܤ�
	 *  0x00�����γ���ߤ�ȯ�����ʤ��Τǡ�0x00�����ͤ�0x01��ľ��������
	 *  �����ޤ˥��åȤ����ͤϡ����Ԥ�������Υ�������ͤ���-1����ɬ�פ�����
	 */
	if (value <= 0x01U) {
		value = 0x01U;
	}
	else {
		value -= 1U;
	}

	/*
	 *  ��ʬ�����ޥ����󥿡����å� ���16bit
	 *  ��ա�����bit���������ꤷ�ʤ��ȡ������2��ȯ�������ǽ��������
	 */
	sil_wrw_iop((void *) TIMER_PERIODH(irq_no), (value >> 16U));
	/* ��ʬ�����ޥ����󥿡����å� ����16bit */
	sil_wrw_iop((void *) TIMER_PERIODL(irq_no), (value & 0xffffU));

	/*
	 *  ��ʬ�����޳���(count down once mode)
	 *  �����ɬ�פΤ��ᡤ����ߥ⡼�ɤ���
	 */
	sil_wrw_iop((void *) TIMER_CONTROL(irq_no), TIMER_CONTROL_ITO | TIMER_CONTROL_START);
}

/*
 *  �ϡ��ɥ����������󥿤θ��߻��֤μ���
 */
static TickType
get_hwcounter(uint32 irq_no, TickType maxval)
{
	return(get_curr_time(irq_no, maxval));
}

/*
 *  �ϡ��ɥ����������󥿤����ꤵ�줿��λ���֤μ��
 */
static void
cancel_hwcounter(uint32 irq_no)
{
	/* ��ʬ��������� */
	sil_wrw_iop((void *) TIMER_CONTROL(irq_no), TIMER_CONTROL_STOP);
}

/*
 *  �ϡ��ɥ����������󥿤ζ���������׵�
 */
static void
trigger_hwcounter(uint32 irq_no)
{
	/* ��ʬ��������� */
	sil_wrw_iop((void *) TIMER_CONTROL(irq_no), TIMER_CONTROL_STOP);

	/* ��ʬ�����ޤγ�����׵�Υ��ꥢ */
	sil_wrw_iop((void *) TIMER_STATUS(irq_no), 0x00U);

	/* ��ʬ�����ޥ����󥿡���0x01�򥻥åȤ��뤳�Ȥǡ�������λ */
	sil_wrw_iop((void *) TIMER_PERIODH(irq_no), 0x00U);
	sil_wrw_iop((void *) TIMER_PERIODL(irq_no), 0x01U);

	/* ��ʬ�����޳��� */
	sil_wrw_iop((void *) TIMER_CONTROL(irq_no), TIMER_CONTROL_ITO | TIMER_CONTROL_START);
}

/*
 *  ������׵�Υ��ꥢ
 */
static void
int_clear_hwcounter(uint32 irq_no)
{
	/* ��ʬ�����ޤγ�����׵�Υ��ꥢ */
	sil_wrw_iop((void *) TIMER_STATUS(irq_no), 0x00U);
}

/*
 *  ������׵�Υ���󥻥�
 *  �ڥ�ǥ��󥰤���Ƥ��������׵�򥭥�󥻥�
 */
static void
int_cancel_hwcounter(uint32 irq_no)
{
	/* ��ʬ�����ޤγ�����׵�Υ��ꥢ */
	sil_wrw_iop((void *) TIMER_STATUS(irq_no), 0x00U);
}

/*
 *  �ϡ��ɥ����������󥿤Υ��󥯥����
 */
static void
increment_hwcounter(uint32 irq_no)
{
	/* Nios2�������åȤ�̤���ݡ��� */
	return;
}

/*
 *  MAIN_HW_COUNTER�����
 */
/* �����󥿤κ����ͤ�2��+1 */
static TickType MAIN_HW_COUNTER_maxval;

/*
 *  �ϡ��ɥ����������󥿤ν����
 */
void
init_hwcounter_MAIN_HW_COUNTER(TickType maxval, TimeType nspertick)
{
	init_hwcounter(TIMER_0_IRQ, maxval, nspertick, &MAIN_HW_COUNTER_maxval);
}

/*
 *  �ϡ��ɥ����������󥿤γ���
 */
void
start_hwcounter_MAIN_HW_COUNTER(void)
{
	start_hwcounter(TIMER_0_IRQ);
}

/*
 *  �ϡ��ɥ����������󥿤����
 */
void
stop_hwcounter_MAIN_HW_COUNTER(void)
{
	stop_hwcounter(TIMER_0_IRQ);
}

/*
 *  �ϡ��ɥ����������󥿤ؤ���λ���֤�����
 */
void
set_hwcounter_MAIN_HW_COUNTER(TickType exprtick)
{
	set_hwcounter(TIMER_0_IRQ, exprtick, MAIN_HW_COUNTER_maxval);
}

/*
 *  �ϡ��ɥ����������󥿤θ��߻��֤μ���
 */
TickType
get_hwcounter_MAIN_HW_COUNTER(void)
{
	return(get_hwcounter(TIMER_0_IRQ, MAIN_HW_COUNTER_maxval));
}

/*
 *  �ϡ��ɥ����������󥿤����ꤵ�줿��λ���֤μ��
 */
void
cancel_hwcounter_MAIN_HW_COUNTER(void)
{
	cancel_hwcounter(TIMER_0_IRQ);
}

/*
 *  �ϡ��ɥ����������󥿤ζ���������׵�
 */
void
trigger_hwcounter_MAIN_HW_COUNTER(void)
{
	trigger_hwcounter(TIMER_0_IRQ);
}

/*
 *  �ϡ��ɥ����������󥿤����ꤵ�줿��λ���֤μ��
 */
void
int_clear_hwcounter_MAIN_HW_COUNTER(void)
{
	int_clear_hwcounter(TIMER_0_IRQ);
}

/*
 *  �ϡ��ɥ����������󥿤����ꤵ�줿��λ���֤μ��
 */
void
int_cancel_hwcounter_MAIN_HW_COUNTER(void)
{
	int_cancel_hwcounter(TIMER_0_IRQ);
}

/*
 *  �ϡ��ɥ����������󥿤Υ��󥯥����
 */
void
increment_hwcounter_MAIN_HW_COUNTER(void)
{
	increment_hwcounter(TIMER_0_IRQ);
}

/*
 *  SUB_HW_COUNTER1B�����
 */
/* �����󥿤κ����ͤ�2��+1 */
static TickType SUB_HW_COUNTER1_maxval;

/*
 *  �ϡ��ɥ����������󥿤ν����
 */
void
init_hwcounter_SUB_HW_COUNTER1(TickType maxval, TimeType nspertick)
{
	init_hwcounter(TIMER_2_IRQ, maxval, nspertick, &SUB_HW_COUNTER1_maxval);
}

/*
 *  �ϡ��ɥ����������󥿤γ���
 */
void
start_hwcounter_SUB_HW_COUNTER1(void)
{
	start_hwcounter(TIMER_2_IRQ);
}

/*
 *  �ϡ��ɥ����������󥿤����
 */
void
stop_hwcounter_SUB_HW_COUNTER1(void)
{
	stop_hwcounter(TIMER_2_IRQ);
}

/*
 *  �ϡ��ɥ����������󥿤ؤ���λ���֤�����
 */
void
set_hwcounter_SUB_HW_COUNTER1(TickType exprtick)
{
	set_hwcounter(TIMER_2_IRQ, exprtick, SUB_HW_COUNTER1_maxval);
}

/*
 *  �ϡ��ɥ����������󥿤θ��߻��֤μ���
 */
TickType
get_hwcounter_SUB_HW_COUNTER1(void)
{
	return(get_hwcounter(TIMER_2_IRQ, SUB_HW_COUNTER1_maxval));
}

/*
 *  �ϡ��ɥ����������󥿤����ꤵ�줿��λ���֤μ��
 */
void
cancel_hwcounter_SUB_HW_COUNTER1(void)
{
	cancel_hwcounter(TIMER_2_IRQ);
}

/*
 *  �ϡ��ɥ����������󥿤ζ���������׵�
 */
void
trigger_hwcounter_SUB_HW_COUNTER1(void)
{
	trigger_hwcounter(TIMER_2_IRQ);
}

/*
 *  �ϡ��ɥ����������󥿤����ꤵ�줿��λ���֤μ��
 */
void
int_clear_hwcounter_SUB_HW_COUNTER1(void)
{
	int_clear_hwcounter(TIMER_2_IRQ);
}

/*
 *  �ϡ��ɥ����������󥿤����ꤵ�줿��λ���֤μ��
 */
void
int_cancel_hwcounter_SUB_HW_COUNTER1(void)
{
	int_cancel_hwcounter(TIMER_2_IRQ);
}

/*
 *  �ϡ��ɥ����������󥿤Υ��󥯥����
 */
void
increment_hwcounter_SUB_HW_COUNTER1(void)
{
	increment_hwcounter(TIMER_2_IRQ);
}

/*
 *  SUB_HW_COUNTER2�����
 */
/* �����󥿤κ����ͤ�2��+1 */
static TickType SUB_HW_COUNTER2_maxval;

/*
 *  �ϡ��ɥ����������󥿤ν����
 */
void
init_hwcounter_SUB_HW_COUNTER2(TickType maxval, TimeType nspertick)
{
	init_hwcounter(TIMER_4_IRQ, maxval, nspertick, &SUB_HW_COUNTER2_maxval);
}

/*
 *  �ϡ��ɥ����������󥿤γ���
 */
void
start_hwcounter_SUB_HW_COUNTER2(void)
{
	start_hwcounter(TIMER_4_IRQ);
}

/*
 *  �ϡ��ɥ����������󥿤����
 */
void
stop_hwcounter_SUB_HW_COUNTER2(void)
{
	stop_hwcounter(TIMER_4_IRQ);
}

/*
 *  �ϡ��ɥ����������󥿤ؤ���λ���֤�����
 */
void
set_hwcounter_SUB_HW_COUNTER2(TickType exprtick)
{
	set_hwcounter(TIMER_4_IRQ, exprtick, SUB_HW_COUNTER2_maxval);
}

/*
 *  �ϡ��ɥ����������󥿤θ��߻��֤μ���
 */
TickType
get_hwcounter_SUB_HW_COUNTER2(void)
{
	return(get_hwcounter(TIMER_4_IRQ, SUB_HW_COUNTER2_maxval));
}

/*
 *  �ϡ��ɥ����������󥿤����ꤵ�줿��λ���֤μ��
 */
void
cancel_hwcounter_SUB_HW_COUNTER2(void)
{
	cancel_hwcounter(TIMER_4_IRQ);
}

/*
 *  �ϡ��ɥ����������󥿤ζ���������׵�
 */
void
trigger_hwcounter_SUB_HW_COUNTER2(void)
{
	trigger_hwcounter(TIMER_4_IRQ);
}

/*
 *  �ϡ��ɥ����������󥿤����ꤵ�줿��λ���֤μ��
 */
void
int_clear_hwcounter_SUB_HW_COUNTER2(void)
{
	int_clear_hwcounter(TIMER_4_IRQ);
}

/*
 *  �ϡ��ɥ����������󥿤����ꤵ�줿��λ���֤μ��
 */
void
int_cancel_hwcounter_SUB_HW_COUNTER2(void)
{
	int_cancel_hwcounter(TIMER_4_IRQ);
}

/*
 *  �ϡ��ɥ����������󥿤Υ��󥯥����
 */
void
increment_hwcounter_SUB_HW_COUNTER2(void)
{
	increment_hwcounter(TIMER_4_IRQ);
}

#endif /* defined(TOPPERS_NIOS2_DEV_2S180) || defined(TOPPERS_NIOS2_DEV_DE2_115) */
