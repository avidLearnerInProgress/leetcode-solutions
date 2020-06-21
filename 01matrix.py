class Solution:
     def updateMatrix(self, A: List[List[int]]) -> List[List[int]]:
        def validNeighbours(i, j, d):
            for dx, dy in (1, 0), (-1, 0), (0, 1), (0, -1):
                ni, nj, dn = i + dx, j + dy, d + 1
                if 0 <= ni < len(A) and 0 <= nj < len(A[0]):
                    yield ni, nj, dn
               
        def bfs(i, j):
            dist = collections.defaultdict(lambda: float('inf'))
            queue = collections.deque([(i, j, 0)])
            while queue:
                i, j, d = queue.popleft()
                if A[i][j] == 0:
                    return d
                for ni, nj, dn in validNeighbours(i, j, d):
                    if dn < dist[(ni, nj)]:
                        dist[(ni, nj)] = dn
                        queue.append((ni, nj, dn))
            return A[i][j]
           
       
        for i in range(len(A)):
            for j in range(len(A[0])):
                if A[i][j] == 1:
                    A[i][j] = bfs(i, j)    
        return A