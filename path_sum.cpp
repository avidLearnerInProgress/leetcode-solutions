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
    
//     bool helper(TreeNode* root, int &sum) {
        
       
//     }
    
    bool hasPathSum(TreeNode* root, int sum) {
         //base cases
        if(!root) return false;
        if(!root->left && !root->right && root->val == sum) return true;
        
        //hypothesis
        sum -= root->val;
        
        //induction
        return hasPathSum(root->left, sum) or hasPathSum(root->right, sum);
    }
};

# # Definition for a binary tree node.
# # class TreeNode:
# #     def __init__(self, x):
# #         self.val = x
# #         self.left = None
# #         self.right = None

# class Solution:
#     def hasPathSum(self, root: TreeNode, sum: int) -> bool:
#         #root to leaf path --> inorder + subtract sum
#         if not root: return False
            
#         if not root.left and not root.right and root.val == sum:
#             return True
        
#         sum -= root.val
#         return self.hasPathSum(root.left, sum) or self.hasPathSum(root.right, sum)w
