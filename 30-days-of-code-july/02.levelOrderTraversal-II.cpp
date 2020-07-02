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
        //BFS(root, 0);
        //return vector<vector<int>> (result.rbegin(), result.rend());
        
        queue<TreeNode *> q;
        q.push(root);
        
        vector<int> clevel;
        vector<vector<int>> alevel;
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                TreeNode *curr = q.front();
                q.pop();
                clevel.push_back(curr->val);
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            alevel.push_back(clevel);
            clevel.clear();
        }
        return vector<vector<int>> (alevel.rbegin(), alevel.rend());
    }
};