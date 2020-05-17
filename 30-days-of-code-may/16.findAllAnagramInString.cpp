class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
    
        if(s.size() == 0 || p.size() > s.size()) return {};
        vector<int> curr_window(26, 0), pattern(26, 0), anagrams_start;
        
        for(auto c : p)
            pattern[c - 'a']++;
        
        /*
        1) eliminate least recently used characters
        2) length of sliding window should always be <= length of pattern to match. If it exceeds, we have to make the sliding window length = pattern length. For this purpose we use 1)
        */
        
        /*
        At i = 3, we eliminate char at i = 0 from s to make our sliding window have characters at s[1],s[2],s[3]
        At i = 4, we eliminate char at i = 1 from s to make our sliding window have characters at s[2],s[3],s[4]
        and so on..
        */
        
        for(auto i=0; i<s.size(); i++){
            curr_window[s[i] - 'a']++; //include current unseen character
            
            if(i >= p.size()){ //exclude least recently used characters
                auto exclude = s[i - p.size()];
                curr_window[exclude - 'a']--; 
            }
            
            if(curr_window == pattern){ //found anagram, store its start index
                anagrams_start.push_back(i - p.size() + 1); //+1 for 0 based indexing
            }
        }
        return anagrams_start;
    }
};