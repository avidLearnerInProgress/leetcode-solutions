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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left and !root->right) return 1; 
        
        if (!root->left) 
            return minDepth(root->right) + 1;
        
        if (!root->right) 
            return minDepth(root->left) + 1;
        
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
    
    //iterative
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        
        queue<TreeNode*> qu;
        TreeNode *current = root;
        qu.push(current);
        
        int mindepth = 1;
        
        while(!qu.empty()) {
            
            int n = qu.size(); 
            while(n-- > 0) {
                current = qu.front();
                qu.pop();
            
                if(!current->left and !current->right) return mindepth;
                
                if(current->left) qu.push(current->left);
                if(current->right) qu.push(current->right);
                    
            }
            mindepth++;
        }
        return mindepth;
    }
};
