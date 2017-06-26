#!/bin/sh
SRCDIR="../.."
#  ABREX
ABREX="${SRCDIR}/utils/abrex/abrex.rb"
#  コンフィギュレーションスクリプト
CFG="${SRCDIR}/configure"
#  ターゲット略称
TARGET="nios2_dev_gcc"
#  アプリケーションプログラム名
APPLNAME="lwip_test"
#  コンフィギュレーションファイル名
CFGNAME="${APPLNAME}"
#  アプリケーションのディレクトリ名
APPLDIR="${SRCDIR}/PRG/${APPLNAME}"
#  オブジェクトファイル名
APPLOBJS="lwip_test.o"
#  テンプレートディレクトリ名
TPLDIR=${APPLDIR}

#  コンパイル結果の消去
make realclean
#  XMLファイルの生成
for file in `find ${APPLDIR} -name "*.yaml"`; do
  ruby ${ABREX} $file
done
#  プログラムの構築
perl ${CFG} -T ${TARGET} -A ${APPLNAME} -C "${CFGNAME}" -a ${APPLDIR} -U "${APPLOBJS}" -t ${TPLDIR} -s
make depend 2> error.txt
make all 2>> error.txt
#make depend &> error.txt
#make all &>> error.txt
#  プログラムの実行
#make run
