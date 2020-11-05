class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
// Forward method
//         unordered_map<int, int> ump; //to keep track of nge for each element in nums2
//         //map of current element in stack => its nge
//         stack<int> st; //to store right part of search
        
//         for(auto num : nums2) {
//             while(!st.empty() and st.top() < num) {
//                 ump[st.top()] = num;
//                 st.pop();
//             } 
//             st.push(num);
//         }
        
//         vector<int> result;
//         for(auto num : nums1) {
//             if(ump.find(num) != ump.end()) result.push_back(ump[num]);
//             else result.push_back(-1);
//         }
        
//         return result;

        //traverse backward
        if(nums1.size() == 0) return {};
        
        int n = nums2.size();
        vector<int> result;
        
        stack<int> st;
        unordered_map<int, int> ump;
        
        for(int i=n-1; i>=0; i--) {
            
            while(!st.empty() and st.top() < nums2[i]) st.pop();
            if(st.empty()) ump[nums2[i]] = -1;    
            else ump[nums2[i]] = st.top();
            
            st.push(nums2[i]);
        }
        
        int m = nums1.size();
        for(auto num : nums1)
            result.push_back(ump[num]);
        
        return result;
    }
};
