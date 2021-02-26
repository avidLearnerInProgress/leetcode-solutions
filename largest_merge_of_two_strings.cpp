class Solution {                
public:                  
    string largestMerge(string word1, string word2) {
        string ans=""; 
        while(!word1.empty() || !word2.empty()) {
              if(word1[0]>word2[0]) {         
                    ans+=word1[0];           
                    word1.erase(word1.begin());
              }else if(word1[0]<word2[0]) {
                    ans+=word2[0];
                    word2.erase(word2.begin());
              }else {
                  if(word1<word2) {
                     ans+=word2[0];
                     word2.erase(word2.begin()); 
                  }else {
                      ans+=word1[0];
                      word1.erase(word1.begin());
                  }
              }        
        }
        return ans;
    }
};
