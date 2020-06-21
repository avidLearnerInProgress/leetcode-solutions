#mysolution
class Solution:
    def flipAndInvertImage(self, A: List[List[int]]) -> List[List[int]]:
        A_rev = [x[::-1] for x in A]
        # print(A_rev)
        A_inv = []
        for ls in A_rev:
            curr, t = ls, []
            for i in range(len(curr)):
                if curr[i] == 1:
                    t.append(0)
                else:
                    t.append(1)
            A_inv.append(t)  
        return A_inv

#optimised
class Solution:
    def flipAndInvertImage(self, A: List[List[int]]) -> List[List[int]]:
        return [[1 ^ i for i in x[::-1]] for x in A]            