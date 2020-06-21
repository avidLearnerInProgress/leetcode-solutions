class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        d = {}
        for a, b in zip(s, t):
            if a in d:
                if d[a] != b:
                    return False
            else:
                d[a] = b
        sett = set(d.values())
        
        if len(d.values()) == len(sett):
            return True
        else:
            return False