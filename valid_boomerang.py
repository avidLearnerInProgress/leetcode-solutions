class Solution:
    def isBoomerang(self, points: List[List[int]]) -> bool:
        p1, p2, p3 = points[0],points[1],points[2]
        
        area = p1[0]*(p2[1]-p3[1]) + p2[0]*(p3[1]-p1[1]) + p3[0]*(p1[1]-p2[1])
        if abs(area) > 0:
            return True 
        if abs(area) == 0:
            return False 