```cpp
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
    void helper(TreeNode *root, int current, int &maxLevel, int &sum) {
        if(!root) return;
        helper(root->left, current + 1, maxLevel, sum);
        
        if(!root->left and !root->right) {
            if(current > maxLevel) {
                maxLevel = current;
                sum = 0; //smart
            }
            if(current == maxLevel) {
                sum += root->val;
            }
        }
      
        helper(root->right, current + 1, maxLevel, sum); 
    }
    
    int deepestLeavesSum(TreeNode* root) {
        if(!root) return 0;
        
        int maxLevel = 0;
        int currentLevel = 0, sum = 0;
        helper(root, currentLevel, maxLevel, sum);    
        
        return sum;
    }
    
    
    //iterative
    int deepestLeavesSum(TreeNode* root) {
        if(!root) return 0;
        
        queue<TreeNode *> qu;
        TreeNode *current = root;
        qu.push(current);
        
        int sum = 0;
        
        while(!qu.empty()) {
            int n = qu.size();
            sum = 0;
            for(int i = 0; i < n; i++) {
                
                current = qu.front();
                qu.pop();
                
                sum += current->val;
                if(current->left) qu.push(current->left);
                if(current->right) qu.push(current->right);
            }
        }
        return sum;
    }
    
};
```
