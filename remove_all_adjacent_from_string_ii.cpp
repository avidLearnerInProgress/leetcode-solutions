// class Solution {
// private:
//     void removeHelper(string &s, int K) {
//         int n = s.length();
//         if(n < K ) return; // edgecase
// 		// cout<<"\nCurrent string - "<<s<<"\n";
		
// 		bool remove = false;
//         int position = 0;
//         int start = 0;
        
//         while(position <= n-K+1) {
//             if(s[position] == s[position+1]) { // if two characters match, then check for the next K characters
//                 start = position; // initialize start pointer for removal
//                 // cout<<"Start"<<start<<"\t";
//                 int checkEqual = 1; // to check for K matches, the count of equal matches must be K - 1. Thus, 1 + K - 1 = K.
//                 while(s[position] == s[position+1]) { // if all the next K characters match
//                     ++position, ++checkEqual;
//                     if(checkEqual == K) break; 
//                 }
//                 // cout<<"CheckEqual"<<checkEqual<<"\n";
//                 if(checkEqual == K and start <= n-K) {
//                     remove = true; // flag for recursive call
//                     s.erase(s.begin() + start, s.begin() + start + K);
//                     cout<<s<<" |##| "<<remove<<" | ";
//                     position += K;
//                     if(position == n) { // check for out of bounds
//                         // cout<<"1\n";
//                         break;
//                     }
//                     else
//                         // cout<<"0\n";
//                 }
//             }
//             else {
//                 ++position; //increment and check next char in case of mismatch
//             }
//         }
//         if(remove == false) return; //if no duplicate found or if string has become empty after recursive deletions
//         else if(remove == true) removeHelper(s, K);
//     }
// public:
//     string removeDuplicates(string S, int k) {
//         if(S == "") return "";
//         removeHelper(S, k);
//         return S;   
//     }  
// };



//stack based solution
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<int,int>> st;//stack will hold  (index, number of same character before the index including itself)
        
        for(int i = 0; i < s.size(); i++) {
            if(!st.empty() and s[st.top().first] == s[i]) { //if the current character matches with the character in the top of the stack
                if(st.top().second + 1 == k) { //if adding the current character in list , makes a list of size 'k' of same chatacters ,
                    int temp = k - 1;
                    while(temp--) 
                        st.pop();
                }
                else   //if it doesn't make a size of 'k' then push (index, number of same character) pair
                    st.push({i,st.top().second + 1});
            }      
            else //if the stack is empty , push the current character index and number of same character , which is 1 
                st.push({i, 1});
            
        }
    
        string result = "";
        while(!st.empty()) {
            result += s[st.top().first];
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
