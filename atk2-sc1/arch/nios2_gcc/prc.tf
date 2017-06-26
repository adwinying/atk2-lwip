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
$  $Id: prc.tf 1801 2015-03-27 06:34:43Z t_ishikawa $
$

$
$     パス2のアーキテクチャ依存テンプレート（Nios2用）
$

$
$  有効な割込み番号
$
$INTNO_VALID = { 0,1,...,31 }$

$
$ 割込み優先度の個数
$
$TNUM_INTPRI = 64$

$
$  CRE_ISR2で使用できる割込み番号
$
$INTNO_CREISR2_VALID = INTNO_VALID$

$FUNCTION EXTERN_INT_HANDLER$
$OUTPUT_LIST = {}$
$
$ 要因ごとの割込み入口処理
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
$  標準テンプレートファイルのインクルード
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
$ C2ISRの優先度下限
$
const uint32 tmin_status_il = ((uint32) INT_IPM($MIN_PRI_ISR2$) << STATUS_IL_OFFSET);$NL$
$NL$

$
$  割込みハンドラテーブル
$
const FunctionRefType isr_tbl[TNUM_INT] = {$NL$
$JOINEACH intno INTNO_VALID "\n"$
	$isrid = INT.ISRID[intno]$
	$IF LENGTH(isrid) && EQ(ISR.CATEGORY[isrid], "CATEGORY_2")$
		$TAB$&$ISR.INT_ENTRY[isrid]$
	$ELSE$
		$TAB$&default_int_handler
	$END$
$	//カンマの出力（最後の要素の後ろに出力しない）
	$IF intno != AT(INTNO_VALID,LENGTH(INTNO_VALID) - 1)$
		,
	$END$
	$TAB$$FORMAT("/* %d */", intno)$
$END$
$NL$};$NL$
$NL$

$
$  ISRCBの取得テーブル
$
ISRCB * const isr_p_isrcb_tbl[TNUM_INT] = {$NL$
$JOINEACH intno INTNO_VALID "\n"$
	$isrid = INT.ISRID[intno]$
	$IF LENGTH(isrid) && EQ(ISR.CATEGORY[isrid], "CATEGORY_2")$
		$TAB$&(isrcb_table[$ISR.ID[isrid]$])
	$ELSE$
		$TAB$NULL
	$END$
$	//カンマの出力（最後の要素の後ろに出力しない）
	$IF intno != AT(INTNO_VALID,LENGTH(INTNO_VALID) - 1)$
		,
	$END$
	$TAB$$FORMAT("/* %d */", intno)$
$END$
$NL$};$NL$
$NL$

$
$ 割込みベクタと各割込み入口処理
$

$
$ 要因ごとの割込み入口処理
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
$ ベクタテーブル
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

$		// 割込みハンドラの登録がない場合
		$TAB$Asm("jmpi default_int_handler");
	$END$
	$FORMAT(" /* %d */", intno)$$NL$
$END$
}$NL$
