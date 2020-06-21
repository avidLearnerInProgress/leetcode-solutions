class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        d = collections.deque()
        out = []
        for i, n in enumerate(nums):
            #print("i = {}, curr element = {}, d = {} and out = {}".format(i, n, d, out))
            while d and nums[d[-1]] < n:
                d.pop()
                #print("\t Popped from d because d has elements and nums[d.top] < curr element")
            d.append(i)
            #print("\t Added i to d")
            if d[0] == i - k:
                d.popleft()
                #print("\t Popped left from d because it's outside the window's leftmost (i-k)")
            if i>=k-1:
                out.append(nums[d[0]])
                #print("\t Append nums[d[0]] = {} to out".format(nums[d[0]]))
        return out