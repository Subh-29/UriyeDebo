from collections import deque

def bfs(adj, s):
    q = deque()
    visited = [False] * len(adj)

    visited[s] = True
    q.append(s)

    while q:
        current = q.popleft()
        print(current, end=" ")

        for num in adj[current]:
            if not visited[num]:
                q.append(num)
                visited[num] = True


def addEdge(adj, u, v):
    adj[u].append(v)
    adj[v].append(u)


if __name__ == "__main__":
    V = 5
    adj = [[]for _ in range(V)]

    addEdge(adj, 0, 1)
    addEdge(adj, 0, 2)
    addEdge(adj, 1, 3)
    addEdge(adj, 1, 4)
    addEdge(adj, 2, 4)

    print("BFS starting from 0: ")
    bfs(adj, 0)