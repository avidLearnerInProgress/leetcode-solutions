class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
       
        if(nums.size() < 4) return vector<vector<int>>();
        vector<vector<int>> result;
        auto sz = nums.size();
        sort(nums.begin(), nums.end());
        
        for(auto i=0; i<sz-3; i++) { //fourth sum
            if(i>0 && nums[i] == nums[i-1]) continue; //continue if not unique
            
            for(auto j=i+1; j<sz-2; j++) { //three sum
                if(j>i+1 && nums[j] == nums[j-1]) continue; //continue if not unique
                //for two sum
                auto left = j + 1;
                auto right = sz - 1;
                while(left < right) {
                    auto sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                        
                        while(left < right and nums[left] == nums[left-1]) left++;
                        while(left < right and nums[right] == nums[right+1]) right--;
                    }
                    
                    else if(sum > target) right--; //check for bounds
                    else left++; 
                } 
            }
            
        }
        return result;
    }
};
