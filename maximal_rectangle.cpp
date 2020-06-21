class Solution {
public:
    /*
    int dfs(vector<vector<char>>& matrix, int i, int j){
        if(i < 0 or j < 0 or i >= matrix.size() or j >= matrix[i].size() or matrix[i][j] == '0')
            return 0;
        else{
            matrix[i][j] = '0';
            return 1 + dfs(matrix, i-1, j) + dfs(matrix, i+1, j) + dfs(matrix, i, j + 1) + dfs(matrix, i, j - 1);
        }
    }*/
    
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
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;
        
        auto curr_area = 0, max_area = INT_MIN;
        vector<int> heights(matrix[0].size());
        
        for(auto i = 0; i < matrix.size(); i++){
            for(auto j = 0; j < matrix[i].size(); j++){
                if(matrix[i][j] == '0')
                    heights[j] = 0 ;
                else
                    heights[j]++;
            }
            max_area = max(max_area, largestRectangleArea(heights));
        }
        return max_area;
    }
};