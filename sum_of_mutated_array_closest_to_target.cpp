class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        
        /*
            The only catch in the problem is we cannot change elements that are previously visited. Only current and all elements from current to end can be mutated.
        */
        
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        int trailingSum = 0, sumNeeded;
        for(int i=0; i<n; i++) {
            sumNeeded = int(round((target - trailingSum - 0.00001) / (n - i)));
            if(sumNeeded <= arr[i]) {
                return sumNeeded;
            }
            trailingSum += arr[i];
        }
        return arr[arr.size() - 1];
        
    }
};
