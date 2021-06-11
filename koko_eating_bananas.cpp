class Solution {
    
    // O(n)
    bool isPossibleEating(int &barrier, vector<int> &piles, int &h) {
        //barrier == k 
        int hours = 0;
        
        for(auto pile : piles) 
            hours += (pile / barrier) + ((pile % barrier == 0) ? 0 : 1);
        
        return (hours <= h);
    }
    
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        /*
            minimize `k` where `k` is the speed of eating bananas. `k` also belongs to the piles. 
            in one hour we can eat upto `k` bananas. if there are less than `k` bananas in the pile, we just sit idle in remaining time of hour and don't start 
            we have to minimize `k` such that we can eat all pile of bananas within `h` hours.
            naturally for any `k` greater than `minimum_k`; we definitely can eat all pile of bananas within `h` hours. this justifies the monotonic increasing property for applying binary search
            so the search space is for k which is between 1 ... max(piles)
            
            min of max pattern .. (minimum eating speed for max bananas in h hours)
        */
        
        int mid, left = 1, right = *max_element(piles.begin(), piles.end());
        
        //(O logn * tC(isPossibleEating))
        while(left < right) {
            
            //find mid
            mid = left + (right - left) / 2;
            
            //condition
            if(isPossibleEating(mid, piles, h)) 
                right = mid;
                
            //else
            else
                left = mid + 1;
        }
        return left;
    }
};
