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
 *  $Id: nios2_system.h 1801 2015-03-27 06:34:43Z t_ishikawa $
 */

/*
 *		Nios2�����ƥ�����
 *
 *  �ڥ�ե����Υ��ɥ쥹�������ֹ���������
 */

#ifndef TOPPERS_NIOS2_SYSTEM_H
#define TOPPERS_NIOS2_SYSTEM_H

#ifdef TOPPERS_NIOS2_DEV_2S180

/*
 *  NIOS2_DEV_2S180 �Ѥ����
 */

/*
 *  ��ư��å������Υ������åȥ����ƥ�̾
 */
#define TARGET_NAME	"NIOS2_DEV_2S180(NIOS2)"

/*
 *  �������ͤ�����ɽ���ȥߥ���ñ�̤Ȥ��Ѵ�
 */
#define TIMER_CLOCK		UINT_C(50000)

/*
 *  ����å��奵����
 */
#define NIOS2_ICACHE_SIZE			UINT_C(0x1000)   /* 4Kbyte */
#define NIOS2_ICACHE_LINE_SIZE		UINT_C(32)
#define NIOS2_DCACHE_SIZE			UINT_C(0)
#define NIOS2_DCACHE_LINE_SIZE		UINT_C(0)

/*
 *  Interval Timer
 */
#define SYS_CLK_TIMER_BASE	UINT_C(0x01001000)
#define SYS_CLK_TIMER_INT	UINT_C(0)

/*
 *  JTAG UART
 */
#define JTAG_UART_PORT1_BASE	UINT_C(0x010008a0)
#define JTAG_UART_PORT1_INT		UINT_C(1)

/*
 *  �����ƥ�С������쥸�����Υ١������ɥ쥹
 */
#define SYSVER_BASE				UINT_C(0x0f000000)

/*
 *  �����ƥ�С�����󻲾���
 */
#define TNUM_HWCORE				UINT_C(1)           /* ������ */
#define MAJOR_VAR				UINT_C(5)           /* �᥸�㡼�С������ */

/*
 *  �٥�������ߥ���ȥ���
 */
#define VIC_BASE				UINT_C(0x01000c00)  /* �١������ɥ쥹 */
#define VIC_INT_NUM				UINT_C(32)

#elif defined(TOPPERS_NIOS2_DEV_DE2_115)

/*
 *  NIOS2_DEV_DE2_115 �Ѥ����
 */

/*
 *  ��ư��å������Υ������åȥ����ƥ�̾
 */
#define TARGET_NAME	"NIOS2_DEV_DE2_115(NIOS2)"

/*
 *  �������ͤ�����ɽ���ȥߥ���ñ�̤Ȥ��Ѵ�
 */
#define TIMER_CLOCK		UINT_C(60000)

/*
 *  ����å��奵����
 */
#define NIOS2_ICACHE_SIZE			UINT_C(0x1000)   /* 4Kbyte */
#define NIOS2_ICACHE_LINE_SIZE		UINT_C(32)
#define NIOS2_DCACHE_SIZE			UINT_C(0)
#define NIOS2_DCACHE_LINE_SIZE		UINT_C(0)

/*
 *  Interval Timer
 */
#define SYS_CLK_TIMER_BASE	UINT_C(0x08000160)
#define SYS_CLK_TIMER_INT	UINT_C(0)

/*
 *  JTAG UART
 */
#define JTAG_UART_PORT1_BASE	UINT_C(0x080001a0)
#define JTAG_UART_PORT1_INT		UINT_C(1)

/*
 *  UART
 */
#define UART_PORT1_BASE	UINT_C(0x02000d00)
#define UART_PORT1_INT	UINT_C(3)

/*
 *  �����ƥ�С������쥸�����Υ١������ɥ쥹
 */
#define SYSVER_BASE				UINT_C(0x080001c0)

/*
 *  �����ƥ�С�����󻲾���
 */
#define TNUM_HWCORE				UINT_C(1)           /* ������ */
#define MAJOR_VAR				UINT_C(7)           /* �᥸�㡼�С������ */

/*
 *  �٥�������ߥ���ȥ���
 */
#define VIC_BASE				UINT_C(0x0f000000)  /* �١������ɥ쥹 */
#define VIC_INT_NUM				UINT_C(32)

#endif /* TOPPERS_NIOS2_DEV_DE2_115 */

/*
 *  �����ƥ�С������쥸����(sysver)
 */
#define SYSVER_MAJOR_VAR	(SYSVER_BASE + 0x00U)
#define SYSVER_MINOR_VAR	(SYSVER_BASE + 0x04U)
#define SYSVER_NUM_CORE		(SYSVER_BASE + 0x08U)

#endif /* TOPPERS_NIOS2_SYSTEM_H */
