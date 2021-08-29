class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        if (n == 0) return 0;
        int num = nums.size();
        long reach = 0;
        int patch = 0;
        for (int i = 0; i < num; ){
            while (nums[i] > reach + 1){
                reach += (reach + 1);
                ++patch;
                if (reach >= n) return patch;
            }
            reach += nums[i];
            if (reach >= n) return patch;
            ++i;
        }
        while (reach < n){
            reach += (reach + 1);
            ++patch;
        } 
        return patch;
    }
};
