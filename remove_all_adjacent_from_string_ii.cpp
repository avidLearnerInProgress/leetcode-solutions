class Solution {
private:
    void removeHelper(string &s, int K) {
        int n = s.length();
        if(n < K ) return; // edgecase
		// cout<<"\nCurrent string - "<<s<<"\n";
		
		bool remove = false;
        int position = 0;
        int start = 0;
        
        while(position <= n-K+1) {
            if(s[position] == s[position+1]) { // if two characters match, then check for the next K characters
                start = position; // initialize start pointer for removal
                // cout<<"Start"<<start<<"\t";
                int checkEqual = 1; // to check for K matches, the count of equal matches must be K - 1. Thus, 1 + K - 1 = K.
                while(s[position] == s[position+1]) { // if all the next K characters match
                    ++position, ++checkEqual;
                    if(checkEqual == K) break; 
                }
                // cout<<"CheckEqual"<<checkEqual<<"\n";
                if(checkEqual == K and start <= n-K) {
                    remove = true; // flag for recursive call
                    s.erase(s.begin() + start, s.begin() + start + K);
                    cout<<s<<" |##| "<<remove<<" | ";
                    position += K;
                    if(position == n) { // check for out of bounds
                        // cout<<"1\n";
                        break;
                    }
                    else
                        // cout<<"0\n";
                }
            }
            else {
                ++position; //increment and check next char in case of mismatch
            }
        }
        if(remove == false) return; //if no duplicate found or if string has become empty after recursive deletions
        else if(remove == true) removeHelper(s, K);
    }
public:
    string removeDuplicates(string S, int k) {
        if(S == "") return "";
        removeHelper(S, k);
        return S;   
    }  
};
