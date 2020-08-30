class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        if(nums.size() == 0) return {};
        if(nums.size() == 1) return nums;
        
        int f = nums[0], s = nums[1], cf = 0, cs = 0;
        
        for(int i=0; i<nums.size(); i++) {
            if(f == nums[i]) { //if curr element is equal to first candidate element
                f = nums[i];
                cf++;
            }
            
            else if(s == nums[i]) { //second candidate element
                s = nums[i];
                cs++;
            }
            
            else if(cf == 0) { //prev element != either of candidate elements; hence count became 0; resent count to 1 with new first candidate element
                f = nums[i];
                cf = 1;
            }
            
            else if(cs == 0) { //prev element != either of candidate elements; hence count became 0; resent count to 1 with new second candidate element
                s = nums[i];
                cs = 1;
            }
            
            else { //decrement count if current element != either of candiate element
                cf--;
                cs--;
            }
        }
        
        //now we have an f and an s; to actually find if the same f-val and s-val is appearing more than n/3 times; we do -
        
        int ccf = 0, ccs = 0;
        for(auto n : nums) {
            if(n == f) ccf++;
            if(n == s and s != f) ccs++;
        }
        
        vector<int> result;
        if(ccf > nums.size()/3)  result.push_back(f);
        if(ccs > nums.size()/3)  result.push_back(s);
        
        return result;
    }
};
