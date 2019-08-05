class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        int l1 = num1.size(), l2 = num2.size();
        if(l1 == 0 || l2 == 0) return 0;
        int ind1, ind2;
        vector<int> result(l1 + l2, 0);
        int sum, carry;
        
        for(int i = 0; i < l1; i++){
            carry = 0;
            ind1 = (int)(num1[l1 - i - 1] - '0');
            for(int j = 0; j < l2; j++){
                ind2 = (int)(num2[l2 - j - 1] - '0');
                sum = ind1 * ind2 + carry + result[i + j];
                carry = sum / 10;
                result[i + j] = sum % 10;
            }
            if(carry > 0)
                result[i + l2] += carry;
        }
        
        int begin = l1 + l2 - 1;
        while(result[begin] == 0) //check trailing zeros
            begin--;
        
        if(begin == -1) return "0";
        
        string f = "";
        for(int i = begin; i >= 0; i--)
            f += (char)(result[i] + '0');
        return f;
    }
};