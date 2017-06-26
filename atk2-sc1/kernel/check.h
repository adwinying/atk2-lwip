/*
 *  TOPPERS ATK2
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *      Automotive Kernel Version 2
 *
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2005-2015 by Center for Embedded Computing Systems
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
 *  $Id: check.h 1801 2015-03-27 06:34:43Z t_ishikawa $
 */

/*
 *		���顼�����å��ѥޥ���
 */

#ifndef TOPPERS_CHECK_H
#define TOPPERS_CHECK_H

#include "Os_Cfg.h"

/*
 * ���ѥ����å��ޥ���
 */
#define CHECK_ERROR_ERCD(exp, error) \
	do {							 \
		if (!(exp)) {				 \
			ercd = (error);			 \
			goto error_exit;		 \
		}							 \
	} while (0)

#define CHECK_ERROR_NO_ERCD(exp) \
	do {						 \
		if (!(exp)) {			 \
			goto error_exit;	 \
		}						 \
	} while (0)

#define D_CHECK_ERROR_ERCD(exp, error) \
	do {							   \
		if (!(exp)) {				   \
			ercd = (error);			   \
			goto d_error_exit;		   \
		}							   \
	} while (0)

#define D_CHECK_ERROR_NO_ERCD(exp) \
	do {						   \
		if (!(exp)) {			   \
			goto d_error_exit;	   \
		}						   \
	} while (0)

/*
 *  ɸ�२�顼�Υ����å��ޥ���
 */
#define S_CHECK_ERROR(exp, error)		CHECK_ERROR_ERCD(exp, error)


#ifdef CFG_USE_ERRORHOOK
/*
 *  ���顼�եå�����̵ͭ�ˤ���٥�κ����
 */
#define error_exit		exit_errorhook
#define d_error_exit	d_exit_errorhook

/*
 *  ���顼�եå�����Ѥ�����ϥ��顼�����ɤ���������
 */
#define S_N_CHECK_ERROR(exp, error)		CHECK_ERROR_ERCD(exp, error)

#else /* CFG_USE_ERRORHOOK */
/*
 *  ���顼�եå�����̵ͭ�ˤ���٥�κ����
 */
#define error_exit		exit_no_errorhook
#define d_error_exit	d_exit_no_errorhook

/*
 *  ���顼�եå�����Ѥ��ʤ����ϥ��顼�����ɤ��������ʤ�
 */
#define S_N_CHECK_ERROR(exp, error)		CHECK_ERROR_NO_ERCD(exp)

#endif /* CFG_USE_ERRORHOOK */


/* �ʲ��Υ����å��ޥ����OS�������Ѥ��� */

/*
 *  ���顼�����ɤ��б������ޥ���
 *   ɸ�२�顼
 */
#ifdef OMIT_STANDARD_DISALLINT

#define S_CHECK_DISALLINT()
#define S_N_CHECK_DISALLINT()

#else /* OMIT_STANDARD_DISALLINT */

#define S_CHECK_DISALLINT()								 \
	S_CHECK_ERROR(										 \
		((callevel_stat & TSYS_DISALLINT) == TSYS_NULL), \
		E_OS_DISABLEDINT								 \
		)
#define S_N_CHECK_DISALLINT()							 \
	S_N_CHECK_ERROR(									 \
		((callevel_stat & TSYS_DISALLINT) == TSYS_NULL), \
		E_OS_DISABLEDINT								 \
		)

#endif /* OMIT_STANDARD_DISALLINT */

#define S_CHECK_STATE(exp)				S_CHECK_ERROR(exp, E_OS_STATE)
#define S_N_CHECK_STATE(exp)			S_N_CHECK_ERROR(exp, E_OS_STATE)
#define S_CHECK_LIMIT(exp)				S_CHECK_ERROR(exp, E_OS_LIMIT)
#define S_N_CHECK_LIMIT(exp)			S_N_CHECK_ERROR(exp, E_OS_LIMIT)
#define S_D_CHECK_NOFUNC(exp)			D_CHECK_ERROR_ERCD(exp, E_OS_NOFUNC)
#define S_D_CHECK_STATE(exp)			D_CHECK_ERROR_ERCD(exp, E_OS_STATE)
#define S_D_CHECK_LIMIT(exp)			D_CHECK_ERROR_ERCD(exp, E_OS_LIMIT)

/*
 *  ���顼�����ɤ��б������ޥ���
 *   ��ĥ���顼
 */
#ifdef CFG_USE_EXTENDEDSTATUS

#define CHECK_ACCESS(exp)				CHECK_ERROR_ERCD(exp, E_OS_ACCESS)
#define D_CHECK_ACCESS(exp)				D_CHECK_ERROR_ERCD(exp, E_OS_ACCESS)
#define CHECK_CALLEVEL(clmask)					  \
	CHECK_ERROR_ERCD(							  \
		((callevel_stat | (clmask)) == (clmask)), \
		E_OS_CALLEVEL							  \
		)
#define CHECK_NOFUNC(exp)				CHECK_ERROR_ERCD(exp, E_OS_NOFUNC)
#define CHECK_RESOURCE(exp)				CHECK_ERROR_ERCD(exp, E_OS_RESOURCE)
#define CHECK_STATE(exp)				CHECK_ERROR_ERCD(exp, E_OS_STATE)
#define D_CHECK_STATE(exp)				D_CHECK_ERROR_ERCD(exp, E_OS_STATE)
#define CHECK_VALUE(exp)				CHECK_ERROR_ERCD(exp, E_OS_VALUE)
#define CHECK_DISABLEDINT()										\
	CHECK_ERROR_ERCD(											\
		((callevel_stat &										\
		  (TSYS_DISALLINT | TSYS_SUSALLINT | TSYS_SUSOSINT)) ==	\
		 TSYS_NULL												\
		),														\
		E_OS_DISABLEDINT										\
		)
#define CHECK_PARAM_POINTER(p_exp)		CHECK_ERROR_ERCD(((p_exp) != NULL), OS_E_PARAM_POINTER)
#define CHECK_ID(exp)					CHECK_ERROR_ERCD(exp, E_OS_ID)

#else /* CFG_USE_EXTENDEDSTATUS */

#define CHECK_ACCESS(exp)
#define D_CHECK_ACCESS(exp)
#define CHECK_CALLEVEL(clmask)
#define CHECK_NOFUNC(exp)
#define CHECK_RESOURCE(exp)
#define D_CHECK_STATE(exp)
#define CHECK_VALUE(exp)
#define CHECK_DISABLEDINT()
#define CHECK_PARAM_POINTER(p_exp)
#define CHECK_ID(exp)

#endif /* CFG_USE_EXTENDEDSTATUS */

#endif /* TOPPERS_CHECK_H */
