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
 *  上記著作権者は，以下の(1)〜(4)の条件を満たす場合に限り，本ソフトウェ
 *  ア（本ソフトウェアを改変したものを含む．以下同じ）を使用・複製・改
 *  変・再配布（以下，利用と呼ぶ）することを無償で許諾する．
 *  (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
 *      権表示，この利用条件および下記の無保証規定が，そのままの形でソー
 *      スコード中に含まれていること．
 *  (2) 本ソフトウェアを，ライブラリ形式など，他のソフトウェア開発に使
 *      用できる形で再配布する場合には，再配布に伴うドキュメント（利用
 *      者マニュアルなど）に，上記の著作権表示，この利用条件および下記
 *      の無保証規定を掲載すること．
 *  (3) 本ソフトウェアを，機器に組み込むなど，他のソフトウェア開発に使
 *      用できない形で再配布する場合には，次のいずれかの条件を満たすこ
 *      と．
 *    (a) 再配布に伴うドキュメント（利用者マニュアルなど）に，上記の著
 *        作権表示，この利用条件および下記の無保証規定を掲載すること．
 *    (b) 再配布の形態を，別に定める方法によって，TOPPERSプロジェクトに
 *        報告すること．
 *  (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
 *      害からも，上記著作権者およびTOPPERSプロジェクトを免責すること．
 *      また，本ソフトウェアのユーザまたはエンドユーザからのいかなる理
 *      由に基づく請求からも，上記著作権者およびTOPPERSプロジェクトを
 *      免責すること．
 *
 *  本ソフトウェアは，AUTOSAR（AUTomotive Open System ARchitecture）仕
 *  様に基づいている．上記の許諾は，AUTOSARの知的財産権を許諾するもので
 *  はない．AUTOSARは，AUTOSAR仕様に基づいたソフトウェアを商用目的で利
 *  用する者に対して，AUTOSARパートナーになることを求めている．
 *
 *  本ソフトウェアは，無保証で提供されているものである．上記著作権者お
 *  よびTOPPERSプロジェクトは，本ソフトウェアに関して，特定の使用目的
 *  に対する適合性も含めて，いかなる保証も行わない．また，本ソフトウェ
 *  アの利用により直接的または間接的に生じたいかなる損害に関しても，そ
 *  の責任を負わない．
 *
 *  $Id: prc_config.h 1801 2015-03-27 06:34:43Z t_ishikawa $
 */

/*
 *		プロセッサ依存モジュール（Nios2用）
 *
 *  このインクルードファイルは，target_config.h（または，そこからインク
 *  ルードされるファイル）のみからインクルードされる．他のファイルから
 *  直接インクルードしてはならない
 */

#ifndef TOPPERS_PRC_CONFIG_H
#define TOPPERS_PRC_CONFIG_H

#include "nios2.h"
#include "vic.h"

/*
 *  エラーチェック方法の指定
 */
#define CHECK_STKSZ_ALIGN	4   /* スタックサイズのアライン単位 */
#define CHECK_FUNC_ALIGN	4   /* 関数のアライン単位 */
#define CHECK_FUNC_NONNULL      /* 関数の非NULLチェック */
#define CHECK_STACK_ALIGN	4   /* スタック領域のアライン単位 */
#define CHECK_STACK_NONNULL     /* スタック領域の非NULLチェック */

/*
 *	アセンブラのメモリ配置設定
 */
#ifndef FUNCTION_ALIGN_SIZE
#define FUNCTION_ALIGN_SIZE	4
#endif /* FUNCTION_ALIGN_SIZE */

/*
 *  割込み番号に関する定義
 */
#define TMIN_INTNO	UINT_C(0)
#define TMAX_INTNO	UINT_C(31)
#define TNUM_INT	UINT_C(32)

#define call_errorhook(ercd, svcid)		stack_change_and_call_func_2((void *) &internal_call_errorhook, (ercd), (svcid))
#define call_shutdownhook(ercd)			stack_change_and_call_func_1((void *) &internal_call_shtdwnhk, ((uint32) (ercd)))

/*
 * 割込み番号から，IRC操作のためのビットパターンを求めるマクロ
 */
#define INTNO_BITPAT(intno)	((uint32) 1 << (intno))

/*
 *  割込み番号の範囲の判定
 */
#define VALID_INTNO(intno)	(((InterruptNumberType) (TMIN_INTNO) <= (intno)) && ((intno) <= (InterruptNumberType) (TMAX_INTNO)))

#ifndef TOPPERS_MACRO_ONLY

/*
 *  非タスクコンテキスト用のスタック開始アドレス設定マクロ
 */
#define TOPPERS_OSTKPT(stk, stksz)	((StackType *) ((sint8 *) (stk) + (stksz)))

/*
 *  プロセッサの特殊命令のインライン関数定義
 */
#include "prc_insn.h"

/*
 *  TOPPERS標準割込み処理モデルの実現
 */

/*
 * 例外（割込み/CPU例外）のネスト回数のカウント
 *
 * コンテキスト参照のために使用
 */
extern uint32		except_nest_cnt;

/*
 * OS割込み禁止時のstatus.ILへの設定値
 */
extern const uint32	tmin_status_il;

/*
 *  割込み処理モデルの実現
 */

/*
 *  割込み優先度マスクの非依存部表現(外部表現)とNios2依存部表現(内部表現)の変換
 */
#define EXT_IPM(iipm)	(-((PriorityType) (iipm)))              /* 内部表現を外部表現に */
#define INT_IPM(ipm)	((uint32) ((PriorityType) (-(ipm))))    /* 外部表現を内部表現に */

/*
 *  全割込み禁止状態への移行
 */
LOCAL_INLINE void
x_lock_all_int(void)
{
	set_status(current_status() & (~STATUS_PIE));
	/* クリティカルセクションの前後でメモリが書き換わる可能性がある */
	Asm("" ::: "memory");
}

/*
 *  全割込み禁止状態の解除
 */
LOCAL_INLINE void
x_unlock_all_int(void)
{
	/* クリティカルセクションの前後でメモリが書き換わる可能性がある */
	Asm("" ::: "memory");
	set_status(current_status() | STATUS_PIE);
}

/*
 *  OS割込み禁止状態の時に割込み優先度マスクを保存する変数
 */
extern volatile uint32	saved_status_il;

/*
 *  x_nested_lock_os_int()のネスト回数
 *  アクセスの順序が変化しないよう，volatile を指定
 */
extern volatile uint8	nested_lock_os_int_cnt;

/*
 *  OS割込み禁止
 *  API実行時に呼び出される
 *  割込み優先度マスクがC2ISRの優先度マスクの範囲より高い状態で呼び出される
 *  ことはない(C1ISRから呼び出されることはない)
 *  リソース取得時はstatus.ILが0より大きい状態で呼び出されるためロック前の
 *  status.ILの値をsaved_status_ilに保存する
 */
LOCAL_INLINE void
x_nested_lock_os_int(void)
{
	uint32 status;

	/*
	 *  一段目ならstatus.ILをOS割込みの禁止レベルに設定割込み優先度マスクの値を保存
	 */
	if (nested_lock_os_int_cnt == 0U) {
		status = current_status();
		set_status((status & (~STATUS_IL)) | tmin_status_il);
		saved_status_il = status & STATUS_IL;
	}
	nested_lock_os_int_cnt++;

	Asm("" ::: "memory");
}

/*
 *  OS割込み解除
 *  API実行時に呼び出される
 *  割込み優先度マスクがC2ISRの優先度マスクの範囲より高い状態で呼び出される
 *  ことはない(C1ISRから呼び出されることはない)
 */
LOCAL_INLINE void
x_nested_unlock_os_int(void)
{
	Asm("" ::: "memory");

	ASSERT(nested_lock_os_int_cnt > 0U);

	nested_lock_os_int_cnt--;

	/*
	 *  一番外側なら割込み優先度マスクを更新
	 */
	if (nested_lock_os_int_cnt == 0U) {
		set_status((uint32) ((current_status() & (~STATUS_IL)) | saved_status_il));
	}
}

/*
 *  SuspendOSInterrupts()から呼び出すOS割込み禁止状態への移行
 *  x_nested_lock_os_int()との違いは，C1ISRから呼び出される可能性があるため，
 *  status.ILがOS割込み禁止時の値より大きい場合はC1ISRから呼び出されたとして，
 *  何もせずリターンする
 */
LOCAL_INLINE void
x_suspend_lock_os_int(void)
{
	uint32	status;
	uint32	status_il;

	status = current_status();
	status_il = status & STATUS_IL;

	/*
	 *  C1ISRから呼ばれた場合は何もしない
	 */
	if (status_il <= tmin_status_il) {

		/*
		 *  一段目ならstatus.ILをOS割込みの禁止レベルに設定割込み優先度マスクの値を保存
		 */
		if (nested_lock_os_int_cnt == 0U) {
			set_status((status & (~STATUS_IL)) | tmin_status_il);
			saved_status_il = status_il;
		}
		nested_lock_os_int_cnt++;

		Asm("" ::: "memory");
	}
}

/*
 *  ResumeOSInterrupts()から呼び出すOS割込み禁止状態の解除
 *  x_nested_unlock_os_int()との違いは，C1ISRから呼び出される可能性があるため，
 *  status.ILがOS割込み禁止時の値より大きい場合はC1ISRから呼び出されたとして，
 *  何もせずリターンする
 */
LOCAL_INLINE void
x_resume_unlock_os_int(void)
{
	uint32	status;
	uint32	status_il;

	Asm("" ::: "memory");

	status = current_status();
	status_il = status & STATUS_IL;

	/*
	 * C1ISRから呼ばれた場合は何もしない
	 */
	if (status_il <= tmin_status_il) {
		ASSERT(nested_lock_os_int_cnt > 0U);
		nested_lock_os_int_cnt--;

		/*
		 *  一番外側なら割込み優先度マスクを更新
		 */
		if (nested_lock_os_int_cnt == 0U) {
			set_status((status & (~STATUS_IL)) | saved_status_il);
		}
	}
}


/*
 *  (モデル上の)割込み優先度マスクの設定
 *
 *  本OSでは次の二点が成り立つ
 *    * OS割込み禁止状態で呼び出される
 *    * OS割込み禁止時の優先度より高い値は指定されない
 */
LOCAL_INLINE void
x_set_ipm(PriorityType intpri)
{
	ASSERT(nested_lock_os_int_cnt > 0U);
	saved_status_il = (INT_IPM(intpri) << STATUS_IL_OFFSET);
}

/*
 *  (モデル上の)割込み優先度マスクの参照
 *
 *  本OSでは次の点が成り立つ
 *    * OS割込み禁止状態で呼び出される
 */
LOCAL_INLINE PriorityType
x_get_ipm(void)
{
	ASSERT(nested_lock_os_int_cnt > 0U);
	return(EXT_IPM((saved_status_il >> STATUS_IL_OFFSET)));
}

/*
 *  割込み要求ラインの属性の設定
 */
extern void x_config_int(InterruptNumberType intno, AttributeType intatr, PriorityType intpri);

/*
 *  割込みハンドラの入り口で必要なIRC操作
 */
LOCAL_INLINE void
i_begin_int(InterruptNumberType intno)
{

}

/*
 *  割込みハンドラの出口で必要なIRC操作
 */
LOCAL_INLINE void
i_end_int(InterruptNumberType intno)
{

}

/*
 *  未定義の割込みが入った場合の処理
 */
extern void default_int_handler(void);

extern void prc_hardware_initialize(void);

/*
 *  プロセッサ依存の初期化
 */
extern void prc_initialize(void);

/*
 *  プロセッサ依存の終了時処理
 */
extern void prc_terminate(void);

/*
 *  タスクディスパッチャ
 */

/*
 *  最高優先順位タスクへのディスパッチ（prc_support.S）
 *
 *  dispatch は，タスクコンテキストから呼び出されたサービスコール処理
 *  内で，OS割込み禁止状態で呼び出さなければならない
 */
extern void dispatch(void);

/*
 *  ディスパッチャの動作開始（prc_support.S）
 *
 *  start_dispatchは，カーネル起動時に呼び出すべきもので，すべての割込
 *  みを禁止した状態（全割込み禁止状態と同等の状態）で呼び出さなければ
 *  ならない
 */
extern void start_dispatch(void) NoReturn;

/*
 *  現在のコンテキストを捨ててディスパッチ（prc_support.S）
 *
 *  exit_and_dispatch は，OS割込み禁止状態で呼び出さなければならない
 */
extern void exit_and_dispatch(void) NoReturn;

/*
 *  タスクコンテキストブロックの定義
 */
typedef struct task_context_block {
	void			*sp;        /* スタックポインタ */
	FunctionRefType	pc;         /* プログラムカウンタ */
} TSKCTXB;

/*
 *  タスクコンテキストの初期化
 *
 *  タスクが休止状態から実行できる状態に移行する時に呼ばれる．この時点
 *  でスタック領域を使ってはならない
 *
 *  activate_contextを，インライン関数ではなくマクロ定義としているのは，
 *  この時点ではTCBが定義されていないためである
 */
extern void start_r(void);

#define activate_context(p_tcb) do {									  \
		(p_tcb)->tskctxb.sp = (void *) ((char8 *) ((p_tcb)->p_tinib->stk) \
										+ (p_tcb)->p_tinib->stksz);		  \
		(p_tcb)->tskctxb.pc = (FunctionRefType) &start_r;				  \
} while (0)

/* 引数の型はハードウェアが扱えるサイズ（uint32）と同サイズを使用 */
extern void stack_change_and_call_func_1(void *func, uint32 arg1);

extern void stack_change_and_call_func_2(void *func, uint8 arg1, uint8 arg2);

#endif /* TOPPERS_MACRO_ONLY */

#endif /* TOPPERS_PRC_CONFIG_H_ */
