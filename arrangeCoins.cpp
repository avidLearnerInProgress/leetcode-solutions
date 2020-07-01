class Solution {
public:
    int arrangeCoins(int n) {
        long start = 0, end = n;
        long k, curr;
        while(start <= end) {
            k = start + (end - start) / 2;
            curr = k * (k + 1) / 2;
            if(curr == n) return (int) k;
            if(n < curr) end = k - 1;
            else start = k + 1;
        }
        return (int)end;
    }
};
