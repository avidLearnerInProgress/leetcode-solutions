
// Forward method
// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
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

//Backward method (more readable and intuitive)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int length = nums2.size(), j = 0;
        stack<int> st; //auxiliary
        unordered_map<int, int> subsetMap;
        vector<int> result;
        
        for(int i = length - 1; i >= 0; i--) {
            int element = nums2[i];
            
            // if element = x, the nge for x will be 2x.. so remove all the x, x/2, x/4, ... elements from stack
            // top of stack represents next greater element seen so far
            while(!st.empty() and element > st.top()) 
                st.pop();

            if(st.empty()) subsetMap[element] = -1;
            else subsetMap[element] = st.top();
            
            st.push(element);            
        }
        
        //since nums1 is subset of nums2; it is guaranteed that all elements of nums1 will be present in nums2
        for(auto element : nums1) {
            result.push_back(subsetMap[element]);
        }
        return result;
    }
};
};
