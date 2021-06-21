# Non optimal solution... we dont need aux arrays to keep track of leftMax and rightMax
# class Solution {
# public:
#     int trap(vector<int>& height) {
        
#         if(height.size() == 0) return 0;
#         int n = height.size();
#         int leftMax[n], rightMax[n];
        
#         leftMax[0] = height[0];
#         rightMax[n-1] = height[n-1];
        
#         for(int i=1; i<n; i++) {
#             leftMax[i] = max(height[i], leftMax[i-1]);
#         }
        
#         for(int i=n-2; i>=0; i--) {
#             rightMax[i] = max(height[i], rightMax[i+1]);
#         }
        
#         int totalWater = 0;
#         for(int i=0; i<n; i++) {
#             totalWater += min(leftMax[i], rightMax[i]) - height[i];
#         }
        
#         return totalWater;
#     }
# };


class Solution:
    def trap(self, height: List[int]) -> int:
        
        left, right = 0, len(height) - 1
        maxLeft, maxRight = 0, 0
        waterTrap = 0
        
        while left <= right:
            if height[left] <= height[right]:
                if height[left] > maxLeft:
                    maxLeft = height[left]
                else:
                    waterTrap += maxLeft - height[left]
                left += 1
            else:
                if height[right] > maxRight:
                    maxRight = height[right]
                else:
                    waterTrap += maxRight - height[right]
                right -= 1

        return waterTrap
                
                
                
            
