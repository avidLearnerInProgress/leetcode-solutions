class Solution {
public:
    
/*
Idea:
-> To work on the same task again, CPU has to wait for time n, therefore we can think of as if there is a cycle, of time n+1, regardless whether you schedule some other task in the cycle or not.
-> To avoid leaving the CPU with limited choice of tasks and having to sit there cooling down frequently at the end, it is critical to keep the diversity of the task pool for as long as possible.
-> In order to do that, we should try to schedule the CPU to always try round robin between the most popular tasks at any time. 
*/
    
    int leastInterval(vector<char>& tasks, int n) {
        
        priority_queue<int> maxHeap;
        unordered_map<int, int> count;
        for(auto &task : tasks) {
            count[task]++;
        }

        // we only care about the number of units of time, so just use the count in priority_queue and not the actual task
        for(auto &[k, v] : count) {
            maxHeap.emplace(v);
        }
        
        
        int minTime = 0;
        while(!maxHeap.empty()) {
            int coolTime = 0;
            vector<int> trackTasks;
            for(int i = 0; i <= n; ++i) {
                if(!maxHeap.empty()) {
                    auto top = maxHeap.top();
                    trackTasks.emplace_back(top - 1);   //track prev taskTimes in a temporary container
                    maxHeap.pop();
                    ++coolTime; //logically this extra variable is not needed, but it just keeps the code clean
                }
            }
            for(auto &t : trackTasks) { //insert taskTimes back into the maxHeap
                if(t) {
                    maxHeap.emplace(t);
                }
            }
            minTime += maxHeap.empty() ? coolTime : n + 1;
        }
        
        return minTime;
    }
};
