# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class FindElements:
    #dfs
    def __init__(self, root: TreeNode):
        self.res = set()
        x = [(root, 0)]
        
        while x:
            node, value = x.pop(0)
            node.val = value
            self.res.add(value)
            if node.left:
                x.append((node.left,(2*value+1)))
            if node.right:
                x.append((node.right,(2*value+2)))
                
    def find(self, target: int) -> bool:
        return target in self.res


# Your FindElements object will be instantiated and called as such:
# obj = FindElements(root)
# param_1 = obj.find(target)
