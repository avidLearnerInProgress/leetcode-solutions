class Solution:
    def commonChars(self, A: List[str]) -> List[str]:
        
        ''' wrong approach --
        res, hash_ = [], dict()
        clist = [c for ele in A for c in ele]
        for ch in clist:
            hash_[ch] = hash_.get(ch, 0) + 1
        for ele, c in hash_.items():
            if c%len(A) == 0:
                res.append(ele)
        return res
        '''
        
        #Naive non-pythonic code
        '''
        fin_res = []
        check = set(A[0])
        for l in check:
            res = min([a.count(l) for a in A])
            print(res)
            fin_res.append([l] * res)
        fi = [i for x in fin_res for i in x]
        return sorted(fi)
        '''
        #power of list comprehensions
        check = set(A[0])
        result = [[l] * min([a.count(l) for a in A]) for l in check]
        return sorted([i for e in result for i in e])
        
        