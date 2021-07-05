// # Non optimal solution... we dont need aux arrays to keep track of leftMax and rightMax
// # class Solution {
// # public:
// #     int trap(vector<int>& height) {
        
// #         if(height.size() == 0) return 0;
// #         int n = height.size();
// #         int leftMax[n], rightMax[n];
        
// #         leftMax[0] = height[0];
// #         rightMax[n-1] = height[n-1];
        
// #         for(int i=1; i<n; i++) {
// #             leftMax[i] = max(height[i], leftMax[i-1]);
// #         }
        
// #         for(int i=n-2; i>=0; i--) {
// #             rightMax[i] = max(height[i], rightMax[i+1]);
// #         }
        
// #         int totalWater = 0;
// #         for(int i=0; i<n; i++) {
// #             totalWater += min(leftMax[i], rightMax[i]) - height[i];
// #         }
        
// #         return totalWater;
// #     }
// # };


// class Solution:
//     def trap(self, height: List[int]) -> int:
        
//         left, right = 0, len(height) - 1
//         maxLeft, maxRight = 0, 0
//         waterTrap = 0
        
//         while left <= right:
//             if height[left] <= height[right]:
//                 if height[left] > maxLeft:
//                     maxLeft = height[left]
//                 else:
//                     waterTrap += maxLeft - height[left]
//                 left += 1
//             else:
//                 if height[right] > maxRight:
//                     maxRight = height[right]
//                 else:
//                     waterTrap += maxRight - height[right]
//                 right -= 1

//         return waterTrap
                
                
                
            


class Solution {
public:
    int trap(vector<int>& height) {
        
        //Method 1: Use two arrays to keep track of maxToLeft and maxToRight
        /*
        int n = height.size();
        if(n == 0) return 0;
        
        vector<int> maxToRight(n), maxToLeft(n);
        int waterTrap = 0;
        
        maxToLeft[0] = height[0];
        for(int i = 1; i < n; i++) {
            maxToLeft[i] = max(height[i], maxToLeft[i - 1]);
        }
        
        maxToRight[n - 1] = height[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            maxToRight[i] = max(height[i], maxToRight[i + 1]);
        }
        
        for(int i = 0 ; i < n; i++) {
            waterTrap += min(maxToLeft[i], maxToRight[i]) - height[i];
        }
        
        return waterTrap;
        */
        
        //Method 2: Use two pointers left and right (instead of ararys) to keep track of maxToLeft and maxToRight
        /*
        int left = 0, right = height.size() - 1;
        int maxLeft = 0, maxRight = 0, waterTrap = 0;
        
        while(left <= right) {
            if(height[left] <= height[right]) {
                if(height[left] > maxLeft) 
                    maxLeft = height[left];
                else 
                    waterTrap += maxLeft - height[left];
                left++;
            }
            else {
                if(height[right] > maxRight) 
                    maxRight = height[right];
                else
                    waterTrap += maxRight - height[right];
                right--;
            }
        }
        return waterTrap;
        */
        
        //Method 3: Least intuitive - using stack
        
        int length = height.size();
        int verticalHeight, leftBound, horizontalWidth, waterTrap = 0, currentIndex, prevTop;
        stack<int> indexes;

        int i = 0;
        while(i < length) {
            currentIndex = i;
            
            //found a increasing sequence - calculate maxArea
            while(!indexes.empty() and height[currentIndex] > height[indexes.top()]) {
                
                prevTop = height[indexes.top()];
                indexes.pop();
                
                if(indexes.empty())
                    break;
                
                horizontalWidth = currentIndex - indexes.top() - 1;
                verticalHeight = min(height[currentIndex], height[indexes.top()]) - height[prevTop];

                waterTrap += verticalHeight * horizontalWidth;
            }
            
            //when its strictly monotonically decreasing sequence of heights
            indexes.push(currentIndex);
            i++;
        }
        return waterTrap; 
    }
};
