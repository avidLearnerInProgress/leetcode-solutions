class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string str=to_string(N);
        int i;
        for(i=0; i<str.size()-1; i++)
            if(str[i]>str[i+1])
                break;
        if(i==str.size()-1)
            return N;
        while(i>0 && str[i-1]>str[i]-1)
            i--;
        int num=0, j=0;
        while(j<str.size()){
            if(j==i)
                num=(num*10)+((str[j]-'0')-1);
            else if(j>i)
                num=(num*10)+9;
            else
                num=(num*10)+(str[j]-'0');
            j++;
        }
        return num;
    }
};