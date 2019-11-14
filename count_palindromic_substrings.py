class Solution:
        def countSubstrings(self, s):

            leftrights = [(x,x) for x in list(range(len(s)))] + [(x,x+1) for x in list(range(len(s)-1))]
            count = 0
            for left, right in leftrights:
                while left >= 0 and right < len(s) and s[left]==s[right]:
                    count += 1
                    left -= 1
                    right += 1
            return count
