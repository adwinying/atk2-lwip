/*
 *  TOPPERS ATK2
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *      Automotive Kernel Version 2
 *
 *  Copyright (C) 2004-2015 by Center for Embedded Computing Systems
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *  Copyright (C) 2011-2015 by FUJI SOFT INCORPORATED, JAPAN
 *  Copyright (C) 2011-2013 by Spansion LLC, USA
 *  Copyright (C) 2011-2015 by NEC Communication Systems, Ltd., JAPAN
 *  Copyright (C) 2011-2015 by Panasonic Advanced Technology Development Co., Ltd., JAPAN
 *  Copyright (C) 2011-2014 by Renesas Electronics Corporation, JAPAN
 *  Copyright (C) 2011-2015 by Sunny Giken Inc., JAPAN
 *  Copyright (C) 2011-2015 by TOSHIBA CORPORATION, JAPAN
 *  Copyright (C) 2004-2015 by Witz Corporation
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
 *  $Id: scheduletable.h 1801 2015-03-27 06:34:43Z t_ishikawa $
 */

/*
 *		�������塼��ơ��֥뵡ǽ
 */

#ifndef TOPPERS_SCHEDULETABLE_H
#define TOPPERS_SCHEDULETABLE_H

#include "counter.h"

/*
 *  ��λ���ơ��֥��������ü����λ������ǥå���
 */
#define EXPPTINDEX_TOP			((uint8) 0x00)
#define EXPPTINDEX_INITIAL		((uint8) 0xff)

/*
 *  �������塼��ơ��֥�ID���饹�����塼��ơ��֥�����֥�å�����Ф�����Υޥ���
 */
#define get_schtblcb(schtblid)	(&(schtblcb_table[(schtblid)]))

/*
 *  ����Ʊ���������塼��ơ��֥�˴ؤ������
 */
#define is_implschtbl(schtblid)	((schtblid) < tnum_implscheduletable)

/*
 *  �ġ�����λ���ơ��֥뷿
 */
typedef struct scheduletable_expire_point_block {
	TickType		offset;                                 /* ���ե��å��� */
	FunctionRefType	expptfnt;                               /* ��λ�������ؿ��Υݥ��� */
} SCHTBLEXPPTCB;


/*
 *  �������塼��ơ��֥������֥�å�
 */
typedef struct scheduletable_initialization_block {
	CNTCB				*p_cntcb;                           /* ��ư�����󥿴����֥�å��Υݥ��� */
	TickType			length;                             /* ������Ĺ�� */
	AppModeType			autosta;                            /* ��ư���륢�ץꥱ�������⡼�� */
	AttributeType		actatr;                             /* ��ư��ư��°�� */
	TickType			staval;                             /* ��ư��ư�ƥ��å��� */
	const SCHTBLEXPPTCB	*p_exppt;                           /* ��λ���ơ��֥����Ƭ�ݥ��� */
	boolean				repeat;                             /* ���������̵ͭ */
	uint8				tnum_exppt;                         /* ��λ���� */
} SCHTBLINIB;

/*
 *  �������塼��ơ��֥�����֥�å�
 */
typedef struct scheduletable_control_block {
	CNTEXPINFO							cntexpinfo;         /* ��������λ����(��¤�Τ���Ƭ������ɬ��) */
	const SCHTBLINIB					*p_schtblinib;      /* ������֥�å��ؤΥݥ��� */
	struct scheduletable_control_block	*p_prevschtblcb;    /* ��ʬ��Next�ˤ����������塼��ơ��֥�����֥�å��ؤΥݥ��� */
	struct scheduletable_control_block	*p_nextschtblcb;    /* Next�������塼��ơ��֥�����֥�å��ؤΥݥ��� */
	ScheduleTableStatusType				status;             /* �������塼��ơ��֥���� */
	uint8								expptindex;         /* ��λ������ǥå��� */
} SCHTBLCB;

/*
 *  ��λ�����¹��Ѵ�������
 */
typedef struct scheduletable_expire_info {
	SCHTBLCB *p_schtblcb;                                   /* �������塼��ơ��֥�����֥�å��Υ��ɥ쥹 */
} SCHTBLEXPINFO;

/*
 *  �������塼��ơ��֥�����ݻ������ѿ������
 */
extern const ScheduleTableType	tnum_scheduletable;         /* ���������塼��ơ��֥�ο� */
extern const ScheduleTableType	tnum_implscheduletable;     /* ����Ʊ���������塼��ơ��֥�� */

/*
 *  �������塼��ơ��֥������֥�å��Υ��ꥢ��Os_Lcfg.c��
 */
extern const SCHTBLINIB			schtblinib_table[];
/*
 *  �������塼��ơ��֥�����֥�å��Υ��ꥢ��Os_Lcfg.c��
 */
extern SCHTBLCB					schtblcb_table[];

/*
 *  �������塼��ơ��֥륪�֥������Ȥν����
 */
extern void schtbl_initialize(void);

/*
 *  �������塼��ơ��֥���λ�����ؿ�
 */
extern void schtbl_expire(CNTEXPINFO *p_cntexpinfo, const CNTCB *p_cntcb);

/*
 *  ��λ�����ؿ�����ƥ����ߥ󥰽����μ¹�
 */
extern void schtbl_expiry_process(SCHTBLEXPINFO *p_schtblexpinfo, const CNTCB *p_cntcb);

/*
 *  �������塼��ơ��֥�γ��Ͻ���
 */
extern boolean schtbl_head(SCHTBLCB *p_schtblcb, const CNTCB *p_cntcb);

/*
 *  �������塼��ơ��֥�γ���λ������
 */
extern boolean schtbl_exppoint_process(SCHTBLCB *p_schtblcb, const CNTCB *p_cntcb);

/*
 *  �������塼��ơ��֥�ν�ü����
 */
extern boolean schtbl_tail(SCHTBLCB *p_schtblcb, SCHTBLEXPINFO *p_schtblexpinfo, const CNTCB *p_cntcb);

#endif /* TOPPERS_SCHEDULETABLE_H */
