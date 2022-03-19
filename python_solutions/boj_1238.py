from heapq import heappop, heappush
import sys
input = sys.stdin.readline
inf = float('inf')
n, m, x = map(int, input().split())
graph = [[] for _ in range(n+1)]
edge = []

for _ in range(m):
    a, b, c = map(int, input().split())
    graph[a].append((c, b))

ans = 0
for start in range(1, n+1):
    if start == x:
        continue
    dist = [0]+[inf]*n
    dist[start] = 0
    heappush(edge, (dist[start], start))
    while edge:
        viaCost, via = heappop(edge)
        for nextCost, next in graph[via]:
            newCost = viaCost+nextCost
            if dist[next] > newCost:
                dist[next] = newCost
                heappush(edge, (newCost, next))
    go = dist[x]
    dist = [0]+[inf]*n
    dist[x] = 0
    heappush(edge, (dist[x], x))
    while edge:
        viaCost, via = heappop(edge)
        for nextCost, next in graph[via]:
            newCost = viaCost+nextCost
            if dist[next] > newCost:
                dist[next] = newCost
                heappush(edge, (newCost, next))
    back = dist[start]
    ans = max(ans, go+back)
print(ans)
