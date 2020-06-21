#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;
#define F(a,b,var) for(int var=a;var<b;var++)
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

void almost_sorted(vector<int> &sequence){
    //edgecases
    if(sequence.size() < 2){
        cout<<"Yes\n"; //since less than 2 means it can be reversed as well as swapped
        return;
    }
    
    if(is_sorted(sequence.begin(), sequence.end())){
        cout<<"Yes\n"; //already sorted
        return;
    }
        
    //vector is partially sorted..
    int N = sequence.size();
    int i = 0, j = sequence.size() - 1;
    
    while(i != N && sequence[i+1] > sequence[i])
        i++; //find start of partial array where it breaks the sorted sequence
    while(j >= 0 && sequence[j-1] < sequence[j])
        j--; //find end of partial array where it breaks the sorted sequence 
    
    //start and end of unsorted - subarray
    swap(sequence[i], sequence[j]);
    if(is_sorted(sequence.begin(), sequence.end())){
        cout<<"yes\n"; //partial is now sorted 
        cout<<"swap "<<(i+1)<<" "<<(j+1)<<"\n";
        return;
    }

    int k = i + 1, l = j - 1;
    while(k < l){
        swap(sequence[k], sequence[l]); //keep swapping the entire partial array .. basically reversing the array
        k++, l--;
    }
    
    if(is_sorted(sequence.begin(), sequence.end())){
        cout<<"yes\n"; //partial is now sorted 
        cout<<"reverse "<<(i+1)<<" "<<(j+1)<<"\n";
        return;
    }
    else{
        cout<<"no\n"; // it is not possible to make the array properly sorted..
        return;
    }
}

int main() {
    //code
    FAST_INP;
    int n;
    cin>>n;

    vector<int> seq(n);
    for(int i = 0; i < n; i++)
        cin>>seq[i];
    
    almost_sorted(seq);
    return 0;
}
