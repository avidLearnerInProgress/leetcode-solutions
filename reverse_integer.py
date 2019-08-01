class Solution:
    def reverse(self, x: int) -> int:
        if x == 0:
            return 0
        elif x < 0:
            s = -1
        else:   
            s = 1
        x = list(str(x * s))
        x.reverse()
        res = int("".join(x))
        return res * s if res < 0x7fffffff else 0