#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;
#define F(a,b,var) for(int var=a;var<b;var++)
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

int longestKUniqueCharSubstr(string &s, int k) {
    if(s.size() == 0) return 0;
    if(k == 0  or k > s.size()) return -1;
    
    const int CHAR_RANGE = 128;
    int frequency[CHAR_RANGE] = {0};
    unordered_set<char> window; // sliding window -- at any instance, there has to be k characters in the window
    int n = s.length();
    int low, high; // low ... high -- keep track of window boundaries
    int begin = 0, end = 0;
    
    for(low = 0, high = 0; high < n; high++) {
        window.insert(s[high]);
        frequency[s[high]]++;
        
        
        while(window.size() > k) { //if the window exceeds k characters -- 
            --frequency[s[low]]; //remove char from left
            if(frequency[s[low]] == 0) { //if the character frequency becomes 0, it means the character is no more present in the window; so erase it
                window.erase(s[low]);
            }
            low++; //increment left boundary 
        }
        
        if(high - low > end - begin) { //store the ax
            end = high, begin = low;
        }
    }
    return end - begin + 1;
}


int main()
 {
	//code
	
        FAST_INP;
        int T;
        cin>>T;
        while(T--)
        {
            int k;
            string s;
            
            cin>>s>>k;
            cout<<longestKUniqueCharSubstr(s, k)<<"\n";
            
        }
	return 0;
}
