class Solution {
public:
    double myPow(double x, int n) {
        double p = 1;
        for (x = n > 0 ? x : 1 / x; n; n /= 2, x *= x) {
            if (n & 1) {
                p *= x;
            }
        }
        return p;
    }
};            
