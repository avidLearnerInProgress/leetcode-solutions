# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def averageOfLevels(self, root: TreeNode) -> List[float]:
        levels, queue = [],[root]
        while queue:
            levels.append(sum([e.val for e in queue]) / float(len(queue)))
            queue = [ee for e in queue for ee in [e.left,e.right] if ee]
        return levels