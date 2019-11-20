#!/bin/python3

import math
import os
import random
import re
import sys


'''
It contains at least one special character. The special characters are: !@#$%^&*()-+ 
'''

# Complete the minimumNumber function below.
def minimumNumber(n, password):
    # Return the minimum number of characters to make the password strong
    numbers = "0123456789"
    lower_case = "abcdefghijklmnopqrstuvwxyz"
    upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    special_characters = "!@#$%^&*()-+"

    def checkNumbers(pwd):
        if not pwd: return 0
        return any(char.isdigit() for char in pwd)
        return 0
    
    def checkLower(pwd):
        if not pwd: return 0
        return any(char.islower() for char in pwd)
        return 0
    
    def checkUpper(pwd):
        if not pwd: return 0
        return any(char.isupper() for char in pwd)
        return 0

    def checkSpecial(pwd):
        if not pwd: return 0
        return any(char in special_characters for char in pwd)
        return 0
    
    count = 0
    if not checkSpecial(password):
        count += 1
    if not checkLower(password):
        count += 1
    if not checkUpper(password): 
        count +=1
    if not checkNumbers(password):
        count += 1
    return max(count, 6 - n)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    password = input()

    answer = minimumNumber(n, password)

    fptr.write(str(answer) + '\n')

    fptr.close()
