class Solution {
public:
    vector<string> search(string a){
        
        vector<string> x;
    
        for(int i=0; i<a.length(); i++)
            x.push_back(a.substr(0, i) + a.substr(i+1, a.length() - i - 1));
        
        return x;
    }
    
    
    int longestStrChain(vector<string>& words) {
        
        if(words.size() == 0) return 0;
        
        vector<vector<string>> w_vec(17);
        map<string, int> mp;
        
        for(auto word: words){
            w_vec[word.length()].push_back(word);
            mp[word] = 1;
        }
        
        int result = 1;
        //const int bound = 17;
        for(int i=2; i<=16; i++){
            for(int j=0; j<w_vec[i].size(); j++){
                
                vector<string> findAllWords = search(w_vec[i][j]);
                
                for(auto w : findAllWords){
                    if(mp.find(w) != mp.end()){
                        mp[w_vec[i][j]] = max(mp[w] + 1, mp[w_vec[i][j]]);
                    }
                }
                
                result = max(result, mp[w_vec[i][j]]);
            }
        }
        return result;
    }
};