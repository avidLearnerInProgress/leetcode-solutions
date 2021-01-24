class Solution {
public:
    int numDecodings(string s) {
        
        int n = s.size();
        int total = 1;
        int single_count = 1;
        
        if(s[0]=='0')
            return 0;
        
        for(int i=n-2; i>=0; i--)
        {
            if(s[i+1]=='0' and (s[i]>'2'|| s[i]=='0'))
                return 0;
            
            if(s[i]=='0')
                continue;
            
            if(s[i+1]=='0')
            {
                single_count=0;
                continue;
            }
            
            if(s[i]>'2' || s[i+1]>'6' and s[i]=='2')
            {
                single_count = total;
                continue;
            }
            
            else
            {
 
                int temp = total;
                total = total+single_count;
                single_count = single_count + (temp-single_count);
            }
        }
        return total;
    }
}; 

