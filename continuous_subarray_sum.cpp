class Solution {
public:
    //subarray sums divisible by k 
    bool checkSubarraySum(vector<int>& nums, int k) {
        int i, sum = 0, len = 0;
        unordered_map<int, int> map;
        map[0] = -1;
        
        if(k==0){
            for(i=1; i<nums.size(); i++){
                if(nums[i]==0 && nums[i-1]==0){
                    return true;
                }
            }
            return false;
        }
        
        for(i=0; i<nums.size(); i++){
            sum += nums[i];
            
            if(map.find(sum % k) != map.end()){
                if(i-map[sum % k] >= 2){
                    return true;
                }
            } else {
                map[sum % k] = i;
            } 
        }
        return false;
    }
};
