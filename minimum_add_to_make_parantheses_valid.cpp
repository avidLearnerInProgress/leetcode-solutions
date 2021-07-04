class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> st;
        
        for(auto ch : s) {
            
            if(ch == '(') st.push(ch);
            else {
                if(!st.empty() and st.top() == '(') st.pop();
                else st.push(ch);
            }
            
        }
        return st.size();
    }
};
