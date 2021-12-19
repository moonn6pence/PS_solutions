from heapq import heappop, heappush
import sys

input = sys.stdin.readline
inf = float('inf')

n = int(input())
m = int(input())

graph = [[0]+[inf]*n for _ in range(n+1)]
dist = [inf]*(n+1)

for i in range(1, n+1):
    graph[i][i] = 0

for _ in range(m):
    a, b, c = map(int, input().split())
    graph[a][b] = min(graph[a][b], c)
start, end = map(int, input().split())

dist[start] = 0
route = [[] for _ in range(n+1)]

edge = []
heappush(edge, (dist[start], start))
while edge:
    viaCost, via = heappop(edge)
    for next in range(1, n+1):
        newCost = viaCost+graph[via][next]
        if dist[next] > newCost:
            dist[next] = newCost
            route[next] = via
            heappush(edge, (newCost, next))


ansRoute = []
node = end
while node:
    ansRoute.append(node)
    node = route[node]

print(dist[end])
print(len(ansRoute))
print(*ansRoute[::-1])
