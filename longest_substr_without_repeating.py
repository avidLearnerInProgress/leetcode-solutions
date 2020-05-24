class Solution:
    def lengthOfLongestSubstring(self, s):
        dic, res, start, = {}, 0, 0
        for i, ch in enumerate(s):
            if ch in dic:
                # update the res
                res = max(res, i-start)
                # here should be careful, like "abba"
                start = max(start, dic[ch]+1)
            dic[ch] = i
        # return should consider the last 
        # non-repeated substring
        return max(res, len(s)-start)