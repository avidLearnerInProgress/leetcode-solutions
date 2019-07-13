class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix:
            return []
        sz, sz0 = len(matrix) - 1, len(matrix[0]) - 1
        rowBegin, rowEnd, colBegin, colEnd = 0, sz, 0, sz0
        ans = []
        while rowBegin <= rowEnd and colBegin <= colEnd:
            #left to right
            for i in range(colBegin, colEnd + 1):
                ans.append(matrix[rowBegin][i])
            rowBegin += 1
            
            #top to bottom
            for i in range(rowBegin, rowEnd + 1):
                ans.append(matrix[i][colEnd])
            colEnd -= 1
            
            #right to left
            if rowBegin <= rowEnd:
                for i in range(colEnd, colBegin - 1, -1):
                    ans.append(matrix[rowEnd][i])
                rowEnd -= 1
            
            #bottom to top
            if colBegin <= colEnd:
                for i in range(rowEnd, rowBegin - 1, -1):
                    ans.append(matrix[i][colBegin])
                colBegin += 1
        return ans
                
            