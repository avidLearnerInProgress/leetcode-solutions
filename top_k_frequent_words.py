from collections import Counter
class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        d = Counter(words)
        sorted_d = sorted(d.items(), key = lambda x: (-x[1], x[0]))
        return [x[0] for x in sorted_d][:k]