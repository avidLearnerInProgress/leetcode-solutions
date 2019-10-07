class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> mp;
        vector<int> solution(2, 0);
        
        //store difference as first element of map and index as second element of map
        for(int i=0; i<numbers.size(); i++){
            int difference = target - numbers[i];
            auto it = mp.find(difference);
            
            //elements not in map
            if(it != mp.end()){
                if(mp[difference] < i){
                solution[0] = mp[difference] + 1;
                solution[1] = i + 1;
                return solution;
                }
            }
            else
                mp[numbers[i]] = i;

        }
        return vector<int>(2, 0);
    }
};