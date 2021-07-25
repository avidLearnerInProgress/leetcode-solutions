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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> result;
        queue<TreeNode* > qu;
        qu.push(root); 
        while(!qu.empty()) {
            int n = qu.size();
            for(int i = 0; i < n; i++) {
                auto current = qu.front();
                qu.pop();
                if(i == n-1) result.push_back(current->val);
                if(current->left) 
                    qu.push(current->left);
                if(current->right) 
                    qu.push(current->right);
            }       
        }
        return result;
    }
};                  
