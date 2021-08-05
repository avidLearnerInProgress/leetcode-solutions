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
    TreeNode *helper(vector<int> &nums, int left, int right) {
        if(left > right) return NULL;
        
        int mid = left + (right - left) / 2;
        TreeNode *current = new TreeNode(nums[mid]);
        current->left = helper(nums, left, mid - 1);
        current->right = helper(nums, mid + 1, right);
        
        return current;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        if(nums.size() == 1) return new TreeNode(nums[0]);
        
        TreeNode *root = NULL;
        int left = 0, right = nums.size() - 1;
        return helper(nums, left, right);
    }
};
