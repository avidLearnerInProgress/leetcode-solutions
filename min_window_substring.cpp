class Solution {
public:
    string minWindow(string s, string t) {
        
        if(s.size() < t.size()) return "";
        
        int hashPattern[256] = {0}, hashString[256] = {0};
        for(auto ch : t) {
            hashPattern[ch]++;
        }
        
        int count = 0, start = 0, startIndex = -1, minWindowLength = INT_MAX;
        for(int i=0; i<s.size(); i++) {
            
            //increment occurence of char in string_map
            hashString[s[i]]++;
            
            // Here we check if the current char is in the pattern as well. 
            // Since we calculate running frequency of char in string_map as we encounter in the for loop, we do a <= comparison of hashString[s[i]] and hashPattern[s[i]]. It means the count of current char in string_map should be either equal count of current char in hash_map or less than count of current char in hash_map 
            //if s[i] is in pattern_map and hashString[s[i]] == hashPattern[s[i]] or  hashString[s[i]] < hashPattern[s[i]]
            if(hashPattern[s[i]] != 0 and hashString[s[i]] <= hashPattern[s[i]]) {
                count++;
            }
            
            
            if(count == t.size()) { //if we find the pattern in the string
                
                //minimize the window from start
                
                while((hashString[s[start]] > hashPattern[s[start]]) or hashPattern[s[start]] == 0) {
                    
                    //if current char at start is occuring more times than in pattern, we can minimize the window.
                    //remove the current char at start from string_map and increment start; thereby reducing size of window.
                    if(hashString[s[start]] > hashPattern[s[start]]) hashString[s[start]]--;
                    
                    //if the current char at start is not present in the pattern, just increment the start...
                    start++;
                }
                
                //get the minimum of all the windows seen so far
                int currentWindowLength = i - start + 1;
                if(currentWindowLength < minWindowLength) {
                    minWindowLength = currentWindowLength;
                    startIndex = start;
                }
            }
        }
        
        if(startIndex == -1) return "";
        else return s.substr(startIndex, minWindowLength);
        
    }
};
