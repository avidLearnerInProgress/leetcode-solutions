class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if(A.size() < 3) return false;
        if(A.size() == 0) return false;
        if(A[0] > A[1]) return false;
        
        int peak = A[0], index = -1;
        
        for(int i=0; i<A.size()-1; i++){
            if(A[i+1] == A[i])
                return false;
            if(A[i+1] < A[i]){
                peak = A[i];
                index = i;
                break;
            }
        }
        for(int i=index+1; i<A.size()-1; i++)
            if(A[i+1] >= A[i])
                return false;
        
        return true;
    }
};