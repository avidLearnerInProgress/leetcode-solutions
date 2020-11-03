class Solution {
public:

    void eraseStr(string &s) {
        s.erase(std::remove_if(s.begin(), s.end(), [](char c) { return !isalnum(c); }), s.end());
    }
    
    int compareVersion(string version1, string version2) {
      
        int i = 0, j = 0, num1 = 0, num2 = 0;
        int n1 = version1.size(), n2 = version2.size();
        
        while(i < n1 || j < n2) {
            
            while(i < n1 && version1[i] != '.') {
                num1 = num1*10 + (version1[i] - '0');
                i++;
            }
            
            while(j < n2 && version2[j] != '.') {
                num2 = num2*10 + (version2[j] - '0');
                j++;
            }
            
            cout<<num1<<"\t"<<num2<<"\n";
            
            if(num1 > num2) {
                return 1;
            }
            else if(num1 < num2) {
                return -1;
            }
            
            num1 = 0;
            num2 = 0;
            i++, j++;
        }
        return 0;
    }
   
};
