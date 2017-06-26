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
 *  $Id: nios2_system.h 1801 2015-03-27 06:34:43Z t_ishikawa $
 */

/*
 *		Nios2システムの定義
 *
 *  ペリフェラルのアドレスや割込み番号を定義する
 */

#ifndef TOPPERS_NIOS2_SYSTEM_H
#define TOPPERS_NIOS2_SYSTEM_H

#ifdef TOPPERS_NIOS2_DEV_2S180

/*
 *  NIOS2_DEV_2S180 用の定義
 */

/*
 *  起動メッセージのターゲットシステム名
 */
#define TARGET_NAME	"NIOS2_DEV_2S180(NIOS2)"

/*
 *  タイマ値の内部表現とミリ秒単位との変換
 */
#define TIMER_CLOCK		UINT_C(50000)

/*
 *  キャッシュサイズ
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
 *  システムバージョンレジスタのベースアドレス
 */
#define SYSVER_BASE				UINT_C(0x0f000000)

/*
 *  システムバージョン参照値
 */
#define TNUM_HWCORE				UINT_C(1)           /* コア数 */
#define MAJOR_VAR				UINT_C(5)           /* メジャーバージョン */

/*
 *  ベクタ割込みコントローラ
 */
#define VIC_BASE				UINT_C(0x01000c00)  /* ベースアドレス */
#define VIC_INT_NUM				UINT_C(32)

#elif defined(TOPPERS_NIOS2_DEV_DE2_115)

/*
 *  NIOS2_DEV_DE2_115 用の定義
 */

/*
 *  起動メッセージのターゲットシステム名
 */
#define TARGET_NAME	"NIOS2_DEV_DE2_115(NIOS2)"

/*
 *  タイマ値の内部表現とミリ秒単位との変換
 */
#define TIMER_CLOCK		UINT_C(60000)

/*
 *  キャッシュサイズ
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
 *  システムバージョンレジスタのベースアドレス
 */
#define SYSVER_BASE				UINT_C(0x080001c0)

/*
 *  システムバージョン参照値
 */
#define TNUM_HWCORE				UINT_C(1)           /* コア数 */
#define MAJOR_VAR				UINT_C(7)           /* メジャーバージョン */

/*
 *  ベクタ割込みコントローラ
 */
#define VIC_BASE				UINT_C(0x0f000000)  /* ベースアドレス */
#define VIC_INT_NUM				UINT_C(32)

#endif /* TOPPERS_NIOS2_DEV_DE2_115 */

/*
 *  システムバージョンレジスタ(sysver)
 */
#define SYSVER_MAJOR_VAR	(SYSVER_BASE + 0x00U)
#define SYSVER_MINOR_VAR	(SYSVER_BASE + 0x04U)
#define SYSVER_NUM_CORE		(SYSVER_BASE + 0x08U)

#endif /* TOPPERS_NIOS2_SYSTEM_H */
