logo

218. The Skyline Problem
Description
Hints
Submissions
Discuss
Solution
      
C++ T:O(nlogn)/S:O(n) with vector/multiset
C++ T:O(nlogn)/S:O(n) with vector/multiset
311
VIEWS
4
Created at: November 30, 2020 12:00 PM

HalleyWang
HalleyWang
 59
/*
    sort x coord first, we will handle each point in x-increasing order.
    For each building, we will have 2 points in our list, (L,H), (R,-H). Negative height means out of the building's width.
    Maintain a priority queue to find out the current max y coord.
    T:O(nlogn)/S:O(n)
*/
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) 
    {
        vector<pair<int,int>> s;
        multiset<int> q;
        vector<vector<int>> ans;
        for (auto building:buildings) {
            s.push_back({building[0],building[2]});
            s.push_back({building[1],-1*building[2]});
        }
        sort(s.begin(),s.end(),[](auto a, auto b){
            if (a.first==b.first) return a.second>=b.second;
            else return a.first<=b.first;
        });
        q.insert(0); int cur_max=0;
        for (auto building:s) {
            if (building.second<0) 
                q.erase(q.find(-1*building.second));
            else q.insert(building.second);
            if (*(q.rbegin())!=cur_max) {
                cur_max=*(q.rbegin());
                ans.push_back({building.first,cur_max});
            }
        }
        return ans;
    }
};
