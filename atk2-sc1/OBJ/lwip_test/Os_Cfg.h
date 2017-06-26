/* Os_Cfg.h */
#ifndef TOPPERS_OS_CFG_H
#define TOPPERS_OS_CFG_H

/****** Scalability Class ******/

#define CFG_USE_SCALABILITYCLASS1

/****** Object OS ******/

#define CFG_USE_STACKMONITORING
#define CFG_USE_GETSERVICEID
#define CFG_USE_PARAMETERACCESS
#define CFG_USE_EXTENDEDSTATUS

/****** Object HOOK ******/

#define CFG_USE_STARTUPHOOK
#define CFG_USE_SHUTDOWNHOOK
#define CFG_USE_PRETASKHOOK
#define CFG_USE_POSTTASKHOOK
#define CFG_USE_ERRORHOOK
#define CFG_USE_PROTECTIONHOOK

#endif /* TOPPERS_OS_CFG_H */

