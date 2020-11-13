class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        /*
            For any value at i, we get the max_reach from that position(i).
            So if i + max_reach > current_max_reach, then there is a possibility to reach further from current i upto new_max_reach
            Thus, we update our max_reach.
            And we check if i == max_reach_possible:
            if it is, we break.
            
            In the end we check if the max_reach exceeds the total size of nums, if it does; we have found a way to reach the last position from the beginning.
        */
        
        int max_jumps = 0;
        for(int i=0; i<nums.size(); i++) {
            if(i + nums[i] > max_jumps) {
                max_jumps = i + nums[i];
            }   
            if(i == max_jumps) {
                break;
            }
        }
        return max_jumps >= nums.size()-1;
    }
};
