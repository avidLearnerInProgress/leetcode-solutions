class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        
        vector<int> bits;
        while(n) {
            bits.push_back(n % 2);
            n /= 2;
        }
        reverse(bits.begin(), bits.end());
        
        vector<int> inverse;
        for(auto &bit : bits) {
            int bitInv = (bit == 1) ? 0 : 1;
            inverse.push_back(bitInv);
        }
        
        unsigned int complement = 0;
        int sz = inverse.size() - 1;
        for(int acc = sz; acc >= 0; --acc) { // x * 2^(n - i) where x == arr[i]
            complement += (inverse[acc] * pow(2, sz - acc));
        }
        
        return complement;
    }
};
