class Solution {
    bool isPossibleToMakeBouquets(vector<int> &bloomDay, int &barrier, int &m, int &k) {
        
        int flowers = 0, bouquets = 0;
        for(auto day : bloomDay) {
            
            flowers = (day <= barrier) ? flowers + 1 : 0;
            if(flowers == k) {
                flowers = 0;
                bouquets++;
            }
            if(bouquets == m) return true;
        }
        return false;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        if((long long)(m * k) > bloomDay.size()) return -1;
        /*Very similar to allocation minimum number of pages*/
        
        int mid, left = *min_element(bloomDay.begin(), bloomDay.end()), right = *max_element(bloomDay.begin(), bloomDay.end());
        
        while(left < right) {
            
            mid = left + (right - left) / 2;
            
            if(isPossibleToMakeBouquets(bloomDay, mid, m, k)) 
                right = mid;
            
            else
                left = mid + 1;
        }
        return left;
    }
};
