class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> next_greatest(T.size(), 0);
        stack<int> temperatures;
        
        for(int i = T.size()-1; i>=0; i--){
            while(!temperatures.empty()  && T[i] >= T[temperatures.top()]){
                temperatures.pop();
            }
            next_greatest[i] = temperatures.empty() ? 0 : temperatures.top() - i;
            temperatures.push(i);
        }
        return next_greatest;
    }
};
