#include <bits/stdc++.h>
using namespace std;

// Complete the riddle function below.
vector<long> riddle(vector<long> arr) {
    // complete this function
    int sz = arr.size();
    vector<long> left(sz+1), right(sz+1);
    stack<long> s;
    vector<long> result(sz+1);

    for (int i=0; i<=sz; i++) 
        result[i] = 0; 

    for(int i=0; i<sz; i++){
        left[i] = -1;
        right[i] = sz;
    }

    for(int i=0; i<sz; i++){
        while(!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
        
        if(!s.empty())
            left[i] = s.top();
        s.push(i);
    }

    while(!s.empty())
        s.pop();

    for(int i=sz-1; i>=0; i--){
        while(!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
        
        if(!s.empty())
            right[i] = s.top();
        s.push(i);
    }

    for(int i=0; i<sz; i++){
        long len = right[i] - left[i] - 1;
        result[len] = max(result[len], arr[i]);
    }    

    for(int i=sz-1; i>=1; i--)
        result[i] = max(result[i], result[i+1]);
    
    result.erase(result.begin());
    return result;
}

int main(){
    int T;
    cin>>T;
    
    while(T--){
        int n;
        cin>>n;
        vector<long> ip(n);
        for(int i=0; i<n; i++){
            cin>>ip[i];
        }
        vector<long> res = riddle(ip);
        for(const long &v: res){
            cout<<v<<" ";
        }
        cout<<"\n";
    }
}