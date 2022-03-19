import sys
sys.setrecursionlimit(20000)


def dfs(start, depth):
    mark = (-1)**depth
    visited[start] = mark
    for node in graph[start]:
        if visited[node] == mark:
            isBipartite[0] = False
            return
        if visited[node] == 0:
            dfs(node, (depth+1) % 2)


k = int(sys.stdin.readline())
for _ in range(k):
    V, E = map(int, sys.stdin.readline().split())
    graph = [[] for i in range(V)]
    visited = [0 for i in range(V)]
    isBipartite = [True]
    for __ in range(E):
        u, v = map(int, sys.stdin.readline().split())
        graph[u-1].append(v-1)
        graph[v-1].append(u-1)
    for node in range(V):
        if not isBipartite[0]:
            break
        if visited[node] == 0:
            dfs(node, 0)
    print('YES' if isBipartite[0] else 'NO')
