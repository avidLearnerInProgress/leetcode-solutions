class Trie {
public:
    bool isEndOfWord;
    vector<Trie *> children;
    /** Initialize your data structure here. */
    Trie() {
        this->isEndOfWord = false;
        this->children = vector<Trie *>(26, nullptr);
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        auto current = this;
        for(auto ch : word) {
            if(current->children[ch - 'a'] == nullptr)
                current->children[ch - 'a'] = new Trie;
            current = current->children[ch - 'a'];
        }
        current->isEndOfWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto current = this;
        for(auto ch : word) {
            if(current->children[ch - 'a'] == nullptr) return false;
            current = current->children[ch - 'a'];
            if(current == NULL) return false;
        }
        return current->isEndOfWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto current = this;
        for(auto ch : prefix) {
            if(current->children[ch - 'a'] == nullptr) return false;
            current = current->children[ch - 'a'];
            if(current == NULL) return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
