// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        int mid, left = 0, right = n;
        while(left < right) {
            
            //find mid
            mid = left + (right - left) / 2;
            
            //condition
            if(isBadVersion(mid)) {
                right = mid;
            }
            
            //else
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};
