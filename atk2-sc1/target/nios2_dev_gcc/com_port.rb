#!ruby
#
#  TOPPERS ATK2
#      Toyohashi Open Platform for Embedded Real-Time Systems
#      Automotive Kernel Version 2
#
#  Copyright (C) 2011-2015 by Center for Embedded Computing Systems
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
#  $Id: com_port.rb 1801 2015-03-27 06:34:43Z t_ishikawa $
#

# �ץ��󥹥ȡ��롧$ gem install serialport
require "rubygems"
require "serialport"

Thread.abort_on_exception = true

# ����1: CORE0����Υ��ե��å�
nOffset = 0
if (ARGV.size() >= 1)
  nOffset = ARGV[0].to_i()
end

# ����2: ��λ�ե饰
bTerminate = false
if (ARGV.size() >= 2)
  bTerminate = ARGV[1]
end


# ctrl+c�ˤ�붯����λ����
Signal.trap(:SIGINT){
  system("kill -9 #$$")
}


# �ݡ���Ƚ��
PORT_PREFIX = "/dev/ttyS"
aPorts = []
thSearchPort = Thread.new {
  IO.popen("ls -1 #{PORT_PREFIX}*") do |io|
    while io.gets()
      aPorts.push($_.gsub!(PORT_PREFIX, "").gsub!("\n", "").to_i())
    end
  end
}
thSearchPort.join()

# COM�ݡ��Ȥ�¸�ߤ��ʤ����Ͻ�λ
if (aPorts.empty?())
  puts("COM port is not found.")
  exit(1)
end

nPreNum = -1
nTargetPort = -1
aPorts.sort.reverse.each{|nNumber|
  if (nPreNum == -1)
    nPreNum = nNumber
    # �ݡ��Ȥ�1�ĤΤߤ��ä����ؤ��б�
    nTargetPort = nNumber
  else
    # �礭�������������Ϣ�֤Ǥʤ��ʤä����ͤ��оݥݡ��ȤȤ���
    if (!((nPreNum - nNumber) == 1))
      nTargetPort = nPreNum
      break
    else
      nPreNum = nNumber
      # ����Ϣ�֤ȤʤäƤ������ؤ��б�
      nTargetPort = nNumber
    end
  end
}


# CORE0����Υ��ե��å�����
nTargetPort += nOffset


# USB���ޤ���ľ��ؤ��б�
sChk = ""
thUSB = Thread.new {
  while true
    IO.popen("stty -F #{PORT_PREFIX}#{nTargetPort}") do |io|
      while io.gets()
        sChk = $_
      end
    end
    if (!sChk.include?("Invalid argument"))
      break
    end
  end
}
thUSB.join()


cCom = nil
nBaudrate = 921600
thMain = Thread.new {
  puts("\nUsing COM port: #{(nTargetPort+1).to_s()} [#{nBaudrate.to_s()}]")

  cCom = SerialPort.open("/dev/ttyS#{nTargetPort}", nBaudrate, 8, 1, SerialPort::NONE)

  while true
    sLine = cCom.gets()
    print(sLine)
    if (sLine == "Kernel Exit...\n")
      # CORE0�⤷���Ͻ�λ�ե饰��false�Ǥʤ����Τ߽�λ����
      if ((nOffset == 0) || (bTerminate != false))
        break
      end
    end
  end

  cCom.close()
}


# COM�ݡ�����³���ctrl+c�Ƕ�����λ���뤿��Υ��ߡ�����å�
thDummy = Thread.new {
  while true
    sleep(1)
  end
}

# 3���֤ǥ����ॢ����
# (���ꥢ���������ߤ������ؤ��н�)
result = thMain.join(10800)
if (result.nil?())
  puts("[com_port.rb] timeout!!")
  cCom.close()
end

