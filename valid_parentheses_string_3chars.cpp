class Solution {
public:
    bool checkValidString(string s) {
        
        
        stack<int> charStack, starStack;
        
        for(auto i=0; i<s.size(); i++){
            if(s[i] == '(')
                charStack.push(i);
            else if(s[i] == '*')
                starStack.push(i);
            else{ //if char is )
                
                if(charStack.empty() && starStack.empty()) return false;
                
                if(!charStack.empty())
                    charStack.pop();
                else{
                    if(!starStack.empty())
                        starStack.pop();
                }
            }
        }
        
        while(!starStack.empty() && !charStack.empty()){
            if(charStack.top() > starStack.top()) return false;
            else{
                charStack.pop();
                starStack.pop();
            }
        }
        return charStack.empty();
    }
};