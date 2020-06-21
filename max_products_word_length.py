class Solution:
    def maxProduct(self, words: List[str]) -> int:
        n, maxres = len(words), 0
        wordsset = [set(i) for i in words]
        for i in range(n):
            for j in range(i+1,n):
                for char in wordsset[j]:
                    if char in wordsset[i]:
                        break
                else:
                    maxres = max(maxres, len(words[i])*len(words[j]))
        return maxres