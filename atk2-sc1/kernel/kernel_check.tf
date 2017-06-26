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
$  上記著作権者は，以下の(1)〜(4)の条件を満たす場合に限り，本ソフトウェ
$  ア（本ソフトウェアを改変したものを含む．以下同じ）を使用・複製・改
$  変・再配布（以下，利用と呼ぶ）することを無償で許諾する．
$  (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
$      権表示，この利用条件および下記の無保証規定が，そのままの形でソー
$      スコード中に含まれていること．
$  (2) 本ソフトウェアを，ライブラリ形式など，他のソフトウェア開発に使
$      用できる形で再配布する場合には，再配布に伴うドキュメント（利用
$      者マニュアルなど）に，上記の著作権表示，この利用条件および下記
$      の無保証規定を掲載すること．
$  (3) 本ソフトウェアを，機器に組み込むなど，他のソフトウェア開発に使
$      用できない形で再配布する場合には，次のいずれかの条件を満たすこ
$      と．
$    (a) 再配布に伴うドキュメント（利用者マニュアルなど）に，上記の著
$        作権表示，この利用条件および下記の無保証規定を掲載すること．
$    (b) 再配布の形態を，別に定める方法によって，TOPPERSプロジェクトに
$        報告すること．
$  (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
$      害からも，上記著作権者およびTOPPERSプロジェクトを免責すること．
$      また，本ソフトウェアのユーザまたはエンドユーザからのいかなる理
$      由に基づく請求からも，上記著作権者およびTOPPERSプロジェクトを
$      免責すること．
$
$  本ソフトウェアは，AUTOSAR（AUTomotive Open System ARchitecture）仕
$  様に基づいている．上記の許諾は，AUTOSARの知的財産権を許諾するもので
$  はない．AUTOSARは，AUTOSAR仕様に基づいたソフトウェアを商用目的で利
$  用する者に対して，AUTOSARパートナーになることを求めている．
$
$  本ソフトウェアは，無保証で提供されているものである．上記著作権者お
$  よびTOPPERSプロジェクトは，本ソフトウェアに関して，特定の使用目的
$  に対する適合性も含めて，いかなる保証も行わない．また，本ソフトウェ
$  アの利用により直接的または間接的に生じたいかなる損害に関しても，そ
$  の責任を負わない．
$
$  $Id: kernel_check.tf 1801 2015-03-27 06:34:43Z t_ishikawa $
$

$INCLUDE "cfg2_out.tf"$

$
$  関数の先頭番地のチェック
$
$IF CHECK_FUNC_ALIGN || CHECK_FUNC_NONNULL$
$	// タスクの先頭番地のアラインチェック
	$tinib = SYMBOL("tinib_table")$
	$FOREACH tskid TSK.ID_LIST$
		$task = PEEK(tinib + offsetof_TINIB_task, sizeof_FunctionRefType)$
		$IF CHECK_FUNC_ALIGN && (task & (CHECK_FUNC_ALIGN - 1)) != 0$
			$ERROR TSK.TEXT_LINE[tskid]$$FORMAT(_("%1% of %2% `%3%\' is not aligned"), "task", "TINIB", tskid)$$END$
		$END$
$		// タスクの先頭番地のNULLチェック
		$IF CHECK_FUNC_NONNULL && task == 0$
			$ERROR TSK.TEXT_LINE[tskid]$$FORMAT(_("%1% of %2% `%3%\' is null"),	"task", "TINIB", tskid)$$END$
		$END$
		$tinib = tinib + sizeof_TINIB$
	$END$

$	// アラーム満了アクションの先頭番地のチェック
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

$	//ハードウェアカウンタの処理関数
	$HWCNTFUNC_VALID = { VALUE("init",0),VALUE("start",1),VALUE("stop",2),VALUE("set",3),VALUE("get",4),
	VALUE("cancel",5),VALUE("trigger",6),VALUE("intclear",7),VALUE("intcancel",8),VALUE("increment",9) }$

$	// ハードウェアカウンタの処理関数のアラインチェック
	$hwcntinib = SYMBOL("hwcntinib_table")$
	$FOREACH hwcntid HWCNT.ID_LIST$
		$FOREACH memberid HWCNTFUNC_VALID$
			$offsetofmember = offsetof_HWCNTINIB_init + (sizeof_FunctionRefType * memberid)$
			$hwfunc = PEEK(hwcntinib + offsetofmember, sizeof_FunctionRefType)$
			$IF CHECK_FUNC_ALIGN && (hwfunc & (CHECK_FUNC_ALIGN - 1)) != 0$
				$ERROR HWCNT.TEXT_LINE[hwcntid]$$FORMAT(_("%1% of %2% in `%3%\' is not aligned"), memberid, "HWCNTINIB", hwcntid)$$END$
			$END$
$			// ハードウェアカウンタの処理関数のNULLチェック
			$IF CHECK_FUNC_NONNULL && hwfunc == 0$
				$ERROR HWCNT.TEXT_LINE[hwcntid]$$FORMAT(_("%1% of %2% in `%3%\' is null"), memberid, "HWCNTINIB", hwcntid)$$END$
			$END$
		$END$
		$hwcntinib = hwcntinib + sizeof_HWCNTINIB$
	$END$
$END$

$
$  スタック領域の先頭番地のチェック
$
$IF CHECK_STACK_ALIGN || CHECK_STACK_NONNULL$
$	// タスクのスタック領域の先頭番地のチェック
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

$	// 非タスクコンテキスト用のスタック領域の先頭番地のチェック
	$ostk_addr = PEEK(SYMBOL("_ostk"), sizeof_void_ptr)$
	$IF CHECK_STACK_ALIGN && (ostk_addr & (CHECK_STACK_ALIGN - 1)) != 0$
		$ERROR OSTK.TEXT_LINE[1]$$FORMAT(_("%1% `%2%\' is not aligned"), "stk", OSTK.STK[1])$$END$
	$END$
	$IF CHECK_STACK_NONNULL && ostk_addr == 0$
		$ERROR OSTK.TEXT_LINE[1]$$FORMAT(_("%1% `%2%\' is null"), "stk", OSTK.STK[1])$$END$
	$END$
$END$
