/*
 *  TOPPERS ATK2
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *      Automotive Kernel Version 2
 *
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2004-2015 by Center for Embedded Computing Systems
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
 *  $Id: t_syslog.h 1801 2015-03-27 06:34:43Z t_ishikawa $
 */

/*
 *		�����ƥ�����Ϥ�Ԥ���������
 *
 *  �����ƥ�������ӥ��ϡ������ƥ�Υ��������Ϥ��뤿��Υ����ӥ�
 *  �Ǥ���
 *  �����ͥ뤫��Υ�����ν��Ϥˤ��Ѥ��뤿�ᡤ�������Ԥ����֤ˤϤ���
 *  ���ȤϤʤ�
 *
 *  ������ϡ������ͥ���Υ��Хåե��˽񤭹��फ�����٥��ʸ����
 *  �ϴؿ����Ѥ��ƽ��Ϥ���
 *  �ɤ����Ȥ����ϡ���ĥ�����ӥ���������ڤ괹���뤳�Ȥ��Ǥ���
 *
 *  ���Хåե��ΰ褬�����Хե��������ˤϡ��Ť��������ä��ƾ�
 *  �񤭤���
 *
 *  ������֥����Υ������ե����뤫�餳�Υե�����򥤥󥯥롼�ɤ����
 *  �ϡ�TOPPERS_MACRO_ONLY��������Ƥ������Ȥǡ��ޥ�������ʳ��ε��Ҥ�
 *  �������Ȥ��Ǥ���
 */

#ifndef TOPPERS_T_SYSLOG_H
#define TOPPERS_T_SYSLOG_H

#include "Os.h"

/*
 *  ������μ��̤����
 */
#define LOG_TYPE_COMMENT	UINT_C(0x01)    /* ������ */
#define LOG_TYPE_ASSERT		UINT_C(0x02)    /* �����������μ��� */

#define LOG_TYPE_ISR			UINT_C(0x11)    /* ����ߥ����ӥ��롼���� */
#define LOG_TYPE_ALM			UINT_C(0x12)    /* ���顼��ϥ�ɥ� */
#define LOG_TYPE_TSKSTAT		UINT_C(0x13)    /* �����������Ѳ� */
#define LOG_TYPE_DSP			UINT_C(0x14)    /* �ǥ����ѥå��� */
#define LOG_TYPE_SVC			UINT_C(0x15)    /* �����ӥ������� */
#define LOG_TYPE_SCHTBL			UINT_C(0x16)    /* �������塼��ơ��֥���λ���� */
#define LOG_TYPE_STAHOOK		UINT_C(0x17)    /* �������ȥ��åץեå� */
#define LOG_TYPE_ERRHOOK		UINT_C(0x18)    /* ���顼�եå� */
#define LOG_TYPE_PROHOOK		UINT_C(0x19)    /* �ץ�ƥ������եå� */
#define LOG_TYPE_SHUTHOOK		UINT_C(0x1a)    /* ����åȥ�����եå� */
#define LOG_TYPE_STAHOOKOSAP	UINT_C(0x1b)    /* OSAP�������ȥ��åץեå� */
#define LOG_TYPE_ERRHOOKOSAP	UINT_C(0x1c)    /* OSAP���顼�եå� */
#define LOG_TYPE_SHUTHOOKOSAP	UINT_C(0x1d)    /* OSAP����åȥ�����եå� */
#define LOG_TYPE_TFN			UINT_C(0x1e)    /* ����ؿ� */

#define LOG_ENTER			UINT_C(0x00)    /* ���������� */
#define LOG_LEAVE			UINT_C(0x80)    /* �и�����λ */

/*
 *  ������ν����٤����
 */
#define LOG_EMERG			UINT_C(0)       /* ����åȥ�������ͤ��륨�顼 */
#define LOG_ALERT			UINT_C(1)
#define LOG_CRIT			UINT_C(2)
#define LOG_ERROR			UINT_C(3)       /* �����ƥ२�顼 */
#define LOG_WARNING			UINT_C(4)       /* �ٹ��å����� */
#define LOG_NOTICE			UINT_C(5)
#define LOG_INFO			UINT_C(6)
#define LOG_DEBUG			UINT_C(7)       /* �ǥХå��ѥ�å����� */

#ifndef TOPPERS_MACRO_ONLY

/*
 *  �������ѥǡ�����
 */

typedef uint32 ObjectIDType;                /* ���֥������Ȥ�ID�ֹ� */

/*
 *  ������Υǡ�����¤
 */

#define TMAX_LOGINFO	UINT_C(6)

typedef struct {
	uint32				logtype;                /* ������μ��� */
	SystemTimeMsType	logtim;                 /* ������ */
	uintptr				loginfo[TMAX_LOGINFO];  /* ����¾�Υ����� */
} SYSLOG;

/*
 *  ������ν����٤Υӥåȥޥåפ��뤿��Υޥ���
 */
#define LOG_MASK(prio)		(1U << (prio))
#define LOG_UPTO(prio)		((((uint32) 1) << ((prio) + 1U)) - 1U)

#ifndef TOPPERS_OMIT_SYSLOG

/*
 *  ���������Ϥ��뤿��Υ饤�֥��ؿ�(syslog.c)
 */
extern StatusType syslog_wri_log(uint32 prio, const SYSLOG *p_syslog);

LOCAL_INLINE void
_syslog_1(uint32 prio, uint32 type, uintptr arg1)
{
	SYSLOG syslog;

	syslog.logtype = type;
	syslog.loginfo[0] = arg1;
	(void) syslog_wri_log(prio, &syslog);
}

LOCAL_INLINE void
_syslog_2(uint32 prio, uint32 type, uintptr arg1, uintptr arg2)
{
	SYSLOG syslog;

	syslog.logtype = type;
	syslog.loginfo[0] = arg1;
	syslog.loginfo[1] = arg2;
	(void) syslog_wri_log(prio, &syslog);
}

LOCAL_INLINE void
_syslog_3(uint32 prio, uint32 type, uintptr arg1, uintptr arg2,
		  uintptr arg3)
{
	SYSLOG syslog;

	syslog.logtype = type;
	syslog.loginfo[0] = arg1;
	syslog.loginfo[1] = arg2;
	syslog.loginfo[2] = arg3;
	(void) syslog_wri_log(prio, &syslog);
}

LOCAL_INLINE void
_syslog_4(uint32 prio, uint32 type, uintptr arg1, uintptr arg2,
		  uintptr arg3, uintptr arg4)
{
	SYSLOG syslog;

	syslog.logtype = type;
	syslog.loginfo[0] = arg1;
	syslog.loginfo[1] = arg2;
	syslog.loginfo[2] = arg3;
	syslog.loginfo[3] = arg4;
	(void) syslog_wri_log(prio, &syslog);
}

LOCAL_INLINE void
_syslog_5(uint32 prio, uint32 type, uintptr arg1, uintptr arg2,
		  uintptr arg3, uintptr arg4, uintptr arg5)
{
	SYSLOG syslog;

	syslog.logtype = type;
	syslog.loginfo[0] = arg1;
	syslog.loginfo[1] = arg2;
	syslog.loginfo[2] = arg3;
	syslog.loginfo[3] = arg4;
	syslog.loginfo[4] = arg5;
	(void) syslog_wri_log(prio, &syslog);
}

LOCAL_INLINE void
_syslog_6(uint32 prio, uint32 type, uintptr arg1, uintptr arg2,
		  uintptr arg3, uintptr arg4, uintptr arg5, uintptr arg6)
{
	SYSLOG syslog;

	syslog.logtype = type;
	syslog.loginfo[0] = arg1;
	syslog.loginfo[1] = arg2;
	syslog.loginfo[2] = arg3;
	syslog.loginfo[3] = arg4;
	syslog.loginfo[4] = arg5;
	syslog.loginfo[5] = arg6;
	(void) syslog_wri_log(prio, &syslog);
}

/*
 *  ������ʥ����ȡˤ���Ϥ��뤿��Υ饤�֥��ؿ���vasyslog.c��
 */
extern void syslog(uint32 prio, const char8 *format, ...);

#else /* TOPPERS_OMIT_SYSLOG */

/*
 *  �����ƥ�����Ϥ��޻ߤ�����
 */

LOCAL_INLINE void
_syslog_1(uint32 prio, uint32 type, uintptr arg1)
{
}

LOCAL_INLINE void
_syslog_2(uint32 prio, uint32 type, uintptr arg1, uintptr arg2)
{
}

LOCAL_INLINE void
_syslog_3(uint32 prio, uint32 type, uintptr arg1, uintptr arg2,
		  uintptr arg3)
{
}

LOCAL_INLINE void
_syslog_4(uint32 prio, uint32 type, uintptr arg1, uintptr arg2,
		  uintptr arg3, uintptr arg4)
{
}

LOCAL_INLINE void
_syslog_5(uint32 prio, uint32 type, uintptr arg1, uintptr arg2,
		  uintptr arg3, uintptr arg4, uintptr arg5)
{
}

LOCAL_INLINE void
_syslog_6(uint32 prio, uint32 type, uintptr arg1, uintptr arg2,
		  uintptr arg3, uintptr arg4, uintptr arg5, uintptr arg6)
{
}

LOCAL_INLINE void
syslog(uint32 prio, const char8 *format, ...)
{
}

#endif /* TOPPERS_OMIT_SYSLOG */

/*
 *  ������ʥ����ȡˤ���Ϥ��뤿��Υޥ���
 *
 *  format����Ӹ�³�ΰ����������������å������򡤽�����prio�ǥ���
 *  ��Ȥ��ƽ��Ϥ��뤿��Υޥ���
 *  arg1��argn��uintptr���˥��㥹�Ȥ��뤿�ᡤuintptr���˷��Ѵ��Ǥ���Ǥ
 *  �դη��Ǥ褤
 */

#define syslog_0(prio, format) \
	_syslog_1((prio), LOG_TYPE_COMMENT, (uintptr) (format))

#define syslog_1(prio, format, arg1)						\
	_syslog_2((prio), LOG_TYPE_COMMENT, (uintptr) (format),	\
			  (uintptr) (arg1))

#define syslog_2(prio, format, arg1, arg2)					\
	_syslog_3((prio), LOG_TYPE_COMMENT, (uintptr) (format),	\
			  (uintptr) (arg1), (uintptr) (arg2))

#define syslog_3(prio, format, arg1, arg2, arg3)			\
	_syslog_4((prio), LOG_TYPE_COMMENT, (uintptr) (format),	\
			  (uintptr) (arg1), (uintptr) (arg2), (uintptr) (arg3))

#define syslog_4(prio, format, arg1, arg2, arg3, arg4)				\
	_syslog_5((prio), LOG_TYPE_COMMENT, (uintptr) (format),			\
			  (uintptr) (arg1), (uintptr) (arg2), (uintptr) (arg3),	\
			  (uintptr) (arg4))

#define syslog_5(prio, format, arg1, arg2, arg3, arg4, arg5)		\
	_syslog_6((prio), LOG_TYPE_COMMENT, (uintptr) (format),			\
			  (uintptr) (arg1), (uintptr) (arg2), (uintptr) (arg3),	\
			  (uintptr) (arg4), (uintptr) (arg5))

#endif /* TOPPERS_MACRO_ONLY */

#endif /* TOPPERS_T_SYSLOG_H */
