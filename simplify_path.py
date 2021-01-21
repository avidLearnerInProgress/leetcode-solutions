from collections import deque
class Solution:
    def simplifyPath(self, path: str) -> str:
        s = deque()
        for node in path.split('/'):
            if node == '..':
                if s:
                    s.pop()
            elif node and node != '.':
                s.append(node)
        return "/" + "/".join(s)
