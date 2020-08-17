class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> result(num_people, 0);
        int cc = 1;
        int index = 0;
        while(candies) {
            result[index++] += cc;
            candies -= cc++;
            if(index == num_people) index = 0;
            if(cc > candies) cc = candies;
        }
        return result;
    }
};


# #mysolution
# class Solution:
#     def distributeCandies(self, candies: int, num_people: int) -> List[int]:
#         res = [0] * num_people
#         i = 0
#         while candies > 0:
#             if i <= (num_people-1):
#                 res[i] = min(candies, i+1)
#             else:
#                 res[i%num_people] += min(candies, i+1)
#             candies -= i+1
#             i+=1    
#         return res

# #better
# class Solution:
#     def distributeCandies(self, candies: int, num_people: int) -> List[int]:
#         res = [0] * num_people
#         i = 0
#         while candies > 0:
#             res[i%num_people] += min(candies, i+1)
#             candies -= i+1
#             i+=1    
#         return res
