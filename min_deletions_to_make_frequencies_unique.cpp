class Solution {
public:
    int minDeletions(string s) {
        int n = s.size();
        if(n==0 || n==1) return 0;
        priority_queue<pair<int,char>> pq;
        
        vector<int> v(26,0);
        int ans=0;
        for(int i=0; i<n; i++) {
            v[s[i]-'a']++;
        }
        for(int i=0; i<26; i++) {
            if(v[i]!=0) {
                pq.push(make_pair(v[i], i+'a'));
            }
        }
        
        while(!pq.empty()) {
            pair<int, char> tmp = pq.top();
            pq.pop();
            
            if(!pq.empty() && tmp.first == pq.top().first) {
                ans++;
                tmp.first--;
                if(tmp.first>0) {
                    pq.push(tmp);
                }
            }
            
        }
        
        return ans;
        
    }
};
