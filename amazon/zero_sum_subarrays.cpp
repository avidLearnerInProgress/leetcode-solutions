#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;
#define F(a,b,var) for(int var=a;var<b;var++)
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

/*
You are given an array A of size N. 
You need to print the total count of sub-arrays having their sum equal to 0
For each test case, in a new line, print the total number of subarrays whose sum is equal to 0.

Constraints:    
1 <= T <= 100
1<= N <= 107
-1010 <= Ai <= 1010

Example:
Input:
2
6
0 0 5 5 0 0
10
6  -1 -3 4 -2 2 4 6 -12 -7

Output:
6
4
*/


int main()
 {
	//code
	
        FAST_INP;
        int T;
        cin>>T;
        while(T--)
        {   
            int n, c; cin>>n;
            vector<int> sub_array_test;
            for(int i = 0; i < n; i++){
                int curr;
                cin>>curr;
                sub_array_test.push_back(curr);
            }
            
            
            /*
            maintain global sum = 0
            use hashmap that maps the current sum to vector of pairs or end index... map<int, vector<int>>
        
            if sum(arr[0...i]) == 0 and sum(arr[0...j]) == 0
            then there exists a sub-array arr[i+1]...arr[j] whose sum is 0
            */
            // initialisations
            
            unordered_map<int, int> sub_array_mp;
            int curr_sum = 0, zero_count = 0;
            
            //o(n)
            for(int i = 0; i < sub_array_test.size(); i++){
                curr_sum += sub_array_test[i]; //cummulative sum
                
                if(curr_sum == 0) // indicates that there exists a pair from 0 to i
                        zero_count++;
    
                if(sub_array_mp[curr_sum] != 0) // a pair exists whose sum == 0 is already discovered
                    zero_count += sub_array_mp[curr_sum];                    
                
                sub_array_mp[curr_sum]++;
            }
            cout<<zero_count<<"\n"; 
        }
	return 0;
}