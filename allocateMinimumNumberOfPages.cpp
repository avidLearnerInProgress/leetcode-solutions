// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{   
    
    bool isPossibleAllocation(int barrier, int arr[], int totalBooks, int students) {
        
        int allowedStudents = 1, pages = 0;
        for(int i = 0; i < totalBooks; i++) {
            
            if(arr[i] > barrier) return false;
            if(arr[i] + pages > barrier) {
                allowedStudents += 1;
                pages = arr[i];
            }
            else
                pages += arr[i];
        }
        
        return (allowedStudents <= students) ? true : false;
    }
    
    public:
    //Function to find minimum number of pages.
    int findPages(int arr[], int n, int m) {
        //code here
        
        int students = m, totalBooks = n;
        int sumOfPages = 0, res = -1;
        int low = arr[0], high = accumulate(arr, arr + n, sumOfPages);
        
        while(low <= high) {
            
            int mid = low + (high - low) / 2;
            
            if(isPossibleAllocation(mid, arr, totalBooks, students)) {
                high = mid - 1;
                res = mid;
            }
            else {
                low = mid + 1;
            }
        }
        
        return res;
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends
