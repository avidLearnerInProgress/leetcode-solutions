class Solution {
public:
    vector<vector<string>>global_result;
    
    void printResult(int matrix[][9],int n){
        vector<string> local_result(n);
        for(int i=0;i<n;i++) {
            string tmp=""; // creating a tmp string             
            for(int j=0;j<n;j++) {
                if(matrix[i][j]==1) {
                    tmp+="Q"; // appending the results to the tmp string
                } else {
                    tmp+=".";
                }
            }
            local_result[i]=tmp; // putting the final tmp string result into the vector
        }
        global_result.push_back(local_result); // inserting the final vector into the resultatnt vector
    }
    
    bool isValid(int matrix[][9],int row,int col,int n) {
        
        // col check
        for(int r=0;r<row;r++) { 
            if(matrix[r][col]==1) return false;
        }
        
        // left diagonal
        int i=row,j=col;
        while(i>=0 && j>=0) {
            if(matrix[i][j]==1) return false;
            i--;j--;
        }
        
        // right diagonal 
        i=row,j=col;
        while(i>=0 && j<n) {
            if(matrix[i][j]==1) return false;
            i--;j++;
        }

        return true;
    }
    
    bool solve(int matrix[][9],int row,int n){
        if(row==n) { // if in all the rows, queens are placed, that means we have reached the end, print the Chessboard 
            printResult(matrix,n);
            return true;
        }
        bool nextQueen=false; // "assuming that next Queen's placement is not decided YET"
        for(int col=0;col<n;col++) { // moving into all the columns of "row" (look at the solve() func call above)
            if(isValid(matrix,row,col,n)) { // Checking if we can place the queen at this particularr place
                matrix[row][col]=1; // if yes, mark it as 1
                nextQueen = solve(matrix,row+1,n);// now looking for next Queen's placement, moving to the next row and calling this function Recursively.
                matrix[row][col]=0; //Backtracking
            }
        }
        return nextQueen; // returning the nextQueen's placement decision's to the function that called it RECURSIVELY
    }
    vector<vector<string>> solveNQueens(int n) {
        int matrix[9][9]={0}; // creating an 2d array of 9X9 since that os the max limit
        solve(matrix,0,n); // solve(matrix,starting row,max rows)
        return global_result;
    
    }
};
