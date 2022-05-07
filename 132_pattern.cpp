class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        // completely wrong first initial thoughts !!!
        //how can i apply sliding window??, there's negative bounds defined!
/*      int size = nums.size();
        if (size <= 1) return false;
        
        int start = 0, end = 1;
        while(end < size) {
            if(nums[start] < nums[end]) { //start < end
                if(end >= size - 1) {
                    return false;
                }
                if(nums[end + 1] < nums[end] and nums[end + 1] < nums[start]) { //next_to_end < end
                    cout<<nums[start]<<nums[end]<<" "<<nums[end + 1]<<"\n";
                    return true;
                }
            }
            start++, end++;
        }
        return false;
*/
    
        /*
            nums[k] < nums[j]
            nums[k] > nums[i]
            nums[j] > nums[i]
            
            finding nums[k] is the problem! This was a bit difficult to figure out - monotonic decreasing sequence.
        */
        
        
        stack<pair<int, int>> st;
        int currentMin = nums[0];
        
        
        for(int i = 1; i < nums.size(); ++i) {
            while(!st.empty() and nums[i] >= st.top().first) {
                st.pop();
            }
            if(!st.empty() and nums[i] < st.top().first and nums[i] > st.top().second) {
                return true;
            }
            
            st.push({nums[i], currentMin});
            currentMin = min(currentMin, nums[i]);
        }
        return false;

    }
};
