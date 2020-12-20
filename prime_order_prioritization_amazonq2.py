#!/bin/python3

import math
import os
import random
import re
import sys


#
# Complete the 'sortOrders' function below.
#
# The function is expected to return a STRING_ARRAY.
# The function accepts STRING_ARRAY orderList as parameter.
#
import re, collections
def sortOrders(orderList):
    # Write your code here
    
    primes, nonprimes = [], []
    
    for order in orderList:
        metadata = order.split()
        if re.search('(^\d+$)', metadata[1]):
            nonprimes.append(order)
        else:
            primes.append(order)
    primes.sort(key = lambda k : k.split(' ', 1)[1])
    return primes + nonprimes    
