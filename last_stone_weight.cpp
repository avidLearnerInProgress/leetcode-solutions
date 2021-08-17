class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> Q;
        for(auto stone : stones) {
            Q.emplace(stone);
        }
        
        while(!Q.empty()) {
            if(Q.size() == 1) return Q.top();
            int x = Q.top(); Q.pop();
            int y = Q.top(); Q.pop();
            if(x != y)
                Q.push(x - y);
        } 
        return 0;
    }
};
