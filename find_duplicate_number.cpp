// Non - optimal solution:
// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
        
//         sort(nums.begin(), nums.end());
        
//         for(auto i = nums.begin(); i != nums.end()-1; i++){
//             if(*(i) == *(i+1))
//                 return *(i);
//         }
//         return -1;
//     }
// };

// Optimal solution - O(n) || O(1)
class Solution {
public:
    
    // Very similar to find the point where there is a loop in the linked list
    // Treat array as a circular list with the duplicate element as the intersection point
    // Hair and Tortoise method
    int findDuplicate(vector<int>& nums) {
        if(nums.size() <= 1) return -1;
        
        int fast = 0, slow = 0;
        
        while(true) {
            slow = nums[slow];
            fast = nums[nums[fast]]; // take index as array element 
            if(slow == fast) break;
        }
        
        fast = 0;
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
};
