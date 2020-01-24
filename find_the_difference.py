class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        from collections import Counter
        hashed_s, hashed_t = dict(Counter(s)), dict(Counter(t))
        found = ""
        for char in t:
            if char not in hashed_s:
                found = char
                return found
            elif hashed_s[char] != hashed_t[char]:
                found = char
                return found
        return None