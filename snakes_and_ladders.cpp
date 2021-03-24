// #include <bits/stdc++.h>
// using namespace std;


// // board {{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,35,-1,-1,13,-1},{-1,-1,-1,-1,-1,-1},{-1,15,-1,-1,-1,-1}}
// class Snake {
//     public:
// 		int vertex, moves;
// 		Snake(){}
// 		Snake(int v, int m) : vertex(v), moves(m) {}    
// };

// auto convertBoardTo1D(vector<vector<int>> &board) {
// 	int r = board.size(), c = board[0].size(), k = 1;
// 	vector<int> boardOneD(r * c, 0);

// 	bool leftToRight = true;

// 	for(int i=r-1; i>=0; i--) {
// 		if(leftToRight)
// 			for(int j=0; j<c; j++) //leftToRight
// 				boardOneD[k++] = board[i][j];
// 		else
// 			for(int j=c-1; j>=0; j--) //rightToLeft
// 				boardOneD[k++] = board[i][j];
// 		leftToRight = !leftToRight;
// 	}
// 	return boardOneD;
// }

// int snakesAndLadders(vector<vector<int>>& board) {
    
//     if(board.size() == 0) return 0;
// 	auto boardOneD = convertBoardTo1D(board);
// 	auto boardSize = boardOneD.size();
// 	// for(auto ele : boardOneD) cout<<ele<<" ";
// 	vector<bool> visited(boardSize + 1, false);
// 	queue<Snake> Q;
// 	Snake s(1, 0); //start state
// 	Q.push(s);

// 	Snake element;
// 	while(!Q.empty()) {
// 		// auto &[vertex, moves] = Q.front();
// 		element = Q.front();
// 		cout<<element.vertex<<" "<<element.moves<<"\n";
// 		Q.pop();
// 		// visited[element.vertex] = true;

// 		if(element.vertex == boardSize) break;

// 		for(int j=element.vertex+1; j<=element.vertex+6 and j<=boardSize; ++j) {
// 			if(!visited[j]) {
// 				visited[j] = true;
// 				// int cvertex = j, cmoves = 0;
// 				Snake cele;
// 				cele.moves = element.moves + 1;

// 				if(boardOneD[j] != -1) 
// 					cele.vertex = boardOneD[j];
// 				else
// 					cele.vertex = j; 
// 				Q.push(cele);
// 			}
// 		}
// 	}
// 	if(element.vertex != boardSize) return -1;
// 	else return element.moves;
// }



// int main() {
    
// 	vector<vector<int>> board = {{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,35,-1,-1,13,-1},{-1,-1,-1,-1,-1,-1},{-1,15,-1,-1,-1,-1}};
// 	cout<<snakesAndLadders(board);
// }



class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size(), d = n*n, moves = 0;
        queue<int> q;
        q.push(1);
        vector<bool> vis(d+1,0);
        vis[1]=1;
        while(q.size()!=0) 
        {
            int z = q.size();
            for(int k=0; k<z; k++)
            {
                int u = q.front();
                q.pop();
                if(u == d)
                    return moves;
                for(int i=1; i<=6; i++)
                {
                    if(u+i < d+1 && !vis[u+i])
                    {
						//mark it visited here so that if tail lies here don't take that snake in future
                        vis[u+i] = 1;
                        //extract row number and column number from current position
                        int x = (u+i-1) / n ; 
                        int y = (u+i-1) % n;
                        //adjust according to given format i.e. boustrophedonically
                        x = n-x-1;  
                        if(x%2==n%2)
                            y = n-y-1;
                        
                        if(board[x][y]!=-1) 
                            q.push(board[x][y]);
                        else
                            q.push(u+i);
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};
