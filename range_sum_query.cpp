class NumArray {
public:
    vector<int> memo = {0};
    NumArray(vector<int>& nums) {
        int summ = 0;
        for (int n : nums) {
            summ += n;
            memo.push_back(summ);
        }
    }
    
    int sumRange(int left, int right) {
        return memo[right + 1] - memo[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
