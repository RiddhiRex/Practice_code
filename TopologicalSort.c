#topological sort
from collections import defaultdict
class Graph:
    def __init__(self, total_vertices):
        self.g=defaultdict(list)
        self.v=total_vertices
        
    def addEdge(self, u, v):
        self.g[u].append(v)
        
    def topoSortHelper(self, curnode, visited, stack):

        visited[curnode]=True
        for each in self.g[curnode]:
            if visited[each]==False:
                self.topoSortHelper(each, visited, stack)
        stack.insert(0, curnode)
        
            
    def topologicalSort(self):
        stack=[]
        visited=[False]*self.v
        for i in range(self.v):
            if visited[i]==False:
                self.topoSortHelper(i, visited, stack)
        print(stack)

gr = Graph(6)
gr.addEdge(5, 2)
gr.addEdge(5, 0) 
gr.addEdge(4, 0) 
gr.addEdge(4, 1) 
gr.addEdge(2, 3) 
gr.addEdge(3, 1)

gr.topologicalSort()
