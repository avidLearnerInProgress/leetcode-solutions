#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;
#define F(a,b,var) for(int var=a;var<b;var++)
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int minOpsToMakePalindrome(vector<int> test_palin){
    int i = 0, j = test_palin.size() - 1;
    int counts = 0;
    while(i <= j){
        if(test_palin[i] == test_palin[j]){
            i += 1;
            j -= 1;
        }
        
        else if(test_palin[i] > test_palin[j]){
            j -= 1;
            test_palin[j] += test_palin[j + 1];
            counts += 1;
        }
        else{
            i += 1;
            test_palin[i] += test_palin[i - 1];
            counts += 1;
        }
    }
    //cout<<counts<<"\n";
    return counts;
}

int main() {
    
	//code
	
    FAST_INP;
    int T;
    cin>>T;
    while(T--)
    {
        int n, i, curr; 
        cin>>n;
        vector<int> test_palin;
        
        for(int i=0; i<n; i++){
            cin>>curr;
            test_palin.push_back(curr);
        }
        cout<<minOpsToMakePalindrome(test_palin)<<endl;
    }
	return 0;
}