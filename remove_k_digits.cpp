class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size() == 0) return "";
        
        int i = 0;
        while(k > 0) { //k--            
            
            //triggered when i > 0
            i = (i > 0) ? i - 1 : 0; //bring the i back to peak before the previously removed peak
            
            while(i<num.size() - 1 && num[i] <= num[i+1]) {
                i++;                
            } // get the peak
            
            num.erase(num.begin() + i); //remove the peak
            k--; //decrement k
        }
        
        
        auto nonzero_int = num.find_first_not_of("0");
        num.erase(0, nonzero_int); //remove head 0's
        
        if(num.size() == 0) return "0";
        return num;
    }
};
