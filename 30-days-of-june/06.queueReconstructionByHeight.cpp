class Solution {
   public:
    // [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
    //  
    // Sort first:
    //
    // [7, 0] 0
    // [7, 1] 1
    // [6, 1] 2
    // [5, 0] 3
    // [5, 2] 4
    // [4, 4] 5
    //  
    // Reconstruct the queue step by step:
    //  
    // [7, 0]
    // [7, 0] [7, 1] 
    // [7, 0] [6, 1] [7, 1]
    // [5, 0] [7, 0] [6, 1] [7, 1]
    // [5, 0] [7, 0] 5, 2] [6, 1] [7, 1]
    // [5, 0] [7, 0] 5, 2] [6, 1] [4, 4] [7, 1]
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        auto cmp = [](const vector<int> &a, const vector<int> &b) {
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        };
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> peopleAfter;
        for (int i = 0; i < people.size(); i++) {
            if (people[i][1] == peopleAfter.size()) {
                // Heights of all previous people are greater or equal to
                // current person.
                peopleAfter.push_back(people[i]);
            } else {
                // Insert at correct position
                peopleAfter.insert(peopleAfter.begin() + people[i][1],
                                   people[i]);
            }
        }
        return peopleAfter;
    }
};