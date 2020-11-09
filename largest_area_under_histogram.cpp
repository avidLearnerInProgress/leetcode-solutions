class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        if(heights.size() == 0) return 0;
        
        stack<int> indexes;
        int largest_rectangular_area = INT_MIN;
        int area_with_prev_top = 0;
        int n = heights.size();
        
        int i=0;
        while(i<n) {
            
            //for strictly increasing sequence of heights, keep inserting indexes of rectangles into the stack
            if(indexes.empty() or heights[indexes.top()] <= heights[i]) {
                indexes.push(i);
                i++;
            }
            
            //found a decreasing sequence
            else {    
                //get the previous top
                int prev_top = indexes.top(); 
                indexes.pop(); //remove the previous top
                
                //calculate area that can be covered by current smaller rectangle.
                area_with_prev_top = heights[prev_top] * (indexes.empty() ? i : i - indexes.top() - 1);
                
                largest_rectangular_area = max(largest_rectangular_area, area_with_prev_top);
            }
        }
            
        while(!indexes.empty()) {
            int prev_top = indexes.top(); 
            indexes.pop(); //remove the previous top
                
                //calculate area that can be covered by current smaller rectangle.
            area_with_prev_top = heights[prev_top] * (indexes.empty() ? i : i - indexes.top() - 1);
                
            largest_rectangular_area = max(largest_rectangular_area, area_with_prev_top);
        }
        return largest_rectangular_area;
        
    }
};
