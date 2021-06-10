class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        
        if(intervals.size() <= 1) return {-1};
        
        map<int, int> mp;
        //map is naturally ordered data structure
        
        vector<int> result(intervals.size());
        
        for(int i=0; i<intervals.size(); i++) {
            mp[intervals[i][0]] = i; //{start_index , i}
        }
        
        for(auto &[k,v] : mp) {
            cout<<k<<" "<<v<<"\n";
        }
        
        for(int i=0; i<intervals.size(); i++) {
            
            //lower_bound() => returns first value >/= intervals[i][1] 
            auto it = mp.lower_bound(intervals[i][1]); 
            if(it != mp.end()) 
                result[i] = it->second;
            else
                result[i] = -1;
         }
        return result;
    }
};
