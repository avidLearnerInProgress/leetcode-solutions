# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
        self.prev = None
        
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        #reverse postorder traversal
        
        """
        if not root: return None
    
        self.flatten(root.right)
        self.flatten(root.left)
        
        root.right = self.prev
        root.left = None
        self.prev = root
        
        