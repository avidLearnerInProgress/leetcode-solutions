class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        
        for i in range(len(nums)):
            m = abs(nums[i]) - 1
            if nums[m] > 0:
                nums[m] = -nums[m]
        res = []
        for i in range(len(nums)):
            if nums[i] > 0:
                res.append(i + 1)
        return res
            
            
            
