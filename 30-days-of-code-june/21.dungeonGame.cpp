class Solution {
 public:
  int calculateMinimumHP(vector<vector<int>>& dungeon) {
    size_t last_col = dungeon.front().size() - 1;
    size_t num_rows = dungeon.size();
    size_t last_row = num_rows - 1;

    // initialize path costs with maximum.
    // has one more row so no special case needs to be considered below
    vector<int> health_needed(num_rows + 1, INT_MAX);
    // we need to arrive with at least one health at princess
    health_needed[last_row] = 1;

    // iterate up->left from princess through all dungeon cells
    for (int col = last_col; col >= 0; --col) {
      for (int row = last_row; row >= 0; --row) {
        // at the beginning (i.e. last row) health_needed_below=INT_MAX and
        // health_needed_right=1 s.t. health_needed_here=1
        int health_needed_below = health_needed[row + 1];
        int health_needed_right = health_needed[row];
        // health_needed_here is the smaller one of coming from below or right
        int health_needed_here = min(health_needed_below, health_needed_right);
        // need cell-cost more health: e.g. cost=-3 --> +3 more health needed
        health_needed_here += -dungeon[row][col];
        // we need at least 1 health at every cell, lower is not allowed,
        // even if later path adds bonus lives
        health_needed_here = max(1, health_needed_here);
        // memo the health needed for this row
        health_needed[row] = health_needed_here;
      }
    }
    // return the health needed at the first row (i.e. the start)
    return health_needed[0];
  }
};
