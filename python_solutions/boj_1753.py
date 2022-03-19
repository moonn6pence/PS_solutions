import heapq
import sys
input = sys.stdin.readline

v, e = map(int, input().split())
graph = [[] for _ in range(v)]
start = int(input())-1
dist = [99999999999]*v
dist[start] = 0
for _ in range(e):
    f, t, w = map(int, input().split())
    f -= 1
    t -= 1
    graph[f].append([t, w])

edge = []
heapq.heappush(edge, (dist[start], start))
while edge:
    minVia = heapq.heappop(edge)
    curCost, cur = minVia
    for next, nextCost in graph[cur]:
        newCost = curCost+nextCost
        if dist[next] > newCost:
            dist[next] = newCost
            heapq.heappush(edge, (newCost, next))

for i in range(v):
    print(dist[i] if dist[i] < 99999999999 else 'INF')
