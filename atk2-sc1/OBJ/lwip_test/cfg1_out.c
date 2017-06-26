/* cfg1_out.c */
#define TOPPERS_CFG1_OUT  1
#include "kernel/kernel_int.h"
#include "lwip_test.h"
#include "target_timer.h"
#include "target_hw_counter.h"


#ifdef INT64_MAX
  typedef sint64 signed_t;
  typedef uint64 unsigned_t;
#else
  typedef sint32 signed_t;
  typedef uint32 unsigned_t;
#endif

#include "target_cfg1_out.h"

const uint32 TOPPERS_cfg_magic_number = 0x12345678;
const uint32 TOPPERS_cfg_sizeof_signed_t = sizeof(signed_t);
const uint32 TOPPERS_cfg_sizeof_pointer = sizeof(const volatile void*);

const unsigned_t TOPPERS_cfg_SIL_ENDIAN_BIG = 
#if defined(SIL_ENDIAN_BIG)
(1);
#else
(0);
#endif
const unsigned_t TOPPERS_cfg_SIL_ENDIAN_LITTLE = 
#if defined(SIL_ENDIAN_LITTLE)
(1);
#else
(0);
#endif
const unsigned_t TOPPERS_cfg_TARGET_MIN_STKSZ = 
#if defined(TARGET_MIN_STKSZ)
(TARGET_MIN_STKSZ);
#else
(0);
#endif
const unsigned_t TOPPERS_cfg_CHECK_STKSZ_ALIGN = 
#if defined(CHECK_STKSZ_ALIGN)
(CHECK_STKSZ_ALIGN);
#else
(0);
#endif
const unsigned_t TOPPERS_cfg_CHECK_FUNC_ALIGN = 
#if defined(CHECK_FUNC_ALIGN)
(CHECK_FUNC_ALIGN);
#else
(0);
#endif
const unsigned_t TOPPERS_cfg_CHECK_FUNC_NONNULL = 
#if defined(CHECK_FUNC_NONNULL)
(1);
#else
(0);
#endif
const unsigned_t TOPPERS_cfg_CHECK_STACK_ALIGN = 
#if defined(CHECK_STACK_ALIGN)
(CHECK_STACK_ALIGN);
#else
(0);
#endif
const unsigned_t TOPPERS_cfg_CHECK_STACK_NONNULL = 
#if defined(CHECK_STACK_NONNULL)
(1);
#else
(0);
#endif
const unsigned_t TOPPERS_cfg_sizeof_void_ptr = ( unsigned_t )sizeof(void*);
const unsigned_t TOPPERS_cfg_sizeof_FunctionRefType = ( unsigned_t )sizeof(FunctionRefType);
const unsigned_t TOPPERS_cfg_sizeof_TINIB = ( unsigned_t )sizeof(TINIB);
const unsigned_t TOPPERS_cfg_sizeof_HWCNTINIB = ( unsigned_t )sizeof(HWCNTINIB);
const unsigned_t TOPPERS_cfg_sizeof_ALMINIB = ( unsigned_t )sizeof(ALMINIB);
const unsigned_t TOPPERS_cfg_offsetof_ALMINIB_action = ( unsigned_t )offsetof(ALMINIB,action);
const unsigned_t TOPPERS_cfg_offsetof_TINIB_task = ( unsigned_t )offsetof(TINIB,task);
const unsigned_t TOPPERS_cfg_offsetof_TINIB_stk = 
#if !defined(USE_TSKINICTXB)
(offsetof(TINIB,stk));
#else
(0);
#endif
const unsigned_t TOPPERS_cfg_offsetof_HWCNTINIB_init = ( unsigned_t )offsetof(HWCNTINIB,init);
const unsigned_t TOPPERS_cfg_ENABLE = ( unsigned_t )ENABLE;
const unsigned_t TOPPERS_cfg_AUTO = ( unsigned_t )AUTO;
const unsigned_t TOPPERS_cfg_TMIN_TPRI = ( unsigned_t )TMIN_TPRI;
const unsigned_t TOPPERS_cfg_TMAX_TPRI = ( unsigned_t )TMAX_TPRI;
const unsigned_t TOPPERS_cfg_TPRI_MAXTASK = ( unsigned_t )TPRI_MAXTASK;
const unsigned_t TOPPERS_cfg_OMIT_INITIALIZE_INTERRUPT = 
#if defined(OMIT_INITIALIZE_INTERRUPT)
(1);
#else
(0);
#endif
const unsigned_t TOPPERS_cfg_USE_TSKINICTXB = 
#if defined(USE_TSKINICTXB)
(1);
#else
(0);
#endif
const unsigned_t TOPPERS_cfg_OMIT_CHECK_CYCLIC_CHAIN = 
#if defined(OMIT_CHECK_CYCLIC_CHAIN)
(1);
#else
(0);
#endif
const unsigned_t TOPPERS_cfg_MINIMUM_OSTKSZ = ( unsigned_t )MINIMUM_OSTKSZ;
const unsigned_t TOPPERS_cfg_DEFAULT_TASKSTKSZ = ( unsigned_t )DEFAULT_TASKSTKSZ;
const unsigned_t TOPPERS_cfg_DEFAULT_ISRSTKSZ = ( unsigned_t )DEFAULT_ISRSTKSZ;
const unsigned_t TOPPERS_cfg_DEFAULT_HOOKSTKSZ = ( unsigned_t )DEFAULT_HOOKSTKSZ;
const unsigned_t TOPPERS_cfg_DEFAULT_OSSTKSZ = ( unsigned_t )DEFAULT_OSSTKSZ;
const unsigned_t TOPPERS_cfg_offsetof_TCB_p_tinib = ( unsigned_t )offsetof(TCB,p_tinib);
const unsigned_t TOPPERS_cfg_offsetof_TCB_curpri = ( unsigned_t )offsetof(TCB,curpri);
const unsigned_t TOPPERS_cfg_offsetof_TCB_sp = ( unsigned_t )offsetof(TCB,tskctxb.sp);
const unsigned_t TOPPERS_cfg_offsetof_TCB_pc = ( unsigned_t )offsetof(TCB,tskctxb.pc);
const unsigned_t TOPPERS_cfg_offsetof_TINIB_exepri = ( unsigned_t )offsetof(TINIB,exepri);
const unsigned_t TOPPERS_cfg_offsetof_INTINIB_remain_stksz = ( unsigned_t )offsetof(INTINIB,remain_stksz);
const unsigned_t TOPPERS_cfg_offsetof_ISRCB_p_intinib = ( unsigned_t )offsetof(ISRCB,p_intinib);
/* #include "lwip_test.h" */
/* #include "target_timer.h" */
/* #include "target_hw_counter.h" */
const unsigned_t TOPPERS_cfg_valueof_TSK_ACTIVATION_USRV_TASK_Os = ( 1U ); 
const unsigned_t TOPPERS_cfg_valueof_TSK_PRIORITY_USRV_TASK_Os = ( (TMAX_TPRI - USRV_MAIN_PRIORITY) ); 
const unsigned_t TOPPERS_cfg_valueof_TSK_STKSZ_USRV_TASK_Os = ( USRV_STACK_SIZE ); 
const unsigned_t TOPPERS_cfg_valueof_ISR_INTNO_target_timer_hdr_Os = ( INTNO_TIMER ); 
const unsigned_t TOPPERS_cfg_valueof_ISR_INTPRI_target_timer_hdr_Os = ( INTPRI_TIMER ); 
const unsigned_t TOPPERS_cfg_valueof_CNT_MAXALLOWED_SysTimerCnt_Os = ( 999U ); 
const unsigned_t TOPPERS_cfg_valueof_CNT_TICKSPERBASE_SysTimerCnt_Os = ( 1U ); 

