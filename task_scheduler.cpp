/*
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
*/
            
            
class Solution {
/*
Based on solution - https://leetcode.com/problems/task-scheduler/discuss/104493/C%2B%2B-Java-Clean-Code-Priority-Queue
*/
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> counts;
        for (char t : tasks) {
            counts[t]++;
        }
        priority_queue<int> pq;
        for (pair<char, int> count : counts) {
            pq.push(count.second);
        }
        int alltime = 0;
        int cycle = n + 1;
        while (!pq.empty()) {
            int time = 0;
            vector<int> tmp;
            for (int i = 0; i < cycle; i++) {
                if (!pq.empty()) {
                    tmp.push_back(pq.top());
                    pq.pop();
                    time++;
                }
            }
            for (int cnt : tmp) {
                if (--cnt) {
                    pq.push(cnt);
                }
            }
            alltime += !pq.empty() ? cycle : time;
        }
        return alltime;
    }
};                
                
                
                
            
        
        
        
        
