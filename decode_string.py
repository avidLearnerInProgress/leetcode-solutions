class Solution:
    def decodeString(self, s: str) -> str:
        prevStr, currStr, currNum = '', '', 0
        decode, ans = [], ''
        for ch in s:
            if ch == '[':
                decode.append(currNum)
                decode.append(currStr)
                currStr = ''
                currNum = 0
            elif ch == ']':
                prevStr = decode.pop()
                digit = decode.pop()
                currStr = prevStr + (currStr * digit)
            elif ch.isdigit():
                currNum = currNum * 10 + int(ch)
            else:
                currStr += ch            
        return currStr
