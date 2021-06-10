class Solution {
    
    bool isPossibleAllocation(int barrier, vector<int> &weights, int &totalDays, int &totalWeights) {
        //totalWeights = number of weights
        
        int allowedDays = 1, capacity = 0;
        for(auto weight : weights) {
            if(weight > barrier) return false;
            
            if(weight + capacity > barrier) {
                allowedDays++; //reallocate capacity
                capacity = weight;
                
                // if(allowedDays > totalDays) return false;
            }
            else
                capacity += weight;
        }
        return (allowedDays <= totalDays) ? true : false;
    }
    
public:
    int shipWithinDays(vector<int>& weights, int days) {
        
        int totalWeights = weights.size(), totalDays = days;
        int res = -1;
        int left = weights[totalWeights - 1], right = accumulate(weights.begin(), weights.end(), 0);
        
        while(left < right) {
            
			//find mid
            int mid = left + (right - left) / 2;
						
            //condition
            if(isPossibleAllocation(mid, weights, totalDays, totalWeights)) {
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
