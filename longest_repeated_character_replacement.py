class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        maxcnt, res = 0, 0
        counts = collections.Counter() #[0] * 26
        for i in range(len(s)):
            counts[s[i]] += 1
            maxcnt = max(maxcnt, counts[s[i]])
            if res - maxcnt < k:
                res += 1
                #print('Curr res:'+ str(res))
            else:
                counts[s[i - res]] -= 1
                #print(str(s[i - res]) + "--" + str(counts[s[i - res]]))
        return res
            
            