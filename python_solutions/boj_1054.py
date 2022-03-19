from heapq import heappop, heappush
import sys
input = sys.stdin.readline
inf = float('inf')

N, E = map(int, input().split())
graph = [[0]+[inf]*N for _ in range(N+1)]
distV1 = [0]+[inf]*N
distV2 = [0]+[inf]*N
for _ in range(E):
    a, b, c = map(int, input().split())
    graph[a][b], graph[b][a] = c, c

v1, v2 = map(int, input().split())

for i in range(1, N+1):
    graph[i][i] = 0

edge = []
heappush(edge, (0, v1))
while edge:
    viaCost, via = heappop(edge)
    for node in range(1, N+1):
        newCost = viaCost+graph[via][node]
        if distV1[node] > newCost:
            distV1[node] = newCost
            heappush(edge, (newCost, node))

heappush(edge, (0, v2))
while edge:
    viaCost, via = heappop(edge)
    for node in range(1, N+1):
        newCost = viaCost+graph[via][node]
        if distV2[node] > newCost:
            distV2[node] = newCost
            heappush(edge, (newCost, node))

ans = min(distV1[1]+distV2[N], distV2[1]+distV1[N]) + distV1[v2]
print(ans if ans < inf else -1)
