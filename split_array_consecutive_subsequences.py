class Solution:
    def isPossible(self, nums: List[int]) -> bool:
        from collections import defaultdict
        occurrences, next_nums = defaultdict(int), defaultdict(int)
        for num in nums:
            occurrences[num] += 1
        for num in nums:
            if occurrences[num] == 0:
                continue 
           # If next_nums contains the number, it is directly appendable to a sequence.
           # We "append" it to the sequence by incrementing the next number by 1.
            elif next_nums[num] > 0:
                next_nums[num] -= 1
                next_nums[num + 1] += 1
           # If the number + 1 and the number + 2 are both still in the occurrences hashmap,
           # We can create a new subsequence of length 3 and add the next number to next_nums.
            elif occurrences[num + 1] > 0 and occurrences[num + 2] > 0:
                occurrences[num + 1] -= 1
                occurrences[num + 2] -= 1
                next_nums[num + 3] += 1
            else:
                return False
            occurrences[num] -= 1
        return True
