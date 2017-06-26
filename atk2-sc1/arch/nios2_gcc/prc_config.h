/*
 *  TOPPERS ATK2
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *      Automotive Kernel Version 2
 *
 *  Copyright (C) 2008-2015 by Center for Embedded Computing Systems
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
 *  $Id: prc_config.h 1801 2015-03-27 06:34:43Z t_ishikawa $
 */

/*
 *		�ץ��å���¸�⥸�塼���Nios2�ѡ�
 *
 *  ���Υ��󥯥롼�ɥե�����ϡ�target_config.h�ʤޤ��ϡ��������饤��
 *  �롼�ɤ����ե�����ˤΤߤ��饤�󥯥롼�ɤ���롥¾�Υե����뤫��
 *  ľ�ܥ��󥯥롼�ɤ��ƤϤʤ�ʤ�
 */

#ifndef TOPPERS_PRC_CONFIG_H
#define TOPPERS_PRC_CONFIG_H

#include "nios2.h"
#include "vic.h"

/*
 *  ���顼�����å���ˡ�λ���
 */
#define CHECK_STKSZ_ALIGN	4   /* �����å��������Υ��饤��ñ�� */
#define CHECK_FUNC_ALIGN	4   /* �ؿ��Υ��饤��ñ�� */
#define CHECK_FUNC_NONNULL      /* �ؿ�����NULL�����å� */
#define CHECK_STACK_ALIGN	4   /* �����å��ΰ�Υ��饤��ñ�� */
#define CHECK_STACK_NONNULL     /* �����å��ΰ����NULL�����å� */

/*
 *	������֥�Υ�����������
 */
#ifndef FUNCTION_ALIGN_SIZE
#define FUNCTION_ALIGN_SIZE	4
#endif /* FUNCTION_ALIGN_SIZE */

/*
 *  ������ֹ�˴ؤ������
 */
#define TMIN_INTNO	UINT_C(0)
#define TMAX_INTNO	UINT_C(31)
#define TNUM_INT	UINT_C(32)

#define call_errorhook(ercd, svcid)		stack_change_and_call_func_2((void *) &internal_call_errorhook, (ercd), (svcid))
#define call_shutdownhook(ercd)			stack_change_and_call_func_1((void *) &internal_call_shtdwnhk, ((uint32) (ercd)))

/*
 * ������ֹ椫�顤IRC���Τ���Υӥåȥѥ���������ޥ���
 */
#define INTNO_BITPAT(intno)	((uint32) 1 << (intno))

/*
 *  ������ֹ���ϰϤ�Ƚ��
 */
#define VALID_INTNO(intno)	(((InterruptNumberType) (TMIN_INTNO) <= (intno)) && ((intno) <= (InterruptNumberType) (TMAX_INTNO)))

#ifndef TOPPERS_MACRO_ONLY

/*
 *  �󥿥�������ƥ������ѤΥ����å����ϥ��ɥ쥹����ޥ���
 */
#define TOPPERS_OSTKPT(stk, stksz)	((StackType *) ((sint8 *) (stk) + (stksz)))

/*
 *  �ץ��å����ü�̿��Υ���饤��ؿ����
 */
#include "prc_insn.h"

/*
 *  TOPPERSɸ�����߽�����ǥ�μ¸�
 */

/*
 * �㳰�ʳ����/CPU�㳰�ˤΥͥ��Ȳ���Υ������
 *
 * ����ƥ����Ȼ��ȤΤ���˻���
 */
extern uint32		except_nest_cnt;

/*
 * OS����߶ػ߻���status.IL�ؤ�������
 */
extern const uint32	tmin_status_il;

/*
 *  ����߽�����ǥ�μ¸�
 */

/*
 *  �����ͥ���٥ޥ��������¸��ɽ��(����ɽ��)��Nios2��¸��ɽ��(����ɽ��)���Ѵ�
 */
#define EXT_IPM(iipm)	(-((PriorityType) (iipm)))              /* ����ɽ������ɽ���� */
#define INT_IPM(ipm)	((uint32) ((PriorityType) (-(ipm))))    /* ����ɽ��������ɽ���� */

/*
 *  ������߶ػ߾��֤ؤΰܹ�
 */
LOCAL_INLINE void
x_lock_all_int(void)
{
	set_status(current_status() & (~STATUS_PIE));
	/* ����ƥ����륻������������ǥ��꤬�񤭴�����ǽ�������� */
	Asm("" ::: "memory");
}

/*
 *  ������߶ػ߾��֤β��
 */
LOCAL_INLINE void
x_unlock_all_int(void)
{
	/* ����ƥ����륻������������ǥ��꤬�񤭴�����ǽ�������� */
	Asm("" ::: "memory");
	set_status(current_status() | STATUS_PIE);
}

/*
 *  OS����߶ػ߾��֤λ��˳����ͥ���٥ޥ�������¸�����ѿ�
 */
extern volatile uint32	saved_status_il;

/*
 *  x_nested_lock_os_int()�Υͥ��Ȳ��
 *  ���������ν�����Ѳ����ʤ��褦��volatile �����
 */
extern volatile uint8	nested_lock_os_int_cnt;

/*
 *  OS����߶ػ�
 *  API�¹Ի��˸ƤӽФ����
 *  �����ͥ���٥ޥ�����C2ISR��ͥ���٥ޥ������ϰϤ��⤤���֤ǸƤӽФ����
 *  ���ȤϤʤ�(C1ISR����ƤӽФ���뤳�ȤϤʤ�)
 *  �꥽������������status.IL��0����礭�����֤ǸƤӽФ���뤿���å�����
 *  status.IL���ͤ�saved_status_il����¸����
 */
LOCAL_INLINE void
x_nested_lock_os_int(void)
{
	uint32 status;

	/*
	 *  �����ܤʤ�status.IL��OS����ߤζػߥ�٥����������ͥ���٥ޥ������ͤ���¸
	 */
	if (nested_lock_os_int_cnt == 0U) {
		status = current_status();
		set_status((status & (~STATUS_IL)) | tmin_status_il);
		saved_status_il = status & STATUS_IL;
	}
	nested_lock_os_int_cnt++;

	Asm("" ::: "memory");
}

/*
 *  OS����߲��
 *  API�¹Ի��˸ƤӽФ����
 *  �����ͥ���٥ޥ�����C2ISR��ͥ���٥ޥ������ϰϤ��⤤���֤ǸƤӽФ����
 *  ���ȤϤʤ�(C1ISR����ƤӽФ���뤳�ȤϤʤ�)
 */
LOCAL_INLINE void
x_nested_unlock_os_int(void)
{
	Asm("" ::: "memory");

	ASSERT(nested_lock_os_int_cnt > 0U);

	nested_lock_os_int_cnt--;

	/*
	 *  ���ֳ�¦�ʤ�����ͥ���٥ޥ����򹹿�
	 */
	if (nested_lock_os_int_cnt == 0U) {
		set_status((uint32) ((current_status() & (~STATUS_IL)) | saved_status_il));
	}
}

/*
 *  SuspendOSInterrupts()����ƤӽФ�OS����߶ػ߾��֤ؤΰܹ�
 *  x_nested_lock_os_int()�Ȥΰ㤤�ϡ�C1ISR����ƤӽФ�����ǽ�������뤿�ᡤ
 *  status.IL��OS����߶ػ߻����ͤ���礭������C1ISR����ƤӽФ��줿�Ȥ��ơ�
 *  ���⤻���꥿���󤹤�
 */
LOCAL_INLINE void
x_suspend_lock_os_int(void)
{
	uint32	status;
	uint32	status_il;

	status = current_status();
	status_il = status & STATUS_IL;

	/*
	 *  C1ISR����ƤФ줿���ϲ��⤷�ʤ�
	 */
	if (status_il <= tmin_status_il) {

		/*
		 *  �����ܤʤ�status.IL��OS����ߤζػߥ�٥����������ͥ���٥ޥ������ͤ���¸
		 */
		if (nested_lock_os_int_cnt == 0U) {
			set_status((status & (~STATUS_IL)) | tmin_status_il);
			saved_status_il = status_il;
		}
		nested_lock_os_int_cnt++;

		Asm("" ::: "memory");
	}
}

/*
 *  ResumeOSInterrupts()����ƤӽФ�OS����߶ػ߾��֤β��
 *  x_nested_unlock_os_int()�Ȥΰ㤤�ϡ�C1ISR����ƤӽФ�����ǽ�������뤿�ᡤ
 *  status.IL��OS����߶ػ߻����ͤ���礭������C1ISR����ƤӽФ��줿�Ȥ��ơ�
 *  ���⤻���꥿���󤹤�
 */
LOCAL_INLINE void
x_resume_unlock_os_int(void)
{
	uint32	status;
	uint32	status_il;

	Asm("" ::: "memory");

	status = current_status();
	status_il = status & STATUS_IL;

	/*
	 * C1ISR����ƤФ줿���ϲ��⤷�ʤ�
	 */
	if (status_il <= tmin_status_il) {
		ASSERT(nested_lock_os_int_cnt > 0U);
		nested_lock_os_int_cnt--;

		/*
		 *  ���ֳ�¦�ʤ�����ͥ���٥ޥ����򹹿�
		 */
		if (nested_lock_os_int_cnt == 0U) {
			set_status((status & (~STATUS_IL)) | saved_status_il);
		}
	}
}


/*
 *  (��ǥ���)�����ͥ���٥ޥ���������
 *
 *  ��OS�Ǥϼ�������������Ω��
 *    * OS����߶ػ߾��֤ǸƤӽФ����
 *    * OS����߶ػ߻���ͥ���٤��⤤�ͤϻ��ꤵ��ʤ�
 */
LOCAL_INLINE void
x_set_ipm(PriorityType intpri)
{
	ASSERT(nested_lock_os_int_cnt > 0U);
	saved_status_il = (INT_IPM(intpri) << STATUS_IL_OFFSET);
}

/*
 *  (��ǥ���)�����ͥ���٥ޥ����λ���
 *
 *  ��OS�Ǥϼ�����������Ω��
 *    * OS����߶ػ߾��֤ǸƤӽФ����
 */
LOCAL_INLINE PriorityType
x_get_ipm(void)
{
	ASSERT(nested_lock_os_int_cnt > 0U);
	return(EXT_IPM((saved_status_il >> STATUS_IL_OFFSET)));
}

/*
 *  ������׵�饤���°��������
 */
extern void x_config_int(InterruptNumberType intno, AttributeType intatr, PriorityType intpri);

/*
 *  ����ߥϥ�ɥ���������ɬ�פ�IRC���
 */
LOCAL_INLINE void
i_begin_int(InterruptNumberType intno)
{

}

/*
 *  ����ߥϥ�ɥ�νи���ɬ�פ�IRC���
 */
LOCAL_INLINE void
i_end_int(InterruptNumberType intno)
{

}

/*
 *  ̤����γ���ߤ����ä����ν���
 */
extern void default_int_handler(void);

extern void prc_hardware_initialize(void);

/*
 *  �ץ��å���¸�ν����
 */
extern void prc_initialize(void);

/*
 *  �ץ��å���¸�ν�λ������
 */
extern void prc_terminate(void);

/*
 *  �������ǥ����ѥå���
 */

/*
 *  �ǹ�ͥ���̥������ؤΥǥ����ѥå���prc_support.S��
 *
 *  dispatch �ϡ�����������ƥ����Ȥ���ƤӽФ��줿�����ӥ����������
 *  ��ǡ�OS����߶ػ߾��֤ǸƤӽФ��ʤ���Фʤ�ʤ�
 */
extern void dispatch(void);

/*
 *  �ǥ����ѥå����ư��ϡ�prc_support.S��
 *
 *  start_dispatch�ϡ������ͥ뵯ư���˸ƤӽФ��٤���Τǡ����٤Ƥγ��
 *  �ߤ�ػߤ������֡�������߶ػ߾��֤�Ʊ���ξ��֡ˤǸƤӽФ��ʤ����
 *  �ʤ�ʤ�
 */
extern void start_dispatch(void) NoReturn;

/*
 *  ���ߤΥ���ƥ����Ȥ�ΤƤƥǥ����ѥå���prc_support.S��
 *
 *  exit_and_dispatch �ϡ�OS����߶ػ߾��֤ǸƤӽФ��ʤ���Фʤ�ʤ�
 */
extern void exit_and_dispatch(void) NoReturn;

/*
 *  ����������ƥ����ȥ֥�å������
 */
typedef struct task_context_block {
	void			*sp;        /* �����å��ݥ��� */
	FunctionRefType	pc;         /* �ץ���५���� */
} TSKCTXB;

/*
 *  ����������ƥ����Ȥν����
 *
 *  ���������ٻ߾��֤���¹ԤǤ�����֤˰ܹԤ�����˸ƤФ�롥���λ���
 *  �ǥ����å��ΰ��ȤäƤϤʤ�ʤ�
 *
 *  activate_context�򡤥���饤��ؿ��ǤϤʤ��ޥ�������Ȥ��Ƥ���Τϡ�
 *  ���λ����Ǥ�TCB���������Ƥ��ʤ�����Ǥ���
 */
extern void start_r(void);

#define activate_context(p_tcb) do {									  \
		(p_tcb)->tskctxb.sp = (void *) ((char8 *) ((p_tcb)->p_tinib->stk) \
										+ (p_tcb)->p_tinib->stksz);		  \
		(p_tcb)->tskctxb.pc = (FunctionRefType) &start_r;				  \
} while (0)

/* �����η��ϥϡ��ɥ������������륵������uint32�ˤ�Ʊ����������� */
extern void stack_change_and_call_func_1(void *func, uint32 arg1);

extern void stack_change_and_call_func_2(void *func, uint8 arg1, uint8 arg2);

#endif /* TOPPERS_MACRO_ONLY */

#endif /* TOPPERS_PRC_CONFIG_H_ */
