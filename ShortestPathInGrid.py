#Find the shortest path taken from source to destination in 2d grid.
#Find the shortest path length too
def bfs(grid, start):
    q = [[start]]
    rowlen=len(grid)
    collen=len(grid[0])
    seen=set(start)
    while(len(q)>0):
        path = q.pop(0)
        x, y = path[-1]
        if grid[x][y]==goal:
            return path
        for xp, yp in [[x-1, y], [x+1, y], [x, y-1], [x, y+1]]:
            if rowlen>xp>=0 and collen>yp>=0 and grid[xp][yp]!=wall and (xp, yp) not in seen:
                q.append(path+[(xp, yp)])
                seen.add((xp, yp))


wall, goal = "#", "G"
grid = ["....",
        ".##.",
        "..G."]
path = bfs(grid, (0, 3))
print("path taken is ", path)
print("shortest path length from src to destination is ", len(path))

