# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def widthOfBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root: return 0
        if not root.left and not root.right: return 1
        queue = [(root, 0)]
        res = 0
        while queue:
            level = []
            for i in range(len(queue)):
                node = queue.pop(0)
                if node[0].left:            
                    level.append((node[0].left, node[1]*2))
                    
                if node[0].right:
                    level.append((node[0].right, node[1]*2 + 1))
            if level:
                res = max(res, level[-1][1] - level[0][1] + 1)
            queue = level
        return res
        