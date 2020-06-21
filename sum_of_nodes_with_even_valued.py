
class Solution:
    def sumEvenGrandparent(self, root: TreeNode) -> int:
        if not root:
            return 0
        
        sum_ = 0
        queue = [(root, None, None)]
        
        while(queue):
            root, parent, grandparent = queue.pop()
            if grandparent and root and grandparent.val % 2 == 0:
                sum_ += root.val;
            
            if root.left:
                queue.append((root.left, root, parent))
                
            
            if root.right:
                queue.append((root.right, root, parent))
            
        return sum_