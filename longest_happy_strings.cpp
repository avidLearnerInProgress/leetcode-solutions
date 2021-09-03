class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if(a != 0) pq.push({ a, 'a' });
        if(b != 0) pq.push({ b, 'b' });
        if(c != 0) pq.push({ c, 'c' });
        char prev1 = '#';
        char prev2 = '#';
        string res;
        while(!pq.empty())
        {
            auto [cnt1, ch1] = pq.top(); pq.pop();
            if(ch1 == prev1 && ch1 == prev2)
            {
                if(pq.empty()) return res;
                auto [cnt2, ch2] = pq.top(); pq.pop();
                res += ch2;
                prev1 = prev2;
                prev2 = ch2;
                pq.push({ cnt1, ch1 });
                if(--cnt2 > 0) pq.push({ cnt2, ch2 });
            }
            else
            {
                prev1 = prev2;
                prev2 = ch1;
                res += ch1;
                if(--cnt1 > 0) pq.push({ cnt1, ch1 });
            }
        }
        return res;
    }
};
