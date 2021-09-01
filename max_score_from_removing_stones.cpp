class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> maxHeap;
        
        maxHeap.push(a);
        maxHeap.push(b);
        maxHeap.push(c);
        int score = 0;
        
        while(maxHeap.size() > 1) {
            auto first = maxHeap.top();
            maxHeap.pop();
            
            auto second = maxHeap.top();
            maxHeap.pop();
            
            if(first > 0 and second > 0) {
                score++;
                maxHeap.push(first - 1);
                maxHeap.push(second - 1);
            }
        }
        
        return score;
    }
};
