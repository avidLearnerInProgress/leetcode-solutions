class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        td = dict()
        count_most_frequent = 0
        for task in tasks:
            if task not in td:
                td[task] = 1
            else:
                td[task] += 1
            count_most_frequent = max(count_most_frequent, td[task])
    
        result = (count_most_frequent - 1) * (n + 1)
        
        for task in td.keys():
            if count_most_frequent == td[task]:
                result += 1
        return max(result, len(tasks))
                
            
            
                
                
                
                
            
        
        
        
        