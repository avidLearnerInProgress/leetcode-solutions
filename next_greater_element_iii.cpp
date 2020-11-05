class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int i = s.size() - 2;
        // start from right
        // find the number x which is smaller than the next one
        for(; i >= 0; i--){
            if(s[i] < s[i + 1]) break;
        }
        
        // if it doesn't exist, return -1
        if(i < 0) return -1;
        
        // find the number x' in the right side which is just greater than x
        for(int j = s.size() - 1; j > i; j--){
            if(s[j] > s[i]){
                swap(s[i], s[j]);
                break;
            }
        }
        
        // reverse right side to make it in increasing order
        reverse(s.begin() + i + 1, s.end());
        long res = stol(s);
        return res > INT_MAX? -1 : res; // check if the result is longer than 32-bits
    }
};
