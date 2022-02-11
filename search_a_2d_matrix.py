class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        
        '''
            1. find target row
            2. find target element from 1
        '''
        
        rowLen, colLen = len(matrix), len(matrix[0])
        top, bottom = 0, rowLen - 1
        
        while top <= bottom:
            centreRow = top + (bottom - top) // 2
            if target > matrix[centreRow][-1]: # target below centreRow
                top = centreRow + 1
            elif target < matrix[centreRow][0]: # target above centreRow
                bottom = centreRow - 1
            else: # target in centreRow
                break
            
        if not (top <= bottom): # element not found in matrix
            return False
    
        # centreRow = top + (bottom - top) // 2
        left, right = 0, colLen - 1
        while left <= right:
            middle = left + (right - left) // 2
            if target > matrix[centreRow][middle]: # target towards right
                left = middle + 1
            elif target < matrix[centreRow][middle]: # target towards left
                right = middle - 1
            else:
                return True
        return False
