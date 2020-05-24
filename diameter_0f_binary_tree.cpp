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
    int findDia(TreeNode* root){
        if(!root)
            return 0;
        int lh = findDia(root->left);
        int rh = findDia(root->right);
        ans = max(ans,1+lh+rh);
        return 1+max(lh,rh);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        ans=0;
        findDia(root);
        return ans>0?ans-1:0;
    }
};