class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        from collections import deque    
        n,m = len(grid), len(grid[0])
        fresh = 0 #counts of 1's
        rotten = deque([])

        for i in range(n):
            for j in range(m):
                if grid[i][j] == 2: rotten.append((i, j)) #all 2's
                if grid[i][j] == 1: fresh += 1
        print(fresh)

        dir_x = [1, -1, 0, 0]
        dir_y = [0, 0, 1, -1]
        minutes = 0

        while rotten:
            #operations = 0 #bool check
            for _ in range(len(rotten)): 
                a, b = rotten.popleft()
                for x,y in zip(dir_x, dir_y):
                    X = a + x
                    Y = b + y
                    if 0 <= X < n and 0 <= Y < m and (grid[X][Y] == 1):
                        #print("Subtracting fresh..")
                        grid[X][Y] = 2
                        fresh -= 1
                        rotten.append((X, Y))
            minutes += 1
        return max(0, minutes-1) if fresh == 0 else -1
        