class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        if(arr.size() == 0) return true;
        
        unordered_map<int, int> ump; //element to count
        sort(arr.begin(), arr.end());
        
        for(auto element : arr) {
            ump[element]++;
        }
        
        for(auto element: arr) {
            if (ump[element] == 0) {
                continue;
            }
            if (element < 0 && element % 2 != 0) { //for -ve values, there is no element/2 pair to match
                return false;
            }
            int pair = element > 0 ? element*2 : element/2; //positive or negative
            if (ump[pair] == 0) { //no match with element
                return false;
            }
            ump[element]--;
            ump[pair]--;
        }
        return true;
    }
};
