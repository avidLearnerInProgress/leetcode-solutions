class Solution {
public:
    bool isIncreasing(vector<int> &A) {
        for(int i=1; i<A.size(); i++){
            if(A[i-1] > A[i]){
                cout<<A[i-1]<<" "<<A[i]<<"\n";
                return false;
            }
                
        }
        return true;
    }
    bool isDecreasing(vector<int> &A) {
        for(int i=1; i<A.size(); i++){
            if(A[i-1] < A[i]){
                cout<<A[i-1]<<" "<<A[i]<<"\n";
                return false;
            }
        }
        return true;
    }
    bool isMonotonic(vector<int>& A) {
        if(isIncreasing(A) || isDecreasing(A))
            return true;
        return false;
    }
};