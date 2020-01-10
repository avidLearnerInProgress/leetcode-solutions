class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int dimension = A.size();
        if(dimension == 0) return {};
        
        
        int ind = dimension - 1;
        int left = 0, right = dimension - 1;
        vector<int> tmp(dimension);
        
        while(left <= right){
            int c1 = A[left] * A[left];
            int c2 = A[right] *A[right];
            
            if(c1 < c2){
                tmp[ind] = c2;
                right--;
                ind--;
            }
            else{
                tmp[ind] = c1;
                left++;
                ind--;
            }
        }
        
        return tmp;
    }
};