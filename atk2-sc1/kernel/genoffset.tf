$
$  TOPPERS ATK2
$      Toyohashi Open Platform for Embedded Real-Time Systems
$      Automotive Kernel Version 2
$
$  Copyright (C) 2011-2015 by Center for Embedded Computing Systems
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
$  $Id: genoffset.tf 1801 2015-03-27 06:34:43Z t_ishikawa $
$

$
$  #define�ǥ��쥯�ƥ��֤�����
$
$FUNCTION DEFINE$
	#define $ARGV[1]$$TAB$$FORMAT("%d", +ARGV[2])$$NL$
$END$

$
$  �ӥåȤΥ�����
$
$FUNCTION SEARCH_BIT$
	$_val = ARGV[1]$
	$FOREACH _val_bit RANGE(0,7)$
		$IF (_val & 1) != 0$
			$RESULT = _val_bit$
		$END$
		$_val = _val >> 1$
	$END$
$END$

$
$  �ӥåȥե�����ɤΥ��ե��åȤȥӥåȰ��֤����������
$
$FUNCTION DEFINE_BIT$
	$label = ARGV[1]$
	$struct_size = ARGV[2]$
	$output_size = ARGV[3]$

	$top = SYMBOL(label)$
	$IF !LENGTH(top)$
		$ERROR$$FORMAT("label %1% not found", label)$$END$
	$ELSE$
		$val = 0$
		$FOREACH i RANGE(0,struct_size-1)$
			$tmp_val = PEEK(top + i, 1)$
			$IF val == 0 && tmp_val != 0$
				$val = tmp_val$
				$offset = i$
			$END$
		$END$

		$IF val == 0$
			$ERROR$$FORMAT("bit not found in %1%", ARGV[1])$$END$
		$ELSE$
			$val_bit = SEARCH_BIT(val)$
			$RESULT = {}$
			$IF EQ(output_size, "W")$
				$IF SIL_ENDIAN_BIG$
					$val_bit = val_bit + 24 - ((offset & 0x03) << 3)$
				$ELSE$
					$val_bit = val_bit + ((offset & 0x03) << 3)$
				$END$
				$offset = offset & ~0x03$
			$ELSE$$IF EQ(output_size, "H")$
				$IF SIL_ENDIAN_BIG$
					$val_bit = val_bit + 8 - ((offset & 0x01) << 3)$
				$ELSE$
					$val_bit = val_bit + ((offset & 0x01) << 3)$
				$END$
				$offset = offset & ~0x01$
			$END$$END$
		$END$

		#define $label$$TAB$$FORMAT("%d", +offset)$$NL$
		#define $label$_bit$TAB$$FORMAT("%d", +val_bit)$$NL$
		#define $label$_mask$TAB$$FORMAT("0x%x", 1 << val_bit)$$NL$
	$END$
$END$

$
$  �Х������֤Υ����å�
$
$FUNCTION MAGIC_CHECK$
	$size = ARGV[1]$
	$check = ARGV[2]$

	$label = FORMAT("MAGIC_%d", +size)$
	$top = SYMBOL(label)$
	$IF !LENGTH(top)$
		$ERROR$$FORMAT("label %1% not found", label)$$END$
	$ELSE$
		$FOREACH offset RANGE(1,size)$
			$IF SIL_ENDIAN_BIG$
				$val = PEEK(top + offset - 1, 1)$
			$ELSE$
				$val = PEEK(top + size - offset, 1)$
			$END$
			$IF val != AT(check, offset - 1)$
				$ERROR$$FORMAT("value check of %1% failed", label)$$END$
			$END$
		$END$
	$END$
$END$

$MAGIC_CHECK(1, { 0x12 })$
$MAGIC_CHECK(2, { 0x12, 0x34 })$
$MAGIC_CHECK(4, { 0x12, 0x34, 0x56, 0x78 })$

$
$  �ե�����إå�������
$
$FILE "offset.h"$

$NL$
