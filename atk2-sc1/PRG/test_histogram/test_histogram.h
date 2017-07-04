/*
 * UDP ECHO サーバのヘッダファイル
 */

#ifndef TOPPERS_TEST_HISTOGRAM_H
#define TOPPERS_TEST_HISTOGRAM_H

/*
 * UDP ECHO サーバ
 */

#define USRV_STACK_SIZE		4096		/* UDP ECHO サーバタスクのスタックサイズ		*/
#define USRV_MAIN_PRIORITY	5			/* UDP ECHO サーバタスクの優先度			*/

/*
 * Enable/Disable lwIP sample programs 
 */

// httpserver_raw contrib example
#define BUILD_HTTPD 0
// udp_echo sample program
#define BUILD_UDPECHO 1
// enable histrogram measure (benchmarking)
#define MEASURE_HISTOGRAM 1

// Expose these variables
#if MEASURE_HISTOGRAM
#define TNUM_HIST 10000
#include "t_syslog.h"
extern uint32   	histarea[1001];
extern ObjectIDType histid;
extern boolean      measuring_flg; 
#endif

#endif /* TOPPERS_TEST_HISTOGRAM_H */
