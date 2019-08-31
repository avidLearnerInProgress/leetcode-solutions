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
    vector<int> result;
    
    void traversal(TreeNode *root){
        if(!root) return;
        traversal(root->left);
        result.push_back(root->val);
        traversal(root->right);
    }
    
    
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;
        traversal(root);
        
        int ans = *(result.begin() + k - 1);
        cout<<ans;
        return ans;
    }
};