class Solution:
    def smallestStringWithSwaps(self, s: str, pairs: List[List[int]]) -> str:
        def dfs(node, subgraph):
            if node not in seen:
                seen.add(node)
                subgraph.append(node)
                for neighbor in graph[node]:
                    dfs(neighbor, subgraph)
                    
        seen = set()
        graph = defaultdict(list)
        for src, dest in pairs:
            graph[src].append(dest)
            graph[dest].append(src)
        
        res = list(s)
        for node in graph.keys():
            if len(seen) == len(res):
                return ''.join(res)
            
            sub_graph = []
            dfs(node, sub_graph)
            
            if len(sub_graph) != 0:    
                sub_graph = sorted(list(set(sub_graph)))
                sub_char = sorted([s[i] for i in sub_graph])
                
                for x, y in zip(sub_graph, sub_char):
                    res[x] = y
                    
        return ''.join(res)
