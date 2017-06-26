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
$  $Id: kernel_check.tf 1801 2015-03-27 06:34:43Z t_ishikawa $
$

$INCLUDE "cfg2_out.tf"$

$
$  �ؿ�����Ƭ���ϤΥ����å�
$
$IF CHECK_FUNC_ALIGN || CHECK_FUNC_NONNULL$
$	// ����������Ƭ���ϤΥ��饤������å�
	$tinib = SYMBOL("tinib_table")$
	$FOREACH tskid TSK.ID_LIST$
		$task = PEEK(tinib + offsetof_TINIB_task, sizeof_FunctionRefType)$
		$IF CHECK_FUNC_ALIGN && (task & (CHECK_FUNC_ALIGN - 1)) != 0$
			$ERROR TSK.TEXT_LINE[tskid]$$FORMAT(_("%1% of %2% `%3%\' is not aligned"), "task", "TINIB", tskid)$$END$
		$END$
$		// ����������Ƭ���Ϥ�NULL�����å�
		$IF CHECK_FUNC_NONNULL && task == 0$
			$ERROR TSK.TEXT_LINE[tskid]$$FORMAT(_("%1% of %2% `%3%\' is null"),	"task", "TINIB", tskid)$$END$
		$END$
		$tinib = tinib + sizeof_TINIB$
	$END$

$	// ���顼����λ������������Ƭ���ϤΥ����å�
	$alminib = SYMBOL("alminib_table")$
	$FOREACH almid ALM.ID_LIST$
		$action = PEEK(alminib + offsetof_ALMINIB_action, sizeof_FunctionRefType)$
		$IF CHECK_FUNC_ALIGN && (action & (CHECK_FUNC_ALIGN - 1)) != 0$
			$ERROR ALM.TEXT_LINE[almid]$$FORMAT(_("%1% of %2% `%3%\' is not aligned"), "action", "alarm", almid)$$END$
		$END$
		$IF CHECK_FUNC_NONNULL && action == 0$
			$ERROR ALM.TEXT_LINE[almid]$$FORMAT(_("%1% of %2% `%3%\' is null"),	"action", "alarm", almid)$$END$
		$END$
		$alminib = alminib + sizeof_ALMINIB$
	$END$

$	//�ϡ��ɥ����������󥿤ν����ؿ�
	$HWCNTFUNC_VALID = { VALUE("init",0),VALUE("start",1),VALUE("stop",2),VALUE("set",3),VALUE("get",4),
	VALUE("cancel",5),VALUE("trigger",6),VALUE("intclear",7),VALUE("intcancel",8),VALUE("increment",9) }$

$	// �ϡ��ɥ����������󥿤ν����ؿ��Υ��饤������å�
	$hwcntinib = SYMBOL("hwcntinib_table")$
	$FOREACH hwcntid HWCNT.ID_LIST$
		$FOREACH memberid HWCNTFUNC_VALID$
			$offsetofmember = offsetof_HWCNTINIB_init + (sizeof_FunctionRefType * memberid)$
			$hwfunc = PEEK(hwcntinib + offsetofmember, sizeof_FunctionRefType)$
			$IF CHECK_FUNC_ALIGN && (hwfunc & (CHECK_FUNC_ALIGN - 1)) != 0$
				$ERROR HWCNT.TEXT_LINE[hwcntid]$$FORMAT(_("%1% of %2% in `%3%\' is not aligned"), memberid, "HWCNTINIB", hwcntid)$$END$
			$END$
$			// �ϡ��ɥ����������󥿤ν����ؿ���NULL�����å�
			$IF CHECK_FUNC_NONNULL && hwfunc == 0$
				$ERROR HWCNT.TEXT_LINE[hwcntid]$$FORMAT(_("%1% of %2% in `%3%\' is null"), memberid, "HWCNTINIB", hwcntid)$$END$
			$END$
		$END$
		$hwcntinib = hwcntinib + sizeof_HWCNTINIB$
	$END$
$END$

$
$  �����å��ΰ����Ƭ���ϤΥ����å�
$
$IF CHECK_STACK_ALIGN || CHECK_STACK_NONNULL$
$	// �������Υ����å��ΰ����Ƭ���ϤΥ����å�
	$tinib = SYMBOL("tinib_table")$
	$FOREACH tskid TSK.ID_LIST$
		$IF USE_TSKINICTXB$
			$stk = GET_STK_TSKINICTXB(tinib)$
		$ELSE$
			$stk = PEEK(tinib + offsetof_TINIB_stk, sizeof_void_ptr)$
		$END$
		$IF CHECK_STACK_ALIGN && (stk & (CHECK_STACK_ALIGN - 1)) != 0$
			$ERROR TSK.TEXT_LINE[tskid]$$FORMAT(_("%1% `%2%\' of `%3%\' is not aligned"), "stk", TSK.STK[tskid], tskid)$$END$
		$END$
		$IF CHECK_STACK_NONNULL && stk == 0$
			$ERROR TSK.TEXT_LINE[tskid]$$FORMAT(_("%1% `%2%\' of `%3%\' is null"), "stk", TSK.STK[tskid], tskid)$$END$
		$END$
		$tinib = tinib + sizeof_TINIB$
	$END$

$	// �󥿥�������ƥ������ѤΥ����å��ΰ����Ƭ���ϤΥ����å�
	$ostk_addr = PEEK(SYMBOL("_ostk"), sizeof_void_ptr)$
	$IF CHECK_STACK_ALIGN && (ostk_addr & (CHECK_STACK_ALIGN - 1)) != 0$
		$ERROR OSTK.TEXT_LINE[1]$$FORMAT(_("%1% `%2%\' is not aligned"), "stk", OSTK.STK[1])$$END$
	$END$
	$IF CHECK_STACK_NONNULL && ostk_addr == 0$
		$ERROR OSTK.TEXT_LINE[1]$$FORMAT(_("%1% `%2%\' is null"), "stk", OSTK.STK[1])$$END$
	$END$
$END$
