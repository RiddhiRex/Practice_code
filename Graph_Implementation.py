from collections import defaultdict

class Graph:
	
	def __init__(self):
		self.graph = defaultdict(list)
	
	def __init__(self, vertices):
		self.V = vertices
		self.graph = [[0 for column in range(vertices)] 
				  for row in range(vertices)]
		
	def addEdge(self,u,v):
		self.graph[u].append(v)
		#self.graph[v].append(u) -- for bidirectional graphs
	
	def dfs(self,start,vis=[]):
		
		print start,
		vis.append(start)
		
		for e in self.graph[start]:
			if e not in vis:
				self.dfs(e,vis)
	
	def bfs(self,start,vis=[]):
	
		vis = []; vis.append(start)
		queue = []; queue.append(start)		
		
		while queue:
			start = queue.pop(0)		
			print start,
			for e in self.graph[start]:
				if e not in vis:
					queue.append(e)
					vis.append(e)
	
	def findMin(self,dist,sp):
		
		min_value = float('inf'); min_index = -1
		for i in xrange(self.V):
			if dist[i] < min_value and sp[i] == False:
				min_value = dist[i]
				min_index = i
		return min_index
	
	def dijkstra(self,src):
		
		dist = [float('inf')]*self.V
		sp = [False]*self.V
		
		dist[src] = 0;
		
		for i in range(self.V):
			
			u = self.findMin(dist,sp)
			print u
			sp[u] = True
			
			for v in range(self.V):
				if sp[v] == False and dist[v] > dist[u] + self.graph[u][v] and self.graph[u][v] > 0: #same for Prim's but instead of dist[v] > dist[u] + self.graph[u][v] its just dist[v] > self.graph[u][v]
					dist[v] = dist[u] + self.graph[u][v]
		
		print dist
		
	

if __name__ == "__main__":
	
	'''
	g = Graph()
	g.addEdge(0, 1)
	g.addEdge(0, 2)
	g.addEdge(1, 2)
	g.addEdge(2, 0)
	g.addEdge(2, 3)
	g.addEdge(3, 3)
	g.dfs(2)
	g.bfs(3)
	'''
	g  = Graph(9)
	g.graph = [[0, 4, 0, 0, 0, 0, 0, 8, 0],
		      [4, 0, 8, 0, 0, 0, 0, 11, 0],
		      [0, 8, 0, 7, 0, 4, 0, 0, 2],
		      [0, 0, 7, 0, 9, 14, 0, 0, 0],
		      [0, 0, 0, 9, 0, 10, 0, 0, 0],
		      [0, 0, 4, 14, 10, 0, 2, 0, 0],
		      [0, 0, 0, 0, 0, 2, 0, 1, 6],
		      [8, 11, 0, 0, 0, 0, 1, 0, 7],
		      [0, 0, 2, 0, 0, 0, 6, 7, 0]
		     ];

	g.dijkstra(0)
