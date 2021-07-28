# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if not root or not p or not q: 
            return None
        
        #max of two < root; then the other has to be less than root which means that both p and q lie in left subtree
        if (max(p.val, q.val) < root.val):
            return self.lowestCommonAncestor(root.left, p, q)
            
        #min of two > root; then the other has to be greater than root which means that both p and q lie in right subtree
        elif min(p.val, q.val) > root.val:
            return self.lowestCommonAncestor(root.right, p, q)
        
        else:
            return root
        
