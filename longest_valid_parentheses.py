class Solution:
    def longestValidParentheses(self, s: str) -> int:
        if not s: return 0
        result, ind = 0, -1
        count, len_ = 0, 0
        for i in range(len(s)):
            len_ += 1
            if s[i] == '(':
                count += 1
            if s[i] == ')':
                count -= 1
            if count == 0 and len_ > result:
                result = len_
            if count < 0:
                len_, count = 0, 0
            
        len_, count = 0, 0
        for i in range(len(s)-1, -1, -1):
            len_ += 1
            if s[i] == ')':
                count += 1
            if s[i] == '(':
                count -= 1
            if count == 0 and len_ > result:
                result = len_
            if count < 0:
                len_, count = 0, 0
        
        return result