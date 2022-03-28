# class Solution {
# public:
#     int lengthOfLongestSubstring(string s) {
#         if(s.size() == 0) return 0;
        
#         unordered_map<char, int> ump;
#         int start = 0, longest = 0;
        
#         for(int i=0; i<s.size(); i++) {
#             if(ump.find(s[i]) != ump.end() and ump[s[i]] >= start) {
#                 start = ump[s[i]] + 1;
#             }
#             ump[s[i]] = i;
#             longest = max(longest, i - start + 1);
#         }
        
#         return longest;
#     }
# };


# class Solution:
#     def lengthOfLongestSubstring(self, s: str) -> int:
        
#         frequency = {}
#         maxLength = float('-inf')
#         start = 0
        
#         for idx, char in enumerate(s):
#             if char in frequency and start <= frequency[char]:
#                 start = frequency[char] + 1
#             else:
#                 maxLength = max(maxLength, idx - start + 1)
            
#             frequency[char] = idx
#         return 0 if maxLength == float('-inf') else maxLength
    
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        s = list(s)
        frequency = defaultdict(int)
        windowStart = 0
        lengthOfLongestSubstring = 0
        
        for windowEnd, endChar in enumerate(s):
            frequency[endChar] += 1
            
            if len(frequency) == (windowEnd - windowStart + 1):
                lengthOfLongestSubstring = max(lengthOfLongestSubstring, windowEnd - windowStart + 1)
                
            elif len(frequency) < (windowEnd - windowStart + 1):
                while len(frequency) < (windowEnd - windowStart + 1):
                    '''
                    less here because, for example - pww as a substring. the frequency state is {p: 1, w: 2}, but the freq.size() == 2 and there are 3 char_seen_so_far. This means that we have some repetitions
                    '''
                    startChar = s[windowStart]
                    frequency[startChar] -= 1
                    if frequency[startChar] == 0:
                        del frequency[startChar]
                    windowStart += 1

        # print(lengthOfLongestSubstring)
        return lengthOfLongestSubstring
