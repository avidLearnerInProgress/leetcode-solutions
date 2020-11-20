// { Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

int minStepToReachTarget(int *, int *, int);

// Driver code to test above methods
int main() {
    // size of square board
    int t;
    cin >> t;
    while (t--) {
        int N;
        int a, b, c, d;
        cin >> N;
        cin >> a >> b;
        cin >> c >> d;
        int knightPos[] = {a, b};
        int targetPos[] = {c, d};
        cout << minStepToReachTarget(knightPos, targetPos, N) << endl;
    }
    return 0;
}
// } Driver Code Ends


// User function template for C++

// KnightPos : knight position coordinates
// targetPos : target position coordinated
// N : square matrix size

class Cell {
  public:
    int x, y, distance;
    Cell(int a, int b, int dist) : x(a), y(b), distance(dist) {}
};

bool isValid(int &x, int &y, int N) {
    return x>=1 and y>=1 and x<=N and y<=N;
}


int minStepToReachTarget(int knightPos[], int targetPos[], int N) {
    // code here
    
    vector<int> dx = {-2, -2, 2, 2, -1, -1, 1, 1};
    vector<int> dy = {1, -1, 1, -1, 2, -2, 2, -2};
    
    vector<vector<int>> visited(N+1, vector<int>(N+1, 0));
    
    queue<Cell> Q;
    Q.push(Cell(knightPos[0], knightPos[1], 0));
    
    while(!Q.empty()) {
        
        auto current = Q.front();
        Q.pop();
        
        
        if(current.x == targetPos[0] and current.y == targetPos[1]) return current.distance;
        
        for(int i=0; i<8; i++) {
            auto x = current.x + dx[i];
            auto y = current.y + dy[i];
            
            if(isValid(x, y, N) and !visited[x][y]) {
                visited[x][y] = true;
                Q.push(Cell(x, y, current.distance + 1));
            }
        }
        
    }
    return -1;
}
