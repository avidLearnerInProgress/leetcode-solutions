class Solution {
    
private:
    void removeHelper(string &s) {
        bool remove = false;
        int n = s.length();
        int position = 0;
        
        while(position < n-1) {
            // cout<<s[position]<<s[position+1]<<"-->";
            if(s[position] == s[position+1]) {
                remove = true;
                s.erase(s.begin() + position, s.begin() + position + 2);
                // cout<<s<<"\n";
                if(position <= n)
                    position+=2;
                else return; //iterator out of bounds
            }
            else {
                ++position; //increment and check 
            }
        }
        
        if(s.length() == 0 || remove == false) return;
        else if(remove == true) removeHelper(s);
    }
public:
    string removeDuplicates(string S) {
        if(S == "") return "";
        removeHelper(S);
        return S;
        
    }
    
    
    
};
