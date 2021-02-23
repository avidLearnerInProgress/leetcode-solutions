class Solution {
public:
    
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        vector<int> heat = heaters;
        sort(heat.begin(), heat.end(), greater<int>());
        int mini = 0, n = heaters.size();
        for (int i = 0; i < houses.size(); i++) {
            vector<int> :: iterator it = lower_bound(heaters.begin(), heaters.end(), houses[i]);
            vector<int> :: iterator it2 = upper_bound(heat.begin(), heat.end(), houses[i],greater<int>());
            int val1, val2;
            if (it == heaters.end())    val1 = abs(houses[i] - *heaters.rbegin());
            else val1 = abs(houses[i] - *it);
            
            if (it2 == heat.end())    val2 = abs(houses[i] - *heat.rbegin());
            else val2 = abs(houses[i] - *it2);
            
            mini = max(mini, min(val1, val2));
        }
        
        return mini;
    }
};
