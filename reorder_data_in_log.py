# best when solved with Python instead of C++. custom sorter in c++ is too complicated unnecessarily
class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        def stable_sort(log):
            left, right = log.split(' ', 1)
            if right[0].isalpha():
                return (0, right, left)
            else:
                return (1, None, None)
        return sorted(logs, key = stable_sort)
       
