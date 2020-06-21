class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        if(A.size() == 0) return 0;
        int count = 0, prev = 0;
        int i = 0, j = 0;
        
        
        while(j < A.size()){
            if(A[j] < L){ 
                count += prev;
                //i++;
            }
            else if(L<=A[j] && A[j]<=R){
                prev = j - i + 1;
                count += prev;
                //i++;
            }
            else{
                prev = 0;
                i = j + 1;
            }
            j++;
        }
        return count;
    }
};