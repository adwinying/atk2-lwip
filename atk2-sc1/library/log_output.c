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
 *  $Id: log_output.c 1801 2015-03-27 06:34:43Z t_ishikawa $
 */

/*
 *		�����ƥ���Υե����ޥåȽ���
 */

#include "log_output.h"

/*
 *  ���ͤ�ʸ������Ѵ�����uintptr���ο��ͤκ���ʸ����
 *  8�ʿ���10�ʿ���16�ʿ����Ѵ�������
 *  ư���㡧
 *  2Byte�ξ�硧16�ʿ���FFFF  ��4ʸ��
 *             ��10�ʿ���65535 ��5ʸ��
 *             �� 8�ʿ���177777��6ʸ��
 *               ��CONVERT_BUFLEN�Ϻ����6ʸ�����֤�
 *  �׻��ѥ�᡼����
 *  8U:1�Х��ȤΥӥåȿ�
 *  2U:3�ǳ�ä��ݤ�;��1�ӥåȡ��ޤ���2�ӥå�ʬ��ޤ�뤿���������
 *  3U:10�ʿ����Ѵ���������3�ӥåȤ�1ʸ���ˤʤ�
 *     (4�ӥåȤ���2������ˤʤ뤿��)
 *  �׻��㡧
 *  2Byte�ξ��
 *     �ӥåȿ���2 * 8U = 16bit
 *     ñ���3�ǳ��ȡ�16 / 3 = 5�Ȥʤꡤ;��1�ӥå�ʬ��ʸ������
 *     �ڤ�ΤƤ��Ƥ��ޤ�
 *     3�ǳ������2�ӥå�ʬ­�����Ȥǡ��ڼΤƤ��ɤ�
 *     (16 + 2) / 3 = 6ʸ��
 */
#define CONVERT_BUFLEN	(((sizeof(uintptr) * 8U) + 2U) / 3U)

/*
 *  ���ͤ�ʸ������Ѵ�
 */
static void
convert(uintptr val, uint32 radix, const char8 *radchar,
		uint32 width, boolean minus, boolean padzero, void (*outputc)(char8 c))
{
	char8	buf[CONVERT_BUFLEN];
	uint32	i, j;

	i = 0U;
	do {
		buf[i++] = radchar[val % radix];
		val /= radix;
	} while ((i < CONVERT_BUFLEN) && (val != 0U));

	if ((minus != FALSE) && (width > 0U)) {
		width -= 1U;
	}
	if ((minus != FALSE) && (padzero != FALSE)) {
		(*outputc)('-');
	}
	for (j = i; j < width; j++) {
		(*outputc)((char8) ((padzero != FALSE) ? '0' : ' '));
	}
	if ((minus != FALSE) && (padzero == FALSE)) {
		(*outputc)('-');
	}
	while (i > 0U) {
		(*outputc)(buf[--i]);
	}
}

/*
 *  ʸ������������
 */
static const char8	raddec[] = "0123456789";
static const char8	radhex[] = "0123456789abcdef";
static const char8	radHEX[] = "0123456789ABCDEF";

void
syslog_printf(const char8 *format, const uintptr *p_args, void (*outputc)(char8 c))
{
	char8		c;
	uint32		width;
	boolean		padzero;
	sintptr		val;
	const char8	*str;

	while ((c = *format++) != '\0') {
		if (c != '%') {
			(*outputc)(c);
			continue;
		}

		width = 0U;
		padzero = FALSE;
		if ((c = *format++) == '0') {
			padzero = TRUE;
			c = *format++;
		}
		while (('0' <= c) && (c <= '9')) {
			width = (width * 10U) + (c - '0');
			c = *format++;
		}
		if (c == 'l') {
			c = *format++;
		}
		switch (c) {
		case 'd':
			val = (sintptr) (*p_args++);
			if (val >= 0) {
				convert((uintptr) val, 10U, raddec,
						width, FALSE, padzero, outputc);
			}
			else {
				convert((uintptr) (-val), 10U, raddec,
						width, TRUE, padzero, outputc);
			}
			break;
		case 'u':
			val = (sintptr) (*p_args++);
			convert((uintptr) val, 10U, raddec, width, FALSE, padzero, outputc);
			break;
		case 'x':
		case 'p':
			val = (sintptr) (*p_args++);
			convert((uintptr) val, 16U, radhex, width, FALSE, padzero, outputc);
			break;
		case 'X':
			val = (sintptr) (*p_args++);
			convert((uintptr) val, 16U, radHEX, width, FALSE, padzero, outputc);
			break;
		case 'c':
			(*outputc)((char8) (uintptr) (*p_args++));
			break;
		case 's':
			str = (const char8 *) (*p_args++);
			while ((c = *str++) != '\0') {
				(*outputc)(c);
			}
			break;
		case '%':
			(*outputc)('%');
			break;
		case '\0':
			format--;
			break;
		default:
			/* �嵭�Υ������ʳ��ξ�硤�����ϹԤ�ʤ� */
			break;
		}
	}
}

/*
 *  ������ν���
 */
void
syslog_print(const SYSLOG *p_syslog, void (*outputc)(char8 c))
{
	switch (p_syslog->logtype) {
	case LOG_TYPE_COMMENT:
		syslog_printf((const char8 *) (p_syslog->loginfo[0]),
					  &(p_syslog->loginfo[1]), outputc);
		break;
	case LOG_TYPE_ASSERT:
		syslog_printf("%s:%u: Assertion '%s' failed.",
					  &(p_syslog->loginfo[0]), outputc);
		break;
	default:
		/* �嵭�Υ������ʳ��ξ�硤���ϤϹԤ�ʤ� */
		break;
	}
}
