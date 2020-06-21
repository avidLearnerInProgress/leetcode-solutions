class Solution {
public:
    string freqAlphabets(string s) {
        
        string res;
        unordered_map<string,string> h = {
            {"1","a"},{"2","b"},{"3","c"},{"4","d"},{"5","e"},{"6","f"},{"7","g"},{"8","h"},{"9","i"},{"10","j"}
			,{"11","k"},{"12","l"},{"13","m"},{"14","n"},{"15","o"},{"16","p"},{"17","q"},{"18","r"},{"19","s"}
			,{"20","t"},{"21","u"},{"22","v"},{"23","w"},{"24","x"},{"25","y"},{"26","z"}
        };
        
        int i = s.length()-1;
        while(i>-1){
            if(s[i]=='#'){
                i-=2;
                string p = s.substr(i,2);
                res=h[p]+res;
            }
            else{
                res=h[s.substr(i,1)]+res;
            }
            i--;
        }
        return res;
        
    }
};