# from collections import Counter
# class Solution:
#     def longestPalindrome(self, s: str) -> int:
#         hashed = dict(Counter(s))
#         sz, szz = 1, len(s)
#         for ele in hashed.values():
#             if ele % 2 == 0:
#                 sz +=  (ele -1)
#             else:
#                 sz += ele
#         if sz > szz:
#             return szz
#         else:
#             return sz
class Solution(object):
    from collections import Counter
    def longestPalindrome(self, s):
        m = set()
        count = 0
        for c in s:
            if c in m:
                m.remove(c)
                count += 1
            else:
                m.add(c)
        return count *  2 + 1 if len(m) != 0 else count * 2
       
            
            
