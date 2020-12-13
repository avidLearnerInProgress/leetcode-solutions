class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
     
        
        /*
            Next greater to right and difference.
            Start scanning from right end of array.
        */
        
        
        stack<pair<int, int>> S; // S.top()[0] ==> temperature, S.top()[1] ==> next warmer(>) temperature
        
        int n = T.size();
        vector<int> result(n, 0);
        
        for(int i=n-1; i>=0; i--) {
            
            //
            while(!S.empty() and S.top().first <= T[i]) { //if current element is greater than element at top of stack..pop the element until we find next greater element in stack(next warmer temperature)
                S.pop();
            }
            
            // once we found it, push the difference between current element to its next warmer temperature in result array.
            if(!S.empty() and T[i] < S.top().first) {
                result[i] = S.top().second - i;
            }
            
            S.push({T[i], i});
        }
        return result;

    }
};



/*
More optimized in terms of time and space.

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
*/
