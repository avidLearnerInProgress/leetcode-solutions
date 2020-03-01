class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        if (len(nums) < 2):
            return len(nums)
        # create array of diffs
        diffs = []
        for i in range(1, len(nums)):
            x = nums[i] - nums[i - 1]
            # ignore diffs of 0 as they don't count as turning points
            if (x != 0):
                diffs.append(x)
        # if there were diffs of only 0, then seq length is 1
        if (not diffs):
            return 1
            
        cnt = 1 # min seq length at this stage
        # now count the number of times the sign of diff between consecutive numbers changes
        # that will be equal to the max wiggle subseq length
        for i in range(1, len(diffs)):
            prod = diffs[i] * diffs[i - 1]
            if (prod < 0):
                cnt += 1
                
        return cnt + 1