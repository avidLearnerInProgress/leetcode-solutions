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
    TreeNode* helper(const vector<int>& preorder, int &id, int limit){
        if(id == preorder.size() || preorder[id] > limit) return NULL;
        
        TreeNode *root = new TreeNode(preorder[id]);
        id++;
        root->left = helper(preorder, id, preorder[id]);
        root->right = helper(preorder, id, limit);
        return root;    
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int id = 0;        
        return helper(preorder, id, INT_MAX);
    }
};