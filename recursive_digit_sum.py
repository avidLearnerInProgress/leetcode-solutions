#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'superDigit' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. STRING n
#  2. INTEGER k
#

def recursiveSumStr(num):
    ints = [int(i) for i in num]
    return sum(ints)

def recursiveSumInts(num):
    return sum([int(i) for i in str(num)])

    
def superDigit(n, k):
    # Write your code here
    super_digit = 0
    
    intermediate_digit = recursiveSumStr(n) * k
    while intermediate_digit % 10 != intermediate_digit:
        intermediate_digit = recursiveSumInts(intermediate_digit)
    return intermediate_digit
    
    
    
        

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n = first_multiple_input[0]

    k = int(first_multiple_input[1])

    result = superDigit(n, k)

    fptr.write(str(result) + '\n')

    fptr.close()
