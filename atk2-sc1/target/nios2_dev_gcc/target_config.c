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
 *  $Id: target_config.c 1801 2015-03-27 06:34:43Z t_ishikawa $
 */

/*
 *		�������åȰ�¸�⥸�塼���NIOS2_DEV�ѡ�
 */

#include "kernel_impl.h"
#include "nios2_gcc/prc_sil.h"
#include "target_sysmod.h"
#ifdef ENABLE_RETURN_MAIN
#include "interrupt.h"
#endif /* ENABLE_RETURN_MAIN */
#ifdef TOPPERS_ENABLE_TRACE
#include "logtrace/trace_config.h"
#endif /* TOPPERS_ENABLE_TRACE */

#ifdef USE_UART
#include "nios2_gcc/uart.h"
#else /* USE_UART */
#include "nios2_gcc/jtag_uart.h"
#endif /* USE_UART */

/* �����ؿ��Υץ�ȥ�������� */
static void hw_version_check(void);

/*
 *  ʸ����ν���
 */
void
target_fput_str(const char8 *c)
{
	while (*c != '\0') {
		nios2_dev_putc(*c);
		c++;
	}
	nios2_dev_putc('\n');
}

/*
 *  �С����������å�
 */
static void
hw_version_check(void)
{
	/* ���������ǧ */
	if (sil_rew_iop((void *) (SYSVER_NUM_CORE)) != TNUM_HWCORE) {
		target_fput_str("Number of core is mismatch!!");
		while (1) {
		}
	}

	if (sil_rew_iop((void *) (SYSVER_MAJOR_VAR)) != MAJOR_VAR) {
		target_fput_str("Hardware Major version is mismatch!!");
		while (1) {
		}
	}
}
void
target_hardware_initialize(void)
{
	/*
	 *  �ϡ��ɥ������С������γ�ǧ
	 */
	hw_version_check();

	prc_hardware_initialize();
}

/*
 *  �������åȰ�¸�ν����
 */
void
target_initialize(void)
{
	/*
	 *  Nios2��¸�ν����
	 */
	prc_initialize();

#ifdef TOPPERS_ENABLE_TRACE
	/*
	 *  �ȥ졼������ǽ�ν����
	 */
	trace_initialize((uintptr) (TRACE_AUTOSTOP));
#endif /* TOPPERS_ENABLE_TRACE */
}

/*
 *  �������åȰ�¸�ν�λ����
 */
void
target_exit(void)
{
#ifdef TOPPERS_ENABLE_TRACE
	/*
	 *  �ȥ졼�����Υ����
	 */
	trace_dump(&target_fput_log);
#endif /* TOPPERS_ENABLE_TRACE */

#ifndef ENABLE_RETURN_MAIN
	/*
	 *  ����åȥ���������ν���
	 */
	target_fput_str("Kernel Exit...");
#else
	target_fput_str("Kernel Shutdown...");
#endif /* ENABLE_RETURN_MAIN */

	/*
	 *  Nios2��¸�ν�λ����
	 */
	prc_terminate();

#ifdef ENABLE_RETURN_MAIN
	kerflg = FALSE;
	except_nest_cnt = 0U;
	nested_lock_os_int_cnt = 0U;
	sus_all_cnt = 0U;
	sus_all_cnt_ctx = 0U;
	sus_os_cnt = 0U;
	sus_os_cnt_ctx = 0U;

	Asm("movia r2, _ostkpt");
	Asm("ldw   sp, 0(r2)");
	Asm("call  main");
#endif /* ENABLE_RETURN_MAIN */

	while (1) {
	}
}

/*
 *  �������åȰ�¸��ʸ������
 */
void
target_fput_log(char8 c)
{
	nios2_dev_putc(c);
}
