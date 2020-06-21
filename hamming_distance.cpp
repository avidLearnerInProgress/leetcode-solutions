class Solution {
public:
    int hammingDistance(int x, int y) {
        int op1, op2;
        long long int distance = 0;
        while(x > 0 || y > 0){
            op1 = x % 2;
            op2 = y % 2;
            distance += (op1 ^ op2);
            x /= 2;
            y /= 2;
        }
        cout<<distance<<"\n";
        cout<<x<<y;
        return distance;
    }
};