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
    vector<int> curr;
    vector<vector<int>> res;
    
    void solve(TreeNode *root, int sum){
        if(!root) return;
        
        curr.push_back(root->val); //push current node in the recursion
        if(!root->left && !root->right && root->val == sum){ //final edgecase to check if its leaf
            res.push_back(curr);
        }
        else{
            solve(root->left, sum - root->val);
            solve(root->right, sum - root->val); //reverse
        }
        curr.pop_back(); //needed since all paths have to be traversed --> useful in both scenarios where we get the sum and where we don't
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root) return vector<vector<int>>();

        solve(root, sum);
        return res;
    }
};