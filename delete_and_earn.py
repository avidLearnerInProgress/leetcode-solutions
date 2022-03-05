class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        def solve(nums: List[int], index: int) -> int:
            nonlocal memoize
            
            #base case
            n = len(nums)
            if index >= n:
                return 0
            
            #check for memoization
            if memoize[index] != -1:
                return memoize[index]
            
            #induction
            
            currValue = currSum = nums[index]
            nextIndex = index + 1
            
            while nextIndex < n and currValue == nums[nextIndex]: 
                currSum += nums[nextIndex] #prefix sum for same values
                nextIndex += 1
            
            while nextIndex < n and currValue + 1 == nums[nextIndex]: #skip
                nextIndex += 1
                
            
            memoize[index] = max(currSum + solve(nums, nextIndex), solve(nums, index + 1)) #pick, unpick
            
            return memoize[index]
        
        nums.sort()
        memoize = [-1 for _ in range(200001)] # constraints
        return solve(nums, 0)
        
