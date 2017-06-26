#
#  TOPPERS ATK2
#      Toyohashi Open Platform for Embedded Real-Time Systems
#      Automotive Kernel Version 2
#
#  Copyright (C) 2008-2015 by Center for Embedded Computing Systems
#              Graduate School of Information Science, Nagoya Univ., JAPAN
#  Copyright (C) 2011-2015 by FUJI SOFT INCORPORATED, JAPAN
#  Copyright (C) 2011-2013 by Spansion LLC, USA
#  Copyright (C) 2011-2015 by NEC Communication Systems, Ltd., JAPAN
#  Copyright (C) 2011-2015 by Panasonic Advanced Technology Development Co., Ltd., JAPAN
#  Copyright (C) 2011-2014 by Renesas Electronics Corporation, JAPAN
#  Copyright (C) 2011-2015 by Sunny Giken Inc., JAPAN
#  Copyright (C) 2011-2015 by TOSHIBA CORPORATION, JAPAN
#  Copyright (C) 2011-2015 by Witz Corporation
#  Copyright (C) 2014-2015 by AISIN COMCRUISE Co., Ltd., JAPAN
#  Copyright (C) 2014-2015 by eSOL Co.,Ltd., JAPAN
#  Copyright (C) 2014-2015 by SCSK Corporation, JAPAN
#
#  �嵭����Ԥϡ��ʲ���(1)��(4)�ξ������������˸¤ꡤ�ܥ��եȥ���
#  �����ܥ��եȥ���������Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ������
#  �ѡ������ۡʰʲ������ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
#  (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭������
#      ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ���
#      ����������˴ޤޤ�Ƥ��뤳�ȡ�
#  (2) �ܥ��եȥ������򡤥饤�֥������ʤɡ�¾�Υ��եȥ�������ȯ�˻�
#      �ѤǤ�����Ǻ����ۤ�����ˤϡ������ۤ�ȼ���ɥ�����ȡ�����
#      �ԥޥ˥奢��ʤɡˤˡ��嵭�����ɽ�����������Ѿ�浪��Ӳ���
#      ��̵�ݾڵ����Ǻܤ��뤳�ȡ�
#  (3) �ܥ��եȥ������򡤵�����Ȥ߹���ʤɡ�¾�Υ��եȥ�������ȯ�˻�
#      �ѤǤ��ʤ����Ǻ����ۤ�����ˤϡ����Τ����줫�ξ�����������
#      �ȡ�
#    (a) �����ۤ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭����
#        �ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
#    (b) �����ۤη��֤��̤�������ˡ�ˤ�äơ�TOPPERS�ץ������Ȥ�
#        ��𤹤뤳�ȡ�
#  (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
#      ������⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ����դ��뤳�ȡ�
#      �ޤ����ܥ��եȥ������Υ桼���ޤ��ϥ���ɥ桼������Τ����ʤ���
#      ͳ�˴�Ť����ᤫ��⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ�
#      ���դ��뤳�ȡ�
#
#  �ܥ��եȥ������ϡ�AUTOSAR��AUTomotive Open System ARchitecture�˻�
#  �ͤ˴�Ť��Ƥ��롥�嵭�ε����ϡ�AUTOSAR����Ū�⻺������������Τ�
#  �Ϥʤ���AUTOSAR�ϡ�AUTOSAR���ͤ˴�Ť������եȥ�����������Ū����
#  �Ѥ���Ԥ��Ф��ơ�AUTOSAR�ѡ��ȥʡ��ˤʤ뤳�Ȥ���Ƥ��롥
#
#  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ�
#  ���TOPPERS�ץ������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����λ�����Ū
#  ���Ф���Ŭ������ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ���
#  �������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤��
#  ����Ǥ�����ʤ���
#
#  $Id: Makefile.prc 1801 2015-03-27 06:34:43Z t_ishikawa $
#

#
#		Makefile �Υץ��å���¸����Nios2�ѡ�
#

#
#  �ץ��å�̾����ȯ�Ķ�̾�����
#
PRC  = nios2
TOOL = gcc

#
#  �ץ��å���¸���ǥ��쥯�ȥ�̾�����
#
PRCDIR = $(SRCDIR)/arch/$(PRC)_$(TOOL)

#
#  �������֤�32�Х��ȥ��饤��
#
ifeq ($(ALIGN_FUNCTIONS_32), true)
	CDEFS := $(CDEFS) -DFUNCTION_ALIGN_SIZE=32
	COPTS := $(COPTS) -falign-functions=32
endif

#
#  ����ѥ��륪�ץ����
#
INCLUDES := $(INCLUDES) -I$(PRCDIR) -I$(SRCDIR)/arch/$(TOOL)
COPTS := $(COPTS) -fno-common
LIBS := $(LIBS) -lgcc -lc

#
#  C++test���ѻ��˥�󥯤���饤�֥��
#
ifdef USE_CPPTEST
  LIBS := $(LIBS) $(KERNEL_LIB)/libcpptest.a -lgcc
endif

#
#  �����ͥ�˴ؤ������
#
KERNEL_DIR := $(KERNEL_DIR) $(PRCDIR)
KERNEL_ASMOBJS := $(KERNEL_ASMOBJS) prc_support.o
KERNEL_COBJS := $(KERNEL_COBJS) prc_config.o vic.o

#
#  �����ƥॿ���ޤ˴ؤ�������
#
ifeq ($(ENABLE_SYS_TIMER),true)
      CDEFS := $(CDEFS) -DTOPPERS_ENABLE_SYS_TIMER
      KERNEL_COBJS := $(KERNEL_COBJS) avalon_timer.o
endif

#
#  GNU��ȯ�Ķ��Υ������åȥ������ƥ���������
#
GCC_TARGET = nios2-elf

#
#  �������ȥ��åץ⥸�塼��˴ؤ������
#
#  ��󥫥�����ץȤˡ�STARTUP(start.o)�פ򵭽Ҥ������ᡤ�������ȥ��åץ⥸�塼
#  ���̾����HIDDEN_OBJS��������롥�ޤ���LDFLAGS��-nostdlib���ɲä��Ƥ��롥
#
HIDDEN_OBJS = start.o

$(HIDDEN_OBJS): %.o: %.S
	$(CC) -c $(CFLAGS) $(KERNEL_CFLAGS) $<

$(HIDDEN_OBJS:.o=.d): %.d: %.S
	@$(PERL) $(SRCDIR)/utils/makedep -C $(CC) \
		-O "$(CFLAGS) $(KERNEL_CFLAGS)" $< >> Makefile.depend

#LDFLAGS := -nostdlib $(LDFLAGS)

#
#  ��¸�ط������
#
cfg1_out.c: $(PRCDIR)/prc_def.csv
Os_Lcfg.timestamp: $(PRCDIR)/prc.tf
$(OBJFILE): $(PRCDIR)/prc_check.tf
offset.h: $(PRCDIR)/prc_offset.tf

#
#  �����ͥ졼���ط����ѿ������
#
CFG_TABS := $(CFG_TABS) --cfg1-def-table $(PRCDIR)/prc_def.csv
