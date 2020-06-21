class Solution:
    def reverseWords(self, s: str) -> str:
        parts = s.strip().split(' ')
        print(parts)
        revst = []
        pparts = []
        for p in parts:
            if p != "":
                pparts.append(p)
        for i in range(len(pparts)):
            revst.append(pparts[i])
        rev = revst[::-1]
        return ' '.join(rev)
    