class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        
        
        sort(arr.begin(), arr.end(), [](const int& A, const int &B){
            
            int countA = __builtin_popcount(A), countB = __builtin_popcount(B);
            return countA == countB ? A < B : countA < countB;
        });
        
        return arr;
    }
};