class Solution {
public:
    string split(string  s){
        string new_str = "";
        for(auto it=s.begin(); it!=s.end();it++){
            if(*it != '.')
                new_str+= *it;
            else if(*it == '.')
                new_str += "[.]";
        }
        return new_str;
    } 
    string defangIPaddr(string address){
        return split(address);
    }      
};