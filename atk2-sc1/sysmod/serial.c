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
 *  $Id: serial.c 1801 2015-03-27 06:34:43Z t_ishikawa $
 */

/*
 *		����ץ�������ꥢ��IO�⥸�塼��
 */

#include	"Os.h"
#include	"target_serial.h"
#include	"target_sysmod.h"
#include	"serial.h"


/*
 *  �����ѥǡ���
 */

static uint8	rx_char;
static boolean	rx_flag;

/*
 *  ���ꥢ��IO�⥸�塼����������
 *
 *  ����߶ػ߾��֤ǸƽФ�����
 */
void
InitSerial(void)
{
	/*
	 *  �����ե饰�����
	 */
	rx_flag = FALSE;

	/*
	 *  ��¸������������¹�
	 */
	InitHwSerial();
}

/*
 *  ���ꥢ��IO�⥸�塼����߽���
 *
 *  ���Ϥ���λ���Ƥ��뤳�Ȥ��ݾ㤷�ʤ��ʥǥåɥ�å��ɻߡ�
 *  ����ƥ����ȥ�å����ƽ��Ϥ���Τǡ��ۤ�����ʤ��ʺǸ�Σ�ʸ���Τߡ�
 *
 *  ����߶ػ߾��֤ǸƽФ�����
 */
void
TermSerial(void)
{
	/*
	 *  ��¸������������¹�
	 */
	TermHwSerial();

	/*
	 *  �����ǡ���̵����
	 */
	rx_flag = FALSE;
}

/*
 *  ʸ����������
 */
void
RecvPolSerialChar(uint8 *character)
{
	SuspendAllInterrupts();
	if (rx_flag != FALSE) {
		/*
		 *  ����߶ػߤˤ��Ƽ����ǡ����������ե饰���ꥢ
		 */
		*character = rx_char;
		rx_flag = FALSE;
	}
	else {
		/*
		 *  �����ǡ������ʤ�����'\0'���֤�
		 */
		*character = '\0';
	}
	ResumeAllInterrupts();
}

/*
 *  ����������Хå��ؿ�
 */
void
RxSerialInt(uint8 character)
{
	/*
	 *  ����߶ػߤˤ��Ƽ����ǡ����ݻ����ե饰���ꥢ
	 */
	SuspendAllInterrupts();
	rx_char = character;
	rx_flag = TRUE;
	ResumeAllInterrupts();
}
