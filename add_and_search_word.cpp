class WordDictionary {
public:
    /** Initialize your data structure here. */
    vector<WordDictionary* > children;
    bool isEndOfWord;
    
    WordDictionary() {
        this->isEndOfWord = false; //determine end of word
        this->children = vector<WordDictionary* >(26, nullptr); //for each node, there are 26 possibilities of character in children
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        auto current_dict = this;
        for(auto const c : word) {
            if(current_dict->children[c - 'a'] == nullptr) //check if the current char exist in the Trie
                current_dict->children[c - 'a'] = new WordDictionary(); //initialize a new dictionary for each possible children
            current_dict = current_dict->children[c - 'a']; //increment this pointer
        }
        current_dict->isEndOfWord = true; //set the flag to true to determine end of word
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        
        auto current_dict = this;
        for(int i=0; i<word.length(); i++) {
            auto c = word[i];
            if(c == '.'){ //iterate through all the possibilities for this edgecase
                for(auto ch : current_dict->children)
                    if(ch && ch->search(word.substr(i+1))) return true;
                return false;
            }
            if(current_dict->children[c - 'a'] == nullptr) return false;
            current_dict = current_dict->children[c - 'a']; //increment this pointer
        }
        return current_dict && current_dict->isEndOfWord;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
