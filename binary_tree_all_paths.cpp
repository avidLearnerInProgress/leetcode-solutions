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
    vector<string> results;
    
    void recurse_util(TreeNode *root, string process){
        if(!root) return;
        
        if(!root->left && !root->right){ 
            //leaf node
            //process the current string
            process += to_string(root->val);
            results.push_back(process);
            return;
        }
        
        //non-leaf nodes
        
        process += to_string(root->val);
        process += "->";
        
        
        recurse_util(root->left, process);
        recurse_util(root->right, process);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return vector<string>();
        string process = "";
        recurse_util(root, process);   
        return results;
    }
    
};