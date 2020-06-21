class Solution:
    def nthUglyNumber(self, n: int) -> int:
        
        inc2, inc3, inc5 = 0, 0, 0
        nxt2, nxt3, nxt5 = 2, 3, 5
        ugly = [0] * n
        ugly[0] = 1
        for i in range(1,n):
            nxt = min(nxt2, nxt3, nxt5)
            ugly[i] = nxt
            if ugly[i] == nxt2:
                inc2 += 1
                nxt2 = ugly[inc2] * 2
            if ugly[i] == nxt3:
                inc3 += 1    
                nxt3 = ugly[inc3] * 3
            if ugly[i] == nxt5:
                inc5 += 1
                nxt5 = ugly[inc5] * 5
        return ugly[-1]
        
            