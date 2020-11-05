class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 0) return {};
        
        vector<int> result(n, -1);
        stack<int> st;
        
        for(int i=2*n-1; i>=0; i--) {
            int num = nums[i % n];
            while(!st.empty() && nums[st.top()] <= num) st.pop();
            if(st.empty()) result[i % n] = -1;
            else result[i % n] = nums[st.top()];
            
            st.push(i % n);
        }
        return result;
        
    }
};
