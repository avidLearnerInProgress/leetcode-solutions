class CombinationIterator {
    string s;
    queue<string> q;
    
    void getCombination(int start, int length, string txt){
        if(length == 0){
            q.push(txt);
            return;
        }
        
        for(int i = start; i <= s.length() - length; ++i)
            getCombination(i+1, length-1, txt + s[i]);
    }
public:
    CombinationIterator(string characters, int combinationLength) {
        s = characters;
        string txt = "";
        getCombination(0, combinationLength, txt);
    }
    
    string next() {
        string str = q.front();
        q.pop();
        return str;
    }
    
    bool hasNext() {
        return !q.empty();
    }
};
