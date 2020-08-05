class Solution {
public:
    int scoreOfParentheses(string S) {
        if(S.size() == 0) return 0;
        int score = 0;
        
        stack<int> st;
        for(const auto c : S) {
            if(c == '(') {
                st.push(score);
                score = 0;
            }
            else {
                score = st.top() + max(2 * score, 1);
                st.pop();
            }
        }
        return score;
    }
};
