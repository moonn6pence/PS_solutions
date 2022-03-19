import sys

n, m = map(int, sys.stdin.readline().split())
graph = [[0 for i in range(n)] for j in range(n)]
visited = [False for _ in range(n)]
order = []

for _ in range(m):
    u, v = map(int, sys.stdin.readline().split())
    graph[u-1][v-1], graph[v-1][u-1] = 1, 1


def bfs(start):
    order.append(start)
    visited[start] = True
    while order:
        curNode = order.pop(0)
        for node in range(n):
            if graph[node][curNode] and not visited[node]:
                order.append(node)
                visited[node] = True


def countComponents():
    cnt = 0
    while False in visited:
        for node in range(n):
            if not visited[node]:
                bfs(node)
                cnt += 1
    print(cnt)


countComponents()
