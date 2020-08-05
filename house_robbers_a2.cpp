class Solution {
public:
    int max(int a, int b) {
        return a >=b ? a: b;
    }
    int rob(vector<int>& nums) {
        int a = 0, b = 0;
        
        for(int i=0; i<nums.size(); i++) {
            if( i%2 == 0)
                a = max(a + nums[i], b);
            else
                b = max(b + nums[i], a);
        }
        return max(a,b);
    }
};
