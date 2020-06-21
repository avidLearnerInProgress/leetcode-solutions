#mysolution
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        res = [0] * num_people
        i = 0
        while candies > 0:
            if i <= (num_people-1):
                res[i] = min(candies, i+1)
            else:
                res[i%num_people] += min(candies, i+1)
            candies -= i+1
            i+=1    
        return res

#better
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        res = [0] * num_people
        i = 0
        while candies > 0:
            res[i%num_people] += min(candies, i+1)
            candies -= i+1
            i+=1    
        return res