class Solution:
    def waysToSplit(self, nums: List[int]) -> int:
        # Calculate prefix & define variables
        N = len(nums)
        prefix = [0] * (N + 1)
        mod = 10 ** 9 + 7
        for i in range(1, N + 1):  
            prefix[i] = prefix[i-1] + nums[i-1]

        l, r, cnt = 0, 0, 0
        for i in range(1, N + 1):
            l = max(l, i + 1)

            # find the first l such that mid >= left
            while(l < N and prefix[i] > prefix[l] - prefix[i]):
                l += 1

            r = max(r, l)

            # find the last r such that right >= mid
            # so that for any r in this range [l, r]
            # left <= mid <= right is True
            while(r < N and prefix[r] - prefix[i] <= prefix[-1] - prefix[r]):
                r += 1

            cnt = (cnt + r - l) % mod
        return cnt
