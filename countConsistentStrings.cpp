class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        
        /*
            convert string to set --
            linear search on words
        */
        set<char> unique;
        for(auto &c : allowed) {
            if(unique.find(c) == unique.end())
                unique.insert(c);
        }
        
        int countConsistent = 0;
        for(auto &word : words) {
            bool checkFlag = true;
            for(auto &chr : word) {
                //if not present flag & break..
                if(unique.find(chr) == unique.end()) {
                    checkFlag = false; break;
                } 
            }
            if(checkFlag)
                countConsistent++;
        }
        
        return countConsistent;
    }
};
