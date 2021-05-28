class Solution {
public:
    int check(int x, vector<int>& A, vector<int>& B)
    {
        int a=0,b=0,k=0;
        for(int i=0;i<A.size();i++)
        {
            if(A[i]==x && B[i]==x)
                continue;
            k++;
            if(A[i]==x)
                a++;
            else if(B[i]==x)
                b++;
            else
                return -1;
        }
        return k-max(a,b);
    }
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int x=check(A[0],A,B);
        if(x==-1)
            return check(B[0],A,B);
        return x;
    }
};
