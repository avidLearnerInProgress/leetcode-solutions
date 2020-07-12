class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result= 0;
        for(int i=0; i<32; i++)
            result = (result<<1) + (n>>i &1);
        
        return result;
        
        /*
        bitset<32> bit_set(n);
        for (int i = 0; i < 32 / 2; ++i) {
            bool temp = bit_set[i];
            bit_set[i] = bit_set[bit_set.size() - 1 - i];
            bit_set[bit_set.size() - 1 - i] = temp;
        }
        return (uint32_t) bit_set.to_ulong();
        */
        /*
         bitset<32> bs{n};
         int l{0}, r{31};
         while(l < r) {
            bool tmp = bs[l];
            bs[l++] = bs[r];
            bs[r--] = tmp;
        }
        return bs.to_ulong();
        */
    }
};
