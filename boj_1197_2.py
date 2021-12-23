# Prim Algorithm
from heapq import heappop, heappush
import sys
input = sys.stdin.readline

V, E = map(int, input().split())
graph = [[] for _ in range(V+1)]
visited = [False]*(V+1)
edge = []
MSTCost = 0
for _ in range(E):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))
    graph[b].append((a, c))

visited[1] = True
for node, cost in graph[1]:
    heappush(edge, (cost, node))

while edge:
    curCost, cur = heappop(edge)
    if visited[cur]:
        continue
    visited[cur] = True
    MSTCost += curCost
    for next, nextCost in graph[cur]:
        heappush(edge, (nextCost, next))

print(MSTCost)
