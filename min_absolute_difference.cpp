class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        int min_absolute_difference = INT_MAX;
        for(int i=0; i<arr.size() - 1; i++){
            min_absolute_difference = min(abs(arr[i+1] - arr[i]), min_absolute_difference);      
        }
        
        vector<vector<int>> varr;
        int curr_min = 0;
        for(int i=0; i<arr.size() - 1; i++){
            curr_min = abs(arr[i+1] - arr[i]);
            if(curr_min == min_absolute_difference)
                varr.push_back({arr[i], arr[i+1]});
        }  
        return varr;
    }
};