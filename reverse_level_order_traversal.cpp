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
    vector<vector<int>> result;
    
    void BFS(TreeNode *root, int level){
        if(root == NULL) return;
        
        if(level == result.size()) result.push_back(vector<int>());
        
        result[level].push_back(root->val);
        
        BFS(root->left, level + 1);
        BFS(root->right, level  + 1);
        
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        if(root == NULL) return vector<vector<int>>();
        BFS(root, 0);
        return vector<vector<int>> (result.rbegin(), result.rend());
    }
};