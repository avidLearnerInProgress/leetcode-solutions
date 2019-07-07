class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        sum_, carry = 0, 0
        i = len(digits) - 1
        while i>=0:
            if i == len(digits) - 1:
                sum_ = carry + digits[-1] + 1        
            else:
                sum_ = carry + digits[i]
            if sum_ > 9:
                carry = 1
                digits[i] = 0
                i -= 1
                continue
            else:
                digits[i] = sum_
                break
        if digits[0] == 0 and carry == 1:
            new_digits = digits.insert(0, 1)
        #print(digits)
        return digits