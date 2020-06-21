#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the isValid function below.
def isValid(s):
    
    freqCounts = [s.count(char) for char in set(s) ]
    print(freqCounts)
    
    if max(freqCounts) - min(freqCounts) == 0: #all frequencies are same
        return 'YES'
        
    #If difference between highest count and lowest count is 1
    #and there is only one letter with highest count, 
    #then return 'YES' (because we can subtract one of these 
    #letters and max=min , i.e. all counts are the same)
    
    elif freqCounts.count(max(freqCounts)) == 1 and max(freqCounts) - min(freqCounts) == 1:
        return 'YES'
    
    #If the minimum count is 1
    #remove this character, and check whether all the other counts are the same
    
    elif freqCounts.count(min(freqCounts)) == 1:
        freqCounts.remove(min(freqCounts))
        if max(freqCounts)-min(freqCounts) == 0:
            return 'YES'
        else:
            return 'NO'
    else:
        return 'NO'
        
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = isValid(s)

    fptr.write(result + '\n')

    fptr.close()
