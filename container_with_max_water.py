class Solution:
    def maxArea(self, height: List[int]) -> int:
        #move left pointer or right pointer only when height is smaller
        i, j = 0, len(height) - 1
        capacity = 0
        while i < j:
            #width of container * min_height
            capacity = max(capacity, (j-i) * min(height[i], height[j]))
            if height[i] < height[j]:
                i+=1
            else:
                j-=1
        return capacity
