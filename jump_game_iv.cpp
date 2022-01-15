class Solution {
public:
int minJumps(vector<int>& arr) 
{
    unordered_map<int,vector<int>> adj;
    int n=arr.size();
    for(int i=0;i<n;++i)
    	if(adj.find(arr[i])==adj.end())
    		adj[arr[i]]={i};
    	else adj[arr[i]].push_back(i);
    vector<int> grey(n,0);
    grey[0]=1;
    queue<pair<int,int>> q;
    q.push({0,0});
    int ret=INT_MAX;
    while(!q.empty())
    {
    	pair<int,int> temp=q.front();
        q.pop();
    	int u=temp.first;
    	int d=temp.second;
    	if(u==n-1)
    		return d;
    	else
    	{
    		if(u>0&&!grey[u-1])
    		{
    			q.push({u-1,d+1});
    			grey[u-1]=1;
    		}
    		if(u+1<n&&!grey[u+1])
    		{
    			q.push({u+1,d+1});
    			grey[u+1]=1;
    		}
    		for(int v:adj[arr[u]])
    			if(!grey[v])
    			{
    				q.push({v,d+1});
    				grey[v]=1;
    			}
            adj[arr[u]]={};
    	}
    }
    return ret;
}   
};
