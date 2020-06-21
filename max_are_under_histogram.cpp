class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {   
        
        /*
        if(heights.size() == 0) return 0;
        
        stack<int> st;
        int max_rect_area = INT_MIN;
        int index, curr_area, i;
        
        for(i=0; i<=heights.size(); i++){
            int cheight = i == heights.size() ? 0 : heights[i];
            if(st.empty() || cheight >= heights[st.top()]){
                st.push(i++);
            }
            else{
                index = st.top();
                st.pop();
                */
                /*
                height[index] = max_rect_seen_so_far
                if stack is empty.. 
                    there is no earlier start that is present
                    this means... the current rect is the only start and end..
                    hence, curr_area = height[index] * i;
                
                if stack is not empty..
                    there is earlier start that is present
                    this means... the current rect has the end..
                    hence, curr_area = height[index] * (i  - s.top() - 1)
                */
                /*
                int breadth = st.empty() ? i : i - st.top() - 1;
                max_rect_area = max(max_rect_area, heights[index] * breadth);
            }
        }
        
        /*
        while(!st.empty()){
            index = st.top();
            st.pop();
            curr_area = heights[index] * (st.empty() ? i : i - st.top() - 1);
            max_rect_area = max(curr_area, max_rect_area);
        }*/
        //return max_rect_area;
        int ans = 0;
        int len = heights.size();
        if(len == 0){
            return 0;
        }
        stack<int> st;
        for(int i = 0; i <= len;){
            int h = (i == len ? 0 : heights[i]);
            if(st.empty() || heights[st.top()] <= h){
                st.push(i++);
            }else{
                int tmp = st.top();
                st.pop();
                int l = (st.empty() ? i : i - st.top() - 1);
                ans = max(ans, l * heights[tmp]);
            }
        }
        return ans;
    }
};