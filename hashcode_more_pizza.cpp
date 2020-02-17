#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;
#define F(a,b,var) for(int var=a;var<b;var++)
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long

int main()
 {
	//code
    FAST_INP;
    
    int M, N, slices;
    cin>>M>>N;
    int W = M;
    vector<ll> types(N), result;
    ll total = 0;
    
    for(auto i=0; i<N; i++)
        cin>>types[i];
    
    for(auto i=N-1; i>=0; i--){
        if(M >= types[i]){
            total+=types[i];
            M -= types[i];
            //cout<<total<<"\t"<<M<<"\t"<<i<<"\n";
            result.push_back(i);
        }
    }
    sort(result.begin(), result.end());
    
    cout<<result.size()<<"\n";
    
    //cout<<"Indices -\n";
    for(auto i: result) cout<<i<<" ";
    
    //cout<<total<<"/"<<W<<"\n";
	return 0;
}