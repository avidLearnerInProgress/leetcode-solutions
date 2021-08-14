class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";
        
        string prev = countAndSay(n-1);
        string cur = "";
        int count = 1;
        
        for (int i = 0; i < prev.length()-1; i++) {
            if (prev[i] == prev[i+1]) {
                count++;
            }
            else {
                cur += to_string(count);
                cur += prev[i];
                count = 1;
            }
        }
        
        cur += to_string(count);
        cur += prev.back();
        
        return cur;
    }
};
