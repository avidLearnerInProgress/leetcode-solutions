class Solution:
    def backspaceCompare(self, str1: str, str2: str) -> bool:

      ptr1, ptr2 = len(str1) - 1, len(str2) - 1

      while ptr1 >= 0 or ptr2 >= 0:
        skipA, skipB = 0, 0

        while ptr1 >= 0:
          # counting a character two times // decrementing the pointer two times for every # that is encountered
          if str1[ptr1] == '#':
            skipA += 1
            ptr1 -= 1
          elif skipA > 0:
            skipA -= 1
            ptr1 -=1
          # for a non-hash char when the skip is 0(no # encountered so far) - compare chars
          else:
            print("skipA", skipA, ptr1)
            break

        while ptr2 >= 0:
          if str2[ptr2] == '#':
            skipB += 1
            ptr2 -= 1
          elif skipB > 0:
            skipB -= 1
            ptr2 -= 1
          else:
            print("skipB", skipB, ptr2)
            break
        
        if (ptr1 >= 0) != (ptr2 >= 0):
          return False

        if ptr1 >= 0 and ptr2 >= 0 and str1[ptr1] != str2[ptr2]:
          return False

        ptr1 -= 1
        ptr2 -= 1

      return True
