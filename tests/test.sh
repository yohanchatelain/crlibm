#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "usage: ./test.sh <mode>"
    exit 1
fi

mode=$1
ROOT=${mode^^}
mkdir -p ${mode^^}

for i in `seq 20`; do
    VFC_BACKENDS="libinterflop_mca.so --mode=$mode" make check
    for f in $(cat functions_list.txt); do
	EXP=${mode^^}_EXP_${f}
	mkdir -p $ROOT/$EXP
	mv check_${f}.log ${ROOT}/${EXP}/check_${f}.log.$i
    done
done
