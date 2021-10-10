class Solution {
public:
    vector<vector<int>> drs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int rows = 0;
    int cols = 0;

    void dfs(int ix, int jy, pair<int, int> prev, vector<vector<bool>> &visited, vector<vector<int>> &heights)
    {
        if (ix < 0 || ix >= rows || jy < 0 || jy >= cols || visited[ix][jy])
            return;
        if (heights[prev.first][prev.second] >heights[ix][jy])
            return;

        visited[ix][jy] = true;

        for (auto &c : drs)
        {
            dfs(ix+c[0],jy+c[1],{ix, jy}, visited, heights);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        rows = heights.size();
        cols = heights[0].size();

        vector<vector<bool>> pacific_drain_visited(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic_drain_visited(rows, vector<bool>(cols, false));

        int j = 0;
        while (j < cols) {
            dfs(0, j, {0, j}, pacific_drain_visited, heights);
            dfs(rows - 1, j, {rows - 1, j}, atlantic_drain_visited, heights);
            j++;
        }

        int i = 0;
        while (i < rows) {
            dfs(i, 0, {i, 0}, pacific_drain_visited, heights);
            dfs(i, cols - 1, {i, cols - 1}, atlantic_drain_visited, heights);
            i++;
        }

        vector<vector<int>> result;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (pacific_drain_visited[i][j] && atlantic_drain_visited[i][j])
                    result.push_back({i, j});
            }
        }
        return result;
    }
};
