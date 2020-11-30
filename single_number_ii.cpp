class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0;
        int twos = 0;
        
        for( const auto num : nums ){
            ones = ones^num & ~twos; // add num to the set of ones if num is not in the set of twos
            twos = twos^num & ~ones; // add num to the set of twos if num is not in the set of ones
        }
        return ones;
    }
};	
