def dfsVisit(adj, s, visited):
    visited[s] = True
    print(s, end=" ")

    for x in adj[s]:
        if not visited[x]:
            dfsVisit(adj, x, visited)

def dfs(adj, s):
    
    visited = [False] * len(adj)
    dfsVisit(adj, s, visited)

def addEdge(adj, u, v):
    adj[u].append(v)
    adj[v].append(u)



if __name__ == "__main__":
    V = 5
    adj = [[] for _ in range(V)]

    edges = [[1, 2], [1, 0], [2, 0], [2, 3], [2, 4]]

    for e in edges:
        addEdge(adj, e[0], e[1])

    source = int(input("Enter the source vertex: "))

    print("DFS traversal: ")
    dfs(adj, source)