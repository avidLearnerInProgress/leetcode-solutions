// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Node {
    public: 
    int x, y, distance;
    Node(int x, int y, int dist) : x(x), y(y), distance(dist) {}
};

class Solution 
{   
    bool isInsideBoard(int x, int y, int N) {
        return (x >= 1 and x <= N and y >= 1 and y <= N);
    }
    
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    
	    queue<Node> q;
	    
	    // generate first 4 pairs ....
	    // and then invert for next 4 pairs
	    int dx[8] = {-2, -2,  2,  2,  -1,  1, -1,  1};
	    int dy[8] = {-1,  1, -1,  1,  -2, -2,  2,  2};
        
		vector<vector<bool> > visited(N + 1, vector<bool>(N + 1, false));
        
	    q.push(Node(KnightPos[0], KnightPos[1], 0));
	    
	    visited[KnightPos[0]][KnightPos[1]] = true;
	    
	    while(!q.empty()) {
	        
	        // grab front and pop
	        Node current = q.front();
	        q.pop();
	        
	        // exit condition
	        if(current.x == TargetPos[0] and current.y == TargetPos[1]) return current.distance;
	        
	        // push neighbors
	        for(int i = 0; i < 8; i++) {
	            int nx = current.x + dx[i];
	            int ny = current.y + dy[i];
	            
	            if(isInsideBoard(nx, ny, N) and !visited[nx][ny]) {
	                visited[nx][ny] = true;
	                q.push(Node(nx, ny, current.distance + 1));
	            }
	        }
	    }
	    return -1; // knight unreachable to its target
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
