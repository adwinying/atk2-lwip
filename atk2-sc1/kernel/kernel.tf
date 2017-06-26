$
$  TOPPERS ATK2
$      Toyohashi Open Platform for Embedded Real-Time Systems
$      Automotive Kernel Version 2
$
$  Copyright (C) 2007 by TAKAGI Nobuhisa
$  Copyright (C) 2007-2015 by Center for Embedded Computing Systems
$              Graduate School of Information Science, Nagoya Univ., JAPAN
$  Copyright (C) 2011-2015 by FUJI SOFT INCORPORATED, JAPAN
$  Copyright (C) 2011-2013 by Spansion LLC, USA
$  Copyright (C) 2011-2015 by NEC Communication Systems, Ltd., JAPAN
$  Copyright (C) 2011-2015 by Panasonic Advanced Technology Development Co., Ltd., JAPAN
$  Copyright (C) 2011-2014 by Renesas Electronics Corporation, JAPAN
$  Copyright (C) 2011-2015 by Sunny Giken Inc., JAPAN
$  Copyright (C) 2011-2015 by TOSHIBA CORPORATION, JAPAN
$  Copyright (C) 2011-2015 by Witz Corporation
$  Copyright (C) 2014-2015 by AISIN COMCRUISE Co., Ltd., JAPAN
$  Copyright (C) 2014-2015 by eSOL Co.,Ltd., JAPAN
$  Copyright (C) 2014-2015 by SCSK Corporation, JAPAN
$
$  �嵭����Ԥϡ��ʲ���(1)��(4)�ξ������������˸¤ꡤ�ܥ��եȥ���
$  �����ܥ��եȥ���������Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ������
$  �ѡ������ۡʰʲ������ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
$  (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭������
$      ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ���
$      ����������˴ޤޤ�Ƥ��뤳�ȡ�
$  (2) �ܥ��եȥ������򡤥饤�֥������ʤɡ�¾�Υ��եȥ�������ȯ�˻�
$      �ѤǤ�����Ǻ����ۤ�����ˤϡ������ۤ�ȼ���ɥ�����ȡ�����
$      �ԥޥ˥奢��ʤɡˤˡ��嵭�����ɽ�����������Ѿ�浪��Ӳ���
$      ��̵�ݾڵ����Ǻܤ��뤳�ȡ�
$  (3) �ܥ��եȥ������򡤵�����Ȥ߹���ʤɡ�¾�Υ��եȥ�������ȯ�˻�
$      �ѤǤ��ʤ����Ǻ����ۤ�����ˤϡ����Τ����줫�ξ�����������
$      �ȡ�
$    (a) �����ۤ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭����
$        �ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
$    (b) �����ۤη��֤��̤�������ˡ�ˤ�äơ�TOPPERS�ץ������Ȥ�
$        ��𤹤뤳�ȡ�
$  (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
$      ������⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ����դ��뤳�ȡ�
$      �ޤ����ܥ��եȥ������Υ桼���ޤ��ϥ���ɥ桼������Τ����ʤ���
$      ͳ�˴�Ť����ᤫ��⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ�
$      ���դ��뤳�ȡ�
$
$  �ܥ��եȥ������ϡ�AUTOSAR��AUTomotive Open System ARchitecture�˻�
$  �ͤ˴�Ť��Ƥ��롥�嵭�ε����ϡ�AUTOSAR����Ū�⻺������������Τ�
$  �Ϥʤ���AUTOSAR�ϡ�AUTOSAR���ͤ˴�Ť������եȥ�����������Ū����
$  �Ѥ���Ԥ��Ф��ơ�AUTOSAR�ѡ��ȥʡ��ˤʤ뤳�Ȥ���Ƥ��롥
$
$  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ�
$  ���TOPPERS�ץ������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����λ�����Ū
$  ���Ф���Ŭ������ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ���
$  �������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤��
$  ����Ǥ�����ʤ���
$
$  $Id: kernel.tf 1801 2015-03-27 06:34:43Z t_ishikawa $
$

$TRACE("EXEC kernel.tf")$

$ XML�Υǡ�����¤�����꤬���뤫
$FATAL = 0$

$ =====================================================================
$ booleanȽ��ؿ�
$ =====================================================================

$FUNCTION IS_TRUE$
	$true_list = {1, "1", "true", "TRUE", "ON", "ENABLE"}$
	$false_list = {0, "0", "false", "FALSE", "OFF", "DISABLE"}$
	$error_flag = 1$
	
	$FOREACH false false_list$
		$IF EQ(false, ARGV[1])$
			$check_result = VALUE("FALSE", 0)$
			$error_flag = 0$
		$END$
	$END$
	$FOREACH true true_list$
		$IF EQ(true, ARGV[1])$
			$check_result = VALUE("TRUE", 1)$
			$error_flag = 0$
		$END$
	$END$

	$IF error_flag > 0$
		$ERROR ARGV[2]$$FORMAT(_("%1% must be boolean type"), ARGV[1])$$END$
	$END$

	$RESULT = check_result$
$END$

$ =====================================================================
$ HOOK.PROTECTIONHOOK���ʤ�����FALSE�������
$ =====================================================================

$IF !LENGTH(HOOK.PROTECTIONHOOK[1])$
	$HOOK.PROTECTIONHOOK[1] = VALUE("false", 0)$
$END$

$ =====================================================================
$ boolean�Ѵ�
$ =====================================================================

$OS.STACKMONITORING[1] = IS_TRUE(OS.STACKMONITORING[1], OS.TEXT_LINE[1])$
$OS.GETSERVICEID[1] = IS_TRUE(OS.GETSERVICEID[1], OS.TEXT_LINE[1])$
$OS.PARAMETERACCESS[1] = IS_TRUE(OS.PARAMETERACCESS[1], OS.TEXT_LINE[1])$
$HOOK.STARTUPHOOK[1] = IS_TRUE(HOOK.STARTUPHOOK[1], HOOK.TEXT_LINE[1])$
$HOOK.SHUTDOWNHOOK[1] = IS_TRUE(HOOK.SHUTDOWNHOOK[1], HOOK.TEXT_LINE[1])$
$HOOK.PRETASKHOOK[1] = IS_TRUE(HOOK.PRETASKHOOK[1], HOOK.TEXT_LINE[1])$
$HOOK.POSTTASKHOOK[1] = IS_TRUE(HOOK.POSTTASKHOOK[1], HOOK.TEXT_LINE[1])$
$HOOK.ERRORHOOK[1] = IS_TRUE(HOOK.ERRORHOOK[1], HOOK.TEXT_LINE[1])$
$HOOK.PROTECTIONHOOK[1] = IS_TRUE(HOOK.PROTECTIONHOOK[1], HOOK.TEXT_LINE[1])$
$FOREACH schtblid SCHTBL.ID_LIST$
	$SCHTBL.REPEAT[schtblid] = IS_TRUE(SCHTBL.REPEAT[schtblid],SCHTBL.TEXT_LINE[schtblid])$
$END$


$ =====================================================================
$ OSTK.STK���ʤ�����NULL�������
$ =====================================================================

$FOREACH ostkid OSTK.ID_LIST$
	$IF !LENGTH(OSTK.STK[ostkid])$
		$OSTK.STK[ostkid] = "NULL"$
	$END$
$END$


$ =====================================================================
$ TSK�Υ��顼�����å��ȴ�Ϣ�Ť�
$ =====================================================================

$TRACE("ASSOCIATE TASK")$

$ TSK.AUTOSTART��TSK�˥��ԡ�
$FOREACH aid TSK.AUTOSTART.ID_LIST$
	$tskid                = TSK.AUTOSTART.PARENT[aid]$
	$TSK.APP_LIST[tskid]  = TSK.AUTOSTART.APP_LIST[aid]$
$END$


$FOREACH tskid TSK.ID_LIST$
$   // ��ά���줿����NULL�ˤ���
	$IF !LENGTH(TSK.STK[tskid])$
		$TSK.STK[tskid] = "NULL"$
	$END$
$	// �����å��������Υǥե��������
	$IF !LENGTH(TSK.STKSZ[tskid])$
		$TSK.STKSZ[tskid] = DEFAULT_TASKSTKSZ$
	$END$
$END$


$ =====================================================================
$ ISR�Υ��顼�����å��ȴ�Ϣ�Ť�
$ =====================================================================

$TRACE("ASSOCIATE ISR")$

$FOREACH isrid ISR.ID_LIST$
	$IF LENGTH(ISR.INTATR[isrid])$
		$ISR.INTATR[isrid] = VALUE(CONCAT(ISR.INTATR[isrid], " | ENABLE"), ISR.INTATR[isrid] | ENABLE)$
	$ELSE$
		$ISR.INTATR[isrid] = ENABLE$
	$END$

	$IF EQ(ISR.CATEGORY[isrid], "CATEGORY_1")$
		$IF LENGTH(ISR.STKSZ[isrid])$
			$ERROR ISR.TEXT_LINE[isrid]$$FORMAT(_("OsIsrStackSize of C1ISR OsIsr(%1%) must not define"), isrid)$$END$
		$ELSE$
			$ISR.STKSZ[isrid] = 0$
		$END$
	$ELIF EQ(ISR.CATEGORY[isrid], "CATEGORY_2")$
		$IF LENGTH(ISR.STKSZ[isrid]) && (ISR.STKSZ[isrid] == 0)$
			$ERROR ISR.TEXT_LINE[isrid]$$FORMAT(_("OsIsrStackSize of C2ISR OsIsr(%1%) should not defined zero"), isrid)$$END$
		$END$
$		// C2ISR�����å��������Υǥե��������
		$IF !LENGTH(ISR.STKSZ[isrid])$
			$ISR.STKSZ[isrid] = DEFAULT_ISRSTKSZ$
		$END$
	$END$
$END$


$ =====================================================================
$ EVT�˴ؤ������
$ =====================================================================

$FOREACH evtid EVT.ID_LIST$
$	// �ޥ�������ά���줿����AUTO�ˤ���
	$IF !LENGTH(EVT.MASK[evtid])$
		$EVT.MASK[evtid] = AUTO$
	$END$
$END$


$ =====================================================================
$ CNT�˴ؤ������
$ =====================================================================

$FOREACH cntid CNT.ID_LIST$
	$IF EQ(CNT.CNTATR[cntid], "HARDWARE")$
		$IF !LENGTH(CNT.ISRID[cntid])$
			$FATAL = 1$
			$ERROR CNT.TEXT_LINE[cntid]$$FORMAT(_("OsCounterIsrRef of HARDWARE OsCounter(%1%) is not defined"), cntid)$$END$
		$END$

$		// NSPERTICK��SECONDSPERTICK����׻�����
		$IF LENGTH(CNT.SECONDSPERTICK[cntid])$
			$CNT.NSPERTICK[cntid] = CONCAT(CNT.SECONDSPERTICK[cntid], " * 1000000000")$
		$END$
	$END$

$END$


$ =====================================================================
$ ALM�˴ؤ������
$ =====================================================================

$TRACE("ASSOCIATE ALARM")$

$ ALM.AUTOSTART.*����ALM.*�˥��ԡ�
$FOREACH aid ALM.AUTOSTART.ID_LIST$
	$almid                              = ALM.AUTOSTART.PARENT[aid]$
	$ALM.APP_LIST[almid]                = ALM.AUTOSTART.APP_LIST[aid]$
	$ALM.ALARMTIME[almid]               = ALM.AUTOSTART.ALARMTIME[aid]$
	$ALM.CYCLETIME[almid]               = ALM.AUTOSTART.CYCLETIME[aid]$
	$ALM.AUTOSTARTTYPE[almid]           = ALM.AUTOSTART.TYPE[aid]$
$END$

$FOREACH almid ALM.ID_LIST$
	$ALM.ALMATR_COUNT[almid] = 0$
$END$

$ ALM.ACTION.ACTIVATETASK.*����ALM.*�˥��ԡ�
$FOREACH almactid ALM.ACTION.ACTIVATETASK.ID_LIST$
	$almid                      = ALM.ACTION.PARENT[ALM.ACTION.ACTIVATETASK.PARENT[almactid]]$
	$ALM.ALMATR[almid]          = "ACTIVATETASK"$
	$ALM.TSKID[almid]           = ALM.ACTION.ACTIVATETASK.TSKID[almactid]$
	$ALM.ALMATR_COUNT[almid]    = ALM.ALMATR_COUNT[almid] + 1$
$END$

$ ALM.ACTION.SETEVENT.*����ALM.*�˥��ԡ�
$FOREACH almactid ALM.ACTION.SETEVENT.ID_LIST$
	$almid                      = ALM.ACTION.PARENT[ALM.ACTION.SETEVENT.PARENT[almactid]]$
	$ALM.ALMATR[almid]          = "SETEVENT"$
	$ALM.TSKID[almid]           = ALM.ACTION.SETEVENT.TSKID[almactid]$
	$ALM.EVTID[almid]           = ALM.ACTION.SETEVENT.EVTID[almactid]$
	$ALM.ALMATR_COUNT[almid]    = ALM.ALMATR_COUNT[almid] + 1$
$END$

$ ALM.ACTION.CALLBACK.*����ALM.*�˥��ԡ�
$FOREACH almactid ALM.ACTION.CALLBACK.ID_LIST$
	$almid                         = ALM.ACTION.PARENT[ALM.ACTION.CALLBACK.PARENT[almactid]]$
	$ALM.ALMATR[almid]             = "CALLBACK"$
	$ALM.CALLBACK[almid]           = ALM.ACTION.CALLBACK.CALLBACK[almactid]$
	$ALM.ALMATR_COUNT[almid]       = ALM.ALMATR_COUNT[almid] + 1$
$END$

$ ALM.ACTION.INCREMENTCOUNTER.*����ALM.*�˥��ԡ�
$FOREACH almactid ALM.ACTION.INCREMENTCOUNTER.ID_LIST$
	$almid                      = ALM.ACTION.PARENT[ALM.ACTION.INCREMENTCOUNTER.PARENT[almactid]]$
	$ALM.ALMATR[almid]          = "INCREMENTCOUNTER"$
	$ALM.INCID[almid]           = ALM.ACTION.INCREMENTCOUNTER.INCID[almactid]$
	$ALM.ALMATR_COUNT[almid]    = ALM.ALMATR_COUNT[almid] + 1$
$END$

$ ALM.ACTION.*��2�İʾ�������Ƥ��ʤ���
$FOREACH almid ALM.ID_LIST$
	$IF ALM.ALMATR_COUNT[almid] != 1$
		$FATAL = 1$
		$ERROR ALM.TEXT_LINE[almid]$$FORMAT(_("OsAlarmAction of OsAlarm(%1%) have too many sub container"), almid)$$END$
	$END$
$END$


$ =====================================================================
$ SCHTBL�˴ؤ������
$ =====================================================================

$TRACE("ASSOCIATE SCHTBL")$

$ ��ά���줿����NONE�ˤ���
$FOREACH schtblid SCHTBL.ID_LIST$
	$SCHTBL.SYNCSTRATEGY[schtblid] = "NONE"$
$END$

$ SCHTBL.AUTOSTART.*����SCHTBL.*�˥��ԡ�
$FOREACH aid SCHTBL.AUTOSTART.ID_LIST$
	$schtblid                                 = SCHTBL.AUTOSTART.PARENT[aid]$
	$SCHTBL.APP_LIST[schtblid]                = SCHTBL.AUTOSTART.APP_LIST[aid]$
	$IF LENGTH(SCHTBL.AUTOSTART.STARTTICK[aid])$
		$SCHTBL.STARTTICK[schtblid]           = SCHTBL.AUTOSTART.STARTTICK[aid]$
	$ELSE$
$		// ��ά���줿���Ȥ򼨤�
		$SCHTBL.STARTTICK[schtblid]           = "NULL"$
	$END$
	$SCHTBL.AUTOSTARTTYPE[schtblid]           = SCHTBL.AUTOSTART.TYPE[aid]$
$END$

$FOREACH syncid SCHTBL.SYNC.ID_LIST$
	$schtblid = SCHTBL.SYNC.PARENT[syncid]$
	$SCHTBL.SYNCSTRATEGY[schtblid] = SCHTBL.SYNC.STRATEGY[syncid]$
$END$


$ =====================================================================
$ EXPPTACT�˴ؤ������
$ =====================================================================

$ SCHTBL.EXPPT.ACTIVATETASK.*����EXPPTACT�˥��ԡ�
$i = 0$
$FOREACH acttskid SCHTBL.EXPPT.ACTIVATETASK.ID_LIST$
	$expid                          = SCHTBL.EXPPT.ACTIVATETASK.PARENT[acttskid]$
	$schtblid                       = SCHTBL.EXPPT.PARENT[expid]$

	$EXPPTACT.SCHTBLID[i]           = schtblid$
	$EXPPTACT.OFFSET[i]             = SCHTBL.EXPPT.OFFSET[expid]$
	$EXPPTACT.TSKID[i]              = SCHTBL.EXPPT.ACTIVATETASK.TSKID[acttskid]$
	$EXPPTACT.EXPIREATR[i]          = "ACTIVATETASK"$

	$EXPPTACT.ID_LIST               = APPEND(EXPPTACT.ID_LIST, i)$
	$i                              = i + 1$
$END$

$ SCHTBL.EXPPT.SETEVENT.*����EXPPTACT�˥��ԡ�
$FOREACH setevid SCHTBL.EXPPT.SETEVENT.ID_LIST$
	$expid                          = SCHTBL.EXPPT.SETEVENT.PARENT[setevid]$
	$schtblid                       = SCHTBL.EXPPT.PARENT[expid]$

	$EXPPTACT.SCHTBLID[i]           = schtblid$
	$EXPPTACT.OFFSET[i]             = SCHTBL.EXPPT.OFFSET[expid]$
	$EXPPTACT.TSKID[i]              = SCHTBL.EXPPT.SETEVENT.TSKID[setevid]$
	$EXPPTACT.EVTID[i]              = SCHTBL.EXPPT.SETEVENT.EVTID[setevid]$
	$EXPPTACT.EXPIREATR[i]          = "SETEVENT"$

	$EXPPTACT.ID_LIST               = APPEND(EXPPTACT.ID_LIST, i)$
	$i                              = i + 1$
$END$

$IF FATAL$
	$DIE()$
$END$


$ =====================================================================
$ OS�Υ��顼�����å�
$ =====================================================================

$IF !(EQ(OS.STATUS[1], "EXTENDED") || EQ(OS.STATUS[1], "STANDARD"))$
	$ERROR OS.TEXT_LINE[1]$$FORMAT(_("OsStatus must be STANDARD or EXTENDED"))$$END$
$END$

$IF LENGTH(OS.SC[1]) && !EQ(OS.SC[1], "SC1")$
	$ERROR OS.TEXT_LINE[1]$$FORMAT(_("OsScalabilityClass must be SC1"))$$END$
$END$


$ =====================================================================
$ �������δ�Ϣ�Ť�
$ =====================================================================

$FOREACH tskid TSK.ID_LIST$
$	// TSK��RES�δ�Ϣ�Ť�
	$FOREACH resid TSK.RES_LIST[tskid]$
		$RES.TSK_LIST[resid] = APPEND(RES.TSK_LIST[resid], tskid)$
	$END$
$	// TSK��EVT�δ�Ϣ�Ť�
	$FOREACH evtid TSK.EVT_LIST[tskid]$
		$EVT.TSK_LIST[evtid] = APPEND(EVT.TSK_LIST[evtid], tskid)$
	$END$
$END$


$ =====================================================================
$ ISR��Ϣ�Υ��顼�����å��������ǡ���������
$ =====================================================================

$TRACE("ISR CHECK")$

$FOREACH isrid ISR.ID_LIST$
$	// INTNO��¾��ISR�Ƚ�ʣ���Ƥ�����
	$FOREACH isrid2 ISR.ID_LIST$
		$IF ISR.INTNO[isrid] == ISR.INTNO[isrid2] && isrid2 < isrid$
			$ERROR ISR.TEXT_LINE[isrid]$$FORMAT(_("OsIsrInterruptNumber(%1%) of OsIsr(%2%) is duplicated"), ISR.INTNO[isrid], isrid)$$END$
		$END$
	$END$

$	// intpri�������ͥ���٤Ȥ����������ʤ����
	$IF (ISR.INTPRI[isrid] > TNUM_INTPRI) || (ISR.INTPRI[isrid] < 1)$
		$ERROR ISR.TEXT_LINE[isrid]$$FORMAT(_("illegal OsIsrInterruptPriority(%1%) of OsIsr(%2%)"), ISR.INTPRI[isrid], isrid)$$END$
	$END$

	$IF !(EQ(ISR.CATEGORY[isrid], "CATEGORY_1") || EQ(ISR.CATEGORY[isrid], "CATEGORY_2"))$
		$ERROR ISR.TEXT_LINE[isrid]$$FORMAT(_("OsIsrCategory of OsIsr(%1%) must be CATEGORY_1 or CATEGORY_2"), isrid)$$END$
	$END$

$	// ISR��RES�δ�Ϣ�Ť�
	$FOREACH resid ISR.RES_LIST[isrid]$
		$RES.ISR_LIST[resid] = APPEND(RES.ISR_LIST[resid], isrid)$
	$END$
$END$


$ C2ISR�κ���ͥ����
$MAX_PRI_ISR2 = -1$
$ C2ISR�κǹ�ͥ����
$MIN_PRI_ISR2 = MAX_PRI_ISR2$

$i = 0$
$FOREACH isrid ISR.ID_LIST$
	$IF EQ(ISR.CATEGORY[isrid], "CATEGORY_2")$
		$ISR.ID[isrid] = i$
		$i = i + 1$
		$ISR2.ID_LIST = APPEND(ISR2.ID_LIST, isrid)$
		$IF MIN_PRI_ISR2 > -ISR.INTPRI[isrid]$
			$MIN_PRI_ISR2 = -ISR.INTPRI[isrid]$
		$END$
		$ISR.INT_ENTRY[isrid] = CONCAT("_kernel_inthdr_", +ISR.INTNO[isrid])$

$		// INTNO��������ֹ�Ȥ����������ʤ����
		$IF !LENGTH(FIND(INTNO_CREISR2_VALID, ISR.INTNO[isrid]))$
			$ERROR ISR.TEXT_LINE[isrid]$$FORMAT(_("illegal OsIsrInterruptNumber(%1%) of OsIsr(%2%)"), ISR.INTNO[isrid], isrid)$$END$
		$END$
	$END$
$END$

$ C2ISR���������Ƥ��ʤ����
$IF !LENGTH(ISR2.ID_LIST)$
	$MAX_PRI_ISR2 = 0$
	$MIN_PRI_ISR2 = 0$
$END$


$ C1ISR�κ���ͥ����
$MAX_PRI_ISR1 = MIN_PRI_ISR2 - 1$
$ C1ISR�κǹ�ͥ����
$MIN_PRI_ISR1 = -TNUM_INTPRI$

$FOREACH isrid ISR.ID_LIST$
	$IF EQ(ISR.CATEGORY[isrid], "CATEGORY_1")$
		$ISR1.ID_LIST = APPEND(ISR1.ID_LIST, isrid)$
		$ISR.ID[isrid] = i$
		$i = i + 1$

$		// C1ISR�γ����ͥ���٤�MIN_PRI_ISR2�ʾ�Ǥ�����
		$IF -ISR.INTPRI[isrid] >= MIN_PRI_ISR2$
			$ERROR ISR.TEXT_LINE[isrid]$$FORMAT(_("OsIsrInterruptPriority(%1%) of OsIsr(%2%) is lower than or equal to C2ISR min priority(%3%)"), ISR.INTPRI[isrid], isrid, -MIN_PRI_ISR2)$$END$
		$END$
		$ISR.INT_ENTRY[isrid] = CONCAT("C1ISRMain", isrid)$

$		// INTNO��������ֹ�Ȥ����������ʤ����
		$IF !LENGTH(FIND(INTNO_VALID, ISR.INTNO[isrid]))$
			$ERROR ISR.TEXT_LINE[isrid]$$FORMAT(_("illegal OsIsrInterruptNumber(%1%) of OsIsr(%2%)"), ISR.INTNO[isrid], isrid)$$END$
		$END$
	$END$
$END$


$ ISR.ID_LIST��C2ISR, C1ISR�ν���ˤ���
$ISR.ID_LIST = APPEND(ISR2.ID_LIST, ISR1.ID_LIST)$


$FOREACH isrid ISR1.ID_LIST$
$	// C1ISR�ϥ꥽����������Ǥ��ʤ�
	$IF LENGTH(ISR.RES_LIST[isrid])$
		$ERROR ISR.TEXT_LINE[isrid]$$FORMAT(_("C1ISR(%1%) can't use RESOURCE"), isrid)$$END$
	$END$
$END$


$FOREACH isrid ISR2.ID_LIST$
$	// ISR�������꥽����������Ǥ��ʤ�
$	// ��󥯥꥽������ɸ��꥽�����˥�󥯤����ΤǤ��뤿���󥯥꥽�����Ǥ���Х��顼�Ȥ��롥

	$FOREACH resid ISR.RES_LIST[isrid]$
		$IF EQ(RES.RESATR[resid], "INTERNAL") || EQ(RES.RESATR[resid], "LINKED")$
			$ERROR ISR.TEXT_LINE[isrid]$$FORMAT(_("OsIsrResourceRef(%1%) of OsIsr(%2%) must be standard resource"), resid, isrid)$$END$
		$END$
	$END$
$END$


$ =====================================================================
$ �꥽������Ϣ�Υ��顼�����å��������ǡ���������
$ =====================================================================

$TRACE("RESOURCE CHECK")$

$FOREACH resid RES.ID_LIST$
$	// ��Ϣ�դ��ե饰�ν����(�꥽�������ɤΥ�����/C2ISR�ˤ��Ϣ�դ�����Ƥ��ʤ���硤warning���Ϥ������֥������Ȥ��������ʤ�)
	$RES.RELATION_FLAG[resid] = (LENGTH(RES.TSK_LIST[resid]) || LENGTH(RES.ISR_LIST[resid]))$
$END$


$FOREACH resid RES.ID_LIST$
	$resatr = RES.RESATR[resid]$
$	// resatr�����ƥ����å���"STANDARD","INTERNAL","LINKED"�ʳ��ʤ饨�顼��
	$IF !(EQ(resatr, "STANDARD") || EQ(resatr, "INTERNAL") || EQ(resatr, "LINKED"))$
		$ERROR RES.TEXT_LINE[resid]$$FORMAT(_("OsResourceProperty of OsResource(%1%) must be STANDARD or INTERNAL or LINKED"), resid)$$END$
	$END$

	$IF EQ(RES.RESATR[resid], "LINKED")$
		$lnkresid = RES.LINKEDRESID[resid]$

		$IF !LENGTH(lnkresid)$
			$ERROR RES.TEXT_LINE[resid]$$FORMAT(_("OsResourceLinkedResourceRef of OsResource(%1%) is not defined"), resid)$$END$
			$DIE()$
		$END$

		$RES.RELATION_FLAG[resid] = RES.RELATION_FLAG[lnkresid]$

$		// ����¦��°����ɸ��꥽��������
		$IF !EQ(RES.RESATR[lnkresid], "STANDARD")$
			$ERROR RES.TEXT_LINE[resid]$$FORMAT(_("OsResourceLinkedResourceRef(%1%) of OsResource(%2%) must be standard resource"), lnkresid, resid)$$END$
		$END$
	$END$

	$IF !RES.RELATION_FLAG[resid]$
		$WARNING RES.TEXT_LINE[resid]$$FORMAT(_("OsResource(%1%) is not related to any TASK or ISR"), resid)$$END$
	$END$
$END$


$
$ �꥽������OS�������Ѥ���ID�������Ƥ�
$ �����꥽�����ʳ�(ɸ�ࡤ���)����ID�������Ƥ�
$
$i = 0$
$tnum_intres = 0$
$new_id_list = {}$
$FOREACH resid RES.ID_LIST$
	$IF !EQ(RES.RESATR[resid], "INTERNAL") && RES.RELATION_FLAG[resid]$
		$RES.ID[resid] = i$
		$i = i + 1$
		$new_id_list = APPEND(new_id_list, resid)$
	$END$
$END$
$STDRES.ID_LIST = new_id_list$
$FOREACH resid RES.ID_LIST$
	$IF EQ(RES.RESATR[resid], "INTERNAL") && RES.RELATION_FLAG[resid]$
		$RES.ID[resid] = i$
		$i = i + 1$
		$tnum_intres = tnum_intres + 1$
		$new_id_list = APPEND(new_id_list, resid)$
	$END$
$END$
$RES.ID_LIST = new_id_list$


$FOREACH resid RES.ID_LIST$
	$IF !EQ(RES.RESATR[resid], "LINKED")$

$		// �꥽�����ξ��ͥ���٤η׻�(������)
		$ceilpri = 0$
		$FOREACH tskid RES.TSK_LIST[resid]$
			$tskpri = TSK.PRIORITY[tskid]$
			$IF ceilpri < tskpri$
				$ceilpri = tskpri$
			$END$
		$END$
		$RES.CEILPRI[resid] = ceilpri$

$		// �꥽�����ξ��ͥ���٤η׻�(ISR)
$		// ISR��ͥ���٤�-1���Ȥ��Ƥ���
		$ceilpri = 0$
		$FOREACH isrid RES.ISR_LIST[resid]$
			$intpri = -ISR.INTPRI[isrid]$
			$IF ceilpri > intpri$
				$ceilpri = intpri$
			$END$
		$END$

$		// ISR���Ѥ���꥽�����ξ��Τ߹���
		$IF ceilpri < 0$
			$RES.CEILPRI[resid] = ceilpri$
		$END$
	$END$
$END$


$FOREACH resid RES.ID_LIST$
$	// ��󥯥꥽�����ξ��ͥ���٤�����
	$IF EQ(RES.RESATR[resid], "LINKED")$
		$RES.CEILPRI[resid] = RES.CEILPRI[RES.LINKEDRESID[resid]]$
	$END$
$END$



$ =====================================================================
$ ���ץꥱ�������⡼�ɤΥ��顼�����å�
$ =====================================================================

$ APP
$ ���ץꥱ�������⡼�ɤ�32�İʲ�����
$IF LENGTH(APP.ID_LIST) > 32$
	$ERROR$$FORMAT(_("too many OsAppMode %1% > 32"), LENGTH(APP.ID_LIST))$$END$
$END$

$i = 0$
$FOREACH appid APP.ID_LIST$
	$APP.ID[appid] = i$
	$i = i + 1$
$END$


$ =====================================================================
$ ��������Ϣ�Υ��顼�����å��������ǡ���������
$ =====================================================================

$TRACE("TASK CHECK")$

$FOREACH tskid TSK.ID_LIST$
	$TSK.EXTENDED[tskid] = LENGTH(TSK.EVT_LIST[tskid]) > 0$

$	// �����꥽��������������硤��������ͥ���٤�����
	$FOREACH resid TSK.RES_LIST[tskid]$
		$IF EQ(RES.RESATR[resid], "INTERNAL")$
			$TSK.INRESPRI[tskid] = RES.CEILPRI[resid]$
		$END$
	$END$

$	// ��������AUTOSTART�ε�ư�ѥ�����
	$astptn = 0$
	$FOREACH appid TSK.APP_LIST[tskid]$
		$astptn = astptn | (1 << APP.ID[appid])$
	$END$
	$TSK.ASTPTN[tskid] = astptn$

$	// �������˴�Ϣ�դ����줿���٥�ȥޥ�����OR��Ȥ�(AUTO��0�Ƿ׻�)
	$TSK.EVTMSK[tskid] = 0$

	$FOREACH evtid TSK.EVT_LIST[tskid]$
		$TSK.EVTMSK[tskid] = TSK.EVTMSK[tskid] | EVT.MASK[evtid]$
	$END$


	$tskpri = TSK.PRIORITY[tskid]$
	$tskext = TSK.EXTENDED[tskid]$
	$tskact = TSK.ACTIVATION[tskid]$
	$tsksch = TSK.SCHEDULE[tskid]$

$	// priority���ϰϥ����å�
	$IF (tskpri < TMIN_TPRI) || (TMAX_TPRI < tskpri)$
		$ERROR TSK.TEXT_LINE[tskid]$$FORMAT(_("OsTaskPriority(%1%) of OsTask(%2%) is a range error"), tskpri, tskid)$$END$
	$END$

$	// activation���ϰϥ����å�
	$IF !tskext$
		$IF (tskact == 0) || (256 < tskact)$
			$ERROR TSK.TEXT_LINE[tskid]$$FORMAT(_("OsTaskActivation(%1%) of OsTask(%2%) is a range error"), tskact, tskid)$$END$
		$END$
	$ELSE$
		$IF (tskact != 1)$
			$ERROR TSK.TEXT_LINE[tskid]$$FORMAT(_("OsTaskActivation(%1%) of OsTask(%2%) must be 1"), tskact, tskid)$$END$
		$END$
	$END$

$	// schedule�����ƥ����å���"NON","FULL"�ʳ��ʤ饨�顼��
	$IF !(EQ(tsksch, "NON") || EQ(tsksch, "FULL"))$
		$ERROR TSK.TEXT_LINE[tskid]$$FORMAT(_("OsTaskSchedule of OsTask(%1%) must be NON or FULL"), tskid)$$END$
	$END$

	$intres_flag = 0$

	$FOREACH resid TSK.RES_LIST[tskid]$
		$IF EQ(RES.RESATR[resid], "INTERNAL")$

$			// �������ˤϺ���1�Ĥ������꥽��������������Ƥ��ʤ����ᡤ
$			// �����꥽������2�İʾ������Ƥ����ϥ��顼�Ȥ��롥

$			// ������Ƥ��꥽�����������꥽�����ʤ��ǧ�ѥե饰�򥻥åȤ��롥
$			// �����꥽������ǧ�ѥե饰�����Ǥ˥��åȤ���Ƥ����饨�顼�Ȥ��롥
			$IF intres_flag == 0$
				$intres_flag = 1$
			$ELSE$
				$ERROR TSK.TEXT_LINE[tskid]$$FORMAT(_("too many assigned internal resource OsTaskResourceRef(%1%) of OsTask(%2%)"), resid, tskid)$$END$
			$END$

$			// �����꥽�������Υ�ץꥨ��ץƥ��֤Υ������ȴ�Ϣ�դ����Ƥ����饨�顼�Ȥ��롥
			$IF EQ(TSK.SCHEDULE[tskid], "NON")$
				$ERROR TSK.TEXT_LINE[tskid]$$FORMAT(_("internal resource OsTaskResourceRef(%1%) of OsTask(%2%) can't be assign to a nonpreemptable task"), resid, tskid)$$END$
			$END$
		$END$

$		// ��󥯥꥽������ɸ��꥽�����˥�󥯤����ΤǤ��뤿��
$		// ��󥯥꥽�����Ǥ���Х��顼�Ȥ��롥
		$IF EQ(RES.RESATR[resid], "LINKED")$
			$ERROR TSK.TEXT_LINE[tskid]$$FORMAT(_("OsTaskResourceRef(%1%) of OsTask(%2%) is linked resource"), resid, tskid)$$END$
		$END$
	$END$
$END$


$
$ ��������OS�������Ѥ���ID�������Ƥ�
$ ��ĥ����������ID�������Ƥ�
$
$i = 0$
$tnum_exttask = 0$
$new_id_list = {}$
$FOREACH tskid TSK.ID_LIST$
	$IF TSK.EXTENDED[tskid]$
		$TSK.ID[tskid] = i$
		$i = i + 1$
		$tnum_exttask = tnum_exttask + 1$
		$new_id_list = APPEND(new_id_list, tskid)$
	$END$
$END$
$FOREACH tskid TSK.ID_LIST$
	$IF !TSK.EXTENDED[tskid]$
		$TSK.ID[tskid] = i$
		$i = i + 1$
		$new_id_list = APPEND(new_id_list, tskid)$
	$END$
$END$
$TSK.ID_LIST = new_id_list$



$ =====================================================================
$ ���٥�ȥޥ����ͷ���
$ =====================================================================

$TRACE("EVENT CHECK")$

$auto_evt_msk = 1$
$auto_evt_num = 0$
$FOREACH evtid EVT.ID_LIST$
$	//�ޥ����ͻ���ͭ
	$IF !EQ(EVT.MASK[evtid], AUTO)$
		$IF (EVT.MASK[evtid] == 0)$
			$ERROR EVT.TEXT_LINE[evtid]$$FORMAT(_("OsEventMask of OsEvent(%1%) must not be zero"), evtid)$$END$
			$DIE()$
		$END$
		$EVT.CALC_MASK[evtid] = EVT.MASK[evtid]$
$	//�ޥ����ͻ���̵
	$ELSE$
		$EVT.CALC_MASK[evtid] = 0$
$		//�������˴�Ϣ�դ�ͭ
		$IF LENGTH(EVT.TSK_LIST[evtid])$
			$hit_flg = 0$
			$auto_tskevt_msk = 1$
			$FOREACH i RANGE(1, 32)$
				$IF !hit_flg$
					$ok_flg = 1$
					$FOREACH tskid EVT.TSK_LIST[evtid]$
						$IF (TSK.EVTMSK[tskid] & auto_tskevt_msk) != 0$
							$ok_flg = 0$
						$END$
					$END$

$					//���������Ƕ����ӥå�ȯ��
					$IF ok_flg$
						$hit_flg = 1$
						$FOREACH tskid EVT.TSK_LIST[evtid]$
							$TSK.EVTMSK[tskid] = TSK.EVTMSK[tskid] | auto_tskevt_msk$
						$END$
						$EVT.CALC_MASK[evtid] = auto_tskevt_msk$
					$ELSE$
						$auto_tskevt_msk = auto_tskevt_msk << 1$
					$END$
				$END$
			$END$
$			//�����ӥåȤʤ�
			$IF !hit_flg$
				$ERROR EVT.TEXT_LINE[evtid]$$FORMAT(_("Auto OsEventMask of OsEvent(%1%) is no free"), evtid)$$END$
				$DIE()$
			$END$
$		//�������˴�Ϣ�դ�̵
		$ELSE$
			$IF auto_evt_num > 31$
				$ERROR EVT.TEXT_LINE[evtid]$$FORMAT(_("Auto OsEventMask of OsEvent(%1%) is over(32)"))$$END$
				$DIE()$
			$END$
			$EVT.CALC_MASK[evtid] = auto_evt_msk$
			$auto_evt_msk = auto_evt_msk << 1$
			$auto_evt_num = auto_evt_num + 1$
		$END$
	$END$
$END$
$NL$



$ =====================================================================
$ �����󥿴�Ϣ�Υ��顼�����å��������ǡ���������
$ =====================================================================

$TRACE("COUNTER CHECK")$


$FOREACH cntid CNT.ID_LIST$
$	// �����󥿤�°����SOFTWARE / HARDWARE�������å�
	$IF !(EQ(CNT.CNTATR[cntid], "SOFTWARE") || EQ(CNT.CNTATR[cntid], "HARDWARE"))$
		$ERROR CNT.TEXT_LINE[cntid]$$FORMAT(_("OsCounterType of OsCounter(%1%) must be SOFTWARE or HARDWARE"), cntid)$$END$
	$END$
$END$


$
$ �����󥿤�OS�������Ѥ���ID�������Ƥ�
$ �ϡ��ɥ����������󥿤���ID�������Ƥ�
$
$i = 0$
$new_id_list = {}$
$FOREACH cntid CNT.ID_LIST$
	$IF EQ(CNT.CNTATR[cntid], "HARDWARE")$
		$CNT.ID[cntid] = i$
		$i = i + 1$
		$new_id_list = APPEND(new_id_list, cntid)$
	$END$
$END$
$FOREACH cntid CNT.ID_LIST$
	$IF EQ(CNT.CNTATR[cntid], "SOFTWARE")$
		$CNT.ID[cntid] = i$
		$i = i + 1$
		$new_id_list = APPEND(new_id_list, cntid)$
	$END$
$END$
$CNT.ID_LIST = new_id_list$


$HWCNT.ID_LIST = {}$
$FOREACH cntid CNT.ID_LIST$
	$cnttpb = CNT.TICKSPERBASE[cntid]$
	$cntmin = CNT.MINCYCLE[cntid]$
	$cntmax = CNT.MAXALLOWED[cntid]$

$	// ticksperbase���ϰϳ�ǧ
	$IF (cnttpb < 1) || (cnttpb > 0x7fffffff)$
		$ERROR CNT.TEXT_LINE[cntid]$$FORMAT(_("OsCounterTicksPerBase(%1%) of OsCounter(%2%) is a range error"), cnttpb, cntid)$$END$
	$END$

$	// mincycle���ϰϳ�ǧ
	$IF (cntmin < 1) || (cntmin > 0x7fffffff)$
		$ERROR CNT.TEXT_LINE[cntid]$$FORMAT(_("OsCounterMinCycle(%1%) of OsCounter(%2%) is a range error"), cntmin, cntid)$$END$
	$END$

$	// maxallowedvalue���ϰϳ�ǧ
	$IF (cntmax < 1) || (cntmax > 0x7fffffff)$
		$ERROR CNT.TEXT_LINE[cntid]$$FORMAT(_("OsCounterMaxAllowedValue(%1%) of OsCounter(%2%) is a range error"), cntmax, cntid)$$END$
	$END$

$	// mincycle��maxallowedvalue����礭������
	$IF cntmax < cntmin$
		$ERROR CNT.TEXT_LINE[cntid]$$FORMAT(_("OsCounterMinCycle(%1%) of OsCounter(%2%) is more than OsCounterMaxAllowedValue(%3%)"), cntmin, cntid, cntmax)$$END$
	$END$

$	// �ϡ��ɥ����������󥿤�ISR��CATEGORY_2�������å�
	$IF EQ(CNT.CNTATR[cntid], "HARDWARE")$
		$IF EQ(ISR.CATEGORY[CNT.ISRID[cntid]], "CATEGORY_2")$
			$HWCNT.ID_LIST = APPEND(HWCNT.ID_LIST, cntid)$
		$ELSE$
			$ERROR CNT.TEXT_LINE[cntid]$$FORMAT(_("OsCounterIsrRef(%1%) of OsCounter(%2%) is C1ISR"), CNT.ISRID[cntid], cntid)$$END$
		$END$
	$END$
$END$



$ =====================================================================
$ ���顼���Ϣ�Υ��顼�����å��������ǡ���������
$ =====================================================================

$TRACE("ALARM CHECK")$

$i = 0$
$FOREACH almid ALM.ID_LIST$

$	// ���顼���AUTOSTART�ε�ư�ѥ�����
	$astptn = 0$
	$FOREACH appid ALM.APP_LIST[almid]$
		$astptn = astptn | (1 << APP.ID[appid])$
	$END$
	$ALM.ASTPTN[almid] = astptn$

$	// ID������
	$ALM.ID[almid] = i$
	$i = i + 1$

$	// ���ץꥱ�������⡼�����ꤷ�����Τߡ����顼����ư�ƥ��å��ͤȼ�����Ŭ����������å�
	$IF ALM.ASTPTN[almid]$
$		// ���顼����ư�ƥ��å��ͤϡ������󥿺����ͤ�Ķ���뤫������0��꾮������
		$IF CNT.MAXALLOWED[ALM.CNTID[almid]] < ALM.ALARMTIME[almid] || ALM.ALARMTIME[almid] < 0$
			$ERROR ALM.TEXT_LINE[almid]$$FORMAT(_("OsAlarmAlarmTime(%1%) of OsAlarm(%2%) must be in the range 0 .. OsCounterMaxAllowedValue(%3%)"), 
													ALM.ALARMTIME[almid], almid, CNT.MAXALLOWED[ALM.CNTID[almid]])$$END$
		$END$

$		// ���顼������ϡ������󥿺����ͤ�Ķ���뤫��0��꾮�������������󥿤κǾ�������꾮����(0�����)��
		$IF CNT.MAXALLOWED[ALM.CNTID[almid]] < ALM.CYCLETIME[almid] || ALM.CYCLETIME[almid] < 0 ||
			(ALM.CYCLETIME[almid] < CNT.MINCYCLE[ALM.CNTID[almid]] && ALM.CYCLETIME[almid] != 0)$
			$ERROR ALM.TEXT_LINE[almid]$$FORMAT(_("OsAlarmCycleTime(%1%) of OsAlarm(%2%) must be zero OR in the range OsCounterMinCycle(%3%) .. OsCounterMaxAllowedValue(%4%)"), 
											ALM.CYCLETIME[almid], almid, CNT.MINCYCLE[ALM.CNTID[almid]], CNT.MAXALLOWED[ALM.CNTID[almid]])$$END$
		$END$

$		// autostarttype��ABSOLUTE/RELATIVE�ʳ��Τ�Τ���Ͽ����Ƥ��ʤ���
		$IF !(EQ(ALM.AUTOSTARTTYPE[almid], "ABSOLUTE") || EQ(ALM.AUTOSTARTTYPE[almid], "RELATIVE"))$
			$ERROR ALM.TEXT_LINE[almid]$$FORMAT(_("OsAlarmAutostartType of OsAlarm(%1%) must be ABSOLUTE or RELATIVE"), almid)$$END$
		$END$

$		// autostarttype��RELATIVE�ξ���STARTTICK==0�϶ػ�
		$IF EQ(ALM.AUTOSTARTTYPE[almid], "RELATIVE") && ALM.ALARMTIME[almid] == 0$
			$ERROR ALM.TEXT_LINE[almid]$$FORMAT(_("OsAlarmAlarmTime of RELATIVE OsAlarm(%1%) must not be zero"), almid)$$END$
		$END$
	$END$

$	// task����ĥ��������(SETEVENT�ξ��)
	$IF EQ(ALM.ALMATR[almid], "SETEVENT")$
		$IF !TSK.EXTENDED[ALM.TSKID[almid]]$
			$ERROR ALM.TEXT_LINE[almid]$$FORMAT(_("OsAlarmSetEventTaskRef(%1%) of OsAlarm(%2%) is not extended task"), ALM.TSKID[almid], almid)$$END$
		$END$
	$END$

	$IF EQ(ALM.ALMATR[almid], "INCREMENTCOUNTER")$
$		// ���顼�फ��ϡ��ɥ����������󥿤򥤥󥯥���Ȥ��Ƥ��뤫�����å�
		$IF EQ(CNT.CNTATR[ALM.INCID[almid]], "HARDWARE")$
			$ERROR ALM.TEXT_LINE[almid]$$FORMAT(_("OsAlarmIncrementCounterRef(%1%) of OsAlarm(%2%) is hardware counter"), ALM.INCID[almid], almid)$$END$
		$END$
	$END$
$END$


$
$ IncrementCounter�ν۴ĥ����å��Τ���δؿ�
$

$ ����γݤ���
$FUNCTION MATRIX_MUL$
	$FOREACH i RANGE(0, matrix_size - 1)$
		$FOREACH j RANGE(0, matrix_size - 1)$
			$result = {}$
			$FOREACH k RANGE(0, matrix_size - 1)$
				$IF LENGTH(result) == 0$
					$IF LENGTH(result_matrix[i * matrix_size + k]) && LENGTH(base_matrix[k * matrix_size + j])$
						$result = APPEND(result_matrix[i * matrix_size + k], base_matrix[k * matrix_size + j])$
					$END$
				$END$
			$END$
$			// �ݤ�����̤���������ݻ�
			$tmp_matrix[i * matrix_size + j] = result$
		$END$
	$END$
$	// �ݤ�����̤��̹���˥��å�
	$FOREACH i RANGE(0, matrix_size - 1)$
		$FOREACH j RANGE(0, matrix_size - 1)$
			$result_matrix[i * matrix_size + j] = tmp_matrix[i * matrix_size + j]$
		$END$
	$END$
$END$


$ �����0�����
$ base_matrix   �������
$ result_matrix �ݤ����η�̤ι���
$FUNCTION INIT_MATRIX$
	$FOREACH almid ALM.ID_LIST$
		$IF EQ(ALM.ALMATR[almid], "INCREMENTCOUNTER")$
			$i = ALM.CNTID[almid] - 1$
			$j = ALM.INCID[almid] - 1$
			$IF !LENGTH(base_matrix[i * matrix_size + j])$
				$base_matrix[i * matrix_size + j] = {almid}$
				$result_matrix[i * matrix_size + j] = {almid}$
			$END$
		$END$
	$END$
$END$


$ ���顼��ν۴ĥꥹ�Ȥ�Ǿ�ID�Υ��顼�ब��Ƭ�ˤʤ�褦�˥��ơ��Ȥ�����
$ �ޤ����۴ĥꥹ�Ȥ˽�ʣ�������顼�ब�ޤޤ�Ƥ������ʣ�������顼��ʹߤ�
$ �ꥹ�Ȥ��������
$FUNCTION ROTATE_LOOPED_ALARM$
$	// �ؿ����i��Ȥ���������
	$tmp_i = i$
	$alm_list = ARGV[1]$
	$size = LENGTH(alm_list)$
$	// �ꥹ����ǤΥ��顼��ID�κǾ���
	$min_alm_id = AT(alm_list, 0)$
	$min_alm_id_index = 0$
	$FOREACH i RANGE(1, size - 1)$
		$IF min_alm_id > AT(alm_list, i)$
			$min_alm_id = AT(alm_list, i)$
			$min_alm_id_index = i$
		$END$
	$END$
	$RESULT = {}$
$	// ��ʣ�������顼��ID��¸�ߤ��뤫
	$duplicate = 0$
	$FOREACH i RANGE(0, size - 1)$
		$append_alm = AT(alm_list, (min_alm_id_index + i) % size)$
		$IF LENGTH(FIND(RESULT, append_alm)) > 0$
$			// ��ʣ�������顼�ब����Ф���ʹߤ��ɲä��ʤ�
			$duplicate = 1$
		$END$
		$IF duplicate == 0$
			$RESULT = APPEND(RESULT, append_alm)$
		$END$
	$END$
	$i = tmp_i$
$END$


$FUNCTION CHECK_COUNTER_LOOP$
	$matrix_size = LENGTH(CNT.ID_LIST)$

	$INIT_MATRIX()$

$	// �۴ĥ��顼��ꥹ�ȤΥꥹ��
	$alm_loop_list_size = 0$

$	// �롼�פθ��Фȥ��顼����
	$FOREACH n RANGE(0,  matrix_size - 1)$
		$FOREACH i RANGE(0,  matrix_size - 1)$
			$IF LENGTH(result_matrix[i * matrix_size + i]) > 0$
				$result_matrix[i * matrix_size + i] = ROTATE_LOOPED_ALARM(result_matrix[i * matrix_size + i])$
				$find = 0$
				$FOREACH ii RANGE(0, alm_loop_list_size - 1)$
$	 				// ���˸��Ф����ꥹ�Ȥ˴ޤޤ�뤫Ĵ�٤�
					$IF EQ(alm_loop_list[ii], result_matrix[i * matrix_size + i])$
						$find = 1$
					$END$
				$END$
				$IF find == 0$
					$alm_loop_list[alm_loop_list_size] = result_matrix[i * matrix_size + i]$
					$alm_loop_list_size = alm_loop_list_size + 1$
					$ERROR ALM.TEXT_LINE[AT(result_matrix[i * matrix_size + i], 0)]$
								$FORMAT(_("OsAlarmIncrementCounterRef of OsAlarm(%1%) is a cyclic chain of alarm action"), result_matrix[i * matrix_size + i])$$END$
				$END$
			$END$
		$END$
		$MATRIX_MUL()$
	$END$
$END$


$ ľ��/����Ū�˥����󥿡��򥤥󥯥���Ȥ��뤫(INCREMENTCOUNTER�ξ��)
$ �桼���إå���OMIT_CHECK_CYCLIC_CHAIN�����������С����顼��۴ĥ����å���Ԥ�ʤ�
$IF !OMIT_CHECK_CYCLIC_CHAIN$
	$CHECK_COUNTER_LOOP()$
$END$



$ =====================================================================
$ �������塼��ơ��֥��Ϣ�Υ��顼�����å��������ǡ���������
$ =====================================================================

$TRACE("SCHEDULETABLE CHECK")$

$FOREACH schtblid SCHTBL.ID_LIST$
$	// Ʊ����ˡ�����ͥ����å�
$	// syncstrategy��NONE/IMPLICIT�����줫��Ĥ����ꤵ��Ƥ��뤫
	$IF !(EQ(SCHTBL.SYNCSTRATEGY[schtblid], "NONE") || EQ(SCHTBL.SYNCSTRATEGY[schtblid], "IMPLICIT"))$
		$ERROR SCHTBL.TEXT_LINE[schtblid]$
				$FORMAT(_("OsScheduleTblSyncStrategy of OsScheduleTable(%1%) must be NONE or IMPLICIT"), schtblid)$$END$
	$END$
$END$


$ �ƥ������塼��ơ��֥�ID�����(����Ʊ��������衤��Ʊ������ϸ�)
$i = 0$
$ �������塼�������֥�å��������˻��Ѥ������դ��ꥹ���ѿ�
$new_id_list = {}$
$FOREACH schtblid SCHTBL.ID_LIST$
	$IF EQ(SCHTBL.SYNCSTRATEGY[schtblid], "IMPLICIT")$
		$SCHTBL.ID[schtblid] = i$
		$i = i + 1$
		$new_id_list = APPEND(new_id_list, schtblid)$
	$END$
$END$
$FOREACH schtblid SCHTBL.ID_LIST$
	$IF EQ(SCHTBL.SYNCSTRATEGY[schtblid], "NONE")$
		$SCHTBL.ID[schtblid] = i$
		$i = i + 1$
		$new_id_list = APPEND(new_id_list, schtblid)$
	$END$
$END$
$NL$
$SCHTBL.ID_LIST = new_id_list$


$exppt_index = 0$
$EXPPT.ID_LIST = {}$
$FOREACH expptactid EXPPTACT.ID_LIST$
$	// ��λ����������°������λ��������������������������������å�
$	// task����ĥ��������(SETEVENT�ξ��)
	$IF EQ(EXPPTACT.EXPIREATR[expptactid], "SETEVENT")$
		$IF !TSK.EXTENDED[EXPPTACT.TSKID[expptactid]]$
			$ERROR EXPPTACT.TEXT_LINE[expptactid]$
						$FORMAT(_("OsScheduleTableSetEventTaskRef(%1%) of OsScheduleTableExpiryPoint(%2%) is not extended task"), EXPPTACT.TSKID[expptactid], expptactid)$$END$
		$END$
	$END$

	$schtblid = EXPPTACT.SCHTBLID[expptactid]$
	$FOREACH expptid EXPPT.ID_LIST$
		$IF EXPPT.OFFSET[expptid] == EXPPTACT.OFFSET[expptactid] &&
			EXPPTACT.SCHTBLID[expptactid] == EXPPT.SCHTBLID[expptid]$
			$EXPPTACT.EXPPTID[expptactid] = expptid$
		$END$
	$END$

$	// ��λ������������ȥ������塼��ơ��֥�Ȥδ�Ϣ�դ�
	$IF !LENGTH(EXPPTACT.EXPPTID[expptactid])$
		$EXPPT.ID_LIST = APPEND(EXPPT.ID_LIST, exppt_index)$
		$EXPPT.SCHTBLID[exppt_index] = schtblid$
		$EXPPT.OFFSET[exppt_index] = EXPPTACT.OFFSET[expptactid]$
		$SCHTBL.EXPPTINDEX_LIST[schtblid] = APPEND(SCHTBL.EXPPTINDEX_LIST[schtblid], exppt_index)$
		$EXPPTACT.EXPPTID[expptactid] = exppt_index$

$		��λ���Υ��ե��åȤ��������塼��ơ��֥�μ�����Ķ�����������å�
		$IF EXPPT.OFFSET[exppt_index] > SCHTBL.DURATIONTICK[schtblid]$
			$ERROR EXPPTACT.TEXT_LINE[expptactid]$
						$FORMAT(_("OsScheduleTblExpPointOffset(%1%) of OsScheduleTableExpiryPoint(%2%) of OsScheduleTable(%3%) more than OsScheduleTableDuration(%4%)"), 
							EXPPTACT.OFFSET[expptactid], expptactid, schtblid, SCHTBL.DURATIONTICK[schtblid])$$END$
		$END$
		$exppt_index = exppt_index + 1$
	$END$
$END$


$ ���ۥ������塼�륫��������ѿ�
$tnum_implscheduletable = 0$

$FOREACH schtblid SCHTBL.ID_LIST$
$	// EXPPTINDEX_LIST��OFFSET�ν�˥����Ȥ���
	$SCHTBL.EXPPTINDEX_LIST[schtblid] = SORT(SCHTBL.EXPPTINDEX_LIST[schtblid], "EXPPT.OFFSET")$

	$astptn = 0$
	$FOREACH appid SCHTBL.APP_LIST[schtblid]$
		$astptn = astptn | (1 << APP.ID[appid])$
	$END$
	$SCHTBL.ASTPTN[schtblid] = astptn$

$	// ���ץꥱ�������⡼�����ꤷ�����Τߡ����ư�ƥ��å��ͤ�����å�
	$IF SCHTBL.ASTPTN[schtblid]$

		$IF !(EQ(SCHTBL.AUTOSTARTTYPE[schtblid], "ABSOLUTE") || EQ(SCHTBL.AUTOSTARTTYPE[schtblid], "RELATIVE"))$
$			// autostarttype��ABSOLUTE/RELATIVE�ʳ��Τ�Τ���Ͽ����Ƥ��ʤ���
			$ERROR SCHTBL.TEXT_LINE[schtblid]$$FORMAT(_("OsScheduleTableAutostartType of OsScheduleTable(%1%) must be ABSOLUTE or RELATIVE"), schtblid)$$END$
		$ELIF EQ(SCHTBL.STARTTICK[schtblid], "NULL")$
$			// ���ư�ƥ��å��ͤ���ά���줿����
			$ERROR SCHTBL.TEXT_LINE[schtblid]$$FORMAT(_("OsScheduleTableStartValue(%1%) of %2% AutoStart OsScheduleTable(%3%) must be designated"),
													SCHTBL.STARTTICK[schtblid], SCHTBL.AUTOSTARTTYPE[schtblid], schtblid)$$END$
			$DIE()$
		$END$

$		// ���ư�ƥ��å��ͤϡ������󥿺����ͤ�Ķ���뤫������0��꾮������
		$IF CNT.MAXALLOWED[SCHTBL.CNTID[schtblid]] < SCHTBL.STARTTICK[schtblid] || SCHTBL.STARTTICK[schtblid] < 0$
			$ERROR SCHTBL.TEXT_LINE[schtblid]$$FORMAT(_("OsScheduleTableStartValue(%1%) of OsScheduleTable(%2%) must be in the range 0 .. OsCounterMaxAllowedValue(%3%)"), 
													SCHTBL.STARTTICK[schtblid], schtblid, CNT.MAXALLOWED[SCHTBL.CNTID[schtblid]])$$END$
		$END$

		$IF EQ(SCHTBL.AUTOSTARTTYPE[schtblid], "RELATIVE")$
$			// autostarttype��RELATIVE�ξ���STARTTICK==0�϶ػ�
			$IF SCHTBL.STARTTICK[schtblid] == 0$
				$ERROR SCHTBL.TEXT_LINE[schtblid]$$FORMAT(_("OsScheduleTableStartValue of RELATIVE OsScheduleTable(%1%) must not be zero"), schtblid)$$END$
			$END$

$			//���ۥ������塼��ơ��֥��autostarttype��RELATIVE�����ꤵ��Ƥ��뤫
			$IF EQ(SCHTBL.SYNCSTRATEGY[schtblid], "IMPLICIT")$
				$ERROR SCHTBL.TEXT_LINE[schtblid]$$FORMAT(_("OsScheduleTableAutostartType of IMPLICIT OsScheduleTable(%1%) must not be RELATIVE"), schtblid)$$END$
			$END$
		$END$
	$END$

$	//��λ����254��Ķ���뤫�����å�
	$IF LENGTH(SCHTBL.EXPPTINDEX_LIST[schtblid]) > 254$
		$ERROR SCHTBL.TEXT_LINE[schtblid]$
					$FORMAT(_("too many OsScheduleTableExpiryPoint of OsScheduleTable(%1%) %2% > 254"), schtblid, LENGTH(SCHTBL.EXPPTINDEX_LIST[schtblid]))$$END$
	$ELSE$
		$previous_exp_expptid = AT(SCHTBL.EXPPTINDEX_LIST[schtblid], 0)$

$		// ������ե��åȤϡ�0����³�����󥿤κǾ������������ͤ��ˤʤ�ɬ�פ�����
		$IF EXPPT.OFFSET[previous_exp_expptid] != 0 && (EXPPT.OFFSET[previous_exp_expptid] < CNT.MINCYCLE[SCHTBL.CNTID[schtblid]] ||
												 EXPPT.OFFSET[previous_exp_expptid] > CNT.MAXALLOWED[SCHTBL.CNTID[schtblid]])$
			$ERROR EXPPT.TEXT_LINE[previous_exp_expptid]$
							$FORMAT(_("The Initial Offset(%1%) of OsScheduleTable(%2%) must be zero OR in the range OsCounterMinCycle(%3%) .. OsCounterMaxAllowedValue(%4%)"), 
								EXPPT.OFFSET[previous_exp_expptid], schtblid, CNT.MINCYCLE[SCHTBL.CNTID[schtblid]], CNT.MAXALLOWED[SCHTBL.CNTID[schtblid]])$$END$
		$END$

$		// ����λ���֤��ٱ��ͤϡ���³�����󥿤κǾ������������ͤ��ˤʤ�ɬ�פ�����
		$FOREACH exp_expptid SCHTBL.EXPPTINDEX_LIST[schtblid]$
			$IF previous_exp_expptid != exp_expptid$
				$IF (EXPPT.OFFSET[exp_expptid] - EXPPT.OFFSET[previous_exp_expptid] < CNT.MINCYCLE[SCHTBL.CNTID[schtblid]]) ||
					(EXPPT.OFFSET[exp_expptid] - EXPPT.OFFSET[previous_exp_expptid] > CNT.MAXALLOWED[SCHTBL.CNTID[schtblid]])$
					$ERROR EXPPT.TEXT_LINE[exp_expptid]$
						$FORMAT(_("The delay of OsScheduleTable(%1%) between OsScheduleTblExpPointOffset(%2% and %3%) must be in the range OsCounterMinCycle(%4%) .. OsCounterMaxAllowedValue(%5%)"),
							schtblid, EXPPT.OFFSET[previous_exp_expptid], EXPPT.OFFSET[exp_expptid], CNT.MINCYCLE[SCHTBL.CNTID[schtblid]], CNT.MAXALLOWED[SCHTBL.CNTID[schtblid]])$$END$
				$END$
				$previous_exp_expptid = exp_expptid$
			$END$
		$END$

$		// �ǽ��ٱ��ͤϡ���³�����󥿤κǾ������������ͤ��ˤʤ�ɬ�פ������ñȯ�ξ��0����������
		$IF ((SCHTBL.DURATIONTICK[schtblid] - EXPPT.OFFSET[previous_exp_expptid] < CNT.MINCYCLE[SCHTBL.CNTID[schtblid]]) ||
			(SCHTBL.DURATIONTICK[schtblid] - EXPPT.OFFSET[previous_exp_expptid] > CNT.MAXALLOWED[SCHTBL.CNTID[schtblid]])) &&
			!(SCHTBL.DURATIONTICK[schtblid] - EXPPT.OFFSET[previous_exp_expptid] == 0 && SCHTBL.REPEAT[schtblid] != 1)$
			$ERROR EXPPT.TEXT_LINE[previous_exp_expptid]$
						$FORMAT(_("Final Delay(%1%) of OsScheduleTable(%2%) must be in the range OsCounterMinCycle(%3%) .. OsCounterMaxAllowedValue(%4%), and allow zero when single-shot"), 
							(SCHTBL.DURATIONTICK[schtblid] - EXPPT.OFFSET[previous_exp_expptid]), schtblid, CNT.MINCYCLE[SCHTBL.CNTID[schtblid]], CNT.MAXALLOWED[SCHTBL.CNTID[schtblid]])$$END$
		$END$
	$END$

$	// ���ۥ������塼��ơ��֥�Υ������
	$IF EQ(SCHTBL.SYNCSTRATEGY[schtblid], "IMPLICIT")$
		$tnum_implscheduletable = tnum_implscheduletable + 1$

$		���ۥ������塼��ơ��֥�μ����ϡ���ư������Ⱥ�����+1�������å�
		$IF SCHTBL.DURATIONTICK[schtblid] != CNT.MAXALLOWED[SCHTBL.CNTID[schtblid]] + 1$
			$ERROR SCHTBL.TEXT_LINE[schtblid]$$FORMAT(_("OsScheduleTableDuration(%1%) of IMPLICIT OsScheduleTable(%2%) must be OsCounterMaxAllowedValue(%3%) + 1"), 
													SCHTBL.DURATIONTICK[schtblid], schtblid, CNT.MAXALLOWED[SCHTBL.CNTID[schtblid]])$$END$
		$END$
	$END$

$END$


$ =====================================================================
$ Os_Cfg_tmp.h������ Os_Cfg.h�Ⱥ�ʬ��������Makefile��Os_Cfg.h�إ��ԡ�
$ =====================================================================

$TRACE("OUTPUT FILES")$

$FILE "Os_Cfg_tmp.h"$
/* Os_Cfg.h */$NL$
#ifndef TOPPERS_OS_CFG_H$NL$
#define TOPPERS_OS_CFG_H$NL$
$NL$

/****** Scalability Class ******/$NL$$NL$

#define CFG_USE_SCALABILITYCLASS1$NL$
$NL$

/****** Object OS ******/$NL$$NL$
$IF OS.STACKMONITORING[1]$
	#define CFG_USE_STACKMONITORING$NL$
$END$

$IF OS.GETSERVICEID[1]$
	#define CFG_USE_GETSERVICEID$NL$
$END$

$IF OS.PARAMETERACCESS[1]$
	#define CFG_USE_PARAMETERACCESS$NL$
$END$

$IF EQ(OS.STATUS[1], "EXTENDED")$
	#define CFG_USE_EXTENDEDSTATUS$NL$
$END$

$USE_HOOK = 0$

$NL$
/****** Object HOOK ******/$NL$$NL$
$IF HOOK.STARTUPHOOK[1]$
	#define CFG_USE_STARTUPHOOK$NL$
	$USE_HOOK = 1$
$END$

$IF HOOK.SHUTDOWNHOOK[1]$
	#define CFG_USE_SHUTDOWNHOOK$NL$
	$USE_HOOK = 1$
$END$

$IF HOOK.PRETASKHOOK[1]$
	#define CFG_USE_PRETASKHOOK$NL$
	$USE_HOOK = 1$
$END$

$IF HOOK.POSTTASKHOOK[1]$
	#define CFG_USE_POSTTASKHOOK$NL$
	$USE_HOOK = 1$
$END$

$IF HOOK.ERRORHOOK[1]$
	#define CFG_USE_ERRORHOOK$NL$
	$USE_HOOK = 1$
$END$

$IF HOOK.PROTECTIONHOOK[1]$
	#define CFG_USE_PROTECTIONHOOK$NL$
	$USE_HOOK = 1$
$END$

$NL$
#endif /* TOPPERS_OS_CFG_H */$NL$


$ =====================================================================
$ Os_Lcfg.h������
$ =====================================================================

$FILE "Os_Lcfg.h"$
/* Os_Lcfg.h */$NL$
#ifndef TOPPERS_OS_LCFG_H$NL$
#define TOPPERS_OS_LCFG_H$NL$
$NL$

$
$ ���֥������ȿ��ޥ���ν���
$
#define TNUM_ALARM				UINT_C($LENGTH(ALM.ID_LIST)$)$NL$
#define TNUM_COUNTER			UINT_C($LENGTH(CNT.ID_LIST)$)$NL$
#define TNUM_HARDCOUNTER		UINT_C($LENGTH(HWCNT.ID_LIST)$)$NL$
#define TNUM_ISR2				UINT_C($LENGTH(ISR2.ID_LIST)$)$NL$
#define TNUM_STD_RESOURCE		UINT_C($LENGTH(STDRES.ID_LIST)$)$NL$
#define TNUM_TASK				UINT_C($LENGTH(TSK.ID_LIST)$)$NL$
#define TNUM_EXTTASK			UINT_C($tnum_exttask$)$NL$
#define TNUM_APP_MODE			UINT_C($LENGTH(APP.ID_LIST)$)$NL$
#define TNUM_SCHEDULETABLE		UINT_C($LENGTH(SCHTBL.ID_LIST)$)$NL$
#define TNUM_IMPLSCHEDULETABLE	UINT_C($tnum_implscheduletable$)$NL$
$NL$

/*$NL$
$SPC$*  Default Definitions of Trace Log Macros$NL$
$SPC$*/$NL$
$NL$
#ifndef TOPPERS_ENABLE_TRACE$NL$
#ifndef LOG_USER_MARK$NL$
#define LOG_USER_MARK(str)$NL$
#endif /* LOG_USER_MARK */$NL$
#endif /* TOPPERS_ENABLE_TRACE */$NL$
$NL$
 /****** Object TASK ******/$NL$$NL$

$ ��������ID�ν���
$FOREACH tskid TSK.ID_LIST$
	#define $tskid$$TAB$UINT_C($TSK.ID[tskid]$)$NL$
$END$
$NL$

 /****** Object COUNTER ******/$NL$$NL$

$ ������ID�ν���

$FOREACH cntid CNT.ID_LIST$
	#define $cntid$$TAB$UINT_C($CNT.ID[cntid]$)$NL$
$END$
$NL$

$ �����󥿥��֥������Ȥ�OS����ν���
$FOREACH cntid CNT.ID_LIST$
	#define OSMAXALLOWEDVALUE_$cntid$$TAB$((TickType) $+CNT.MAXALLOWED[cntid]$)$NL$
	#define OSTICKSPERBASE_$cntid$$TAB$((TickType) $+CNT.TICKSPERBASE[cntid]$)$NL$
	#define OSMINCYCLE_$cntid$$TAB$((TickType) $+CNT.MINCYCLE[cntid]$)$NL$
$END$
$NL$

$ �ƥ��å��ͤ�����֤ؤ��Ѵ��ޥ���(PhysicalTimeType�η���float,double�Τ����줫������)
$FOREACH cntid HWCNT.ID_LIST$
	$IF LENGTH(CNT.NSPERTICK[cntid])$
		#define OS_TICKS2SEC_$cntid$(tick)$TAB$(((PhysicalTimeType)$CNT.NSPERTICK[cntid]$) * (tick) / 1000000000U)$NL$
		#define OS_TICKS2MS_$cntid$(tick)$TAB$(((PhysicalTimeType)$CNT.NSPERTICK[cntid]$) * (tick) / 1000000U)$NL$
		#define OS_TICKS2US_$cntid$(tick)$TAB$(((PhysicalTimeType)$CNT.NSPERTICK[cntid]$) * (tick) / 1000U)$NL$
		#define OS_TICKS2NS_$cntid$(tick)$TAB$(((PhysicalTimeType)$CNT.NSPERTICK[cntid]$) * (tick))$NL$
	$END$
	$NL$
$END$

 /****** Object ALARM ******/$NL$$NL$

$ ���顼��ID�ν���
$FOREACH almid ALM.ID_LIST$
	#define $almid$$TAB$UINT_C($ALM.ID[almid]$)$NL$
$END$
$NL$

 /****** Object SCHEDULETABLE ******/$NL$$NL$

$ �������塼��ơ��֥�ID�ν���
$FOREACH schtblid SCHTBL.ID_LIST$
	#define $schtblid$$TAB$UINT_C($SCHTBL.ID[schtblid]$)$NL$
$END$
$NL$

 /****** Object RESOURCE ******/$NL$$NL$

$ �꥽����ID�ν���
$FOREACH resid RES.ID_LIST$
	#define $resid$$TAB$UINT_C($RES.ID[resid]$)$NL$
$END$
$NL$

 /****** Object ISR ******/$NL$$NL$

$ ISR��ID�ν���
$FOREACH isrid ISR.ID_LIST$
	#define $isrid$$TAB$UINT_C($ISR.ID[isrid]$)$NL$
$END$
$NL$

 /****** Object APPMODE ******/$NL$$NL$

$FOREACH appid APP.ID_LIST$
	#define $appid$$TAB$UINT_C($APP.ID[appid]$)$NL$
$END$
$NL$

$ ���٥�Ȥν���
 /****** Object EVENT ******/$NL$
$FOREACH evtid EVT.ID_LIST$
	#define $evtid$$TAB$UINT_C($FORMAT("0x%08x", +EVT.CALC_MASK[evtid])$)$NL$
$END$
$NL$

$NL$


$ =====================================================================
$ Os_Lcfg.c������
$ =====================================================================
$FILE "Os_Lcfg.c"$

/* Os_Lcfg.c */$NL$
#include "kernel/kernel_int.h"$NL$
#include "Os_Lcfg.h"$NL$
$NL$
#ifndef TOPPERS_EMPTY_LABEL$NL$
#define TOPPERS_EMPTY_LABEL(x, y) x y[0]$NL$
#endif$NL$
$NL$

$
$  �ȥ졼�����ޥ���Υǥե�������
$
/*$NL$
$SPC$*  Default Definitions of Trace Log Macros$NL$
$SPC$*/$NL$
$NL$
#ifndef LOG_ISR_ENTER$NL$
#define LOG_ISR_ENTER(isrid)$NL$
#endif /* LOG_ISR_ENTER */$NL$
$NL$
#ifndef LOG_ISR_LEAVE$NL$
#define LOG_ISR_LEAVE(isrid)$NL$
#endif /* LOG_ISR_LEAVE */$NL$
$NL$

$
$  ���󥯥롼�ɥǥ��쥯�ƥ��֡�#include��
$
/*$NL$
$SPC$*  Include Directives (#include)$NL$
$SPC$*/$NL$
$NL$
$INCLUDES$
$NL$

$
$ ���֥������ȿ��ѿ��ν���
$
const AlarmType					tnum_alarm				= TNUM_ALARM;$NL$
const CounterType				tnum_counter			= TNUM_COUNTER;$NL$
const CounterType				tnum_hardcounter		= TNUM_HARDCOUNTER;$NL$
const ISRType					tnum_isr2				= TNUM_ISR2;$NL$
const ResourceType				tnum_stdresource		= TNUM_STD_RESOURCE;$NL$
const TaskType					tnum_task				= TNUM_TASK;$NL$
const TaskType					tnum_exttask			= TNUM_EXTTASK;$NL$
const AppModeType				tnum_appmode			= TNUM_APP_MODE;$NL$
const ScheduleTableType			tnum_scheduletable		= TNUM_SCHEDULETABLE;$NL$
const ScheduleTableType			tnum_implscheduletable	= TNUM_IMPLSCHEDULETABLE;$NL$
$NL$

$
$ ���֥��������ѿ��ν���
$

$IF USE_EXTERNAL_ID$

	$NL$
	/****** Object ID ******/$NL$
	$NL$

$ 	// ��������ID�ν���
	$FOREACH tskid TSK.ID_LIST$
		const TaskType $tskid$_id = $tskid$;$NL$
	$END$
	$NL$

$	// ������ID�ν���
	$FOREACH cntid CNT.ID_LIST$
		const CounterType $cntid$_id = $cntid$;$NL$
	$END$
	$NL$

$	// ���顼��ID�ν���
	$FOREACH almid ALM.ID_LIST$
		const AlarmType $almid$_id = $almid$;$NL$
	$END$
	$NL$

$	// �꥽����ID�ν���
	$FOREACH resid RES.ID_LIST$
		const ResourceType $resid$_id = $resid$;$NL$
	$END$
	$NL$

$	// ���٥��ID�ν���
	$FOREACH evtid EVT.ID_LIST$
		const EventMaskType $evtid$_id = $evtid$;$NL$
	$END$
	$NL$

$	// ISR��ID�ν���
	$FOREACH isrid ISR.ID_LIST$
		const ISRType $isrid$_id = $isrid$;$NL$
	$END$
	$NL$

$END$

$
$  ������
$
$NL$
 /****** Object TASK ******/$NL$
$NL$

$ �����å��ΰ�������Ȥ���˴ؤ��륨�顼�����å�
$FOREACH tskid TSK.ID_LIST$
$ 	// NULL(0)��0����ꤷ����硤�ǥե����������(�����å��ΰ���ꤷ����硤�桼����Ǥ)
	$IF TSK.STKSZ[tskid] == 0$
		$TSK.STKSZ[tskid] = DEFAULT_TASKSTKSZ$
	$END$

$	// �������å�����κǾ��͡�TARGET_MIN_STKSZ�ˤ��⾮�������
	$IF TARGET_MIN_STKSZ && (TSK.STKSZ[tskid] < TARGET_MIN_STKSZ)$
		$ERROR TSK.TEXT_LINE[tskid]$$FORMAT(_("OsTaskStackSize(%1%) of OsTask(%2%) is too small"), TSK.STKSZ[tskid], tskid)$$END$
	$END$
$ 	// stksz�������å��ΰ�Υ������Ȥ����������ʤ����
	$IF !EQ(TSK.STK[tskid], "NULL") && CHECK_STKSZ_ALIGN
							&& (TSK.STKSZ[tskid] & (CHECK_STKSZ_ALIGN - 1))$
		$ERROR TSK.TEXT_LINE[tskid]$$FORMAT(_("OsTaskStackSize(%1%) of OsTask(%2%) is not aligned"), TSK.STKSZ[tskid], tskid)$$END$
	$END$

	$IF EQ(TSK.STK[tskid], "NULL")$
		$IF TSK.EXTENDED[tskid]$
			static StackType _kernel_stack_$tskid$[COUNT_STK_T($TSK.STKSZ[tskid]$)];$NL$
			$TSK.TINIB_STKSZ[tskid] = FORMAT("ROUND_STK_T(%1%)", TSK.STKSZ[tskid])$
			$TSK.TINIB_STK[tskid] = CONCAT("_kernel_stack_", tskid)$
		$ELSE$
			$TSK.TINIB_STK[tskid] = CONCAT("_kernel_shared_stack_", +TSK.PRIORITY[tskid])$
			$TSK.SHARED_STK_ID[tskid] = TSK.PRIORITY[tskid]$
$ 			// ���ܥ������Ѥζ�ͭ�����å��Υ����������
			$IF !LENGTH(shared_stack_size[TSK.PRIORITY[tskid]])
					|| shared_stack_size[TSK.PRIORITY[tskid]] < TSK.STKSZ[tskid]$
				$shared_stack_size[TSK.PRIORITY[tskid]] = TSK.STKSZ[tskid]$
			$END$
		$END$
	$ELSE$
		$TSK.TINIB_STKSZ[tskid] = TSK.STKSZ[tskid]$
		$TSK.TINIB_STK[tskid] = TSK.STK[tskid]$
	$END$
$END$

$FOREACH tskid TSK.ID_LIST$
	$IF LENGTH(TSK.SHARED_STK_ID[tskid])$
		$TSK.TINIB_STKSZ[tskid] = FORMAT("ROUND_STK_T(%1%)", shared_stack_size[TSK.PRIORITY[tskid]])$
	$END$
$END$

$FOREACH tskpri RANGE(TMIN_TPRI, TMAX_TPRI)$
	$IF LENGTH(shared_stack_size[tskpri])$
		static StackType _kernel_shared_stack_$tskpri$[COUNT_STK_T($shared_stack_size[tskpri]$)];$NL$
	$END$
$END$
$NL$


$IF LENGTH(TSK.ID_LIST)$
$	// ������������֥�å��ν���
	const TINIB tinib_table[TNUM_TASK] = {$NL$
	$JOINEACH tskid TSK.ID_LIST ",\n"$
		$TAB${$NL$
		$TAB$$TAB$&TASKNAME($tskid$),$NL$
		$IF USE_TSKINICTXB$
			$GENERATE_TSKINICTXB(tskid)$
		$ELSE$
			$TAB$$TAB$$TSK.TINIB_STKSZ[tskid]$,$NL$
			$TAB$$TAB$$TSK.TINIB_STK[tskid]$,$NL$
		$END$

		$TAB$$TAB$$TMAX_TPRI - TSK.PRIORITY[tskid]$,$NL$

		$IF EQ(TSK.SCHEDULE[tskid], "NON")$
			$TAB$$TAB$$+TPRI_MAXTASK$,$NL$
		$ELSE$
			$IF LENGTH(TSK.INRESPRI[tskid])$
				$TAB$$TAB$$TMAX_TPRI - TSK.INRESPRI[tskid]$,$NL$
			$ELSE$
				$TAB$$TAB$$TMAX_TPRI - TSK.PRIORITY[tskid]$,$NL$
			$END$
		$END$

		$TAB$$TAB$($TSK.ACTIVATION[tskid]$) - 1U,$NL$
		$TAB$$TAB$$FORMAT("0x%08xU", +TSK.ASTPTN[tskid])$$NL$
		$TAB$}
	$END$
	$NL$
	};$NL$
	$NL$

$	// TCB�ν���
	TCB tcb_table[TNUM_TASK];$NL$
	$NL$
$ELSE$
	TOPPERS_EMPTY_LABEL(const TINIB, tinib_table);$NL$
	TOPPERS_EMPTY_LABEL(TCB, tcb_table);$NL$
$END$

$
$ �����󥿤ν���
$
$NL$
 /****** Object COUNTER ******/$NL$
$NL$

$IF LENGTH(CNT.ID_LIST)$
	const CNTINIB cntinib_table[TNUM_COUNTER] = {$NL$
	$JOINEACH cntid CNT.ID_LIST ",\n"$
		$TAB${ $CNT.MAXALLOWED[cntid]$,$SPC$
		($CNT.MAXALLOWED[cntid]$ * 2U) + 1U,$SPC$
		$CNT.TICKSPERBASE[cntid]$,$SPC$
		$CNT.MINCYCLE[cntid]$ }
	$END$
	$NL$
	};$NL$
	$NL$

	CNTCB cntcb_table[TNUM_COUNTER];$NL$
$ELSE$
	TOPPERS_EMPTY_LABEL(const CNTINIB, cntinib_table);$NL$
	TOPPERS_EMPTY_LABEL(CNTCB, cntcb_table);$NL$
$END$

$ �ϡ��ɥ����������󥿥ݥ��󥿥ơ��֥�����ν���
$IF LENGTH(HWCNT.ID_LIST)$
	const HWCNTINIB hwcntinib_table[TNUM_HARDCOUNTER] = $NL$
	{$NL$
	$JOINEACH cntid HWCNT.ID_LIST ",\n"$
		$TAB${$NL$
			$TAB$$TAB$&init_hwcounter_$cntid$,$NL$
			$TAB$$TAB$&start_hwcounter_$cntid$,$NL$
			$TAB$$TAB$&stop_hwcounter_$cntid$,$NL$
			$TAB$$TAB$&set_hwcounter_$cntid$,$NL$
			$TAB$$TAB$&get_hwcounter_$cntid$,$NL$
			$TAB$$TAB$&cancel_hwcounter_$cntid$,$NL$
			$TAB$$TAB$&trigger_hwcounter_$cntid$,$NL$
			$TAB$$TAB$&int_clear_hwcounter_$cntid$,$NL$
			$TAB$$TAB$&int_cancel_hwcounter_$cntid$,$NL$
			$TAB$$TAB$&increment_hwcounter_$cntid$,$NL$
			$TAB$$TAB$$CNT.NSPERTICK[cntid]$$NL$
		$TAB$}
	$END$
	$NL$};$NL$

$ELSE$
	TOPPERS_EMPTY_LABEL(const HWCNTINIB, hwcntinib_table);$NL$
$END$
$NL$


$
$ ���顼��ν���
$
$NL$
 /****** Object ALARM ******/$NL$
$NL$

$FOREACH almid ALM.ID_LIST$

$	// ��������ư�ѤΥ��������ؿ�
	$IF EQ(ALM.ALMATR[almid], "ACTIVATETASK")$
		static void$NL$
		_activate_alarm_$+almid$(void);$NL$
		static void$NL$
		_activate_alarm_$+almid$(void)$NL$
		{$NL$
		$TAB$(void) activate_task_action($ALM.TSKID[almid]$);$NL$
		}$NL$

$	// ���٥�ȥ��å��ѤΥ��������ؿ�
	$ELIF EQ(ALM.ALMATR[almid], "SETEVENT")$
		static void$NL$
		_setevent_alarm_$+almid$(void);$NL$
		static void$NL$
		_setevent_alarm_$+almid$(void)$NL$
		{$NL$
		$TAB$(void) set_event_action($ALM.TSKID[almid]$, $ALM.EVTID[almid]$);$NL$
		}$NL$

$	// IncrementCounter�ѤΥ��������ؿ�
	$ELIF EQ(ALM.ALMATR[almid], "INCREMENTCOUNTER")$
		static void$NL$
		_incrementcounter_alarm_$+almid$(void);$NL$
		static void$NL$
		_incrementcounter_alarm_$+almid$(void)$NL$
		{$NL$
		$TAB$(void) incr_counter_action($ALM.INCID[almid]$);$NL$
		}$NL$
	$END$
	$NL$
$END$

$ ���顼�ॳ��ȥ���֥�å�

$IF LENGTH(ALM.ID_LIST)$
	const ALMINIB alminib_table[TNUM_ALARM] = {$NL$
	$JOINEACH almid ALM.ID_LIST ",\n"$
		$TAB${ &(cntcb_table[$ALM.CNTID[almid]$]),$SPC$
		$IF EQ(ALM.ALMATR[almid], "ACTIVATETASK")$
$			// ��������ư��
			&_activate_alarm_$+almid$,$SPC$
		$ELIF EQ(ALM.ALMATR[almid], "SETEVENT")$
$			// ���٥�ȥ��å���
			&_setevent_alarm_$+almid$,$SPC$
		$ELIF EQ(ALM.ALMATR[almid], "INCREMENTCOUNTER")$
$			// IncrementCounter��
			&_incrementcounter_alarm_$+almid$,$SPC$
		$ELIF EQ(ALM.ALMATR[almid], "CALLBACK")$
$			// ������Хå���
			ALARMCALLBACKNAME($ALM.CALLBACK[almid]$),$SPC$
		$END$

		$FORMAT("0x%08xU", +ALM.ASTPTN[almid])$,$SPC$
		$IF ALM.ASTPTN[almid]$
			$ALM.ALARMTIME[almid]$,$SPC$
			$ALM.CYCLETIME[almid]$,$SPC$
$			// ���顼�ॳ����Хå��ȼ�ư��ư°���ʳ���°����������ʤ�
			($ALM.ALMATR[almid]$ & CALLBACK) | $ALM.AUTOSTARTTYPE[almid]$ }
		$ELSE$
			0U, 0U, $ALM.ALMATR[almid]$ & CALLBACK }
		$END$
	$END$
	$NL$
	};$NL$
	$NL$

	ALMCB	almcb_table[TNUM_ALARM];$NL$
$ELSE$
	TOPPERS_EMPTY_LABEL(const ALMINIB, alminib_table);$NL$
	TOPPERS_EMPTY_LABEL(ALMCB, almcb_table);$NL$
$END$


$
$ �������塼��ơ��֥�ν���
$
$NL$
 /****** Object SCHEDULETABLE ******/$NL$
$NL$

$ �ƥ������塼��ơ��֥�γ���λ���Υ��������ؿ�����λ�������֥�å�������
$FOREACH schtblid SCHTBL.ID_LIST$
	/* Object SCHEDULETABLE($schtblid$) */$NL$
	$NL$
	$FOREACH exppt_index RANGE(0, LENGTH(SCHTBL.EXPPTINDEX_LIST[schtblid]) - 1)$
		$expptid = AT(SCHTBL.EXPPTINDEX_LIST[schtblid], exppt_index)$
		static void$NL$
		_expire_scheduletable_$+schtblid$_$exppt_index$(void);$NL$
		static void$NL$
		_expire_scheduletable_$+schtblid$_$exppt_index$(void)$NL$
		{$NL$
$		// ��������ư
		$FOREACH expptactid EXPPTACT.ID_LIST$
			$IF EXPPTACT.EXPPTID[expptactid] == expptid && EQ(EXPPTACT.EXPIREATR[expptactid], "ACTIVATETASK")$
				$TAB$(void) activate_task_action($EXPPTACT.TSKID[expptactid]$);$NL$
			$END$
		$END$
$		// ���٥�ȥ��å�
		$FOREACH expptactid EXPPTACT.ID_LIST$
			$IF EXPPTACT.EXPPTID[expptactid] == expptid && EQ(EXPPTACT.EXPIREATR[expptactid], "SETEVENT")$
				$TAB$(void) set_event_action($EXPPTACT.TSKID[expptactid]$, $EXPPTACT.EVTID[expptactid]$);$NL$
			$END$
		$END$
		}$NL$
	$END$
	$NL$
	static const SCHTBLEXPPTCB schtblexppt_table_$+schtblid$[$LENGTH(SCHTBL.EXPPTINDEX_LIST[schtblid])$] = {$NL$
	$JOINEACH exppt_index RANGE(0, LENGTH(SCHTBL.EXPPTINDEX_LIST[schtblid]) - 1) ",\n"$
		$expptid = AT(SCHTBL.EXPPTINDEX_LIST[schtblid], exppt_index)$
		$TAB${ $EXPPT.OFFSET[expptid]$, &_expire_scheduletable_$+schtblid$_$exppt_index$ }
	$END$
	$NL$
	};$NL$
	$NL$
$END$
$NL$

$ �������塼��ơ��֥��Ϣ�Υǡ����֥�å������
$IF LENGTH(SCHTBL.ID_LIST)$
	const SCHTBLINIB schtblinib_table[TNUM_SCHEDULETABLE] = {$NL$
	$JOINEACH schtblid SCHTBL.ID_LIST ",\n"$
		$TAB${ &(cntcb_table[$SCHTBL.CNTID[schtblid]$]),$SPC$
		$SCHTBL.DURATIONTICK[schtblid]$,$SPC$
		$FORMAT("0x%08xU", +SCHTBL.ASTPTN[schtblid])$,$SPC$
		$IF SCHTBL.ASTPTN[schtblid]$
			$SCHTBL.AUTOSTARTTYPE[schtblid]$,$SPC$
			$SCHTBL.STARTTICK[schtblid]$, $SPC$
		$ELSE$
			0U, 0U,$SPC$
		$END$
		schtblexppt_table_$+schtblid$,$SPC$
		$IF SCHTBL.REPEAT[schtblid]$
			TRUE,$SPC$
		$ELSE$
			FALSE,$SPC$
		$END$
		$LENGTH(SCHTBL.EXPPTINDEX_LIST[schtblid])$U }
	$END$
	$NL$
	};$NL$
	$NL$
	SCHTBLCB schtblcb_table[TNUM_SCHEDULETABLE];$NL$
$ELSE$
	TOPPERS_EMPTY_LABEL(const SCHTBLINIB, schtblinib_table);$NL$
	TOPPERS_EMPTY_LABEL(SCHTBLCB, schtblcb_table);$NL$
$END$

$NL$


$
$ �꥽�����ν���
$
$NL$
 /****** Object RESOURCE ******/$NL$
$NL$

$IF LENGTH(STDRES.ID_LIST)$
	const RESINIB resinib_table[TNUM_STD_RESOURCE] = {$NL$
	$JOINEACH resid STDRES.ID_LIST ",\n"$
		$IF RES.CEILPRI[resid] > 0$
$           �������Τߤ������꥽�����ξ��
			$TAB${ $TMAX_TPRI - RES.CEILPRI[resid]$ }
		$ELSE$
$           ISR�ⰷ���꥽�����ξ��
			$TAB${ $RES.CEILPRI[resid]$ }
		$END$
	$END$
	$NL$
	};$NL$
	$NL$

	RESCB rescb_table[TNUM_STD_RESOURCE];$NL$
$ELSE$
	TOPPERS_EMPTY_LABEL(const RESINIB, resinib_table);$NL$
	TOPPERS_EMPTY_LABEL(RESCB, rescb_table);$NL$
$END$

$NL$


$
$ ISR�ν���
$
$NL$
 /****** Object ISR ******/$NL$
$NL$
$NL$

$IF LENGTH(ISR2.ID_LIST)$
	ISRCB isrcb_table[TNUM_ISR2];$NL$
	$NL$
$ELSE$
	TOPPERS_EMPTY_LABEL(ISRCB, isrcb_table);$NL$
$END$

$
$ ���֥������Ƚ�����롼����
$
$NL$
void$NL$
object_initialize(void)$NL$
{$NL$
$TAB$interrupt_initialize();$NL$
$IF LENGTH(STDRES.ID_LIST)$
$TAB$resource_initialize();$NL$
$END$
$TAB$task_initialize();$NL$
$IF LENGTH(CNT.ID_LIST)$
$TAB$counter_initialize();$NL$
$END$
$IF LENGTH(ALM.ID_LIST)$
$TAB$alarm_initialize();$NL$
$END$
$IF LENGTH(SCHTBL.ID_LIST)$
$TAB$schtbl_initialize();$NL$
$END$
}$NL$
$NL$

$
$ ���֥������Ƚ�λ�����롼����
$
$NL$
void$NL$
object_terminate(void)$NL$
{$NL$
$IF LENGTH(CNT.ID_LIST)$
$TAB$counter_terminate();$NL$
$END$
}$NL$
$NL$

$
$  ����ߴ�����ǽ
$
$NL$
/*$NL$
$SPC$*  Interrupt Management Functions$NL$
$SPC$*/$NL$
$NL$

$ ISR�Ѥγ���ߥϥ�ɥ�
$FOREACH isrid ISR2.ID_LIST$
	void$NL$
	$ISR.INT_ENTRY[isrid]$(void)$NL$
	{$NL$
	$TAB$i_begin_int($ISR.INTNO[isrid]$);$NL$
	$TAB$LOG_ISR_ENTER($isrid$);$NL$
	$TAB$ISRNAME($isrid$)();$NL$
	$TAB$LOG_ISR_LEAVE($isrid$);$NL$
	$TAB$i_end_int($ISR.INTNO[isrid]$);$NL$
	}$NL$
$END$
$NL$

$ �ϡ��ɥ����������󥿳���߽���
/* HardWare Counter Interrupt Handler(C2ISR) */$NL$
$FOREACH cntid HWCNT.ID_LIST$
	ISR($CNT.ISRID[cntid]$)$NL$
	{$NL$
		$TAB$notify_hardware_counter($cntid$);$NL$
	}$NL$
$END$
$NL$

/*$NL$
$SPC$*  Stack Area for Non-task Context$NL$
$SPC$*/$NL$
$NL$

$ �󥿥�������ƥ������ѤΥ����å��ΰ襵�����׻�
$FOREACH isrid ISR2.ID_LIST$
$ 	// NULL(0)��0����ꤷ����硤�ǥե����������
	$IF ISR.STKSZ[isrid] == 0$
		$ISR.STKSZ[isrid] = DEFAULT_ISRSTKSZ$
	$END$

$	// �󥿥�������ƥ������ѤΥ����å��ΰ�׻��ΰ١�ͥ����������ͤι�׽���
	$IF LENGTH(ISR.STKSZ[isrid]) && (!LENGTH(isr_shared_stack_size[ISR.INTPRI[isrid]])
			|| isr_shared_stack_size[ISR.INTPRI[isrid]] < ISR.STKSZ[isrid])$
		$isr_shared_stack_size[ISR.INTPRI[isrid]] = ISR.STKSZ[isrid]$
	$END$
$END$

$	// MINIMUM_OSTKSZ�ϡ��󥿥�������ƥ����ȥ����å��������κǾ��ͤȤ��ơ���¸��������
$total_stksz = MINIMUM_OSTKSZ$

$ ISR�����å��ΰ�Υ���������
$FOREACH isrpri RANGE(-MAX_PRI_ISR2, -MIN_PRI_ISR2)$
	$IF LENGTH(isr_shared_stack_size[isrpri])$
		$total_stksz = total_stksz + isr_shared_stack_size[isrpri]$
	$END$
$END$

$IF USE_HOOK$
$ 	// �����å��������Υǥե��������
$ 	// NULL(0)��0����ꤷ����硤�ǥե����������
	$IF LENGTH(HSTK.ID_LIST) && HSTK.STKSZ[1] != 0$
		$total_stksz = total_stksz + HSTK.STKSZ[1]$
	$ELSE$
		$total_stksz = total_stksz + DEFAULT_HOOKSTKSZ$
	$END$
$END$

$IF OS.STACKMONITORING[1]$
$ �����å����̥����å������ѤΥ����å����̥������׻�
$FOREACH isrid ISR.ID_LIST$
	$ISR.STKSZ_2[isrid] = ISR.STKSZ[isrid]$
	$IF (EQ(ISR.CATEGORY[isrid], "CATEGORY_2"))$
		$FOREACH isrpri	RANGE(-ISR.INTPRI[isrid], -MIN_PRI_ISR2)$
			$IF ISR.INTPRI[isrid] < isrpri$
				$IF LENGTH(isr_shared_stack_size[isrpri])$
					$ISR.STKSZ_2[isrid] = ISR.STKSZ_2[isrid] + isr_shared_stack_size[isrpri]$
				$END$
			$END$
		$END$
	$END$
$END$

$ �եå�ͭ�����������å����̥����å������ѥ����å���������û�
$IF USE_HOOK$
	$FOREACH isrid2 ISR2.ID_LIST$
		$IF LENGTH(HSTK.ID_LIST) && HSTK.STKSZ[1] != 0$
			$ISR.STKSZ_2[isrid2] = ISR.STKSZ_2[isrid2] + HSTK.STKSZ[1]$
		$ELSE$
			$ISR.STKSZ_2[isrid2] = ISR.STKSZ_2[isrid2] + DEFAULT_HOOKSTKSZ$
		$END$
	$END$
$END$
$END$

$ ����ߴ�����ǽ�Τ����ɸ��Ū�ʽ�������������
$IF !OMIT_INITIALIZE_INTERRUPT$

$	// ������׵�饤���
	#define TNUM_INTNO	UINT_C($LENGTH(ISR.ID_LIST)$)$NL$
	const InterruptNumberType tnum_intno = TNUM_INTNO;$NL$
	$NL$

$	// ������׵�饤�������ơ��֥�
	$IF LENGTH(ISR.ID_LIST)$
		const INTINIB intinib_table[TNUM_INTNO] = {$NL$
		$JOINEACH isrid ISR.ID_LIST ",\n"$
			$TAB${ ($ISR.INTNO[isrid]$), $ISR.INTATR[isrid]$, ($-ISR.INTPRI[isrid]$), 
			$IF OS.STACKMONITORING[1]$
				$FORMAT("0x%xU",+ISR.STKSZ_2[isrid])$
			$END$
			 }
		$END$$NL$
		};$NL$
	$ELSE$
		TOPPERS_EMPTY_LABEL(const INTINIB, intinib_table);$NL$
	$END$
	$NL$
$END$

$
$  �󥿥�������ƥ������ѤΥ����å��ΰ�
$
$IF !LENGTH(OSTK.ID_LIST)$
$	// OSTK���ʤ����η׻����������å�����ͤ�����
$	// �󥹥��å�����ƥ����ȥ����å������� = ISR��ͭ�奵���� + MINIMUM_OSTKSZ
	static StackType			_kernel_ostack[$FORMAT("COUNT_STK_T(0x%xU)", +total_stksz)$];$NL$
	#define TOPPERS_OSTKSZ		$FORMAT("ROUND_STK_T(0x%xU)", +total_stksz)$$NL$
	#define TOPPERS_OSTK		_kernel_ostack$NL$
$ELSE$
$ 	// �����å��������Υǥե��������
$ 	// NULL(0)��0����ꤷ����硤�ǥե����������
	$IF !LENGTH(OSTK.STKSZ[1]) || OSTK.STKSZ[1] == 0$
		$OSTK.STKSZ[1] = DEFAULT_OSSTKSZ$
	$END$

$ 	// stksz�������å��ΰ�Υ������Ȥ����������ʤ����
	$IF !EQ(OSTK.STK[1], "NULL") && CHECK_STKSZ_ALIGN
							&& OSTK.STKSZ[1] & (CHECK_STKSZ_ALIGN - 1)$
		$ERROR OSTK.TEXT_LINE[1]$$FORMAT(_("OsOsStackSize(%1%) is not aligned"), OSTK.STKSZ[1])$$END$
	$END$

$ 	// stksz��ɬ�פʥ����å���������꾮�������
	$IF OSTK.STKSZ[1] < total_stksz$
		$ERROR OSTK.TEXT_LINE[1]$$FORMAT(_("OsOsStackSize(%1%) is necessary 0x%2$x and more)"), OSTK.STKSZ[1], +total_stksz)$$END$
	$END$

	$IF EQ(OSTK.STK[1], "NULL")$
$		// �����å��ΰ�μ�ư���դ�
		static StackType				_kernel_ostack[COUNT_STK_T($OSTK.STKSZ[1]$)];$NL$
		#define TOPPERS_OSTKSZ		ROUND_STK_T($OSTK.STKSZ[1]$)$NL$
		#define TOPPERS_OSTK		_kernel_ostack$NL$
	$ELSE$
		#define TOPPERS_OSTKSZ		($OSTK.STKSZ[1]$)$NL$
		#define TOPPERS_OSTK		($OSTK.STK[1]$)$NL$
	$END$
$END$
$NL$

$ �󥿥�������ƥ������ѤΥ����å��ΰ�
const MemorySizeType	_ostksz = TOPPERS_OSTKSZ;$NL$
StackType * const		_ostk = (StackType *) TOPPERS_OSTK;$NL$
$NL$
#ifdef TOPPERS_OSTKPT$NL$
StackType * const	_ostkpt = TOPPERS_OSTKPT(TOPPERS_OSTK, TOPPERS_OSTKSZ);$NL$
#endif /* TOPPERS_OSTKPT */$NL$
$NL$

$FILE "Os_Lcfg.h"$
#ifndef TOPPERS_MACRO_ONLY$NL$
#ifdef TOPPERS_ENABLE_TRACE$NL$
extern const char8 *atk2_appid_str(AppModeType id);$NL$
extern const char8 *atk2_tskid_str(TaskType id);$NL$
extern const char8 *atk2_isrid_str(ISRType id);$NL$
extern const char8 *atk2_cntid_str(CounterType id);$NL$
extern const char8 *atk2_almid_str(AlarmType id);$NL$
extern const char8 *atk2_resid_str(ResourceType id);$NL$
extern const char8 *atk2_schtblid_str(ScheduleTableType id);$NL$
extern const char8 *atk2_evtid_str(TaskType task, EventMaskType event);$NL$
#endif /* TOPPERS_ENABLE_TRACE */$NL$

$
$  ������
$
$NL$
 /****** Object TASK ******/$NL$
$NL$

$ ��������extern���
$FOREACH tskid TSK.ID_LIST$
	extern TASK($tskid$);$NL$
$END$

$
$ ���顼��ν���
$
$NL$
 /****** Object ALARM ******/$NL$
$NL$

$FOREACH almid ALM.ID_LIST$
$	// ���顼�ॳ����Хå��ؿ���extern���
	$IF EQ(ALM.ALMATR[almid], "CALLBACK")$
		extern ALARMCALLBACK($ALM.CALLBACK[almid]$);$NL$
	$END$
$END$

$
$  ����ߴ�����ǽ
$
$NL$
/*$NL$
$SPC$*  Interrupt Management Functions$NL$
$SPC$*/$NL$
$NL$

$FOREACH isrid ISR.ID_LIST$
$	//����ߴؿ��Ǥ��뤳�Ȥ򼨤�����ѥ��륪�ץ������դ���ؿ����������Ƥ����礫
	$IF EQ(ISR.CATEGORY[isrid], "CATEGORY_1") && ISFUNCTION("EXTERN_C1ISR_HANDLER")$
		$EXTERN_C1ISR_HANDLER(ISR.INT_ENTRY[isrid])$$NL$
	$ELSE$
		extern void $ISR.INT_ENTRY[isrid]$(void);$NL$
	$END$
$END$

$ ISR�Ѥγ���ߥϥ�ɥ�
$FOREACH isrid ISR2.ID_LIST$
	extern ISR($isrid$);$NL$
$END$
$NL$

$ �ϡ��ɥ����������󥿤γ�����������ν���
$FOREACH cntid HWCNT.ID_LIST$
	extern void init_hwcounter_$cntid$(TickType maxval, TimeType nspertick);$NL$
	extern void start_hwcounter_$cntid$(void);$NL$
	extern void stop_hwcounter_$cntid$(void);$NL$
	extern void set_hwcounter_$cntid$(TickType exprtick);$NL$
	extern TickType get_hwcounter_$cntid$(void);$NL$
	extern void cancel_hwcounter_$cntid$(void);$NL$
	extern void trigger_hwcounter_$cntid$(void);$NL$
	extern void int_clear_hwcounter_$cntid$(void);$NL$
	extern void int_cancel_hwcounter_$cntid$(void);$NL$
	extern void increment_hwcounter_$cntid$(void);$NL$
$END$
$NL$

$IF ISFUNCTION("EXTERN_INT_HANDLER")$
	$EXTERN_INT_HANDLER()$
$END$

#endif /* TOPPERS_MACRO_ONLY */$NL$

#endif /* TOPPERS_OS_LCFG_H */$NL$


$FILE "Os_Lcfg.c"$
#ifdef TOPPERS_ENABLE_TRACE$NL$
const char8 *$NL$
atk2_appid_str(AppModeType id)$NL$
{$NL$
$IF LENGTH(APP.ID_LIST)$
	$TAB$const char8	*appid_str;$NL$
	$TAB$switch (id) {$NL$
	$FOREACH appid APP.ID_LIST$
		$TAB$case $appid$:$NL$
		$TAB$$TAB$appid_str = "$appid$";$NL$
		$TAB$$TAB$break;$NL$
	$END$
	$TAB$default:$NL$
	$TAB$$TAB$appid_str = "";$NL$
	$TAB$$TAB$break;$NL$
	$TAB$}$NL$
	$TAB$return(appid_str);$NL$
$ELSE$
	$TAB$return("");$NL$
$END$
}$NL$

const char8 *$NL$
atk2_tskid_str(TaskType id)$NL$
{$NL$
$TAB$const char8	*tskid_str;$NL$
$TAB$switch (id) {$NL$
$FOREACH tskid TSK.ID_LIST$
	$TAB$case $tskid$:$NL$
	$TAB$$TAB$tskid_str = "$tskid$";$NL$
	$TAB$$TAB$break;$NL$
$END$
$TAB$case INVALID_TASK:$NL$
$TAB$$TAB$tskid_str = "INVALID_TASK";$NL$
$TAB$$TAB$break;$NL$
$TAB$default:$NL$
$TAB$$TAB$tskid_str = "";$NL$
$TAB$$TAB$break;$NL$
$TAB$}$NL$
$TAB$return(tskid_str);$NL$
}$NL$

$NL$
const char8 *$NL$
atk2_isrid_str(ISRType id)$NL$
{$NL$
$TAB$const char8	*isrid_str;$NL$
$TAB$switch (id) {$NL$
$FOREACH isrid ISR.ID_LIST$
	$TAB$case $isrid$:$NL$
	$TAB$$TAB$isrid_str = "$isrid$";$NL$
	$TAB$$TAB$break;$NL$
$END$
$TAB$case INVALID_ISR:$NL$
$TAB$$TAB$isrid_str = "INVALID_ISR";$NL$
$TAB$$TAB$break;$NL$
$TAB$default:$NL$
$TAB$$TAB$isrid_str = "";$NL$
$TAB$$TAB$break;$NL$
$TAB$}$NL$
$TAB$return(isrid_str);$NL$
}$NL$

$NL$
const char8 *$NL$
atk2_cntid_str(CounterType id)$NL$
{$NL$
$IF LENGTH(CNT.ID_LIST)$
	$TAB$const char8	*cntid_str;$NL$
	$TAB$switch (id) {$NL$
	$FOREACH cntid CNT.ID_LIST$
		$TAB$case $cntid$:$NL$
		$TAB$$TAB$cntid_str = "$cntid$";$NL$
		$TAB$$TAB$break;$NL$
	$END$
	$TAB$default:$NL$
	$TAB$$TAB$cntid_str = "";$NL$
	$TAB$$TAB$break;$NL$
	$TAB$}$NL$
	$TAB$return(cntid_str);$NL$
$ELSE$
	$TAB$return("");$NL$
$END$
}$NL$

$NL$
const char8 *$NL$
atk2_almid_str(AlarmType id)$NL$
{$NL$
$IF LENGTH(ALM.ID_LIST)$
	$TAB$const char8	*almid_str;$NL$
	$TAB$switch (id) {$NL$
	$FOREACH almid ALM.ID_LIST$
		$TAB$case $almid$:$NL$
		$TAB$$TAB$almid_str = "$almid$";$NL$
		$TAB$$TAB$break;$NL$
	$END$
	$TAB$default:$NL$
	$TAB$$TAB$almid_str = "";$NL$
	$TAB$$TAB$break;$NL$
	$TAB$}$NL$
	$TAB$return(almid_str);$NL$
$ELSE$
	$TAB$return("");$NL$
$END$
}$NL$

$NL$
const char8 *$NL$
atk2_resid_str(ResourceType id)$NL$
{$NL$
$IF LENGTH(RES.ID_LIST)$
	$TAB$const char8	*resid_str;$NL$
	$TAB$switch (id) {$NL$
	$FOREACH resid RES.ID_LIST$
		$TAB$case $resid$:$NL$
		$TAB$$TAB$resid_str = "$resid$";$NL$
		$TAB$$TAB$break;$NL$
	$END$
	$TAB$default:$NL$
	$TAB$$TAB$resid_str = "";$NL$
	$TAB$$TAB$break;$NL$
	$TAB$}$NL$
	$TAB$return(resid_str);$NL$
$ELSE$
	$TAB$return("");$NL$
$END$
}$NL$

$NL$
const char8 *$NL$
atk2_schtblid_str(ScheduleTableType id)$NL$
{$NL$
$IF LENGTH(SCHTBL.ID_LIST)$
	$TAB$const char8	*schtblid_str;$NL$
	$TAB$switch (id) {$NL$
	$FOREACH schtblid SCHTBL.ID_LIST$
		$TAB$case $schtblid$:$NL$
		$TAB$$TAB$schtblid_str = "$schtblid$";$NL$
		$TAB$$TAB$break;$NL$
	$END$
	$TAB$default:$NL$
	$TAB$$TAB$schtblid_str = "";$NL$
	$TAB$$TAB$break;$NL$
	$TAB$}$NL$
	$TAB$return(schtblid_str);$NL$
$ELSE$
	$TAB$return("");$NL$
$END$
}$NL$

$NL$
const char8 *$NL$
atk2_evtid_str(TaskType task, EventMaskType event)$NL$
{$NL$
$TAB$const char8	*evtid_str;$NL$
$IF LENGTH(TSK.ID_LIST)$
	$TAB$switch (task) {$NL$
	$FOREACH tskid TSK.ID_LIST$
		$TAB$case $tskid$:$NL$
		$IF LENGTH(TSK.EVT_LIST[tskid])$
			$TAB$$TAB$switch (event) {$NL$
			$FOREACH evtid TSK.EVT_LIST[tskid]$
				$TAB$$TAB$case $evtid$:$NL$
				$TAB$$TAB$$TAB$evtid_str = "$evtid$";$NL$
				$TAB$$TAB$$TAB$break;$NL$
			$END$
			$TAB$$TAB$default:$NL$
			$TAB$$TAB$$TAB$evtid_str = NULL;$NL$
			$TAB$$TAB$$TAB$break;$NL$
			$TAB$$TAB$}$NL$
		$ELSE$
			$TAB$$TAB$evtid_str = NULL;$NL$
		$END$
		$TAB$$TAB$break;$NL$
	$END$
	$TAB$default:$NL$
	$TAB$$TAB$evtid_str = NULL;$NL$
	$TAB$$TAB$break;$NL$
	$TAB$}$NL$
$END$
$TAB$if (evtid_str == NULL) {$NL$
$FOREACH evtid EVT.ID_LIST$
	$TAB$$TAB$if (event == $evtid$) {$NL$
	$TAB$$TAB$$TAB$evtid_str = "$evtid$";$NL$
	$TAB$$TAB$}$NL$
$END$
$TAB$}$NL$
$TAB$return(evtid_str);$NL$
}$NL$
#endif /* TOPPERS_ENABLE_TRACE */$NL$

$FILE "cfg2_out.tf"$
$$ cfg2_out.tf$NL$
$NL$
$$TSK.ID_LIST = {
$JOINEACH tskid TSK.ID_LIST ","$
	VALUE("$tskid$", $+tskid$)
$END$
}$$$NL$

$NL$
$$ALM.ID_LIST = {
$JOINEACH almid ALM.ID_LIST ","$
	VALUE("$almid$", $+almid$)
$END$
}$$$NL$

$NL$
$$HWCNT.ID_LIST = {
$JOINEACH hwcntid HWCNT.ID_LIST ","$
	VALUE("$hwcntid$", $+hwcntid$)
$END$
}$$$NL$
