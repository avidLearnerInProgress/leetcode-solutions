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
public:
    int min_ = INT_MAX, tc = -1;
    
    int getMinimumDifference(TreeNode* root) {
        if(!root) return 0;
        if(root->left)
            getMinimumDifference(root->left);
        if(tc>=0) min_ = min(min_, root->val - tc);
        tc = root->val;
        if(root->right)
            getMinimumDifference(root->right);
        return min_;
    }
};