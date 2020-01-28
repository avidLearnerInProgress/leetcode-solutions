class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        c = {}
        for num in nums: # O(n)
            if num in c:
                c[num] += 1
            else:
                c[num] = 1
        print(c)
        
        f = {}
        for num, freq in c.items(): # O(n)
            if freq not in f:
                f[freq] = [num] 
            else:
                f[freq].append(num)
        res = []
 
        for i in range(len(nums), -1, -1): # O(n)
            if i in f:
                res += f[i]
            if len(res) >= k:
                break
        return res[:k]