class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        
        dp = [[False for _ in range(len(p)+1)] for _ in range(len(s)+1)]

        for i in range(len(s) + 1):
            for j in range(len(p) + 1):
                start_s, start_p = i-1, j-1
                
                if i == 0 and j == 0: # first cell in the dp matrix
                    dp[i][j] = True
                
                elif i == 0: # first row in the dp matrix
                # for first char in string s, if the pattern character is *(0 or more matches.) and there is a previous index match in s and p; the n set the current i,j th cell to true else false. In this case, its 0 matches
                    dp[i][j] = dp[i][j-1] and p[start_p] == '*'
                
                elif j == 0: # first column in the dp matrix
                # for any character in the string s, if 
                    dp[i][j] = False
                    
                elif p[start_p] == '*': #if the current character in pattern is a star then there is a match or no match
                    dp[i][j] = dp[i-1][j] or dp[i][j-1]
                    
                    
                # if there is an exact match or a ? in pattern string
                elif p[start_p] == s[start_s] or p[start_p] == '?': # start_p = o-1
                    dp[i][j] = dp[i-1][j-1]
                    
        return dp[len(s)][len(p)]
