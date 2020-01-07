#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the substrCount function below.
def substrCount(n, s):
    range_subStr = [1] * n
    substrCnt = n #1 for each n chars in s

    #two conditions
    #1. check for aa, aaa, aaaa, aaaaa etc.
    #2. check for symmetry with 1 middle char different aabaa, aba, aaabaaa etc..

    for i in range(1, n): #since we are doing backward comparison
        if s[i] == s[i-1]: #checks for 1.
            substrCnt += range_subStr[i-1]
            range_subStr[i] = range_subStr[i-1] + 1 #checks for count of prev char in sequence
        mid_different = i - range_subStr[i] - 1
        if mid_different >= 0: #there exists a symmetric pattern with middle as different
            if s[i] == s[mid_different] and range_subStr[mid_different] >= range_subStr[i]:
                substrCnt += 1
    return substrCnt 

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    n = int(input())
    s = input()
    result = substrCount(n, s)
    fptr.write(str(result) + '\n')
    fptr.close()