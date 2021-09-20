class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<int> d(N+1, 1000000);
        d[K]=0;
        for(int i=0;i<N-1;i++)
            for(auto it: times)
                if(d[it[1]]>d[it[0]] + it[2])
                    d[it[1]]=d[it[0]]+it[2];
        int res=*max_element(d.begin()+1, d.end());
        if(res==1000000) return -1;
        return res;
    }
};
