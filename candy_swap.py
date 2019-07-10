class Solution:
    def fairCandySwap(self, A: List[int], B: List[int]) -> List[int]:
        su = (sum(A) + sum(B)) // 2
        diffSum = su - sum(A)
        sb = set(B)
        for a in A:
            if diffSum + a in sb:
                return [a, diffSum + a]

'''
A [1, 1]
B [2, 2]

S = 6 // 2 = 3
diffSum = 3 - 2 = 1
if 1 + 1 in sb: 
    Yes -- 
    return [1 , 2]
'''