#naive solution
class Solution:
    def reduceUgly(self, a, b):
        while a%b == 0:
            a /= b
        return a
    
    def isUgly(self, num: int) -> bool:
        
        num = self.reduceUgly(num, 2)
        num = self.reduceUgly(num, 3)
        num = self.reduceUgly(num, 5)
        
        if num == 1: return True
        else: return False
        