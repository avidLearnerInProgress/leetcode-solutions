class Solution {
public:
    
    vector<vector<string>> result;
    
    //find all paths upto min-depth using DFS
    void DFS(string &beginWord, string &endWord, vector<string> &path, unordered_map<string, unordered_set<string>> &adjacencyList) {
        
        path.push_back(beginWord);
        
        if(beginWord == endWord) { //terminating condition
            result.push_back(path);
            path.clear();
            return;
        }
        
        for(auto child : adjacencyList[beginWord]) {
            DFS(child, endWord, path, adjacencyList);
        }
        
        path.pop_back(); //backtrack
    }
    
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        if(beginWord.size() == 0 or endWord.size() == 0 or wordList.size() == 0) return vector<vector<string>>();
        
        queue<string> Q; //BFS
        unordered_map<string, int> visited; // Key => Node, Value => Depth
        unordered_map<string, unordered_set<string>> adjacencyList; //store list for immediate children to current parent (next level)
        unordered_set<string> words(wordList.begin(), wordList.end()); //set of words
        
        if(words.find(endWord) == words.end()) return vector<vector<string>>();
        
        //get min-depth via BFS
        Q.push(beginWord);
        visited[beginWord] = 0;
        
        while(!Q.empty()) {
            
            auto currentWord = Q.front();
            Q.pop();
            
            string temp = currentWord;
            for(int i=0; i<currentWord.size(); i++) {
                
                for(char x='a'; x<='z'; x++) {
                    
                    if(temp[i] == x) continue; //if same character as that of original string
                    
                    temp[i] = x; //change original character
                    
                    if(words.find(temp) != words.end()) { //current string(temp) in wordList
                        
                        if(visited.find(temp) == visited.end()) { //current string(temp) already not visited.. means its a new child
                            visited[temp] = visited[currentWord] + 1; //store level of current child as level_of_parent+1
                            Q.push(temp); //push current child to Q
                            adjacencyList[currentWord].insert(temp); //add next level child as an adjacent node to currentWord(parent)
                        }
                        
                        else if(visited[temp] == visited[currentWord] + 1) { //if the current child is already visited and its the child in the new level below level of currentWord(parent)
                            
                            adjacencyList[currentWord].insert(temp); //add next level child as an adjacent node to currentWord(parent)
                            
                        }                        
                    }
                    temp[i] = currentWord[i]; //replace original character
                    
                }
            }
            
        }
        
        vector<string> path;
        DFS(beginWord, endWord, path, adjacencyList);
        
        return result;
    }
};
