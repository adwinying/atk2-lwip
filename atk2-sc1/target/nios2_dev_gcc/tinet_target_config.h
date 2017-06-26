#ifndef _TINET_TARGET_CONFIG_H_
#define _TINET_TARGET_CONFIG_H_

/*
 *  TCP/IP �˴ؤ������
 */

/* TCP �˴ؤ������ */

/*
 *  MAX_TCP_SND_SEG: �����������ȥ������κ�����
 *
 *    ��꤫�� MSS ���ץ����ǥ������ȥ���������ꤵ��Ƥ⡢
 *    �����ͤǡ��������ȥ����������¤Ǥ��롣
 */

#ifndef MAX_TCP_SND_SEG
#define MAX_TCP_SND_SEG		(IF_MTU - (IP_HDR_SIZE + TCP_HDR_SIZE))
#endif	/* of #ifndef MAX_TCP_SND_SEG */

/*
 *  DEF_TCP_RCV_SEG: �����������ȥ������ε�����
 */

#ifndef DEF_TCP_RCV_SEG
#define DEF_TCP_RCV_SEG		(IF_MTU - (IP_HDR_SIZE + TCP_HDR_SIZE))
#endif	/* of #ifndef DEF_TCP_RCV_SEG */

/*
 *  �������Ȥν��֤������ؤ���Ȥ��˿����˥ͥåȥ���Хåե�������Ƥơ�
 *  �ǡ����򥳥ԡ����륵�����Τ�������
 */
#define MAX_TCP_REALLOC_SIZE	1024

#define TCP_CFG_OPT_MSS		/* ���ͥ�������߻��ˡ��������ȥ��������ץ�����Ĥ����������롣*/
#define TCP_CFG_DELAY_ACK	/* ACK ���٤餻��Ȥ��ϥ����Ȥ򳰤���			*/
#define TCP_CFG_ALWAYS_KEEP	/* ��˥����ץ��饤�֤�����ϥ����Ȥ򳰤���		*/

/* UDP �˴ؤ������ */

#define UDP_CFG_IN_CHECKSUM	/* UDP �����ϥ����å������Ԥ����ϥ����Ȥ򳰤���	*/
#define UDP_CFG_OUT_CHECKSUM	/* UDP �ν��ϥ����å������Ԥ����ϥ����Ȥ򳰤���	*/

/* ICMPv4/v6 �˴ؤ������ */

#define ICMP_REPLY_ERROR		/* ICMP ���顼��å�����������������ϥ����Ȥ򳰤���*/

/* IPv4 �˴ؤ������ */

#define IP4_CFG_FRAGMENT		/* �ǡ���������ʬ�䡦�ƹ����Ԥ����ϥ����Ȥ򳰤���	*/
#define NUM_IP4_FRAG_QUEUE	2	/* �ǡ��������ƹ������塼������			*/
#define IP4_CFG_FRAG_REASSM_SIZE	4096	/* IPv4 �ƹ����Хåե�������			*/

/* IPv6 �˴ؤ������ */

#define NUM_IP6_DAD_COUNT	1	/* ��ʣ���ɥ쥹���Ф�����������������β����		*/
					/*  0 ����ꤹ��ȡ���ʣ���ɥ쥹���Ф�Ԥ�ʤ���	*/
#define NUM_ND6_CACHE_ENTRY	10	/* ���٥���å���Υ���ȥ��				*/

/*
 *  IPv6 �ѥۥ��ȥ���å���Υ���ȥ����
 *  0 ����ꤹ���IPv6 �ѥۥ��ȥ���å�����ȹ��ޤʤ���
 */
#define NUM_IN6_HOSTCACHE_ENTRY	4

#ifdef SUPPORT_ETHER

#define IP6_CFG_AUTO_LINKLOCAL		/* ��󥯥����륢�ɥ쥹�μ�ư�����Ԥ����ϥ����Ȥ򳰤���*/

/*
 *  �ǥ��ե���ȥ롼���ꥹ�Ȥ˴ؤ������
 */

/*
 *  �ǥ��ե���ȥ롼���ꥹ�ȤΥ���ȥ����
 *  �����ͤ� 16��0 ����ꤹ��ȥ롼�����Τ�������ʤ���
 */
#define NUM_ND6_DEF_RTR_ENTRY		4

/*
 *  �ץ�ե��å����ꥹ�Ȥ˴ؤ��������
 *  �����ͤ� 16��
 */
#define NUM_ND6_PREFIX_ENTRY		4	/*  �ץ�ե��å����ꥹ�ȤΥ���ȥ��			*/

/*
 *  ��ư���Υ롼���������ϲ����
 *  0 ����ꤹ��ȥ롼����������Ϥ��ʤ���
 */
#define NUM_ND6_RTR_SOL_RETRY	3

#define IP6_CFG_FRAGMENT		/* �ǡ���������ʬ�䡦�ƹ����Ԥ����ϥ����Ȥ򳰤���	*/
#define NUM_IP6_FRAG_QUEUE	2	/* �ǡ��������ƹ������塼������			*/
#define IP6_CFG_FRAG_REASSM_SIZE	4096	/* IPv6 �ƹ����Хåե�������			*/

#endif	/* of #ifdef SUPPORT_ETHER */

/*
 *  �ǡ�������� (�ͥåȥ�����󥿥ե�����) �˴ؤ������
 */

/*
 *  PPP����ǥ�˴ؤ������
 */

#define MODEM_CFG_DIAL		"ATD"	/* �������륳�ޥ��ʸ����		*/
#define MODEM_CFG_RETRY_CNT	3	/* ���������ȥ饤���			*/
#define MODEM_CFG_RETRY_WAIT	10000	/* ���������ȥ饤�ޤǤ��Ԥ����� [ms]	*/

/*
 *  PPP��HDLC �˴ؤ������
 */

#define DEF_LOCAL_ACCM		ULONG_C(0x000a0000)	/* ��ʬ�� ACCM��XON �� XOFF �Τ��Ѵ�	*/
#define DEF_REMOTE_ACCM		ULONG_C(0xffffffff)	/* ���� ACCM������ͤ������Ѵ�	*/

/*
 *  PPP��LCP �˴ؤ������
 */

#define LCP_CFG_MRU		UINT_C(0x0001)	/* MRU					*/
#define LCP_CFG_ACCM		UINT_C(0x0002)	/* ACCM					*/
#define LCP_CFG_MAGIC		UINT_C(0x0004)	/* �ޥ��å��ֹ�				*/
#define LCP_CFG_PCOMP		UINT_C(0x0008)	/* �ץ�ȥ��������̵�ǽ			*/
#define LCP_CFG_ACCOMP		UINT_C(0x0010)	/* ���ɥ쥹������������			*/
#define LCP_CFG_PAP		UINT_C(0x0020)	/* PAP					*/
/*#define LCP_CFG_CHAP		UINT_C(0x0040)	   CHAP �ϼ���ͽ��			*/

#ifdef LCP_CFG_MAGIC

#define LCP_ECHO_INTERVAL	(20*NET_TIMER_HZ)	/* ���󥿡��Х����		*/
#define LCP_ECHO_FAILS		9			/* ��������			*/

#endif	/* of #ifdef LCP_CFG_MAGIC */

/*
 *  PPP��PAP �˴ؤ������
 */

#define DEF_PAP_TIMEOUT		(3*NET_TIMER_HZ)
#define DEF_PAP_REQTIME		(30*NET_TIMER_HZ)	/* �����ॢ���Ƚ�����Ԥ��Ȥ��ϥ����Ȥ򳰤���*/
#define MAX_PAP_REXMT		10			/* ǧ���׵�κ���������	*/

/*
 *  NIC �˴ؤ������
 */

#define TMO_IF_TSE_GET_NET_BUF	1	/* [ms]�������� net_buf ���������ॢ����	*/
					/* [s]�� ���������ॢ����			*/
#define TMO_IF_TSE_XMIT		(2*IF_TIMER_HZ)

/*
 *  �������ͥåȽ��ϻ��ˡ�NIC �� net_buf ����������˻��ꤹ�롣
 */

#define ETHER_NIC_CFG_RELEASE_NET_BUF

/*
 *  NIC �˴ؤ������
 */

#define TSE_BASE		UINT_C(0x02000800)	/* TSE �Υ١������ɥ쥹			*/
#define SGDMA_RX_BASE		UINT_C(0x02000c40)	/* ���� SGDMA �Υ١������ɥ쥹		*/
#define SGDMA_TX_BASE		UINT_C(0x02000c00)	/* ���� SGDMA �Υ١������ɥ쥹		*/
#define DESCRIPTOR_MEMORY_BASE	UINT_C(0x02001000)	/* �ǥ�������ץ�����Υ١������ɥ쥹	*/

#define INTNO_IF_TSE_RX		UINT_C(12)		/* ���� SGDMA �γ�����ֹ�		*/
#define INTNO_IF_TSE_TX		UINT_C(13)		/* ���� SGDMA �γ�����ֹ�		*/
#define INTPRI_IF_TSE		3			/* �����ͥ����				*/

/*
 *  ARP �˴ؤ������
 */

#define NUM_ARP_ENTRY		10			/* ARP ����å��奨��ȥ��	*/

/*
 *  DHCP �˴ؤ������
 *
 *    �����: TINET �ϡ�DHCP ��������Ƥ��ʤ������ѥץ����ǡ�
 *            DHCP ��å�������������뤿�������Ǥ��롣
 *            �ޤ������ߤ� IPv4 �Τ�ͭ���Ǥ��롣
 */

/*#define DHCP_CFG					 DHCP �����������ϥ����Ȥ򳰤���*/

/*
 *  Ethernet �˴ؤ������
 */

/*#define ETHER_CFG_ACCEPT_ALL		 �ޥ�����㥹�ȡ����顼�ե졼����������Ȥ��ϥ����Ȥ򳰤���	*/
/*#define ETHER_CFG_UNEXP_WARNING	 �󥵥ݡ��ȥե졼��ηٹ��ɽ������Ȥ��ϥ����Ȥ򳰤���	*/
/*#define ETHER_CFG_802_WARNING		 IEEE 802.3 �ե졼��ηٹ��ɽ������Ȥ��ϥ����Ȥ򳰤���	*/
/*#define ETHER_CFG_MCAST_WARNING	 �ޥ�����㥹�Ȥηٹ��ɽ������Ȥ��ϥ����Ȥ򳰤���		*/

/*
 *  ���ɥ쥹�ꥹ�Ȥ˴ؤ��������
 */
#define NUM_IN6_IFADDR_ENTRY		5	/*  ���󥿥ե������Υ��ɥ쥹�ꥹ�ȤΥ���ȥ��		*/

/*
 *  ���ѥͥåȥ���˴ؤ������
 */

/*
 *  �ͥåȥ���Хåե��˴ؤ������
 */

/* �ͥåȥ���Хåե��� */

#ifdef SUPPORT_PPP

/*
 *  PPP �Ǥϡ������Ѥ� �ͥåȥ���Хåե��� PDU (1502) ����������
 *  ������Ƥʤ���Фʤ�ʤ��Τ� PDU ��������¿��˳��ݤ��롣
 */

#ifndef NUM_MPF_NET_BUF_CSEG
#define NUM_MPF_NET_BUF_CSEG	2	/* IF + IP + TCP��2 �ʾ�*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_CSEG */

#ifndef NUM_MPF_NET_BUF_64
#define NUM_MPF_NET_BUF_64	0	/* 64 �����ƥå�	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_64 */

#ifndef NUM_MPF_NET_BUF_128
#define NUM_MPF_NET_BUF_128	0	/* 128 �����ƥå�	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_128 */

#ifndef NUM_MPF_NET_BUF_256
#define NUM_MPF_NET_BUF_256	0	/* 256 �����ƥå�	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_256 */

#ifndef NUM_MPF_NET_BUF_512
#define NUM_MPF_NET_BUF_512	0	/* 512 �����ƥå�	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_512 */

#ifndef NUM_MPF_NET_BUF_1024
#define NUM_MPF_NET_BUF_1024	0	/* 1024 �����ƥå�	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_1024 */

#ifndef NUM_MPF_NET_BUF_IF_PDU
#define NUM_MPF_NET_BUF_IF_PDU	2	/* IF ���� PDU ������	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_IF_PDU */

#ifndef NUM_MPF_NET_BUF4_REASSM

#if defined(SUPPORT_INET4) && defined(IP4_CFG_FRAGMENT)
#define NUM_MPF_NET_BUF4_REASSM	2	/* IPv4 �ƹ����Хåե�������	*/
#else
#define NUM_MPF_NET_BUF4_REASSM	0	/* IPv4 �ƹ����Хåե�������	*/
#endif

#endif	/* of #ifndef NUM_MPF_NET_BUF4_REASSM */

#ifndef NUM_MPF_NET_BUF6_REASSM

#if defined(SUPPORT_INET6) && defined(IP6_CFG_FRAGMENT)
#define NUM_MPF_NET_BUF6_REASSM	2	/* IPv6 �ƹ����Хåե�������	*/
#else
#define NUM_MPF_NET_BUF6_REASSM	0	/* IPv6 �ƹ����Хåե�������	*/
#endif

#endif	/* of #ifndef NUM_MPF_NET_BUF6_REASSM */

#endif	/* of #ifdef SUPPORT_PPP */

#ifdef SUPPORT_ETHER

/*
 *  �������ͥåȤξ��Υͥåȥ���Хåե����γ������
 */

/*
 *  ���!!
 *
 *  NE2000 �ߴ� NIC �Υǥ��Х����ɥ饤�С�if_ed�ˤκ��������Ĺ��
 *  60�ʥ��饤�󤷤� 62�˥����ƥåȤΤ��� IF + IP +TCP ����
 *  64 �����ƥåȤΥͥåȥ���Хåե���������Ŭ�Ǥ��롣
 */

#ifndef NUM_MPF_NET_BUF_CSEG
#define NUM_MPF_NET_BUF_CSEG	0	/* IF + IP + TCP	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_CSEG */

#ifndef NUM_MPF_NET_BUF_64
#define NUM_MPF_NET_BUF_64	2	/* 64 �����ƥå�	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_64 */

#ifndef NUM_MPF_NET_BUF_128
#define NUM_MPF_NET_BUF_128	0	/* 128 �����ƥå�	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_128 */

#ifndef NUM_MPF_NET_BUF_256
#define NUM_MPF_NET_BUF_256	0	/* 256 �����ƥå�	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_256 */

#ifndef NUM_MPF_NET_BUF_512
#define NUM_MPF_NET_BUF_512	0	/* 512 �����ƥå�	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_512 */

#if defined(SUPPORT_INET4)

#ifndef NUM_MPF_NET_BUF_IP_MSS
#define NUM_MPF_NET_BUF_IP_MSS	0	/* IF + 576 �����ƥå�	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_IP_MSS */

#endif	/* of #if defined(SUPPORT_INET4) */

#ifndef NUM_MPF_NET_BUF_1024
#define NUM_MPF_NET_BUF_1024	0	/* 1024 �����ƥå�	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_1024 */

#if defined(SUPPORT_INET6)

#ifndef NUM_MPF_NET_BUF_IPV6_MMTU
#define NUM_MPF_NET_BUF_IPV6_MMTU	0	/* IF + 1280	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_IPV6_MMTU */

#endif	/* of #if defined(SUPPORT_INET6) */

#ifndef NUM_MPF_NET_BUF_IF_PDU
#define NUM_MPF_NET_BUF_IF_PDU	4	/* IF ���� PDU ������	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_IF_PDU */

#ifndef NUM_MPF_NET_BUF4_REASSM

#if defined(SUPPORT_INET4) && defined(IP4_CFG_FRAGMENT)
#define NUM_MPF_NET_BUF4_REASSM	2	/* IPv4 �ƹ����Хåե�������	*/
#else
#define NUM_MPF_NET_BUF4_REASSM	0	/* IPv4 �ƹ����Хåե�������	*/
#endif

#endif	/* of #ifndef NUM_MPF_NET_BUF4_REASSM */

#ifndef NUM_MPF_NET_BUF6_REASSM

#if defined(SUPPORT_INET6) && defined(IP6_CFG_FRAGMENT)
#define NUM_MPF_NET_BUF6_REASSM	2	/* IPv6 �ƹ����Хåե�������	*/
#else
#define NUM_MPF_NET_BUF6_REASSM	0	/* IPv6 �ƹ����Хåե�������	*/
#endif

#endif	/* of #ifndef NUM_MPF_NET_BUF6_REASSM */

#endif	/* of #ifdef SUPPORT_ETHER */

#ifdef SUPPORT_LOOP

#ifndef NUM_MPF_NET_BUF_CSEG
#define NUM_MPF_NET_BUF_CSEG	2	/* IF + IP + TCP	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_CSEG */

#ifndef NUM_MPF_NET_BUF_64
#define NUM_MPF_NET_BUF_64	0	/* 64 �����ƥå�	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_64 */

#ifndef NUM_MPF_NET_BUF_128
#define NUM_MPF_NET_BUF_128	0	/* 128 �����ƥåȡ�2 �ʾ�	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_128 */

#ifndef NUM_MPF_NET_BUF_256
#define NUM_MPF_NET_BUF_256	0	/* 256 �����ƥå�	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_256 */

#ifndef NUM_MPF_NET_BUF_512
#define NUM_MPF_NET_BUF_512	0	/* 512 �����ƥå�	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_512 */

#ifndef NUM_MPF_NET_BUF_1024
#define NUM_MPF_NET_BUF_1024	0	/* 1024 �����ƥå�	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_1024 */

#ifndef NUM_MPF_NET_BUF_IF_PDU
#define NUM_MPF_NET_BUF_IF_PDU	4	/* IF ���� PDU ������	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_IF_PDU */

#endif	/* of #ifdef SUPPORT_LOOP */

/*
 *  �ͥåȥ�����׾���η�¬
 *
 *  �ͥåȥ�����׾���η�¬��Ԥ����ϡ�tinet/include/net/net.h
 *  ���������Ƥ���ץ�ȥ��뼱�̥ե饰����ꤹ�롣
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
