// class Solution {
// public:
//     bool checkPossibility(vector<int>& nums) {
//         bool changed = false;
//         for(int i = 0; i < nums.size()-1; i++) {
//             if(nums[i] > nums[i+1]) {
//                 if(changed) return false;
//                 changed = true;
//                 if(i > 0) {
//                     if(nums[i-1] > nums[i+1]) {
//                         nums[i+1] = nums[i];
//                     } else {
//                         nums[i] = nums[i-1];
//                     }
//                 }
//             }
//         }
//         return true;
        
//     }
// };


class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        
        //remember blue, black and green viz.
        
        if(nums.size() == 0) return false;
        int count = 0;
        
        for(auto i=1; i<nums.size(); i++) {
            if(nums[i] < nums[i-1]) { //current lesser than prev (blue < green)
                
                //2 cases                
                //case 1: prev->prev <= current
                if(i == 1 || nums[i-2] <= nums[i]) { // (black <= blue) 
                    // bring green down
                    nums[i-1] = nums[i];   
                }
                
                //case 2: prev->prev > current
                else { // (black > blue)
                    nums[i] = nums[i-1];
                }
                count++; //modified one element
            }
        }
        return count <= 1;
    }
};
