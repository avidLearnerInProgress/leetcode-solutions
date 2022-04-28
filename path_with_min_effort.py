class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        def withinBounds(x, y, rowLen, colLen, visited):
            return x >= 0 and x < rowLen and y >= 0 and y < colLen and (x, y) not in visited        
    
        heap = []
        heap.append((0, 0, 0)) # (cost, row, col)
        
        visited = set()
        rowLen, colLen = len(heights), len(heights[0])
        while heap:
            cost, row, col = heappop(heap)
            if row == rowLen - 1 and col == colLen - 1:
                return cost
            
            if (row, col) in visited:
                continue

            
            visited.add((row, col))
            for neighbor in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                x = row + neighbor[0]
                y = col + neighbor[1]
                
                if withinBounds(x, y, rowLen, colLen, visited):
                    heappush(heap, (max(cost, abs(heights[x][y] - heights[row][col])), x, y))
