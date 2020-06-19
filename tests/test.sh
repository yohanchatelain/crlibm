#!/bin/bash

for i in `seq 10`; do
    VFC_BACKENDS=libinterflop_mca.so make check
    for c in check*.log ; do
	cp $c $c.$i
    done
    ./compute_stats.py $c
done
