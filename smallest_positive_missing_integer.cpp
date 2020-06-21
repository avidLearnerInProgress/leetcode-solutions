#include<bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.
int missingNumber(int arr[], int n);
int main() { 
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)cin>>arr[i];
        cout<<missingNumber(arr, n)<<endl;
    }
    return 0; 
} 
int missingNumber(int arr[], int n) { 
    
    // Your code here
    map<int,int>mp;
    for(int i=0;i<n;i++)
        if(arr[i]>0)
            mp[arr[i]]++;
    
   map<int, int>:: iterator it;
   int max_ele = *max_element(arr,arr+n);
   int i=1;
   while(i<=max_ele)
   {
       if(mp.find(i)==mp.end())
       return i;
       i++;
   }
    return i;    
} 