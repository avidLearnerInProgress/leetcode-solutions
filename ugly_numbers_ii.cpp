class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly(n);
        ugly[0] = 1; //ugly of first number is 1
        
        int i2 = 0, i3 = 0, i5 = 0;
        int nm2 = 2, nm3 = 3, nm5 = 5;
        int next_ugly_number = 1;
        
        for(int i=1; i<n; i++) {
            next_ugly_number = min(nm2, min(nm3, nm5));
            ugly[i] = min(nm2 * ugly[i2], min(nm3 * ugly[i3], nm5 * ugly[i5]));
            if(ugly[i] == 2 * ugly[i2]) i2++;
            if(ugly[i] == 3 * ugly[i3]) i3++;
            if(ugly[i] == 5 * ugly[i5]) i5++;
        }
        return ugly[n-1];
    }
};
