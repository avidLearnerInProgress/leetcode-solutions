from collections import Counter
class Solution:
    def longestPalindrome(self, s: str) -> int:
        hashed = dict(Counter(s))
        sz, szz = 1, len(s)
        for ele in hashed.values():
            if ele % 2 == 0:
                sz +=  (ele -1)
            else:
                sz += ele
        if sz > szz:
            return szz
        else:
            return sz