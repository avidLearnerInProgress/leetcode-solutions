# Based on approach mentioned here -> https://leetcode.com/problems/regular-expression-matching/discuss/991342/C%2B%2B-Bottom-up-dp-solution-with-detailed-comments-from-O(mn)-space-to-O(n)-space

class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        m, n = len(s), len(p)
        
        dp = [[False for _ in range(n+1)] for _ in range(m+1)]
        dp[0][0] = True
        
        
        for j in range(2, n+1):
            if p[j-1] == "*":
                dp[0][j] = dp[0][j-2]
                
        
        for i in range(1,m+1):
            for j in range(1,n+1):                
                if p[j-1] != "*":
                    dp[i][j] = dp[i-1][j-1] and (p[j-1] == "." or p[j-1] == s[i-1])
                else:
                    dp[i][j] = (dp[i-1][j] and ( (p[j-2] == '.')or(p[j-2] == s[i-1]) )) or dp[i][j-2]
        
        return dp[m][n]
                    
        	
