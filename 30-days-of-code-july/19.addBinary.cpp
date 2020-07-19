class Solution {
public:
    string addBinary(string a, string b) {
            int la= a.size();
            int lb=b.size();
            string res="";
            int carry=0;
            while(la>0 || lb >0)
            {            
                int sum = carry;
                if(la > 0)
                    sum += (a[--la] - '0');

                if(lb > 0)
                    sum += (b[--lb] - '0');

                res.insert(res.begin(), sum % 2 + '0');
                carry = sum / 2;
            }
            if(carry > 0)
                res.insert(res.begin(), '1');

            return res;
    }
};
