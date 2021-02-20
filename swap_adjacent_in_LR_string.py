class Solution:
    def canTransform(self, start: str, end: str) -> bool:
        if len(start) != len(end): return False
        i, j, l = 0, 0, len(start)
        while True:
            while i < l and start[i] == 'X': i += 1
            while j < l and end[j] == 'X': j += 1
            if i == l or j == l:
                if i == j: return True
                return False
            if start[i] != end[j]: return False
            if start[i] == 'L': 
                if i < j: return False
            #start[i] == 'R'
            else:
                if i > j: return False
            i, j = i+1, j+1
        
