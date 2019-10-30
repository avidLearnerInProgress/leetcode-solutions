#include<bits/stdc++.h>
using namespace std;

long long maxArea(long long a[],long long n){
    stack<long long> s;
    long long max_area=0;
    long long area_with_top;
    long long top;
    
    long long i=0;
    while(i<n){
        if(s.empty() || a[s.top()]<=a[i]) //check if curr is > than curr_top
            s.push(i++); //i++ because starting from 0 
            
        else{
            top=s.top(); 
            s.pop();
            area_with_top=a[top]*(s.empty() ? i: i-s.top() -1);
            
            if(max_area<area_with_top)
                max_area=area_with_top;
                
        }
    }
    
    
    while(!s.empty()){
            top=s.top();
            s.pop();
            area_with_top=a[top]*(s.empty() ? i: i-s.top() -1);
            
            if(max_area<area_with_top)
                max_area=area_with_top;
                
    }
    return max_area;
}

int main()
 {
	//code
        long long T;
        cin>>T;
        while(T--)
        { 
            long long n;cin>>n;
            long long arr[n];
            for(long long i=0;i<n;i++)cin>>arr[i];
            
            long long res=maxArea(arr,n);
            cout<<res<<endl;
        }
	return 0;
}