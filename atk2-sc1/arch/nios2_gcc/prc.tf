$
$  TOPPERS ATK2
$      Toyohashi Open Platform for Embedded Real-Time Systems
$      Automotive Kernel Version 2
$
$  Copyright (C) 2008-2015 by Center for Embedded Computing Systems
$              Graduate School of Information Science, Nagoya Univ., JAPAN
$  Copyright (C) 2011-2015 by FUJI SOFT INCORPORATED, JAPAN
$  Copyright (C) 2011-2013 by Spansion LLC, USA
$  Copyright (C) 2011-2015 by NEC Communication Systems, Ltd., JAPAN
$  Copyright (C) 2011-2015 by Panasonic Advanced Technology Development Co., Ltd., JAPAN
$  Copyright (C) 2011-2014 by Renesas Electronics Corporation, JAPAN
$  Copyright (C) 2011-2015 by Sunny Giken Inc., JAPAN
$  Copyright (C) 2011-2015 by TOSHIBA CORPORATION, JAPAN
$  Copyright (C) 2011-2015 by Witz Corporation
$  Copyright (C) 2014-2015 by AISIN COMCRUISE Co., Ltd., JAPAN
$  Copyright (C) 2014-2015 by eSOL Co.,Ltd., JAPAN
$  Copyright (C) 2014-2015 by SCSK Corporation, JAPAN
$
$  �嵭����Ԥϡ��ʲ���(1)��(4)�ξ������������˸¤ꡤ�ܥ��եȥ���
$  �����ܥ��եȥ���������Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ������
$  �ѡ������ۡʰʲ������ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
$  (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭������
$      ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ���
$      ����������˴ޤޤ�Ƥ��뤳�ȡ�
$  (2) �ܥ��եȥ������򡤥饤�֥������ʤɡ�¾�Υ��եȥ�������ȯ�˻�
$      �ѤǤ�����Ǻ����ۤ�����ˤϡ������ۤ�ȼ���ɥ�����ȡ�����
$      �ԥޥ˥奢��ʤɡˤˡ��嵭�����ɽ�����������Ѿ�浪��Ӳ���
$      ��̵�ݾڵ����Ǻܤ��뤳�ȡ�
$  (3) �ܥ��եȥ������򡤵�����Ȥ߹���ʤɡ�¾�Υ��եȥ�������ȯ�˻�
$      �ѤǤ��ʤ����Ǻ����ۤ�����ˤϡ����Τ����줫�ξ�����������
$      �ȡ�
$    (a) �����ۤ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭����
$        �ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
$    (b) �����ۤη��֤��̤�������ˡ�ˤ�äơ�TOPPERS�ץ������Ȥ�
$        ��𤹤뤳�ȡ�
$  (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
$      ������⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ����դ��뤳�ȡ�
$      �ޤ����ܥ��եȥ������Υ桼���ޤ��ϥ���ɥ桼������Τ����ʤ���
$      ͳ�˴�Ť����ᤫ��⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ�
$      ���դ��뤳�ȡ�
$
$  �ܥ��եȥ������ϡ�AUTOSAR��AUTomotive Open System ARchitecture�˻�
$  �ͤ˴�Ť��Ƥ��롥�嵭�ε����ϡ�AUTOSAR����Ū�⻺������������Τ�
$  �Ϥʤ���AUTOSAR�ϡ�AUTOSAR���ͤ˴�Ť������եȥ�����������Ū����
$  �Ѥ���Ԥ��Ф��ơ�AUTOSAR�ѡ��ȥʡ��ˤʤ뤳�Ȥ���Ƥ��롥
$
$  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ�
$  ���TOPPERS�ץ������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����λ�����Ū
$  ���Ф���Ŭ������ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ���
$  �������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤��
$  ����Ǥ�����ʤ���
$
$  $Id: prc.tf 1801 2015-03-27 06:34:43Z t_ishikawa $
$

$
$     �ѥ�2�Υ������ƥ������¸�ƥ�ץ졼�ȡ�Nios2�ѡ�
$

$
$  ͭ���ʳ�����ֹ�
$
$INTNO_VALID = { 0,1,...,31 }$

$
$ �����ͥ���٤θĿ�
$
$TNUM_INTPRI = 64$

$
$  CRE_ISR2�ǻ��ѤǤ��������ֹ�
$
$INTNO_CREISR2_VALID = INTNO_VALID$

$FUNCTION EXTERN_INT_HANDLER$
$OUTPUT_LIST = {}$
$
$ �װ����Ȥγ������������
$
$FOREACH intno INTNO_VALID$
	$FOREACH isrid ISR.ID_LIST$
		$IF LENGTH(isrid) && EQ(ISR.CATEGORY[isrid], "CATEGORY_2") &&
			ISR.INTNO[isrid] == intno && !LENGTH(FIND(OUTPUT_LIST, intno))$
			extern void int_handler_entry_$intno$(void) __attribute__((naked));$NL$
			$OUTPUT_LIST = APPEND(OUTPUT_LIST, intno)$
		$END$
	$END$
$END$
$NL$
$END$

$
$  ɸ��ƥ�ץ졼�ȥե�����Υ��󥯥롼��
$
$INCLUDE "kernel/kernel.tf"$


$FOREACH intno INTNO_VALID$
	$FOREACH isrid ISR.ID_LIST$
		$IF intno == ISR.INTNO[isrid]$
			$INT.ISRID[intno] = isrid$
		$END$
	$END$
$END$


$FILE "Os_Lcfg.c"$

$
$ C2ISR��ͥ���ٲ���
$
const uint32 tmin_status_il = ((uint32) INT_IPM($MIN_PRI_ISR2$) << STATUS_IL_OFFSET);$NL$
$NL$

$
$  ����ߥϥ�ɥ�ơ��֥�
$
const FunctionRefType isr_tbl[TNUM_INT] = {$NL$
$JOINEACH intno INTNO_VALID "\n"$
	$isrid = INT.ISRID[intno]$
	$IF LENGTH(isrid) && EQ(ISR.CATEGORY[isrid], "CATEGORY_2")$
		$TAB$&$ISR.INT_ENTRY[isrid]$
	$ELSE$
		$TAB$&default_int_handler
	$END$
$	//����ޤν��ϡʺǸ�����Ǥθ��˽��Ϥ��ʤ���
	$IF intno != AT(INTNO_VALID,LENGTH(INTNO_VALID) - 1)$
		,
	$END$
	$TAB$$FORMAT("/* %d */", intno)$
$END$
$NL$};$NL$
$NL$

$
$  ISRCB�μ����ơ��֥�
$
ISRCB * const isr_p_isrcb_tbl[TNUM_INT] = {$NL$
$JOINEACH intno INTNO_VALID "\n"$
	$isrid = INT.ISRID[intno]$
	$IF LENGTH(isrid) && EQ(ISR.CATEGORY[isrid], "CATEGORY_2")$
		$TAB$&(isrcb_table[$ISR.ID[isrid]$])
	$ELSE$
		$TAB$NULL
	$END$
$	//����ޤν��ϡʺǸ�����Ǥθ��˽��Ϥ��ʤ���
	$IF intno != AT(INTNO_VALID,LENGTH(INTNO_VALID) - 1)$
		,
	$END$
	$TAB$$FORMAT("/* %d */", intno)$
$END$
$NL$};$NL$
$NL$

$
$ ����ߥ٥����ȳƳ������������
$

$
$ �װ����Ȥγ������������
$
$FOREACH intno INTNO_VALID$
	$isrid = INT.ISRID[intno]$
	$IF LENGTH(isrid) && EQ(ISR.CATEGORY[isrid], "CATEGORY_2")$
		void$NL$
		int_handler_entry_$intno$(void)$NL$
		{$NL$
			$TAB$Asm("movi  et, $intno$");$NL$
			$TAB$Asm("jmpi  interrupt");$NL$
		}$NL$
		$NL$
	$END$
$END$

$
$ �٥����ơ��֥�
$
void __attribute__((naked))$NL$
kernel_vectors(void)$NL$
{$NL$
$FOREACH intno INTNO_VALID$
	$isrid = INT.ISRID[intno]$
	$IF LENGTH(isrid)$
		$IF EQ(ISR.CATEGORY[isrid], "CATEGORY_2")$
			$TAB$Asm("jmpi int_handler_entry_$intno$");
		$ELSE$
			$TAB$Asm("jmpi $ISR.INT_ENTRY[isrid]$");
		$END$
	$ELSE$

$		// ����ߥϥ�ɥ����Ͽ���ʤ����
		$TAB$Asm("jmpi default_int_handler");
	$END$
	$FORMAT(" /* %d */", intno)$$NL$
$END$
}$NL$
