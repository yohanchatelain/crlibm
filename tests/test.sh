#!/bin/bash

for i in `seq 3`; do
    VFC_BACKENDS=libinterflop_mca.so make check    
    for f in $(cat functions_list.txt); do
	mv check_${f}.log check_${f}.log.$i
    done
done
