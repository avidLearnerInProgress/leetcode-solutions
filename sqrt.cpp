class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        if(x == 1) return 1;
        
        int left = 1, right = x;
        long mid;
        
        while(left < right) {
            
            //find mid
            mid = left + (right - left) / 2;
            
            //condition
            if(mid * mid > x) right = mid;
            
            //else
            else left = mid + 1;
        }
        return left - 1;
    }
};
