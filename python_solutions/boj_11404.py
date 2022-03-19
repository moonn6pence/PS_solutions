import sys
input = sys.stdin.readline
inf = float('inf')
n = int(input())
m = int(input())
graph = [[inf]*n for _ in range(n)]
dist = [[0]*n for _ in range(n)]

for _ in range(m):
    a, b, c = map(int, input().split())
    graph[a-1][b-1] = min(c, graph[a-1][b-1])

for i in range(n):
    for j in range(n):
        if i == j:
            dist[i][j] = 0
        else:
            dist[i][j] = graph[i][j]

for via in range(n):
    for start in range(n):
        for end in range(n):
            if dist[start][end] > dist[start][via]+dist[via][end]:
                dist[start][end] = dist[start][via]+dist[via][end]

for i in range(n):
    for j in range(n):
        print(dist[i][j] if dist[i][j] != inf else 0, end=' ')
    print()
