class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int length = nums.size();
        stack<int> st;
        vector<int> result(length, 0);
        
        
        // since, its a circular array, 
            // we have create another copy of array elements towards its front
            // this behavior is captured by iterating over 2 * length indices and using (i % n)th index while accessing elements of nums
        for(int i = length * 2 - 1; i >= 0; i--) {
            
            while(!st.empty() and nums[i % length] >= st.top()) {
                st.pop();
            }
            
            
            if(st.empty()) result[i % length] = -1;
            else result[i % length] = st.top();
            
            st.push(nums[i % length]);
        }
        
        return result;
    }
};
