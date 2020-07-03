class Solution {
public:
   void prison(vector<int>& cells, int n) {
        while(n--) {
            vector<int> prev(8, 0);
            for(int k=1; k<7; k++) {
                if(cells[k-1] == cells[k+1]) {
                     prev[k] = 1;
                } else {
                    prev[k] = 0;
                }
            }
            cells = prev;
        }
    }
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        int n = cells.size();
        if(n == 0) return cells;
        prison(cells, 1);
        prison(cells, (N-1) % 14);
        return cells;
    }
};
