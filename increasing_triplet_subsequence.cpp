class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int min_ = INT_MAX, nmin_ = INT_MAX;
            
        for(auto num : nums){
            min_ = min(min_, num);
            if(num > min_)
                nmin_ = min(nmin_, num);
            if(num > nmin_)
                return true;
        }
        return false;
    }
};