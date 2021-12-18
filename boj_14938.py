from collections import deque
import sys
input = sys.stdin.readline
inf = float('inf')

n, m, r = map(int, input().split())
item = [0]+list(map(int, input().split()))
graph = [[0]*(n+1) for _ in range(n+1)]
dist = [[0]+[inf]*n for _ in range(n+1)]
for _ in range(r):
    a, b, l = map(int, input().split())
    graph[a][b], graph[b][a] = l, l
    dist[a][b], dist[b][a] = l, l
for i in range(n):
    dist[i][i] = 0

for via in range(1, n+1):
    for start in range(1, n+1):
        for end in range(1, n+1):
            if dist[start][end] > dist[start][via]+dist[via][end]:
                dist[start][end] = dist[start][via]+dist[via][end]

ans = 0
for i in range(1, n+1):
    tmp = 0
    for j in range(1, n+1):
        if dist[i][j] <= m:
            tmp += item[j]
    ans = max(ans, tmp)

print(ans)
