class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0) return -1;
        int k = 2;
        
        priority_queue<int, vector<int>> Q;
        
        for(auto num : nums)
            Q.emplace(num);
        
        vector<int> res;
        while(k-- and !Q.empty()) {
            res.emplace_back(Q.top());
            Q.pop();
        }
        return ((res[0]-1) * (res[1]-1));
    }
};
