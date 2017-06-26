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
 *  $Id: counter.c 1801 2015-03-27 06:34:43Z t_ishikawa $
 */

/*
 *		����������⥸�塼��
 */

#include "kernel_impl.h"
#include "task.h"
#include "counter.h"

/*
 *  �ȥ졼�����ޥ���Υǥե�������
 */
#ifndef LOG_INCCNT_ENTER
#define LOG_INCCNT_ENTER(cntid)
#endif /* LOG_INCCNT_ENTER */

#ifndef LOG_INCCNT_LEAVE
#define LOG_INCCNT_LEAVE(ercd)
#endif /* LOG_INCCNT_LEAVE */

#ifndef LOG_GETCNT_ENTER
#define LOG_GETCNT_ENTER(cntid, p_val)
#endif /* LOG_GETCNT_ENTER */

#ifndef LOG_GETCNT_LEAVE
#define LOG_GETCNT_LEAVE(ercd, val)
#endif /* LOG_GETCNT_LEAVE */

#ifndef LOG_GETECT_ENTER
#define LOG_GETECT_ENTER(cntid, val, p_eval)
#endif /* LOG_GETECT_ENTER */

#ifndef LOG_GETECT_LEAVE
#define LOG_GETECT_LEAVE(ercd, val, eval)
#endif /* LOG_GETECT_LEAVE */

/*
 *  ��������λ���塼�ؤ�����
 */
#ifdef TOPPERS_insert_cnt_expr_que

void
insert_cnt_expr_que(CNTEXPINFO *p_cntexpinfo, CNTCB *p_cntcb)
{
	TickType	enqval, curval;
	QUEUE		*next;
	CounterType cntid;

	enqval = p_cntexpinfo->expiretick;

	/*
	 *  ��������λ���塼�ؤ��������֤���ꤹ�뤿��δ����
	 *
	 *  �ϡ��ɥ����������󥿤ξ�硤��������λ���塼�ؤ��������֤����������
	 *  ��λ�������˹������Ƥ����ͤ���Ѥ����ϡ��ɥ��������鸽���ͤ�����Ϥ��ʤ�
	 *  (�ϡ��ɥ����������󥿾�Υƥ��å��ͤ���λ���Ƥ��뤬���ޤ���λ������¹Ԥ���
	 *  ���ʤ����ˡ��������δ�ब����Ƥ��ޤ�����)
	 */
	curval = p_cntcb->curval;

	/* �������Υ����� */
	next = p_cntcb->cntexpque.p_next;

	if (curval < enqval) {
		/* �����󥿤Υ����С��ե���������ʤ���� */
		while ((next != &(p_cntcb->cntexpque)) &&
			   (curval <= ((CNTEXPINFO *) next)->expiretick) &&
			   (((CNTEXPINFO *) next)->expiretick <= enqval)) {
			next = next->p_next;
		}
	}
	else {
		/* �����󥿤Υ����С��ե����������� */
		while ((next != &(p_cntcb->cntexpque)) &&
			   ((curval <= ((CNTEXPINFO *) next)->expiretick)
				|| (((CNTEXPINFO *) next)->expiretick <= enqval))) {
			next = next->p_next;
		}
	}

	queue_insert_prev(next, &(p_cntexpinfo->cntexpque));

	/*
	 *  �ϡ��ɥ����������󥿤�����Ƭ�������������,���٥ϡ��ɥ����������󥿤�
	 *  ��λ���֤����ꤷľ��ɬ�פ�����
	 */
	cntid = CNTID(p_cntcb);
	if (is_hwcnt(cntid) && (p_cntcb->cntexpque.p_next == &(p_cntexpinfo->cntexpque))) {

		/* �������ꤵ��Ƥ������򥭥�󥻥� */
		(hwcntinib_table[cntid].cancel)();

		/* ��Ƭ��������������˺����� */
		(hwcntinib_table[cntid].set)(enqval);
		p_cntcb->hwset = TRUE;

		/*
		 *  ��������˼�����λ���֤�᤮�Ƥ��ޤä��������å�
		 *
		 *  �᤮�Ƥ��ޤä����, ��������ߤˤ����λ������¹Ԥ���
		 *  �ޤ�set�������֤�get�������֤�Ʊ���Ǥ��ä����,
		 *  �ϡ��ɥ������Ǽ�ꤳ�ܤ��Ƥ�������ꤷ, ��������ߤ�ȯ��������
		 *  �ϡ��ɥ������Ǽ�ꤳ�ܤ��Ƥ��ʤ����˶�������ߤ򵯤����Ƥ�����ʤ�
		 */
		if (diff_tick((hwcntinib_table[cntid].get)(), enqval,
					  p_cntcb->p_cntinib->maxval2) <= p_cntcb->p_cntinib->maxval) {
			/* �������ꤵ��Ƥ������򥭥�󥻥� */
			(hwcntinib_table[cntid].cancel)();
			/* ��������ߤ�ȯ�������� */
			(hwcntinib_table[cntid].trigger)();
		}
	}
}

#endif /* TOPPERS_insert_cnt_expr_que */

/*
 *  ��������λ���塼������
 */
#ifdef TOPPERS_delete_cnt_expr_que

void
delete_cnt_expr_que(CNTEXPINFO *p_cntexpinfo, CNTCB *p_cntcb)
{
	CounterType cntid;
	QUEUE		*p_cntexpque;

	/* �����󥿥��塼������λ������������������Ƭ���塼�ݻ� */
	p_cntexpque = p_cntcb->cntexpque.p_next;

	queue_delete(&(p_cntexpinfo->cntexpque));
	queue_initialize(&(p_cntexpinfo->cntexpque));

	/*
	 *  �ϡ��ɥ����������󥿤��ĺ��������λ�����ϥ�������λ��
	 *  ��Ƭ�ξ�硤�����ޤ򥭥�󥻥뤹��
	 */
	cntid = CNTID(p_cntcb);
	if (is_hwcnt(cntid) && (p_cntcb->cntexpque.p_next != p_cntexpque)) {

		/* �������ꤵ��Ƥ������򥭥�󥻥� */
		(hwcntinib_table[cntid].cancel)();

		/* �ڥ�ǥ�����γ�����׵�򥭥�󥻥� */
		(hwcntinib_table[cntid].intcancel)();

		/*
		 *  p_cntexpinfo�ǻ��ꤵ�줿��λ��������塤��������λ����
		 *  ��λ��������λ�������ꤹ��
		 */
		if (queue_empty(&(p_cntcb->cntexpque)) == FALSE) {

			/* ��Ƭ��������������˺����� */
			(hwcntinib_table[cntid].set)(((CNTEXPINFO *) p_cntcb->cntexpque.p_next)->expiretick);
			p_cntcb->hwset = TRUE;

			/*
			 *  ��������˼�����λ���֤�᤮�Ƥ��ޤä��������å�
			 *
			 *  �᤮�Ƥ��ޤä����, ��������ߤˤ����λ������¹Ԥ���
			 *  �ޤ�set�������֤�get�������֤�Ʊ���Ǥ��ä����,
			 *  �ϡ��ɥ������Ǽ�ꤳ�ܤ��Ƥ�������ꤷ, ��������ߤ�ȯ��������
			 *  �ϡ��ɥ������Ǽ�ꤳ�ܤ��Ƥ��ʤ����˶�������ߤ򵯤����Ƥ�����ʤ�
			 */
			if (diff_tick((hwcntinib_table[cntid].get)(),
						  ((CNTEXPINFO *) p_cntcb->cntexpque.p_next)->expiretick,
						  p_cntcb->p_cntinib->maxval2) <= p_cntcb->p_cntinib->maxval) {
				/* �������ꤵ��Ƥ������򥭥�󥻥� */
				(hwcntinib_table[cntid].cancel)();
				/* ��������ߤ�ȯ�������� */
				(hwcntinib_table[cntid].trigger)();
			}
		}
	}

}

#endif /* TOPPERS_delete_cnt_expr_que */

/*
 *  �����󥿵�ǽ�ν����
 */
#ifdef TOPPERS_counter_initialize

void
counter_initialize(void)
{
	CounterType	i;
	CNTCB		*p_cntcb;

	for (i = 0U; i < tnum_counter; i++) {
		p_cntcb = &(cntcb_table[i]);
		p_cntcb->p_cntinib = &(cntinib_table[i]);
		p_cntcb->curval = 0U;
		queue_initialize(&(p_cntcb->cntexpque));
		p_cntcb->cstat = CS_NULL;
	}

	for (i = 0U; i < tnum_hardcounter; i++) {
		(hwcntinib_table[i].init)(cntinib_table[i].maxval2,
								  hwcntinib_table[i].nspertick);
		(hwcntinib_table[i].start)();
	}

}

#endif /* TOPPERS_counter_initialize */

/*
 *  �����󥿵�ǽ�ν�λ����
 */
#ifdef TOPPERS_counter_terminate

void
counter_terminate(void)
{
	CounterType i;

	for (i = 0U; i < tnum_hardcounter; i++) {
		(hwcntinib_table[i].stop)();
	}
}

#endif /* TOPPERS_counter_terminate */

/*
 *  ���ꤷ�����л��֤���Υ������ͼ���(API����μ���)
 *
 *  ���ꤷ�������󥿤θ����ͤ�, �Ϥ��줿�����ͤ�­�����߹����ͤ�
 *  ����ͤȤ����֤�
 */
#ifdef TOPPERS_get_reltick

TickType
get_reltick(const CNTCB *p_cntcb, TickType relval)
{
	CounterType	cntid;
	TickType	result;
	TickType	curval;

	cntid = CNTID(p_cntcb);

	curval = get_curval(p_cntcb, cntid);

	/* ���߻��֤�����ꤵ�줿���ե��å�ʬ�᤮�����֤򻻽Ф��� */
	result = add_tick(curval, relval, p_cntcb->p_cntinib->maxval2);

	return(result);
}

#endif /* TOPPERS_get_reltick */

/*
 *  ���ꤷ�����л��֤���Υ������ͼ���(API����μ���)
 *
 *  �������Ϥ��줿�����ͤ���ꤷ�������󥿤θ����ͤ��Ѵ���
 *  �����ͤ�����ͤȤ����֤�
 */
#ifdef TOPPERS_get_abstick

TickType
get_abstick(const CNTCB *p_cntcb, TickType absval)
{
	CounterType	cntid;
	TickType	result;
	TickType	curval;
	TickType	nextval;

	cntid = CNTID(p_cntcb);

	curval = get_curval(p_cntcb, cntid);

	/* maxval2���θ�������л��֤��Ѵ� */
	nextval = absval +  p_cntcb->p_cntinib->maxval + 1U;

	if (curval < (p_cntcb->p_cntinib->maxval + 1U)) {
		/*
		 *  �����󥿤θ����ͤ�0��maxval�δ֤ξ�硤
		 *  ���л����̤��ã�ʤΤǡ����л�����֤�
		 */
		if (absval > curval) {
			result = absval;
		}
		else {
			result = nextval;
		}
	}
	else {
		/*
		 *  �����󥿤θ����ͤ�maxval��maxval2�δ֤ξ�硤
		 *  maxval2��θ�������Ф�Ķ�����Τǡ����л�����֤�
		 */
		if (nextval <= curval) {
			result = absval;
		}
		else {
			result = nextval;
		}
	}

	return(result);
}

#endif /* TOPPERS_get_abstick */

/*
 *  �����󥿤���λ����
 */
#ifdef TOPPERS_expire_process

void
expire_process(CNTCB *p_cntcb, CounterType cntid)
{
	CNTEXPINFO	*p_cntexpinfo;
	TickType	nowval;

	p_cntcb->hwset = FALSE;
	nowval = get_curval(p_cntcb, cntid);

	/*
	 *  �����󥿤���λ����
	 *
	 *  ���塼�����Ǥʤ�, �ꥢ�륿����ʸ��߻��֤��鸫�ƥ��塼����Ƭ����λ
	 *  ���֤����˲᤮�Ƥ����, ��λ������¹Ԥ���
	 *
	 *  �ꥢ�륿����ʸ��߻��֤򤽤����ټ������뤿��,���塼����Ƭ��λ����
	 *  ����λ���֤�����ꤹ�������Ū����λ���֤�Ķ���Ƥ��ޤäƤ⥫�С�
	 *  �Ǥ���
	 */
	while ((queue_empty(&(p_cntcb->cntexpque)) == FALSE) &&
		   (diff_tick(nowval, ((CNTEXPINFO *) p_cntcb->cntexpque.p_next)->expiretick,
					  p_cntcb->p_cntinib->maxval2) <= p_cntcb->p_cntinib->maxval)) {

		/* ��������λ���塼����Ƭ����λ�����򡤥��塼���鳰�� */
		p_cntexpinfo = (CNTEXPINFO *) p_cntcb->cntexpque.p_next;
		queue_delete(&(p_cntexpinfo->cntexpque));
		queue_initialize(&(p_cntexpinfo->cntexpque));
		if (is_hwcnt(cntid)) {
			/*
			 *  �������ͤ���λ��������λ���ǹ���������λ�������塼����λ����
			 *  �������������λ�������塼������������Ӥ˻���
			 */
			p_cntcb->curval = p_cntexpinfo->expiretick;

			/*
			 *  ������λ��������
			 *  ������λ�����»��֤�вᤷ�Ƥ��ʤ�������ꤹ��
			 */
			if ((queue_empty(&(p_cntcb->cntexpque)) == FALSE) && ((diff_tick((hwcntinib_table[cntid].get)(),
																			 ((CNTEXPINFO *) p_cntcb->cntexpque.p_next)->expiretick, p_cntcb->p_cntinib->maxval2)) >
																  p_cntcb->p_cntinib->maxval)) {
				(hwcntinib_table[cntid].set)(((CNTEXPINFO *) p_cntcb->cntexpque.p_next)->expiretick);
				p_cntcb->hwset = TRUE;
			}
		}

		/* ��������λ�����ƽФ� */
		(p_cntexpinfo->expirefunc)(p_cntexpinfo, p_cntcb);

		/*
		 *  ����������θƤӽФ�������ͥ���٥�������ǥ����֤ˤʤä���礢��Τǡ�
		 *  �����å����ƥǥ����ѥå�����
		 */
		if ((p_runtsk != p_schedtsk) && (callevel_stat == TCL_TASK)) {
			dispatch();
		}

		/*
		 *  ����ߥ쥹�ݥ󥹹�θ����1�Ĥ���λ���������
		 *  1��γ������/�ػߤ�»�
		 */
		x_nested_unlock_os_int();
		x_nested_lock_os_int();

		nowval = get_curval(p_cntcb, cntid);
	}

	if (is_hwcnt(cntid) && (queue_empty(&(p_cntcb->cntexpque)) == FALSE) && (p_cntcb->hwset == FALSE)) {
		(hwcntinib_table[cntid].set)(((CNTEXPINFO *) p_cntcb->cntexpque.p_next)->expiretick);
	}
}
#endif /* TOPPERS_expire_process */
