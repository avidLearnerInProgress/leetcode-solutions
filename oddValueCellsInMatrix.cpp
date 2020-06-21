class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        
        vector<int> rows(n, false);
        vector<int> cols(m, false);
        
        //toggling the state of each cell in the vectors
        for(auto &index : indices){
            rows[index[0]] = !rows[index[0]];
            cols[index[1]] = !cols[index[1]];
        }
        
        //if the ^ of rows[i] and cols[j] results in 1, just add it to odd count
        int odds = 0;
        for(auto i = 0; i < n; i++)
            for(auto j = 0; j < m; j++)
                if(rows[i] ^ cols[j]) odds++;
        return odds;
    }
};