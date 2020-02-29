
class Graph:
    def __init__(self, v): 
        self.V = v
        self.graph = [[] for _ in range(self.V)]
        self.visited = [False] * (self.V)

    def addEdge(self, u, v):
        self.graph[u].append(v)

    def helper(self, i, visited, stack):
        '''
        Ensure that all the adjacent nodes are explored and pushed in stack first before the parent node..
        '''

        self.visited[i] = True
        for adjacent in self.graph[i]:
            if not self.visited[adjacent]:
                self.helper(adjacent, self.visited, stack)
        stack.append(i)

    def topologicalSort(self):
        stack = []        
        for i in range(self.V):
            if not self.visited[i]:
                self.helper(i, self.visited, stack)
        print(stack[::-1])

if __name__ == '__main__':
    g = Graph(6)
    g.addEdge(5, 2)
    g.addEdge(5, 0) 
    g.addEdge(4, 0) 
    g.addEdge(4, 1) 
    g.addEdge(2, 3) 
    g.addEdge(3, 1)
    g.topologicalSort()



