/*
 *  lwIP v1.4.1 test
 */

/*
 *  AUTOSAR includes
 */

#include "Os.h"
#include "t_syslog.h"
#include "t_stdlib.h"
#include "sysmod/serial.h"
#include "sysmod/syslog.h"

#include "sysmod/banner.h"
#include "target_sysmod.h"
#include "target_serial.h"
#include "target_hw_counter.h"

#include "target_test.h"
#include "lwip_test.h"






/*
 *  lwIP includes
 */

#include <stdio.h>
#include <unistd.h>
#include "system.h"
#include "sys/alt_sys_init.h"
#include "alt_types.h"

#include "lwip/init.h"
#include "lwip/netif.h"
#include "lwip/dhcp.h"
#include "lwip/tcp.h"
#include "lwip/tcp_impl.h"
#include "lwip/stats.h"
#include "lwip/ip_frag.h"
#include "lwip/ip_addr.h"
#include "netif/etharp.h"
#include "drivers/alteraTseEthernetif.h"

/*
 * lwIP #define and constants/variables
 */

#define mSdelay(x) usleep(x*1000)

//  Define USE_DHCP to 1 to use DHCP.  Otherwise a static IP must be defined
#define USE_DHCP 0
#if ! LWIP_DHCP
#error LWIP_DHCP must be enabled in lwipopts.h
#endif
#if ! USE_DHCP
#define STATIC_IP IP4_ADDR(&lwipStaticIp,172,24,11,32)  // Must be in this format (change the IP addr if needed)
struct ip_addr lwipStaticIp;
#endif

//  Define BUILD_HTTPD to 1 to build the httpserver_raw contrib example
#define BUILD_HTTPD 1

//  Alarm varibles
static uint32   lwip250mStimer;

//  Define netif for lwIP
struct netif    tseNetif;





/*
 *  APIエラーログマクロ
 *
 *  ErrorHookが有効の場合はErrorHookから
 *  エラーログを出力し, ErrorHookが無効の場合は
 *  以下のマクロよりエラーログ出力を行う
 */
#if defined(CFG_USE_ERRORHOOK)
#define error_log(api)  (api)
#else /* !defined( CFG_USE_ERRORHOOK ) */
#define error_log(api)                                         \
{                                                          \
    StatusType ercd;                                       \
    ercd = api;     /* 各API実行 */                           \
    if (ercd != E_OK) {                                    \
        syslog(LOG_INFO, "Error:%d", atk2_strerror(ercd)); \
    }                                                      \
}
#endif /* defined( CFG_USE_ERRORHOOK ) */

/*
 *  ユーザメイン関数
 *
 *  カーネル起動
 */
sint32
main(void)
{
    /*
     *  カーネル起動
     */
    StartOS(AppMode);

    while (1) {
    }
}   /* main */

/*
 *  lwIP main task
 */

TASK(USRV_TASK)
{
    //ATK2 debug purposes
    TaskType    tskid;
    GetTaskID(&tskid);

    static struct ip_addr   ip_zero = { 0 };
    void httpd_init(void);

    syslog(LOG_INFO, "lwIP Running...\n");
    
    //  Load platform specific MAC address into netif
    tseNetif.hwaddr[0] = 0x00;
    tseNetif.hwaddr[1] = 0x07;
    tseNetif.hwaddr[2] = 0xab;
    tseNetif.hwaddr[3] = 0xf0;
    tseNetif.hwaddr[4] = 0x0d;
    tseNetif.hwaddr[5] = 0xba;

    //  Initialize lwIP, Altera TSE and the ethernetif
    lwip_init();
    if(netif_add(&tseNetif, &ip_zero, &ip_zero, &ip_zero, tseNetif.state, ethernetif_init, ethernet_input) == NULL)
        {
        syslog(LOG_INFO, "Fatal error initializing...\n" );
        for(;;);
        }
    netif_set_default(&tseNetif);
    
    // Initialize Altera TSE in a loop if waiting for a link
    syslog(LOG_INFO, "Waiting for link...");
    while(((struct ethernetif *) tseNetif.state)->link_alive!=1)
        {
        mSdelay(1000);
        syslog(LOG_INFO, '.');
        tse_mac_init(0, tseNetif.state);
        }
    // Start lwIP callback alarm
    lwip250mStimer = 0;
    SetRelAlarm(LWIP_ALARM, TICK_FOR_10MS*25, TICK_FOR_10MS*25);
    syslog(LOG_INFO, "OK\n");
        
#if USE_DHCP
    dhcp_start(&tseNetif);
    //  Wait for DCHP
    syslog(LOG_INFO, "Waiting for DHCP IP address...");
    while(! netif_is_up(&tseNetif))
        {
        //  Poll lwIP for incoming packets.
        ethernetif_input(&tseNetif);
        }
#else
    STATIC_IP;
    netif_set_ipaddr(&tseNetif, &lwipStaticIp);
    netif_set_up(&tseNetif);
#endif
    syslog(LOG_INFO, "IP address: %s\n", ip_ntoa(&tseNetif.ip_addr));



#if BUILD_HTTPD
    httpd_init();
#endif
    //  This is the main loop for lwIP - other processing can be done by calling application functions.
    for(;;)
        {
        //  Poll lwIP for incoming packets.
        ethernetif_input(&tseNetif);
        }
    return 0;



    /*
     *  ここにはこない
     */
    syslog(LOG_INFO, "[USRV_TASK:%d] terminated.", tskid);
    error_log(TerminateTask());
}   /* TASK( MAIN_TASK ) */


//  Run this every 250ms to update lwIP timers
ALARMCALLBACK(LWIP_ALARM_CALLBACK)
{
    lwip250mStimer += 250;
    if( (lwip250mStimer % TCP_TMR_INTERVAL) == 0 ) { tcp_tmr(); }
    if( (lwip250mStimer % ARP_TMR_INTERVAL) == 0 ) { etharp_tmr(); }
#if IP_REASSEMBLY
    if( (lwip250mStimer % IP_TMR_INTERVAL) == 0 ) { ip_reass_tmr(); }
#endif
#if LWIP_AUTOIP
    if( (lwip250mStimer % AUTOIP_TMR_INTERVAL ) == 0 ) { autoip_tmr(); }
#endif
#if LWIP_IGMP
    if( (lwip250mStimer % IGMP_TMR_INTERVAL ) == 0 ) { igmp_tmr(); } 
#endif
#if LWIP_DHCP
    if( (lwip250mStimer % DHCP_FINE_TIMER_MSECS ) == 0 ) { dhcp_fine_tmr(); }
    if( (lwip250mStimer % (DHCP_COARSE_TIMER_SECS*1000) ) == 0 ) { dhcp_coarse_tmr(); }
#endif
#if LWIP_DNS
    if( (lwip250mStimer % DNS_TMR_INTERVAL) == 0 ) { dns_tmr(); }
#endif
}





/*
 *  エラーフックルーチン
 */
#ifdef CFG_USE_ERRORHOOK
void
ErrorHook(StatusType Error)
{
    /*
     *  エラー要因ごとのパラメータログ出力
     */
    switch (OSErrorGetServiceId()) {
    case OSServiceId_ActivateTask:
        syslog(LOG_INFO, "Error:%s=ActivateTask(%d)", atk2_strerror(Error), OSError_ActivateTask_TaskID());
        break;
    case OSServiceId_TerminateTask:
        syslog(LOG_INFO, "Error:%s=TerminateTask()", atk2_strerror(Error));
        break;
    case OSServiceId_ChainTask:
        syslog(LOG_INFO, "Error:%s=ChainTask(%d)", atk2_strerror(Error), OSError_ChainTask_TaskID());
        break;
    case OSServiceId_Schedule:
        syslog(LOG_INFO, "Error:%s=Schedule()", atk2_strerror(Error));
        break;
    case OSServiceId_GetTaskID:
        syslog(LOG_INFO, "Error:%s=GetTaskID(0x%p)", atk2_strerror(Error), OSError_GetTaskID_TaskID());
        break;
    case OSServiceId_GetTaskState:
        syslog(LOG_INFO, "Error:%s=GetTaskState(%d, 0x%p)", atk2_strerror(Error),
               OSError_GetTaskState_TaskID(), OSError_GetTaskState_State());
        break;
    case OSServiceId_EnableAllInterrupts:
        syslog(LOG_INFO, "Error:%s=EnableAllInterrupts()", atk2_strerror(Error));
        break;
    case OSServiceId_DisableAllInterrupts:
        syslog(LOG_INFO, "Error:%s=DisableAllInterrupts()", atk2_strerror(Error));
        break;
    case OSServiceId_ResumeAllInterrupts:
        syslog(LOG_INFO, "Error:%s=ResumeAllInterrupts()", atk2_strerror(Error));
        break;
    case OSServiceId_SuspendAllInterrupts:
        syslog(LOG_INFO, "Error:%s=SuspendAllInterrupts()", atk2_strerror(Error));
        break;
    case OSServiceId_ResumeOSInterrupts:
        syslog(LOG_INFO, "Error:%s=ResumeOSInterrupts()", atk2_strerror(Error));
        break;
    case OSServiceId_SuspendOSInterrupts:
        syslog(LOG_INFO, "Error:%s=SuspendOSInterrupts()", atk2_strerror(Error));
        break;
    case OSServiceId_GetISRID:
        syslog(LOG_INFO, "Error:%s=GetISRID()", atk2_strerror(Error));
        break;
    case OSServiceId_GetResource:
        syslog(LOG_INFO, "Error:%s=GetResource(%d)", atk2_strerror(Error), OSError_GetResource_ResID());
        break;
    case OSServiceId_ReleaseResource:
        syslog(LOG_INFO, "Error:%s=ReleaseResource(%d)", atk2_strerror(Error), OSError_ReleaseResource_ResID());
        break;
    case OSServiceId_SetEvent:
        syslog(LOG_INFO, "Error:%s=SetEvent(%d, 0x%x)", atk2_strerror(Error),
               OSError_SetEvent_TaskID(), OSError_SetEvent_Mask());
        break;
    case OSServiceId_ClearEvent:
        syslog(LOG_INFO, "Error:%s=ClearEvent(0x%x)", atk2_strerror(Error), OSError_ClearEvent_Mask());
        break;
    case OSServiceId_GetEvent:
        syslog(LOG_INFO, "Error:%s=GetEvent(%d, 0x%p)", atk2_strerror(Error),
               OSError_GetEvent_TaskID(), OSError_GetEvent_Event());
        break;
    case OSServiceId_WaitEvent:
        syslog(LOG_INFO, "Error:%s=WaitEvent(0x%x)", atk2_strerror(Error), OSError_WaitEvent_Mask());
        break;
    case OSServiceId_GetAlarmBase:
        syslog(LOG_INFO, "Error:%s=GetAlarmBase(0x%p)", atk2_strerror(Error), OSError_GetAlarmBase_AlarmID());
        break;
    case OSServiceId_GetAlarm:
        syslog(LOG_INFO, "Error:%s=GetAlarm(%d, 0x%p)", atk2_strerror(Error),
               OSError_GetAlarm_AlarmID(), OSError_GetAlarm_Tick());
        break;
    case OSServiceId_SetRelAlarm:
        syslog(LOG_INFO, "Error:%s=SetRelAlarm(%d, %d, %d)", atk2_strerror(Error),
               OSError_SetRelAlarm_AlarmID(), OSError_SetRelAlarm_increment(), OSError_SetRelAlarm_cycle());
        break;
    case OSServiceId_SetAbsAlarm:
        syslog(LOG_INFO, "Error:%s=SetAbsAlarm(%d, %d, %d)", atk2_strerror(Error),
               OSError_SetAbsAlarm_AlarmID(), OSError_SetAbsAlarm_start(), OSError_SetAbsAlarm_cycle());
        break;
    case OSServiceId_CancelAlarm:
        syslog(LOG_INFO, "Error:%s=CancelAlarm(%d)", atk2_strerror(Error), OSError_CancelAlarm_AlarmID());
        break;
    case OSServiceId_StartScheduleTableRel:
        syslog(LOG_INFO, "Error:%s=StartScheduleTableRel(%d, %d)", atk2_strerror(Error),
               OSError_StartScheduleTableRel_ScheduleTableID(), OSError_StartScheduleTableRel_Offset());
        break;
    case OSServiceId_StartScheduleTableAbs:
        syslog(LOG_INFO, "Error:%s=StartScheduleTableAbs(%d, %d)", atk2_strerror(Error),
               OSError_StartScheduleTableAbs_ScheduleTableID(), OSError_StartScheduleTableAbs_Start());
        break;
    case OSServiceId_StopScheduleTable:
        syslog(LOG_INFO, "Error:%s=StopScheduleTable(%d)", atk2_strerror(Error), OSError_StopScheduleTable_ScheduleTableID());
        break;
    case OSServiceId_NextScheduleTable:
        syslog(LOG_INFO, "Error:%s=NextScheduleTable(%d, %d)", atk2_strerror(Error),
               OSError_NextScheduleTable_ScheduleTableID_From(), OSError_NextScheduleTable_ScheduleTableID_To());
        break;
    case OSServiceId_GetScheduleTableStatus:
        syslog(LOG_INFO, "Error:%s=GetScheduleTableStatus(%d, 0x%p)", atk2_strerror(Error),
               OSError_GetScheduleTableStatus_ScheduleTableID(), OSError_GetScheduleTableStatus_ScheduleStatus());
        break;
    case OSServiceId_GetActiveApplicationMode:
        syslog(LOG_INFO, "Error:%s=GetActiveApplicationMode()", atk2_strerror(Error));
        break;
    case OSServiceId_StartOS:
        syslog(LOG_INFO, "Error:%s=StartOS()", atk2_strerror(Error));
        break;
    case OSServiceId_ShutdownOS:
        syslog(LOG_INFO, "Error:%s=ShutdownOS()", atk2_strerror(Error));
        break;
    case OSServiceId_IncrementCounter:
        syslog(LOG_INFO, "Error:%s=IncrementCounter(%d)", atk2_strerror(Error), OSError_IncrementCounter_CounterID());
        break;
    case OSServiceId_TaskMissingEnd:
        syslog(LOG_INFO, "Error:%s=MissingEnd()", atk2_strerror(Error));
        break;
    default:
        syslog(LOG_INFO, "Error:%s=UnKnownFunc()", atk2_strerror(Error));
        break;
}

}   /* ErrorHook */
#endif /* CFG_USE_ERRORHOOK */

/*
 *  プレタスクフックルーチン
 *
 *  空ルーチンを呼出す
 */
#ifdef CFG_USE_PRETASKHOOK
void
PreTaskHook(void)
{
}   /* PreTaskHook */
#endif /* CFG_USE_PRETASKHOOK */

/*
 *  ポストタスクフックルーチン
 *
 *  空ルーチンを呼出す
 */
#ifdef CFG_USE_POSTTASKHOOK
void
PostTaskHook(void)
{
}   /* PostTaskHook */
#endif /* CFG_USE_POSTTASKHOOK */

/*
 *  スタートアップフックルーチン
 */
#ifdef CFG_USE_STARTUPHOOK
#ifdef TOPPERS_ENABLE_SYS_TIMER
extern void target_timer_initialize(void);
#endif /* TOPPERS_ENABLE_SYS_TIMER */

void
StartupHook(void)
{
    #ifdef TOPPERS_ENABLE_SYS_TIMER
    target_timer_initialize();
    #endif /* TOPPERS_ENABLE_SYS_TIMER */
    syslog_initialize();
    syslog_msk_log(LOG_UPTO(LOG_INFO));
    alt_sys_init();
    InitSerial();
    print_banner();
}   /* StartupHook */
#endif /* CFG_USE_STARTUPHOOK */

/*
 *  シャットダウンフックルーチン
 */
#ifdef CFG_USE_SHUTDOWNHOOK
#ifdef TOPPERS_ENABLE_SYS_TIMER
extern void target_timer_terminate(void);
#endif /* TOPPERS_ENABLE_SYS_TIMER */

void
ShutdownHook(StatusType Error)
{
    /* 終了ログ出力 */
    syslog(LOG_INFO, "");
    syslog(LOG_INFO, "Sample System ShutDown");
    syslog(LOG_INFO, "ShutDownCode:%s", atk2_strerror(Error));
    syslog(LOG_INFO, "");

    if (Error == E_OS_SYS_ASSERT_FATAL) {
        syslog(LOG_INFO, "fatal_file_name:%s", fatal_file_name);
        syslog(LOG_INFO, "fatal_line_num:%d", fatal_line_num);
    }

    #ifdef TOPPERS_ENABLE_SYS_TIMER
    target_timer_terminate();
    #endif /* TOPPERS_ENABLE_SYS_TIMER */
    TermSerial();

}   /* ShutdownHook */
#endif /* CFG_USE_SHUTDOWNHOOK */

/*
 *  プロテクションフックルーチン
 */
#ifdef CFG_USE_PROTECTIONHOOK
ProtectionReturnType
ProtectionHook(StatusType FatalError)
{
    StatusType ercd;

    syslog(LOG_INFO, "");
    syslog(LOG_INFO, "ProtectionHook");

    if (FatalError == E_OS_STACKFAULT) {
        syslog(LOG_INFO, "E_OS_STACKFAULT");
        ercd = PRO_SHUTDOWN;
    }
    else if (FatalError == E_OS_PROTECTION_EXCEPTION) {
        syslog(LOG_INFO, "E_OS_PROTECTION_EXCEPTION");
        ercd = PRO_IGNORE;
    }
    else {
        ercd = PRO_SHUTDOWN;
    }

    return(ercd);
}
#endif /* CFG_USE_PROTECTIONHOOK */
