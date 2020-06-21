class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        #Boyer - Moore Major Vote Algorithm
        
        major, count = nums[0], 1
        for i in range(1, len(nums)):
            if count == 0:
                count += 1
                major = nums[i]
            elif major == nums[i]:
                count += 1
            else:
                count -= 1
        return major
    
    #normal sorting
    #return sorted(nums)[len(nums)//2]