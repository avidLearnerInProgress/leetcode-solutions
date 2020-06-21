class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())return 0;
        int a = 0 ,b = 0;
        for(int i=0; i<nums.size(); i++){
            int a_ = max(a, b);
            cout<<"A_"<<a_<<"\n";
            int b_ = max(a, a+nums[i]); //check for max(prev_max, prev_max + curr_val)
            cout<<"B_"<<b_<<"\n";
            a = a_;
            b = b_;
        }
        return max(a,b);
    }
};