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
    //final ds
    vector<vector<int>> result;
    
    //intermediary ds to check if current path is a 'path sum'
    vector<int> current_path; 
        
    //recursive method to find all root-to-leaf paths
    void helper(TreeNode* root, int sum) {
        
        
        //base case i
        if(!root) return;
        
        current_path.push_back(root->val); //push current node in path and recurse for all the children emanting out of the path from current node i.e. root
        
        //basecase ii
        if(!root->left && !root->right && root->val == sum) {
            result.push_back(current_path);
        }
        
        else { //recurse for child nodes
            sum -= root->val;
            helper(root->left, sum);
            helper(root->right, sum);
        }
        
        current_path.pop_back(); //remove current visited node
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root) return vector<vector<int>> ();
        helper(root, sum);
        return result;
    }
};


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
    vector<vector<int>> result;
    vector<int> currentPath;
    
    void helper(TreeNode *root, int targetSum) {
        
        if(!root) return;
        currentPath.push_back(root->val); 
        
        if(!root->left and !root->right and targetSum == root->val) {
            result.push_back(currentPath);
        }
        else {
            helper(root->left, targetSum - root->val);
            helper(root->right, targetSum - root->val);
        }
        
        //this line is only executed when we have to backtrack.
        //this happens when we have either found a path that equals target sum or visited both the children of the current node
        currentPath.pop_back(); 
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return {};
        helper(root, targetSum);
        return result;
    }
};
