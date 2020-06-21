class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        strings = [""] * numRows
        nR = numRows
        steps, row = 0, 0
        for c in s:
            strings[row] += c
            if row == 0: steps = 1
            if row == nR - 1: steps = -1
            row += steps        
        s = str()
        
        for li in strings:
            s += str(li)
        return s