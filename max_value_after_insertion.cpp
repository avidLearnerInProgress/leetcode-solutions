class Solution {
public:
    string maxValue(string n, int x) {
        char c = ('0' + x);
        string ans = "";
        int i = 0;

        if(n[0] != '-') {
            while(i < n.size() && c <= n[i])
                ans += n[i++];
            ans += c;
            
            while(i < n.size())
                ans += n[i++];
        }
        
        else {
            ans += '-';
            i = 1;
            while(i < n.size() && n[i] <= c)
                ans += n[i++];
            ans += c;
            while(i < n.size())
                ans += n[i++];
        }

        return ans;
    }
};
