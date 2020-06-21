class Solution:
    def wordPattern(self, pattern: str, str: str) -> bool:
        words = str.split()
        p = list(pattern)
        x1 = []
        x2 = []
        y1 = []
        y2 = []
        
        for i in p:
            if i not in x1:
                x1.append(i)
            x2.append(x1.index(i))
        
        for j in words:
            if j not in y1:
                y1.append(j)
            y2.append(y1.index(j))
            
        print(x2)
        print(y2)
        return x2 == y2