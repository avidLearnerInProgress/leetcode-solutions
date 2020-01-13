In DFS/recursive implementation you may end up going down one sub-tree and explore all the nodes.
In BFS there are chances we find solution faster as we do level order traversal and return depth of first leaf node.

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if not root: return 0
        queue = []
        queue.append({'n':root, 'd':1})
        
        while len(queue)>0:
            ele = queue.pop(0)
            node, depth = ele['n'], ele['d']
            if(node):
                if node.left is None and node.right is None:
                    return depth
                if node.left is not None:
                    queue.append({'n':node.left, 'd':depth + 1})
                if node.right is not None:
                    queue.append({'n':node.right, 'd':depth + 1})
