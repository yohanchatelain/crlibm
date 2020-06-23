#!/usr/bin/python3

import numpy as np
import sys
import os
import math
import matplotlib.pyplot as plt

# IO dict
# key: input, value: [outputs]

# key: function+RM, values: IO_dict
values_map = dict()

# 0     1   2     3    4        5
# Errro for <fct> with rounding <RM>
def get_function_name(line):
    splt = line.strip().split()
    if line.find("exit status") != -1:
        name = splt[1]
    else:
        name = splt[2] + splt[5]
    return name

# 0      1    2    3
# Input: <XH> <XL> (<input>)
def get_input(line):
    splt = line.strip().split()
    # return splt[1]+splt[2]
    value = splt[3]
    value = value.replace('(','')
    value = value.replace(')','')
    return np.float128(value)

# 0       1    2    3
# Output: <Xh> <Xl> (<output>)
def get_output(line):
    splt = line.strip().split()
    value = splt[3]
    value = value.replace('(','')
    value = value.replace(')','')
    return np.float128(value)
        
def add_key(key):
    if not key in values_map:
        values_map[key] = dict()

def add_input(key, i):
    if not i in values_map[key]:
        values_map[key][i] = []

def add_output(key, i, o):    
    values_map[key][i].append(o)
    
def parse_file(filename):

    fi = open(filename, 'r')
    
    key = ''
    i = None
    o = None
    for line in fi:
        l = line.strip()
        if l.startswith('ERROR'):
            key = get_function_name(l)
            add_key(key)
        elif l.startswith('Input'):
            i = get_input(l)
            add_input(key, i)
        elif l.startswith('Output'):
            o = get_output(l)
            add_output(key, i, o)
        else:
            continue
    

def get_list_filename(directory):
    ls = os.listdir(directory)
    return [directory + os.path.sep + f for f in ls if os.path.isfile(directory + os.path.sep + f)]
    
def get_s(mean, std):
    if mean==0:
        return 0
    elif std == 0:
        return 16
    else:
        return -math.log(abs(std/mean),10)

def get_stats():

    stats = dict()

    for function, values in values_map.items():
        print('Function: {f}'.format(f=function))
        stats[function] = dict()
        for inputs,outputs in values.items():
            na = np.array(outputs, dtype=np.float128)
            for a in na:
                if math.isnan(a):
                    print("NAN found")
            na = np.array([a for a in na if not math.isnan(a)])
            for a in na:
                if math.isinf(a):
                    print("INF found")
            na = np.array([a for a in na if not math.isinf(a)])
            if na.size > 0:
                mean = na.mean()
                std = na.std(dtype=np.float128)
                s = get_s(mean, std)
            else:
                s = 0
            stats[function][inputs] = s
                
            print('\tInput: {i}\t Mean: {m}\t Std: {std}\t S: {s}'.format(i=inputs,
                                                                          m=mean,
                                                                          std=std,
                                                                          s=s))

        stats[function] = dict(sorted(stats[function].items()))
    return stats

def plot(f,x,y):
    plt.plot(x,y,'.',label=f)

def log(k):
    if k==0:
        return 0
    else:
        return math.log(k,10)

# {MODE}_EXP_{function}
def get_title(directory):
    splt = directory.split("_")
    mode = splt[0].split('/')[0]
    function = splt[2]
    return "Function {fun} (mode {mode})".format(fun=function,
                                                 mode=mode)

if '__main__' == __name__:

    directory = sys.argv[1]
    print(directory)
    filenames_list = get_list_filename(directory)
    print(filenames_list)
    for f in filenames_list:
        parse_file(f)
        
    stats = get_stats()
    print(stats)

    title = get_title(directory)
    plt.title(title)

    for f in stats.keys():

        x = list([math.copysign(log(abs(k)),k) for k in stats[f].keys()])
        y = list(stats[f].values())
        print(f)
        print(len(x))
        plot(f,x,y)

    plt.xlabel("Inputs exponent")
    plt.ylabel("Number of significant digits (b=10)")
    plt.legend()
    savename = directory.split("_")[-1]
    plt.savefig(savename+'.pdf')
