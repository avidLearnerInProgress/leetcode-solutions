// # Non recursive solution    
// # class Solution:
// #     def decodeString(self, s: str) -> str:
// #         prevStr, currStr, currNum = '', '', 0
// #         decode, ans = [], ''
// #         for ch in s:
// #             if ch == '[':
// #                 decode.append(currNum)
// #                 decode.append(currStr)
// #                 currStr = ''
// #                 currNum = 0
// #             elif ch == ']':
// #                 prevStr = decode.pop()
// #                 digit = decode.pop()
// #                 currStr = prevStr + (currStr * digit)
// #             elif ch.isdigit():
// #                 currNum = currNum * 10 + int(ch)
// #             else:
// #                 currStr += ch            
// #         return currStr

    
class Solution {
    
private:
    string decodeStringHelper(int &position, string s) {
        
        int num = 0; //keep track of current integer
        string word = ""; //current word 
        
        for(;position<s.size(); ++position) {
            
            //if we encounter a [ - treat it as a start of subproblem and recurse. After this repeat the substr formed from recursion num times
            // ] - end of subproblem, return word
            //if we encounter a number - form the num
            //if we encounter a character - just add it to the current word 
            
            char currChar = s[position];
            if(currChar == '[') {
                string currStr = decodeStringHelper(++position, s);
                for(; num > 0; num--) word += currStr;
            } 
            
            else if(currChar >= '0' and currChar <= '9') {
                num = num * 10 + currChar - '0';
            }
            
            else if(currChar == ']') {
                return word;
            }
            
            else {
                word += currChar;
            }
            
        }
        return word;
    }
    
public:
    /*
        Recursive solution - more intuitive
    */   
    string decodeString(string s) {
        
        int position = 0;
        return decodeStringHelper(position, s);
    }
};
    
    
