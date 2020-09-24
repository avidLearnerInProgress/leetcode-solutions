class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(nums.size() == 0) return 0;
        
        int running_sum = 0, result = 0;
        unordered_map<int, int> ump;
        
        for(int i=0; i<nums.size(); i++) {
            running_sum += nums[i];
            
            int s = running_sum - k; // k + s = running_sum => if difference between k and current_sum is in map or not.
            
            if(ump[s]) { //if s in map
                result += ump[s];
            }
            
            if(running_sum == k) result++;
            
            ump[running_sum]++; //if s not in map
        }
        
        return result;
    }
};
