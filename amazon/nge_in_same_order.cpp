#include<bits/stdc++.h>
using namespace std;

void nge(const vector<int> &v){
    if(v.size() == 0) return;
    
    int next;
    stack<int> s;
    s.push(v[0]);
    
    for(int i=1; i<v.size();i++){
        next = v[i];
        if(s.empty()){ //corner case
            s.push(next);
            continue;
        }
        
        while(!s.empty() && next > s.top()){
            cout<<s.top()<<" "<<next<<"\n"; //next is nge for all eles in stack
            s.pop();
        }
        s.push(next);
    }
    
    while(!s.empty()){
        cout<<s.top()<<" "<<-1<<"\n";
        s.pop();
    }
}

void ngeSameOrder(const vector<int> &v){
    if(v.size() == 0) return;
    stack<int> s;
    vector<int> res(v.size());
    
    for(int i = v.size()-1; i>=0; i--){
        int next = v[i];
        
        while(!s.empty() && s.top() <= next)
            s.pop();
        
        if(s.empty())
            res[i] = -1;
        else
            res[i] = s.top();
        s.push(v[i]);
    }
    for(int i=0; i<res.size();i++){
        cout<<v[i]<<" "<<res[i]<<"\n";
    }
    
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];
    //nge logic
    //nge(v);
    ngeSameOrder(v);
    return 0;
}