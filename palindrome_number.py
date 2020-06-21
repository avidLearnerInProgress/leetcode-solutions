class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x is None:
            return True
        reversin = list(str(x))
        reversin.reverse()
        reversing = ''.join(reversin)
        if reversing == str(x):
            return True
        else:
            return False