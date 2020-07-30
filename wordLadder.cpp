class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        if(beginWord.size() == 0 or endWord.size() == 0 or wordList.size() == 0) return 0;
        
        set<string> dict;
        for(auto word : wordList) dict.insert(word);
    
        queue<string> q;
        int ladder = 1;
        q.push(beginWord);
        
        while(!q.empty()){
            
            int n = q.size();
            for(int i=0; i<n; i++){
                
                auto current = q.front();
                q.pop();
                
                if(current == endWord) 
                    return ladder;
                
                for(int j=0; j<current.size(); j++){
                    auto c = current[j];
                    
                    for(int k=0; k<26; k++){
                        
                        current[j] = 'a' + k;
                        if(dict.find(current) != dict.end()){
                            dict.erase(current);
                            q.push(current);
                        }
                    }
                    
                    current[j] = c;
                }
            }
            ladder++;
        }
        return 0;
    }
};
