#https://ide.geeksforgeeks.org/vmx13r2tRM

#path to treasure island
from collections import deque

#bfs
def minimum_distance(island):
    if island is None or island == []: return 0
    
    #all okay, lets begin
    steps = 0 
    directions = [[1, 0], [-1, 0], [0, 1], [0, -1]] #left, right, up, down
    queue = deque() #to store directions
    rlen, clen, dirlen = len(island), len(island[0]), len(directions)
    visited =  [[0] * rlen for _ in range(clen)]
    #print(visited)
    
    queue.append((0, 0)) #start
    while queue:
        sz = len(queue)
        while sz > 0:
            x, y = queue.popleft() #get the co-ords of next in queue
            if island[x][y] == 'X': #found an obstacle, return condition for recursion
                return steps
            for i in range(dirlen): #find the deviations on basis of directions
                dx, dy = x + directions[i][0], y + directions[i][1]
                #check for edge-cases and if already explored
                if dx >= 0 and dy >= 0 and dx < rlen and dy < clen and (visited[dx][dy] == 0) and (island[dx][dy] == 'O' or island[dx][dy] == 'X'):
                    visited[dx][dy] = 1
                    queue.append((dx, dy))
            sz -= 1
        steps += 1

if __name__ == '__main__':
    island = [['O', 'O', 'O', 'O'], 
             ['D', 'O', 'D', 'O'], 
             ['O', 'O', 'O', 'O'], 
             ['O', 'D', 'X', 'O']]
    result = minimum_distance(island)
    print(result)
    