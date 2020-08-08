/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    public:
    //helper method
    int helper(TreeNode *root,int sum){
        if(root == nullptr) return 0;
        return (root->val==sum? 1 : 0) + helper(root->left, sum-root->val) + helper(root->right, sum-root->val);
    }
      
    int pathSum(TreeNode* root, int sum) {
        if(root == nullptr) return 0;
        return helper(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
};

# # Definition for a binary tree node.
# # class TreeNode:
# #     def __init__(self, x):
# #         self.val = x
# #         self.left = None
# #         self.right = None

# class Solution:
#     def pathSum(self, root: TreeNode, sum: int) -> int:
#         if not root:
#             return 0
#         return self.helper(root, sum) + self.pathSum(root.left, sum) + self.pathSum(root.right, sum)
    
#     def helper(self, root, sum):
#         if not root:
#             return 0
        
#         return (1 if root.val == sum else 0) + self.helper(root.left, sum - root.val) + self.helper(root.right, sum - root.val)
