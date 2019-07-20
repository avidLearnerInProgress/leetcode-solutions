class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int>m;
        for(auto i: nums)
            m[i]++;
        int res = 0;
        for(auto it:m)
            if(m.count(it.first-1)>0)
                res = max(res, it.second+m[it.first-1]);
        return res;
    }
};