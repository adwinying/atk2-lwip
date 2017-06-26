/*
 *  TOPPERS ATK2
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *      Automotive Kernel Version 2
 *
 *  Copyright (C) 2000 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2006-2015 by Center for Embedded Computing Systems
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
 *  $Id: queue.h 1801 2015-03-27 06:34:43Z t_ishikawa $
 */

/*
 *		���塼���饤�֥��
 *
 *  ���Υ��塼���饤�֥��Ǥϡ����塼�إå���ޤ��󥰹�¤�Υ��֥�
 *  ��󥯥��塼�򰷤�������Ū�ˤϡ����塼�إå��μ�����ȥ�ϥ��塼��
 *  ��Ƭ�Υ���ȥꡤ������ȥ�ϥ��塼�������Υ���ȥ�Ȥ��롥�ޤ�����
 *  �塼����Ƭ�Υ���ȥ��������ȥ�ȡ����塼�������Υ���ȥ�μ�����
 *  �ȥ�ϡ����塼�إå��Ȥ��롥���Υ��塼�ϡ�������ȥꡤ������ȥ��
 *  �⼫ʬ���Ȥ�ؤ����塼�إå��Ǥ���魯
 */

#ifndef	TOPPERS_QUEUE_H
#define	TOPPERS_QUEUE_H

/*
 *  ���塼�Υǡ�����¤�����
 */
typedef struct queue {
	struct queue	*p_next;    /* ������ȥ�ؤΥݥ��� */
	struct queue	*p_prev;    /* ������ȥ�ؤΥݥ��� */
} QUEUE;

/*
 *  ���塼�ν����
 */
LOCAL_INLINE void
queue_initialize(QUEUE *p_queue)
{
	p_queue->p_prev = p_queue;
	p_queue->p_next = p_queue;
}

/*
 *  ���塼��������ȥ�ؤ�����
 */
LOCAL_INLINE void
queue_insert_prev(QUEUE *p_queue, QUEUE *p_entry)
{
	p_entry->p_prev = p_queue->p_prev;
	p_entry->p_next = p_queue;
	p_queue->p_prev->p_next = p_entry;
	p_queue->p_prev = p_entry;
}

/*
 *  ���塼�θ奨��ȥ�ؤ�����
 */
LOCAL_INLINE void
queue_insert_next(QUEUE *p_queue, QUEUE *p_entry)
{
	p_entry->p_next = p_queue->p_next;
	p_entry->p_prev = p_queue;
	p_queue->p_next->p_prev = p_entry;
	p_queue->p_next = p_entry;
}

/*
 *  ����ȥ�κ��
 */
LOCAL_INLINE void
queue_delete(QUEUE *p_entry)
{
	p_entry->p_prev->p_next = p_entry->p_next;
	p_entry->p_next->p_prev = p_entry->p_prev;
}

/*
 *  ���塼�μ�����ȥ�μ�Ф�
 */
LOCAL_INLINE QUEUE *
queue_delete_next(QUEUE *p_queue)
{
	QUEUE *p_entry;

	ASSERT(p_queue->p_next != p_queue);
	p_entry = p_queue->p_next;
	p_queue->p_next = p_entry->p_next;
	p_entry->p_next->p_prev = p_queue;
	return(p_entry);
}

/*
 *  ���塼�������ɤ����Υ����å�
 */
LOCAL_INLINE boolean
queue_empty(const QUEUE *p_queue)
{
	return(p_queue->p_next == p_queue);
}

#endif /* TOPPERS_QUEUE_H */
