// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int maxLen(int A[], int n);

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++)
            cin >> A[i];
        cout << maxLen(A, N) << endl;
    }
}
// } Driver Code Ends


/*You are required to complete this function*/

int maxLen(int A[], int n) {
    unordered_map<int,int > mp;
    int sum=0;
    int max_length=0;
    for(int i=0; i<n; i++){
        
        sum += A[i];
        if(A[i]==0 && max_length==0){
            max_length=1;
        }
        if(sum==0 && max_length>0){
            max_length = i+1;
        }
        if(mp.find(sum)!=mp.end()){
            max_length = max(max_length,i-mp[sum]);
        }else{
            mp[sum]=i;
        }
        
    }
    return max_length;
}         
