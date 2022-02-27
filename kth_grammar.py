class Solution:
    def kthGrammar(self, n: int, k: int) -> int:
        # pattern - 
        # for nth row 
        # + mutate the (n-1)th row 
        # + negate the (n-1)th row
        
        if n == 1 or k == 1:
            return 0
        
        mid = pow(2, n - 1) // 2
        
        if k <= mid:
            return self.kthGrammar(n - 1, k)
        else:
            return (int) (not self.kthGrammar(n - 1, k - mid)) 
