class Solution {
public:
    int addDigits(int num) {
        int mod = num%9;
        if(num==0)
            return 0;
        if(mod==0)
            return 9;
        return mod;
    }
};``
