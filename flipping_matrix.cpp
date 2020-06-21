class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        /* make sure all the col-0 will be 1's */
        for(int i = 0 ; i < A.size() ; i++)
            if(A[i][0] == 0) 
                for(int& element:A[i]) element=!element;
        
        /* check col-1 from col-end */
        int row_mid = (A.size()/2) + (A.size()%2);
        for(int i = 1 ; i < A[0].size() ; i++)
            count_1s_and_flip(A,i,row_mid);
        
        /* sum up the binary value to res */
        int res = 0;
        for(int i = 0 ; i < A.size() ; i ++)
            res += binary2dec(A,i);
        
        return res;
    }
    
    /* this function is used to count if current column has more 0's than 1's, if YES, flip it */
    void count_1s_and_flip(vector<vector<int>>& A, int col,int row_mid){
        for(int i = 0 ; i < A.size() ;i++)
            row_mid -= A[i][col];
        if(row_mid > 0) // 0's is more than 1's need to flip
            for(int i = 0 ; i < A.size() ;i++)
                A[i][col] = !A[i][col];
    }
    /* this function is used to calculate row into a decimal value */
    int binary2dec(vector<vector<int>>& A, int row){
        int res = 0;
        for(int i = A[0].size()-1,cnt = 0 ; i >= 0 ; i--,cnt++)
            res += (A[row][i]<<cnt);
        return res;
    }
        
        
        /*
        
        
        //check for first column greedily..
        for(int i=0; i<A.size(); i++){
            for(int &element : A[i])
                if(A[i][0] == 0) element = !element;
        }
        
        
        //check for rest of the columns..
        int mid = (A.size()/2) + (A.size()%2);
        
        for(int i=1; i<A[0].size(); i++)
            count_flip(A, i, mid);   
        
        int res = 0;
        for(int row = 0; row < A.size(); row++){
        for(int i = A[0].size()-1,cnt = 0 ; i >= 0 ; i--,cnt++)
            res += (A[row][i]<<cnt);
        }
        return res;
        
    }
    
    
    void count_flip(vector<vector<int>> &A, int i, int mid){
        int res = 0;
        
        for(int col=0; col<A[i].size(); col++){
            mid -= A[col][i];    
        }
        if(res > 0){
            for(int col=0; col<A[i].size(); col++){
                A[col][i] = !A[col][i];
            }
        }
    }
    */
    
    
    
    
};