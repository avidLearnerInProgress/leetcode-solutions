class Solution:
    def maxRotateFunction(self, A: List[int]) -> int:
        if len(A) == 0:
            return 0
        totalSum = sum(A)
        lMax = 0 
        for i in range(len(A)):
            lMax += i * A[i]
        gMax = lMax
        for i in range(len(A)-1, 0, -1):
            lMax += (totalSum - A[i] * len(A))
            gMax = max(gMax, lMax)
        return gMax 
