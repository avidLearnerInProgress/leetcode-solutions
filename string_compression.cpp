class Solution {
public:
    int compress(vector<char>& chars) {
        
        int index = 0;
        int i = 0;
        
        while(i < chars.size()) {
            int j = i;
            
            while(j < chars.size() and chars[i] == chars[j]) {
                j++;
            }
            
            chars[index++] = chars[i]; //first char of repeated sequence ... 
            if(j - i > 1) {
                string count = to_string(j - i);
                for(char c : count)
                    chars[index++] = c;
            }
            i = j;
        }
        
        return index;
    }
};
