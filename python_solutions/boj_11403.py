import sys
input = sys.stdin.readline

n = int(input().rstrip())
graph = [list(map(int, input().split())) for _ in range(n)]
dist = [[99]*n for _ in range(n)]

for i in range(n):
    for j in range(n):
        dist[i][j] = graph[i][j] if graph[i][j] else 99

for via in range(n):
    for s in range(n):
        for e in range(n):
            if dist[s][via]+dist[via][e] < dist[s][e]:
                dist[s][e] = dist[s][via]+dist[via][e]

for i in range(n):
    for j in range(n):
        if dist[i][j] < 99:
            dist[i][j] = 1
        else:
            dist[i][j] = 0

for i in range(n):
    print(*dist[i])
