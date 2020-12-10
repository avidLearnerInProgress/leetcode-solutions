class Solution {
private:
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    bool isValidCell(int row, int col, int m, int n, vector<vector<int>> &image, int oldColor) {
        if(row >= 0 and row < m and col >= 0 and col < n and image[row][col] == oldColor) return true;
        else return false;
    }
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
            
        if(image.size() == 0) return vector<vector<int>>();
        int m = image.size();
        int n = image[0].size();
        
        int oldColor = image[sr][sc];
        if(oldColor == newColor) return image;
        
        queue<pair<int, int>> Q;
        Q.push({sr, sc});
        
        
        while(!Q.empty()) {
            auto &[r, c] = Q.front();
            Q.pop();
            image[r][c] = newColor;
            
            for(int i=0; i<4; i++) {
                int x = r + directions[i].first, y = c + directions[i].second;   
                if(isValidCell(x, y, m, n, image, oldColor)) {
                    Q.push({x, y});
                }
            }   
        }
        return image;
    }
};
