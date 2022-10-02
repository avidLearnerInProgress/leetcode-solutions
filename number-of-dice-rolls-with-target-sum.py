class Solution:
    def numRollsToTarget(self, n: int, k: int, target: int) -> int:
        dp = {}
        
        def dfs(idx, currSum):
            if idx == 0 and currSum == target:
                return 1
            if idx == 0 or currSum > target:
                return 0
            
            if (idx, currSum) in dp:
                return dp[(idx, currSum)]
            
            count = 0
            for i in range(1, k + 1): 
                count += dfs(idx - 1, currSum + i)
            dp[(idx, currSum)] = count
            
            return count
        return dfs(n, 0) % (10**9 + 7)