/*
 *  TOPPERS ATK2
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *      Automotive Kernel Version 2
 *
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
 *  $Id: histogram.c 1801 2015-03-27 06:34:43Z t_ishikawa $
 */

/*
 *		�¹Ի���ʬ�۽��ץ⥸�塼��
 */

#include "histogram.h"
#include "target_timer.h"
#include "target_test.h"

/*
 *  �¹Ի���ʬ�۷�¬�ο�
 */
#ifndef TNUM_HIST
#define TNUM_HIST		10
#endif /* TNUM_HIST */

/*
 *  �������åȰ�¸���������ѹ����뤿��Υޥ���
 */
#ifndef HISTTIM                     /* �¹Ի��ַ�¬�Ѥλ���Υǡ����� */
#define HISTTIM			SystemTimeUsType
#endif /* HISTTIM */

#ifndef HIST_GET_TIM                /* �¹Ի��ַ�¬�Ѥθ��߻���μ��� */
#ifndef TOPPERS_SUPPORT_GET_UTM
#error get_utm is not supported
#endif /* TOPPERS_SUPPORT_GET_UTM */
#define HIST_GET_TIM(p_time)	((void) get_utm(p_time))
#endif /* HIST_GET_TIM */

#ifndef HIST_CONV_TIM               /* ����κ�����¹Ի��֤ؤ��Ѵ� */
#define HIST_CONV_TIM(time)		((uint32) (time))
#endif /* HIST_CONV_TIM */

#ifndef HIST_BM_HOOK                /* �¹Ի��ַ�¬ľ���˹Ԥ��٤����� */
#define HIST_BM_HOOK()
#endif /* HIST_BM_HOOK */

LOCAL_INLINE void
get_utm(HISTTIM *p_time)
{
#ifndef GET_UTIM
	*p_time = (HISTTIM) get_tim_utime();
#else /* GET_UTIM */
	*p_time = (HISTTIM) GET_UTIM();
#endif /* GET_UTIM */

}

/*
 *  �¹Ի���ʬ�۷�¬�����֥�å�
 */
typedef struct histogram_control_block {
	HISTTIM	begin_time;             /* ��¬���ϻ��� */
	uint32	maxval;                 /* ʬ�ۤ�Ͽ���������� */
	uint32	*histarea;              /* ʬ�ۤ�Ͽ��������ΰ� */
	uint32	over;                   /* ������֤�Ķ�����ٿ� */
	uint32	under;                  /* ���֤ε�ž���������ٿ� */
	boolean	initialized;            /* ������Ѥߤ��ɤ����Υե饰 */
} HISTCB;

/*
 *  �¹Ի���ʬ�۷�¬�����֥�å��Υ��ꥢ
 */
HISTCB histcb_table[TNUM_HIST];

/*
 *  �¹Ի���ʬ�۷�¬ID�κǾ��ͤȺ�����
 */
#define TMIN_HISTID		1
#define TMAX_HISTID		((TMIN_HISTID + TNUM_HIST) - 1)

/*
 *  �¹Ի���ʬ�۷�¬�ν����
 */
boolean
init_hist(ObjectIDType histid, uint32 maxval, uint32 *histarea)
{
	HISTCB	*p_histcb;
	uint32	i;
	boolean ret = TRUE;

	/* ������ʬ�۷�¬ID�ξ��FALSE���֤� */
	if ((histid < TMIN_HISTID) || (histid > TMAX_HISTID)) {
		ret = FALSE;
	}
	else {
		p_histcb = &(histcb_table[histid - TMIN_HISTID]);

		for (i = 0U; i <= maxval; i++) {
			histarea[i] = 0U;
		}
		p_histcb->maxval = maxval;
		p_histcb->histarea = histarea;
		p_histcb->over = 0U;
		p_histcb->under = 0U;
		p_histcb->initialized = TRUE;
	}
	return(ret);
}

/*
 *  �¹Ի��ַ�¬�γ���
 */
boolean
begin_measure(ObjectIDType histid)
{
	HISTCB	*p_histcb;
	boolean ret = TRUE;

	/* ������ʬ�۷�¬ID�ξ��FALSE���֤� */
	if ((histid < TMIN_HISTID) || (histid > TMAX_HISTID)) {
		ret = FALSE;
	}
	else {
		p_histcb = &(histcb_table[histid - TMIN_HISTID]);

		/* ��������Ƥ��ʤ����FALSE���֤� */
		if (p_histcb->initialized == FALSE)	{
			ret = FALSE;
		}
		else {
			HIST_BM_HOOK();
			HIST_GET_TIM(&(p_histcb->begin_time));
		}
	}
	return(ret);
}

/*
 *  �¹Ի��ַ�¬�ν�λ
 */
boolean
end_measure(ObjectIDType histid)
{
	HISTCB	*p_histcb;
	HISTTIM	end_time;
	uint32	val;
	boolean ret = TRUE;

	HIST_GET_TIM(&end_time);

	/* ������ʬ�۷�¬ID�ξ��FALSE���֤� */
	if ((histid < TMIN_HISTID) || (histid > TMAX_HISTID)) {
		ret = FALSE;
	}
	else {
		p_histcb = &(histcb_table[histid - TMIN_HISTID]);

		/* ��������Ƥ��ʤ����FALSE���֤� */
		if (p_histcb->initialized == FALSE)	{
			ret = FALSE;
		}
		else {
			val = HIST_CONV_TIM(end_time - p_histcb->begin_time);
			if (val <= p_histcb->maxval) {
				p_histcb->histarea[val]++;
			}
			else if (val <= ((uint32) 0x7fffffff)) {
				p_histcb->over++;
			}
			else {
				p_histcb->under++;
			}
		}
	}
	return(ret);
}

/*
 *  �¹Ի���ʬ�۷�¬��ɽ��
 */
boolean
print_hist(ObjectIDType histid)
{
	HISTCB	*p_histcb;
	uint32	i;
	boolean ret = TRUE;

	/* ������ʬ�۷�¬ID�ξ��FALSE���֤� */
	if ((histid < TMIN_HISTID) || (histid > TMAX_HISTID)) {
		ret = FALSE;
	}
	else {
		p_histcb = &(histcb_table[histid - TMIN_HISTID]);

		/* ��������Ƥ��ʤ����FALSE���֤� */
		if (p_histcb->initialized == FALSE)	{
			ret = FALSE;
		}
		else {
			for (i = 0U; i <= p_histcb->maxval; i++) {
				if (p_histcb->histarea[i] > 0U) {
#ifndef MEASURE_100_NANO
					syslog_2(LOG_NOTICE, "%d : %d", i, p_histcb->histarea[i]);
#else
					syslog_3(LOG_NOTICE, "%d.%d : %d", i / 10, i % 10, p_histcb->histarea[i]);
#endif /* MEASURE_100_NANO */
				}
			}
			if (p_histcb->over > 0U) {
				syslog_2(LOG_NOTICE, "> %d : %d", p_histcb->maxval, p_histcb->over);
			}
			if (p_histcb->under > 0U) {
				syslog_1(LOG_NOTICE, "> 0x7fffffff : %d", p_histcb->under);
			}
		}
	}

	return(ret);
}
