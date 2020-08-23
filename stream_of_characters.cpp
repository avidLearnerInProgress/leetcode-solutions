//standard trie class to insert character in the trie
class Trie {
    public:
    vector<Trie*> next;
    bool isWord;
    Trie () {
        next = vector<Trie*>(26,nullptr);
        isWord = false;
    }
    void insert (string& s) {
        Trie* cur = this;
        for (char& c: s) {
            if (cur->next[c-'a']==nullptr) {
                cur->next[c-'a'] = new Trie();
            }
            cur = cur->next[c-'a'];
        }
        cur->isWord = true;
    }  
};


class StreamChecker {
    Trie root;
    list<char> buffer;
    int W_MAX;
    
    public:
    StreamChecker(vector<string>& words) {
        W_MAX = 0;
        for (auto& w: words) {
            if (w.size() > W_MAX) W_MAX = w.size();
            reverse(w.begin(), w.end());
            root.insert(w);
        }
    }
    
    bool query(char letter) {
        buffer.push_back(letter);
        if (buffer.size() == W_MAX+1) buffer.pop_front();
		/*
		 * No point in writing input letters in an unbounded buffer.
         * the maximum size of the words from input list is W_MAX. We don't need to store
         * more characters than that.
		 */
        Trie* cur = &root;
        for (auto it = buffer.rbegin(); it != buffer.rend(); ++it) {
            if (cur->isWord) return true;
            if (cur->next[*it -'a'] == nullptr) return false;
            cur = cur->next[*it-'a'];
        }
        return (cur->isWord);
    }
};


/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
