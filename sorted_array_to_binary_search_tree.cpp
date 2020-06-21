class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        if(nums.size() == 1) return new TreeNode(nums[0]);
        int mid = nums.size() / 2;
        TreeNode* current = new TreeNode(nums[mid]);
        vector<int> leftInts(nums.begin(), nums.begin() + mid);
        vector<int> rightInts(nums.begin() + mid + 1, nums.end());
        current->left = sortedArrayToBST(leftInts);
        current->right = sortedArrayToBST(rightInts);
        return current;
    }
};