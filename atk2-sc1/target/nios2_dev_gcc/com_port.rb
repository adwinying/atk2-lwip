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
#  上記著作権者は，以下の(1)〜(4)の条件を満たす場合に限り，本ソフトウェ
#  ア（本ソフトウェアを改変したものを含む．以下同じ）を使用・複製・改
#  変・再配布（以下，利用と呼ぶ）することを無償で許諾する．
#  (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
#      権表示，この利用条件および下記の無保証規定が，そのままの形でソー
#      スコード中に含まれていること．
#  (2) 本ソフトウェアを，ライブラリ形式など，他のソフトウェア開発に使
#      用できる形で再配布する場合には，再配布に伴うドキュメント（利用
#      者マニュアルなど）に，上記の著作権表示，この利用条件および下記
#      の無保証規定を掲載すること．
#  (3) 本ソフトウェアを，機器に組み込むなど，他のソフトウェア開発に使
#      用できない形で再配布する場合には，次のいずれかの条件を満たすこ
#      と．
#    (a) 再配布に伴うドキュメント（利用者マニュアルなど）に，上記の著
#        作権表示，この利用条件および下記の無保証規定を掲載すること．
#    (b) 再配布の形態を，別に定める方法によって，TOPPERSプロジェクトに
#        報告すること．
#  (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
#      害からも，上記著作権者およびTOPPERSプロジェクトを免責すること．
#      また，本ソフトウェアのユーザまたはエンドユーザからのいかなる理
#      由に基づく請求からも，上記著作権者およびTOPPERSプロジェクトを
#      免責すること．
#
#  本ソフトウェアは，AUTOSAR（AUTomotive Open System ARchitecture）仕
#  様に基づいている．上記の許諾は，AUTOSARの知的財産権を許諾するもので
#  はない．AUTOSARは，AUTOSAR仕様に基づいたソフトウェアを商用目的で利
#  用する者に対して，AUTOSARパートナーになることを求めている．
#
#  本ソフトウェアは，無保証で提供されているものである．上記著作権者お
#  よびTOPPERSプロジェクトは，本ソフトウェアに関して，特定の使用目的
#  に対する適合性も含めて，いかなる保証も行わない．また，本ソフトウェ
#  アの利用により直接的または間接的に生じたいかなる損害に関しても，そ
#  の責任を負わない．
#
#  $Id: com_port.rb 1801 2015-03-27 06:34:43Z t_ishikawa $
#

# 要インストール：$ gem install serialport
require "rubygems"
require "serialport"

Thread.abort_on_exception = true

# 引数1: CORE0からのオフセット
nOffset = 0
if (ARGV.size() >= 1)
  nOffset = ARGV[0].to_i()
end

# 引数2: 終了フラグ
bTerminate = false
if (ARGV.size() >= 2)
  bTerminate = ARGV[1]
end


# ctrl+cによる強制終了設定
Signal.trap(:SIGINT){
  system("kill -9 #$$")
}


# ポート判定
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

# COMポートが存在しない場合は終了
if (aPorts.empty?())
  puts("COM port is not found.")
  exit(1)
end

nPreNum = -1
nTargetPort = -1
aPorts.sort.reverse.each{|nNumber|
  if (nPreNum == -1)
    nPreNum = nNumber
    # ポートが1つのみだった場合への対応
    nTargetPort = nNumber
  else
    # 大きい方から数えて連番でなくなった数値を対象ポートとする
    if (!((nPreNum - nNumber) == 1))
      nTargetPort = nPreNum
      break
    else
      nPreNum = nNumber
      # 全て連番となっていた場合への対応
      nTargetPort = nNumber
    end
  end
}


# CORE0からのオフセット補正
nTargetPort += nOffset


# USBを挿した直後への対応
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
      # CORE0もしくは終了フラグがfalseでない場合のみ終了する
      if ((nOffset == 0) || (bTerminate != false))
        break
      end
    end
  end

  cCom.close()
}


# COMポート接続中もctrl+cで強制終了するためのダミースレッド
thDummy = Thread.new {
  while true
    sleep(1)
  end
}

# 3時間でタイムアウト
# (シリアル受信が停止した場合への対処)
result = thMain.join(10800)
if (result.nil?())
  puts("[com_port.rb] timeout!!")
  cCom.close()
end

