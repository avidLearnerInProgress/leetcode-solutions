#include <bits/stdc++.h>
using namespace std;


// board {{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,35,-1,-1,13,-1},{-1,-1,-1,-1,-1,-1},{-1,15,-1,-1,-1,-1}}
class Snake {
    public:
		int vertex, moves;
		Snake(){}
		Snake(int v, int m) : vertex(v), moves(m) {}    
};

auto convertBoardTo1D(vector<vector<int>> &board) {
	int r = board.size(), c = board[0].size(), k = 1;
	vector<int> boardOneD(r * c, 0);

	bool leftToRight = true;

	for(int i=r-1; i>=0; i--) {
		if(leftToRight)
			for(int j=0; j<c; j++) //leftToRight
				boardOneD[k++] = board[i][j];
		else
			for(int j=c-1; j>=0; j--) //rightToLeft
				boardOneD[k++] = board[i][j];
		leftToRight = !leftToRight;
	}
	return boardOneD;
}

int snakesAndLadders(vector<vector<int>>& board) {
    
    if(board.size() == 0) return 0;
	auto boardOneD = convertBoardTo1D(board);
	auto boardSize = boardOneD.size();
	// for(auto ele : boardOneD) cout<<ele<<" ";
	vector<bool> visited(boardSize + 1, false);
	queue<Snake> Q;
	Snake s(1, 0); //start state
	Q.push(s);

	Snake element;
	while(!Q.empty()) {
		// auto &[vertex, moves] = Q.front();
		element = Q.front();
		cout<<element.vertex<<" "<<element.moves<<"\n";
		Q.pop();
		// visited[element.vertex] = true;

		if(element.vertex == boardSize) break;

		for(int j=element.vertex+1; j<=element.vertex+6 and j<=boardSize; ++j) {
			if(!visited[j]) {
				visited[j] = true;
				// int cvertex = j, cmoves = 0;
				Snake cele;
				cele.moves = element.moves + 1;

				if(boardOneD[j] != -1) 
					cele.vertex = boardOneD[j];
				else
					cele.vertex = j; 
				Q.push(cele);
			}
		}
	}
	if(element.vertex != boardSize) return -1;
	else return element.moves;
}



int main() {
    
	vector<vector<int>> board = {{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,35,-1,-1,13,-1},{-1,-1,-1,-1,-1,-1},{-1,15,-1,-1,-1,-1}};
	cout<<snakesAndLadders(board);
}
