class Graph:
    def __init__(self, V):
        from collections import defaultdict
        self.v = V
        self.graph = defaultdict(list)

    def addEdge(self, u, w):
        self.graph[u].append(w)

    def topologicalSort(self):

        indegree = [0] * self.v

        for node in self.graph:
            for j in self.graph[node]:
                indegree[j] += 1

        from collections import deque
        queue = deque()

        for v in range(self.v):
            if indegree[v] == 0:
                queue.append(v)

        result, counter = [], 0
        while queue:
            curr = queue.popleft()
            result.append(curr)
            counter += 1
            for node in self.graph[curr]:
                indegree[node] -= 1
                if indegree[node] == 0:
                    queue.append(node)

        if counter != self.v:
            print("Cycle in graph..")
        else:
            for r in result: print(r)

g = Graph(6)
g.addEdge(5, 2)
g.addEdge(5, 0)
g.addEdge(4, 0)
g.addEdge(4, 1)
g.addEdge(2, 3)
g.addEdge(3, 1)
g.topologicalSort()