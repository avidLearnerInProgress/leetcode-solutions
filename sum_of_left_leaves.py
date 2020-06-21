# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sumOfLeftLeaves(self, root: TreeNode, isLeft = False) -> int:
        if not root : return 0
        if not root.left and not root.right:
            return root.val * isLeft
        return self.sumOfLeftLeaves(root.left, True) + self.sumOfLeftLeaves(root.right)s