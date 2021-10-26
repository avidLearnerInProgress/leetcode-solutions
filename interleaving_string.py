class Solution:
     def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        if len(s1) + len(s2) != len(s3): return False
        m, n = len(s1), len(s2)
        
        @lru_cache(None)
        def dp(i, j):
            if i == m and j == n: return True  # Found a valid match
            ans = False
            if i < m and s1[i] == s3[i+j]:  # Case match s1[i] with s3[i+j]
                ans |= dp(i + 1, j)
            if j < n and s2[j] == s3[i+j]:  # Case match s2[j] with s3[i+j]
                ans |= dp(i, j + 1)
            return ans

        return dp(0, 0) 
