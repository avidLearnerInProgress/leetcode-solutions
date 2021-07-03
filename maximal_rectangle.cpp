class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
            
        int length = heights.size();
        int verticalHeight, leftBound, horizontalWidth, currentArea, maxArea = -1, currentIndex;
        stack<int> indexes;
        
        
        for(int i = 0; i < length; i++) {
            currentIndex = i;
            
            //found a decreasing sequence - calculate maxArea
            while(!indexes.empty() and heights[currentIndex] <= heights[indexes.top()]) {
                
                verticalHeight = heights[indexes.top()];
                indexes.pop();
                
                if(indexes.empty())
                    horizontalWidth = currentIndex;
                else {
                    leftBound = indexes.top();
                    horizontalWidth = currentIndex - leftBound - 1;
                }
                
                currentArea = verticalHeight * horizontalWidth;
                
                if(currentArea > maxArea)
                    maxArea = currentArea;
            }
            
            //when its strictly monotonically increasing sequence of heights
            indexes.push(currentIndex);
        }
        
        //if the array only has increasing sequence of elements
        if(!indexes.empty()) currentIndex++; // you need to be out of bounds at this point to get the 
        while(!indexes.empty()) {
                
                verticalHeight = heights[indexes.top()];
                indexes.pop();
                
                if(indexes.empty())
                    horizontalWidth = currentIndex;
                else {
                    leftBound = indexes.top();
                    horizontalWidth = currentIndex - leftBound - 1;
                }
                
                currentArea = verticalHeight * horizontalWidth;
                
                if(currentArea > maxArea)
                    maxArea = currentArea;
            }
        
        return maxArea;
        
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
