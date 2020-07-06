class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        //edgecases
        if(digits.empty()) return {};
        if(digits.size() == 1 && digits[0] == 9) return {1,0};
        
        auto len = digits.size() - 1;
        
        //start from right and traverse to the start
        auto rightmost = digits[len], carry = 0;
        rightmost++;
        
        if(rightmost <= 9) {
            digits[len] = rightmost;
            return digits;
        }
        else{
            digits[len] = rightmost % 10;
            carry = 1; //carry = true
            auto sz = digits.size() - 2;
            
            //if carry is true, keep iterating backwards
            while(sz >= 0) {
                auto curr = digits[sz]; //current digit
                curr += carry;
                if(curr <= 9) {
                    digits[sz] = curr;
                    carry = 0;
                    break;
                }
                else{
                    cout<<sz<<"\n";
                    digits[sz] = curr % 10;
                }
                //cout<<sz;
                if(sz == 0) {
                    break;
                }
                else
                    sz--;
            }
            //for(auto d : digits) cout<<d<<" ";
            if(carry == 1) {
                cout<<"inside last edgecase\n";
                digits.emplace(begin(digits), 1);
                return digits;
            }
            return digits;
        }
    }
};
