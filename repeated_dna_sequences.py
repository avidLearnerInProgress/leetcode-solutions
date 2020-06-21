class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        count=dict()
        return_=[]
        for i in range(0,len(s)-9):
            sub=s[i:i+10]
            if sub in count:
                if count[sub]:
                    return_.append(sub)
                    count[sub]=False
            else:
                count[sub]=True
        return return_