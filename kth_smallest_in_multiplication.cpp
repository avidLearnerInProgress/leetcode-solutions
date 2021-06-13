class Solution {
    bool isEnough(int m, int n, int k, int num) {
        int count = 0;
        for(int i = 1; i < m + 1; i++) {
            int add = min(num/i, n);
            if (add == 0)
                break;
            count += add;
        }
        return count >= k;
    }
    
public:
    int findKthNumber(int m, int n, int k) {
        
        int left = 1, right = m * n;
        
        while(left < right) {
            
            //find mid
            int mid = left + (right-left)/2;
            
            //condition
            if (isEnough(m,n,k,mid))
                right = mid;
            
            //else
            else
                left = mid+1;
        }
        
        return left;
    }
};
