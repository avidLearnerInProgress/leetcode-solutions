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
    
    int util(TreeNode *root, int &count, int k){
        if(!root) return -1;
        
        auto lval = util(root->left, count, k);
        if(lval != -1) return lval;
        
        count++;
        if(count == k) return root->val;
        
        auto rval = util(root->right, count, k);
        if(rval != -1) return rval;
        
        return -1;
    } 
    
    
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return -1;
        int count = 0;
        return util(root, count, k); 
    }
};s