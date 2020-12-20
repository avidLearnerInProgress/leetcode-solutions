#!/bin/python3

import math
import os
import random
import re
import sys



#
# Complete the 'distanceTraversed' function below.
#
# The function is expected to return an INTEGER.
# The function accepts 2D_INTEGER_ARRAY lot as parameter.
#

def distanceTraversed(lot):
    # Write your code here
    
    possible_moves = [[-1,0], [0, -1], [0, 1], [1, 0]]
    
    xmin = ymin = 0
    xmax = len(lot)
    ymax = len(lot[0])
    
    
    visited = [[0 for _ in range(ymax)] for _ in range(xmax)]
    visited[0][0] = 1
 
    queue = []
    queue.append([0,0,0])
    
    while queue:
        current = queue[0]
        if lot[current[0]][current[1]] == 9:
            return current[2]
        queue.pop(0)
        for i in range(4):
            nx = current[0] + possible_moves[i][0]
            ny = current[1] + possible_moves[i][1]
            if nx >= 0 and ny >= 0 and nx < xmax and ny < ymax:
                if lot[nx][ny] == 1 or lot[nx][ny] == 9 and not visited[nx][ny]:
                    visited[nx][ny] = 1
                    queue.append([nx, ny, current[2] + 1])
    return -1
