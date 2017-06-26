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
 *  $Id: kernel_fncode.h 1801 2015-03-27 06:34:43Z t_ishikawa $
 */

#ifndef TOPPERS_KERNEL_FNCODE_H
#define TOPPERS_KERNEL_FNCODE_H

#define TMAX_SVCID	UINT_C(34)

#define TFN_STARTOS						UINT_C(0)
#define TFN_SHUTDOWNOS					UINT_C(1)
#define TFN_ACTIVATETASK				UINT_C(2)
#define TFN_TERMINATETASK				UINT_C(3)
#define TFN_CHAINTASK					UINT_C(4)
#define TFN_SCHEDULE					UINT_C(5)
#define TFN_GETTASKID					UINT_C(6)
#define TFN_GETTASKSTATE				UINT_C(7)
#define TFN_ENABLEALLINTERRUPTS			UINT_C(8)
#define TFN_DISABLEALLINTERRUPTS		UINT_C(9)
#define TFN_RESUMEALLINTERRUPTS			UINT_C(10)
#define TFN_SUSPENDALLINTERRUPTS		UINT_C(11)
#define TFN_RESUMEOSINTERRUPTS			UINT_C(12)
#define TFN_SUSPENDOSINTERRUPTS			UINT_C(13)
#define TFN_GETISRID					UINT_C(14)
#define TFN_GETRESOURCE					UINT_C(15)
#define TFN_RELEASERESOURCE				UINT_C(16)
#define TFN_SETEVENT					UINT_C(17)
#define TFN_CLEAREVENT					UINT_C(18)
#define TFN_GETEVENT					UINT_C(19)
#define TFN_WAITEVENT					UINT_C(20)
#define TFN_GETALARMBASE				UINT_C(21)
#define TFN_GETALARM					UINT_C(22)
#define TFN_SETRELALARM					UINT_C(23)
#define TFN_SETABSALARM					UINT_C(24)
#define TFN_CANCELALARM					UINT_C(25)
#define TFN_INCREMENTCOUNTER			UINT_C(26)
#define TFN_GETCOUNTERVALUE				UINT_C(27)
#define TFN_GETELAPSEDVALUE				UINT_C(28)
#define TFN_GETACTIVEAPPLICATIONMODE	UINT_C(29)
#define TFN_STARTSCHEDULETABLEREL		UINT_C(30)
#define TFN_STARTSCHEDULETABLEABS		UINT_C(31)
#define TFN_STOPSCHEDULETABLE			UINT_C(32)
#define TFN_NEXTSCHEDULETABLE			UINT_C(33)
#define TFN_GETSCHEDULETABLESTATUS		UINT_C(34)

#endif /* TOPPERS_KERNEL_FNCODE_H */
