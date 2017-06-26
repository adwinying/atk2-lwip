#ifndef _TINET_TARGET_CONFIG_H_
#define _TINET_TARGET_CONFIG_H_

/*
 *  TCP/IP に関する定義
 */

/* TCP に関する定義 */

/*
 *  MAX_TCP_SND_SEG: 送信セグメントサイズの最大値
 *
 *    相手から MSS オプションでセグメントサイズを指定されても、
 *    この値で、セグメントサイズを制限できる。
 */

#ifndef MAX_TCP_SND_SEG
#define MAX_TCP_SND_SEG		(IF_MTU - (IP_HDR_SIZE + TCP_HDR_SIZE))
#endif	/* of #ifndef MAX_TCP_SND_SEG */

/*
 *  DEF_TCP_RCV_SEG: 受信セグメントサイズの規定値
 */

#ifndef DEF_TCP_RCV_SEG
#define DEF_TCP_RCV_SEG		(IF_MTU - (IP_HDR_SIZE + TCP_HDR_SIZE))
#endif	/* of #ifndef DEF_TCP_RCV_SEG */

/*
 *  セグメントの順番を入れ替えるときに新たにネットワークバッファを割当てて、
 *  データをコピーするサイズのしきい値
 */
#define MAX_TCP_REALLOC_SIZE	1024

#define TCP_CFG_OPT_MSS		/* コネクション開設時に、セグメントサイズオプションをつけて送信する。*/
#define TCP_CFG_DELAY_ACK	/* ACK を遅らせるときはコメントを外す。			*/
#define TCP_CFG_ALWAYS_KEEP	/* 常にキープアライブする時はコメントを外す。		*/

/* UDP に関する定義 */

#define UDP_CFG_IN_CHECKSUM	/* UDP の入力チェックサムを行う場合はコメントを外す。	*/
#define UDP_CFG_OUT_CHECKSUM	/* UDP の出力チェックサムを行う場合はコメントを外す。	*/

/* ICMPv4/v6 に関する定義 */

#define ICMP_REPLY_ERROR		/* ICMP エラーメッセージを送信する場合はコメントを外す。*/

/* IPv4 に関する定義 */

#define IP4_CFG_FRAGMENT		/* データグラムの分割・再構成行う場合はコメントを外す。	*/
#define NUM_IP4_FRAG_QUEUE	2	/* データグラム再構成キューサイズ			*/
#define IP4_CFG_FRAG_REASSM_SIZE	4096	/* IPv4 再構成バッファサイズ			*/

/* IPv6 に関する定義 */

#define NUM_IP6_DAD_COUNT	1	/* 重複アドレス検出で送信する近隣要請の回数、		*/
					/*  0 を指定すると、重複アドレス検出を行わない。	*/
#define NUM_ND6_CACHE_ENTRY	10	/* 近隣キャッシュのエントリ数				*/

/*
 *  IPv6 用ホストキャッシュのエントリ数。
 *  0 を指定するとIPv6 用ホストキャッシュを組込まない。
 */
#define NUM_IN6_HOSTCACHE_ENTRY	4

#ifdef SUPPORT_ETHER

#define IP6_CFG_AUTO_LINKLOCAL		/* リンクローカルアドレスの自動設定を行う場合はコメントを外す。*/

/*
 *  ディフォルトルータリストに関する定義
 */

/*
 *  ディフォルトルータリストのエントリ数。
 *  最大値は 16、0 を指定するとルータ通知を受信しない。
 */
#define NUM_ND6_DEF_RTR_ENTRY		4

/*
 *  プレフィックスリストに関する定義。
 *  最大値は 16。
 */
#define NUM_ND6_PREFIX_ENTRY		4	/*  プレフィックスリストのエントリ数			*/

/*
 *  起動時のルータ要請出力回数。
 *  0 を指定するとルータ要請を出力しない。
 */
#define NUM_ND6_RTR_SOL_RETRY	3

#define IP6_CFG_FRAGMENT		/* データグラムの分割・再構成行う場合はコメントを外す。	*/
#define NUM_IP6_FRAG_QUEUE	2	/* データグラム再構成キューサイズ			*/
#define IP6_CFG_FRAG_REASSM_SIZE	4096	/* IPv6 再構成バッファサイズ			*/

#endif	/* of #ifdef SUPPORT_ETHER */

/*
 *  データリンク層 (ネットワークインタフェース) に関する定義
 */

/*
 *  PPP、モデムに関する定義
 */

#define MODEM_CFG_DIAL		"ATD"	/* ダイアルコマンド文字列		*/
#define MODEM_CFG_RETRY_CNT	3	/* ダイアルリトライ回数			*/
#define MODEM_CFG_RETRY_WAIT	10000	/* ダイアルリトライまでの待ち時間 [ms]	*/

/*
 *  PPP、HDLC に関する定義
 */

#define DEF_LOCAL_ACCM		ULONG_C(0x000a0000)	/* 自分の ACCM、XON と XOFF のみ変換	*/
#define DEF_REMOTE_ACCM		ULONG_C(0xffffffff)	/* 相手の ACCM、初期値は全て変換	*/

/*
 *  PPP、LCP に関する定義
 */

#define LCP_CFG_MRU		UINT_C(0x0001)	/* MRU					*/
#define LCP_CFG_ACCM		UINT_C(0x0002)	/* ACCM					*/
#define LCP_CFG_MAGIC		UINT_C(0x0004)	/* マジック番号				*/
#define LCP_CFG_PCOMP		UINT_C(0x0008)	/* プロトコル部圧縮機能			*/
#define LCP_CFG_ACCOMP		UINT_C(0x0010)	/* アドレス・制御部圧縮			*/
#define LCP_CFG_PAP		UINT_C(0x0020)	/* PAP					*/
/*#define LCP_CFG_CHAP		UINT_C(0x0040)	   CHAP は実装予定			*/

#ifdef LCP_CFG_MAGIC

#define LCP_ECHO_INTERVAL	(20*NET_TIMER_HZ)	/* インターバル時間		*/
#define LCP_ECHO_FAILS		9			/* 失敗閾値			*/

#endif	/* of #ifdef LCP_CFG_MAGIC */

/*
 *  PPP、PAP に関する定義
 */

#define DEF_PAP_TIMEOUT		(3*NET_TIMER_HZ)
#define DEF_PAP_REQTIME		(30*NET_TIMER_HZ)	/* タイムアウト処理を行うときはコメントを外す。*/
#define MAX_PAP_REXMT		10			/* 認証要求の最大再送回数	*/

/*
 *  NIC に関する定義
 */

#define TMO_IF_TSE_GET_NET_BUF	1	/* [ms]、受信用 net_buf 獲得タイムアウト	*/
					/* [s]、 送信タイムアウト			*/
#define TMO_IF_TSE_XMIT		(2*IF_TIMER_HZ)

/*
 *  イーサネット出力時に、NIC で net_buf を開放する場合に指定する。
 */

#define ETHER_NIC_CFG_RELEASE_NET_BUF

/*
 *  NIC に関する定義
 */

#define TSE_BASE		UINT_C(0x02000800)	/* TSE のベースアドレス			*/
#define SGDMA_RX_BASE		UINT_C(0x02000c40)	/* 受信 SGDMA のベースアドレス		*/
#define SGDMA_TX_BASE		UINT_C(0x02000c00)	/* 送信 SGDMA のベースアドレス		*/
#define DESCRIPTOR_MEMORY_BASE	UINT_C(0x02001000)	/* ディスクリプタメモリのベースアドレス	*/

#define INTNO_IF_TSE_RX		UINT_C(12)		/* 受信 SGDMA の割込み番号		*/
#define INTNO_IF_TSE_TX		UINT_C(13)		/* 送信 SGDMA の割込み番号		*/
#define INTPRI_IF_TSE		3			/* 割込み優先度				*/

/*
 *  ARP に関する定義
 */

#define NUM_ARP_ENTRY		10			/* ARP キャッシュエントリ数	*/

/*
 *  DHCP に関する定義
 *
 *    ・注意: TINET は、DHCP を実装していない。応用プログラムで、
 *            DHCP メッセージを受信するための定義である。
 *            また、現在は IPv4 のみ有効である。
 */

/*#define DHCP_CFG					 DHCP を処理する場合はコメントを外す。*/

/*
 *  Ethernet に関する定義
 */

/*#define ETHER_CFG_ACCEPT_ALL		 マルチキャスト、エラーフレームも受信するときはコメントを外す。	*/
/*#define ETHER_CFG_UNEXP_WARNING	 非サポートフレームの警告を表示するときはコメントを外す。	*/
/*#define ETHER_CFG_802_WARNING		 IEEE 802.3 フレームの警告を表示するときはコメントを外す。	*/
/*#define ETHER_CFG_MCAST_WARNING	 マルチキャストの警告を表示するときはコメントを外す。		*/

/*
 *  アドレスリストに関する定義。
 */
#define NUM_IN6_IFADDR_ENTRY		5	/*  インタフェースのアドレスリストのエントリ数		*/

/*
 *  汎用ネットワークに関する定義
 */

/*
 *  ネットワークバッファに関する定義
 */

/* ネットワークバッファ数 */

#ifdef SUPPORT_PPP

/*
 *  PPP では、受信用の ネットワークバッファは PDU (1502) サイズを常に
 *  割り当てなければならないので PDU サイズを多めに確保する。
 */

#ifndef NUM_MPF_NET_BUF_CSEG
#define NUM_MPF_NET_BUF_CSEG	2	/* IF + IP + TCP、2 以上*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_CSEG */

#ifndef NUM_MPF_NET_BUF_64
#define NUM_MPF_NET_BUF_64	0	/* 64 オクテット	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_64 */

#ifndef NUM_MPF_NET_BUF_128
#define NUM_MPF_NET_BUF_128	0	/* 128 オクテット	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_128 */

#ifndef NUM_MPF_NET_BUF_256
#define NUM_MPF_NET_BUF_256	0	/* 256 オクテット	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_256 */

#ifndef NUM_MPF_NET_BUF_512
#define NUM_MPF_NET_BUF_512	0	/* 512 オクテット	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_512 */

#ifndef NUM_MPF_NET_BUF_1024
#define NUM_MPF_NET_BUF_1024	0	/* 1024 オクテット	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_1024 */

#ifndef NUM_MPF_NET_BUF_IF_PDU
#define NUM_MPF_NET_BUF_IF_PDU	2	/* IF 最大 PDU サイズ	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_IF_PDU */

#ifndef NUM_MPF_NET_BUF4_REASSM

#if defined(SUPPORT_INET4) && defined(IP4_CFG_FRAGMENT)
#define NUM_MPF_NET_BUF4_REASSM	2	/* IPv4 再構成バッファサイズ	*/
#else
#define NUM_MPF_NET_BUF4_REASSM	0	/* IPv4 再構成バッファサイズ	*/
#endif

#endif	/* of #ifndef NUM_MPF_NET_BUF4_REASSM */

#ifndef NUM_MPF_NET_BUF6_REASSM

#if defined(SUPPORT_INET6) && defined(IP6_CFG_FRAGMENT)
#define NUM_MPF_NET_BUF6_REASSM	2	/* IPv6 再構成バッファサイズ	*/
#else
#define NUM_MPF_NET_BUF6_REASSM	0	/* IPv6 再構成バッファサイズ	*/
#endif

#endif	/* of #ifndef NUM_MPF_NET_BUF6_REASSM */

#endif	/* of #ifdef SUPPORT_PPP */

#ifdef SUPPORT_ETHER

/*
 *  イーサネットの場合のネットワークバッファ数の割り当て
 */

/*
 *  注意!!
 *
 *  NE2000 互換 NIC のディバイスドライバ（if_ed）の最低割当て長は
 *  60（アラインして 62）オクテットのため IF + IP +TCP よりは
 *  64 オクテットのネットワークバッファの方が最適である。
 */

#ifndef NUM_MPF_NET_BUF_CSEG
#define NUM_MPF_NET_BUF_CSEG	0	/* IF + IP + TCP	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_CSEG */

#ifndef NUM_MPF_NET_BUF_64
#define NUM_MPF_NET_BUF_64	2	/* 64 オクテット	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_64 */

#ifndef NUM_MPF_NET_BUF_128
#define NUM_MPF_NET_BUF_128	0	/* 128 オクテット	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_128 */

#ifndef NUM_MPF_NET_BUF_256
#define NUM_MPF_NET_BUF_256	0	/* 256 オクテット	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_256 */

#ifndef NUM_MPF_NET_BUF_512
#define NUM_MPF_NET_BUF_512	0	/* 512 オクテット	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_512 */

#if defined(SUPPORT_INET4)

#ifndef NUM_MPF_NET_BUF_IP_MSS
#define NUM_MPF_NET_BUF_IP_MSS	0	/* IF + 576 オクテット	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_IP_MSS */

#endif	/* of #if defined(SUPPORT_INET4) */

#ifndef NUM_MPF_NET_BUF_1024
#define NUM_MPF_NET_BUF_1024	0	/* 1024 オクテット	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_1024 */

#if defined(SUPPORT_INET6)

#ifndef NUM_MPF_NET_BUF_IPV6_MMTU
#define NUM_MPF_NET_BUF_IPV6_MMTU	0	/* IF + 1280	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_IPV6_MMTU */

#endif	/* of #if defined(SUPPORT_INET6) */

#ifndef NUM_MPF_NET_BUF_IF_PDU
#define NUM_MPF_NET_BUF_IF_PDU	4	/* IF 最大 PDU サイズ	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_IF_PDU */

#ifndef NUM_MPF_NET_BUF4_REASSM

#if defined(SUPPORT_INET4) && defined(IP4_CFG_FRAGMENT)
#define NUM_MPF_NET_BUF4_REASSM	2	/* IPv4 再構成バッファサイズ	*/
#else
#define NUM_MPF_NET_BUF4_REASSM	0	/* IPv4 再構成バッファサイズ	*/
#endif

#endif	/* of #ifndef NUM_MPF_NET_BUF4_REASSM */

#ifndef NUM_MPF_NET_BUF6_REASSM

#if defined(SUPPORT_INET6) && defined(IP6_CFG_FRAGMENT)
#define NUM_MPF_NET_BUF6_REASSM	2	/* IPv6 再構成バッファサイズ	*/
#else
#define NUM_MPF_NET_BUF6_REASSM	0	/* IPv6 再構成バッファサイズ	*/
#endif

#endif	/* of #ifndef NUM_MPF_NET_BUF6_REASSM */

#endif	/* of #ifdef SUPPORT_ETHER */

#ifdef SUPPORT_LOOP

#ifndef NUM_MPF_NET_BUF_CSEG
#define NUM_MPF_NET_BUF_CSEG	2	/* IF + IP + TCP	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_CSEG */

#ifndef NUM_MPF_NET_BUF_64
#define NUM_MPF_NET_BUF_64	0	/* 64 オクテット	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_64 */

#ifndef NUM_MPF_NET_BUF_128
#define NUM_MPF_NET_BUF_128	0	/* 128 オクテット、2 以上	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_128 */

#ifndef NUM_MPF_NET_BUF_256
#define NUM_MPF_NET_BUF_256	0	/* 256 オクテット	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_256 */

#ifndef NUM_MPF_NET_BUF_512
#define NUM_MPF_NET_BUF_512	0	/* 512 オクテット	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_512 */

#ifndef NUM_MPF_NET_BUF_1024
#define NUM_MPF_NET_BUF_1024	0	/* 1024 オクテット	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_1024 */

#ifndef NUM_MPF_NET_BUF_IF_PDU
#define NUM_MPF_NET_BUF_IF_PDU	4	/* IF 最大 PDU サイズ	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_IF_PDU */

#endif	/* of #ifdef SUPPORT_LOOP */

/*
 *  ネットワーク統計情報の計測
 *
 *  ネットワーク統計情報の計測を行う場合は、tinet/include/net/net.h
 *  で定義されているプロトコル識別フラグを指定する。
 */

#if 1

#ifdef SUPPORT_INET4

#define NET_COUNT_ENABLE	(0			\
				| PROTO_FLG_PPP_HDLC	\
				| PROTO_FLG_PPP_PAP	\
				| PROTO_FLG_PPP_LCP	\
				| PROTO_FLG_PPP_IPCP	\
				| PROTO_FLG_PPP		\
				| PROTO_FLG_LOOP	\
				| PROTO_FLG_ETHER_NIC	\
				| PROTO_FLG_ETHER	\
				| PROTO_FLG_ARP		\
				| PROTO_FLG_IP4		\
				| PROTO_FLG_ICMP4	\
				| PROTO_FLG_UDP		\
				| PROTO_FLG_TCP		\
				| PROTO_FLG_NET_BUF	\
				)

#endif	/* of #ifdef SUPPORT_INET4 */

#ifdef SUPPORT_INET6

#define NET_COUNT_ENABLE	(0			\
				| PROTO_FLG_PPP_HDLC	\
				| PROTO_FLG_PPP_PAP	\
				| PROTO_FLG_PPP_LCP	\
				| PROTO_FLG_PPP_IPCP	\
				| PROTO_FLG_PPP		\
				| PROTO_FLG_LOOP	\
				| PROTO_FLG_ETHER_NIC	\
				| PROTO_FLG_ETHER	\
				| PROTO_FLG_IP6		\
				| PROTO_FLG_ICMP6	\
				| PROTO_FLG_ND6		\
				| PROTO_FLG_UDP		\
				| PROTO_FLG_TCP		\
				| PROTO_FLG_NET_BUF	\
				)

#endif	/* of #ifdef SUPPORT_INET6 */

#else	/* of #if 0 */

#define NET_COUNT_ENABLE	(0			\
				)

#endif	/* of #if 0 */

#endif /* _TINET_TARGET_CONFIG_H_ */
