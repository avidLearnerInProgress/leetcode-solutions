class Solution {
public:
    int jump(vector<int>& nums) {
        
        /*
        
        Iterate over the nums array. Traverse only till the len - 1. The reason is because if we do it till the end/last element; we will increment one more jump and we dont need to consider the jumps allowed on the last position since last position is the destination.
        
        
        current_index  | 0 1 2 3 4
        jumps_possible | 2 3 1 1 4
        
        
        For each element in nums array, check - 
            if current_index + jumps_possible[i] > currentMax:
                currentMax = i + jumps_possible[i] #update the max reach from current index
            
            if i is equal to currentReach:
                increment jump
                currentReach = currentMax
        return jumps
        
        */
        
        
        
        int currentReach = 0, currentMax = 0, jumps = 0;
        
        for(int i=0; i<nums.size() - 1; i++) {
            if(i + nums[i] > currentMax) {
                currentMax = i + nums[i];
            }
            
            if(i == currentReach) {
                currentReach = currentMax;
                jumps++;
            }
            
        }
        return jumps;
        
        
    }
};
