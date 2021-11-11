class Solution {
public:
	int minimumOperations(vector<int>& nums, int start, int goal) {
		int ans = 0;

		vector<bool> visited(1001, false); //visited array
		queue<int>q;//queue for BFS

		q.push(start); //add start in queue as base for BFS

		while (!q.empty())
		{
			int size = q.size();
			while (size--)
			{
				int x = q.front();
				q.pop();

				if (x == goal) //x == goal return ans
				{
					return ans;
				}
				else if (x > 1000 || x < 0 || visited[x]) //x out of bound [0,1000] or x is previously visited //no need to again proceed it
				{
					continue;
				}
				
				//so now x is un visited
				for (auto i : nums) //do all three operation(+,-,^) on x and add that value in queue
				{
					q.push(x + i);
					q.push(x - i);
					q.push(x ^ i);
				}
				visited[x] = true; //mark x as visited
			}
			ans++; //operation count increase by 1
		}
		return -1; //not fount goal in above BFS so return -1
	}
};
