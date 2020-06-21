# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
        def findTilt(self, root: TreeNode) -> int:
            if not root:
                return 0
            self._sum = 0
            def util(root):
                if not root:
                    return 0
                left, right = util(root.left), util(root.right)
                self._sum += abs(left - right)
                return root.val + left + right
            util(root)
            return self._sum