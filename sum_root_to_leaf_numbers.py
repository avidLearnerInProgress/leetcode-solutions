# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
        self._sum = 0
    
    def util(self, root, c):
        if root == None:
            return
        
        c = c*10 + root.val #sum
        
        if root.left == None and root.right == None: #cummulative sum
            self._sum += c
        
        self.util(root.left, c)
        self.util(root.right, c)
        c /= 10 #used for backtracking from left to right node
        
    
    def sumNumbers(self, root: TreeNode) -> int:
        self.util(root, 0)
        return self._sum