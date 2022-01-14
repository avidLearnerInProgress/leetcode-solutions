class Solution {
public:
     int myAtoi(string str) {
        int r = 0;
        stringstream ss;
        ss << str;
        ss >> r;
        return r;
    }  
};
