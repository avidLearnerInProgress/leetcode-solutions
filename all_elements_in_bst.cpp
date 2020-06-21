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
private:
    vector<int> tp;
    
    void traverse(TreeNode *root){
        if(!root) return;
        traverse(root->left);
        tp.push_back(root->val);
        traverse(root->right);
     }    
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        traverse(root1);
        traverse(root2);
        sort(tp.begin(), tp.end());
        return tp;
        
    }
};