class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
//         vector<vector<pair<int, int>>> graph(n);
        
//         //using minHeap we keep track of the cheapest price from city x to city y with at most k stops
//         priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > minHeap;
        
//         //create adjacency list
//         for(vector<int>& flight : flights) {
//             int s = flight[0], d = flight[1], dist = flight[2];
//             graph[s].push_back({d, dist});
//         }
        
//         vector<int> dist(n+1, INT_MAX);
//         int e = k + 1; //k = hops; edges = number of hops + 1
//         minHeap.push({0, src, e}); // {distanceSoFar, currentNode, edgesSeenSoFar}
        
//         while(!minHeap.empty()) {
//             auto current = minHeap.top();
//             minHeap.pop();
            
//             int distance = current[0], currentNode = current[1], edges = current[2];
//             if(edges < 0) {
//                 continue;
//             }
		    
//             if(dist[currentNode] < edges) {
//                 continue;
//             }
		        
//             dist[currentNode] = edges;
//             if(currentNode == dst) { //if we are at the destination node
//                 return distance;
//             }
//             if(edges > 0) { //if not, explore all neighbors of the currentNode in the graph
//                 for(pair<int, int>& neighbor : graph[currentNode]) {
//                     minHeap.push({neighbor.second + distance, neighbor.first, edges - 1});
//                 }
//             }   
//         }
//         return -1;
        
        
        if (flights.empty()) return 0;
        vector<unordered_map<int, int>> flights_matrix(n);
        for (int i = 0; i < flights.size(); ++i) {
            flights_matrix[flights[i][0]][flights[i][1]] = flights[i][2];
        }
        vector<pair<int, int>> queue;
        queue.push_back({src, 0});
        unordered_map<int,int> visited_price;
        visited_price[src] = 0;
        int stops = 0;
        while(queue.size() && stops <= k) {
            vector<pair<int, int>> new_queue;
            for (int i = 0; i < queue.size(); ++i) {
                for (const auto& iter : flights_matrix[queue[i].first]) {
                    const int stop = iter.first;
                    const int price = queue[i].second + iter.second;
                    if (visited_price.count(stop) && visited_price[stop] < price) continue;
                    visited_price[stop] = price;
                    new_queue.push_back({stop, price});
                }
            }
            swap(queue, new_queue);
            ++stops;
        }
        return visited_price.count(dst) == 0 ? -1 : visited_price[dst];
    }
};
