/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    int ans;
public:
    int maxPathRec(TreeNode* root){
        if(!root) return 0;
        
        int l = max(0, maxPathRec(root->left));
        int r = max(0, maxPathRec(root->right));
        
        ans = max(ans, l+r+root->val);
        return max(l, r) + root->val;
    }
    
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        maxPathRec(root);
        return ans;
    }
};
