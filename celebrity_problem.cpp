// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    bool knows(vector<vector<int>> &M, int a, int b) {
        return M[a][b];   
    }
    
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        
       int a = 0, b = n - 1;
       
       while(a < b) {
           if(knows(M, a, b)) a++;
           else b--;
       }
    
        for (int i = 0; i < n; i++) {
            if ( (i != a) && (knows(M, a, i) || !knows(M, i, a)) ) 
                return -1; 
        }
        
        return a; 
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends
