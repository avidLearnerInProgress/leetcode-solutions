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
    int diff = INT_MAX, prev = -1;
    
    int helper(TreeNode *root) {
        
        if(!root) return 0;
        
        if(root->left)
            helper(root->left);
          
        if(prev >= 0){
            diff = min(diff, root->val - prev);
        }
         prev = root->val;
        
        if(root->right)
            helper(root->right);
        
        return diff;
    }
    
    int minDiffInBST(TreeNode* root) {
        int result = helper(root);
        return result == INT_MAX ? -1 : result;
    }
};
