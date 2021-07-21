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
    
    //recursive
    
    void helper(TreeNode *root, string s, vector<string> &result) {
        if(!root) return;
        if(!root->left and !root->right) {
            result.push_back(s + to_string(root->val));
            return;
        }
        
        else {
            if(root->left)
                helper(root->left, s + to_string(root->val) + "->", result);
            
            if(root->right)
                helper(root->right, s + to_string(root->val) + "->", result);
        }
    }
    
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        
        helper(root, "", result);
        return result;
    }
    
    
    
    //iterative
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return {};
        
        queue<TreeNode *> treeQu;
        queue<string> strQu;
        TreeNode *current = root;
        vector<string> result;
        string currentStr = "";
        
        treeQu.push(current);
        strQu.push(currentStr);
        
        while(!treeQu.empty()) {
            
            current = treeQu.front(); treeQu.pop();
            currentStr = strQu.front(); strQu.pop();
            
            
            if(!current->left and !current->right) {
                result.push_back(currentStr + to_string(current->val));
            }
            
            if(current->left) {
                treeQu.push(current->left);
                strQu.push(currentStr + to_string(current->val) + "->");
            }
            if(current->right) {
                treeQu.push(current->right);
                strQu.push(currentStr + to_string(current->val) + "->");
            }
        }
        return result;
    }
};
