class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        if(source.size() == 0) return {};
        int i, j;
        bool is_comment = false;
        vector<string> result;
        string s;
        
        for(i = 0; i<source.size();i++){
            for(j = 0; j<source[i].size();j++){
                /*if(j < source[i].size()-1){
                     if(!is_comment){
                         if(source[i][j] == '/' && source[i][j+1] == '/'){
                             break;
                         }
                         else if(source[i][j] == '/' && source[i][j+1] == '*'){
                             is_comment = true; j++;
                         }
                     }
                     else if(is_comment){
                        if(source[i][j] == '*' && source[i][j+1] == '/'){
                            is_comment = false; j++;
                        }
                    }
                    else if(!is_comment) s.push_back(source[i][j]);
                }*/
                
                if(!is_comment && j < source[i].size() - 1 && source[i][j] == '/' && source[i][j+1] == '/'){ // just break and goto next line
                    break;                
                }
                else if(!is_comment && j < source[i].size() && source[i][j] == '/' && source[i][j+1] == '*'){
                    is_comment = true; //now we dont care about other characters 
                    j++;
                }
                else if(is_comment && j < source[i].size() && source[i][j] == '*' && source[i][j+1] == '/'){
                    is_comment = false;
                    j++;
                }
                else if(!is_comment){ //normal character)
                    s.push_back(source[i][j]);
                }
            }
            if(!is_comment) result.push_back(s), s.clear();                   
        }
        vector<string> f_res;
        
        for(string r : result){
            if(r != "")
                f_res.push_back(r);        
        }
        return f_res;
    //return result;
    }
};
