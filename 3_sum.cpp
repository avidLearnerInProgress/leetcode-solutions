class Solution {
public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            vector<vector<int>> result;
            int l, r, n = nums.size();
            for(int i=0; i<n-2; i++) {
                if(i > 0 && (nums[i] == nums[i-1])) continue; //check for uniqueness
                int l = i + 1;
                int r = n - 1;
                
                while(l < r) {
                    int total = nums[i] + nums[l] + nums[r];
                    if(total < 0) l++;
                    else if(total > 0) r--;
                    else {
                        result.push_back(vector<int>{nums[i], nums[l], nums[r]});
                         while(l+1 < r && nums[l] == nums[l+1])  l++; //for uniqueness of ele at l
                         while(l < r-1 && nums[r] == nums[r-1])  r--; //for uniqueness of ele at l
                         l++, r--;
                    }
                }
            }
            return result;
        }
};
