class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        if(A.size() == 0) return 0;
        
        int nocircle = helper(A), sum = 0;
        if(nocircle < 0) return nocircle;
        
        auto t = A;
        for(auto &n : t){
            sum += n;
            n *= -1;
        }
        
        int circle = sum + helper(t);
        return max(circle, nocircle);
    }
    
    int helper(vector<int>& A){
        if(A.size() == 0) return 0;
        
        int max_seen_so_far = INT_MIN, max_positive_seen = 0;
        for(auto num : A){
            if(max_positive_seen < 0)
                max_positive_seen = num;
            else
                max_positive_seen += num;
            max_seen_so_far = max(max_seen_so_far, max_positive_seen);
        }
        return max_seen_so_far;
    }
};