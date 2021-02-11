// BFS approach - n^2
class Solution {
public:
	int minCut(string s) {
		queue<int> node;
		node.push(0);
		int cuts = 0;
		//bfs
		vector<bool> visited(s.size(), false);
		while (true){
			queue<int> tmp;
			while (!node.empty()){
				int cur = node.front();
				node.pop();
				for (int i = s.size() - 1; i >= cur; i--){
					if (visited[i]==false&&ispal(s, cur, i)){
						if (i == s.size() - 1)
							return cuts;
						tmp.push(i+1);
					}
				}
				visited[cur] = true;
			}
			cuts++;
			node = tmp;
		}
	}

	bool ispal(string& s, int pre, int post){
		while (pre < post){
			if (s[pre++] != s[post--])
				return false;
		}
		return true;
	}
};
