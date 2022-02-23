// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
//         if(strs.empty()) return {{}};
        
//         map<string, vector<string>> mp;
        
//         for(auto str: strs){
//             int cHash[26] = {0};
//             for(auto c : str)
//                 cHash[c-'a']++;
//             string st;
//             for(auto i : cHash){
//                 st += to_string(i) + ',';
//             }
//             mp[st].push_back(str);
//         }
        
//         vector<vector<string>> vs;
//         vector<string> cvs;
        
//         for(auto& [key, value] : mp){
//             for(auto ele : value){
//                 cvs.push_back(ele);
//             }
//             vs.push_back(cvs);
//             cvs.clear();
//         }
//         return vs;
//     }
// };


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
    
        # works only if we have all chars between 'a' => 'z'
        # TC: O(m * n * 26)) ==> O(m * n) where m = len(strs), n = max_length_of_string_in_strs
        hashmap = defaultdict(list)
        
        for string in strs:
            frequency = [0] * 26
            for char in string:
                frequency[ord(char) - 97] += 1 #97 is ord('a')
                
            hashmap[tuple(frequency)].append(string)
            
        return hashmap.values()
