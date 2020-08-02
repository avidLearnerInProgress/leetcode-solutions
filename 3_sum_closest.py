class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        length = len(nums)
        if length <= 2: return 0
        nums.sort()
        result = sum(nums[:3])
        
        for i in range(length - 2):    
            a_ptr = i + 1 #second sum
            b_ptr = length - 1 #third sum
            
            while a_ptr < b_ptr: #normal two pointer technique
                current_sum = nums[i] + nums[a_ptr] + nums[b_ptr]
                if current_sum > target: b_ptr -= 1
                else: a_ptr += 1
                
                if abs(current_sum - target) < abs(result - target):
                    result = current_sum
        return result
