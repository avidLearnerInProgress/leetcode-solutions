class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        from collections import Counter
        d = dict(Counter(list1))
        e = {}

        min_ind_sum = float('inf')
        min_ind_lst = []

        for i, ele in enumerate(list2):
            if ele in d:
                print(ele, end = '\t')
                l1_ind, l2_ind = i, list1.index(ele)
                sum = l1_ind + l2_ind
                if sum in e:
                    e[sum].append([ele])
                else:
                    e[sum] = [ele]
                '''
                print(sum)
                if  sum < min_ind_sum:
                    min_ind_sum = sum
                    min_ind_lst.append(ele)
                    print(min_ind_lst)
                '''
        min_l = []
        min_ind = min(e.keys())
        print(min_ind)
        for ele in e[min_ind]:
            if(type(ele) == list):
                min_l.extend(ele)
            else:
                min_l.append(ele)
        return min_l