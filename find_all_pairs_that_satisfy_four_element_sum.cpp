#include<bits/stdc++.h>
using namespace std;

int main(){
    
    vector<int> input;
    int n, x; cin>>n;
    
    for(int i=0; i<n; i++)
    {
         cin>>x;
         input.push_back(x);
    }
    
    map<int, pair<int, int>> harry_potter;
    
    //o(n^2)
    int count = 0;
    for(int i=0; i<n; i++){ //o(n)
        for(int j=i+1; j<n; j++){ //o(n)
            if(harry_potter.find(input[i] + input[j]) != harry_potter.end()){
                pair<int, int> pp = harry_potter[input[i] + input[j]];
                cout<<input[pp.first]<<"\t"<<input[pp.second]<<"\t-->\t"<<input[i]<<"\t"<<input[j]<<"\n";
                count++;
            }
            //do this only if the pair is already not present in the map...
            else
                harry_potter[input[i] + input[j]] = make_pair(i, j);
        }
    }
    cout<<count<<"\n";
}