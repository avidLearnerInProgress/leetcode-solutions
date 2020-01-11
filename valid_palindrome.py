class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()
        stt = []
        for st in s:
            if st >= 'a' and st <= 'z' or st >= '0' and st <= '9':
                stt.append(st)
        print(stt)
        i = 0; j = len(stt) - 1
        
        while(i <= j):
            if stt[i] != stt[j]:
                return False
            i += 1
            j -= 1
        return True