#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the alternatingCharacters function below.
def alternatingCharacters(s):
    st, i, dupCnt = [], 0, 0
    for c in s:
        if not st:
            st.append(c)
        elif st[-1] == c:
            dupCnt += 1
        else:
            st.append(c)
    return dupCnt
    
    '''
    dupCnt = 0
    for i in range(len(s) - 1):
        if s[i] == s[i+1]:
            dupCnt += 1
    return dupCnt
    '''

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input())

    for q_itr in range(q):
        s = input()

        result = alternatingCharacters(s)

        fptr.write(str(result) + '\n')

    fptr.close()
