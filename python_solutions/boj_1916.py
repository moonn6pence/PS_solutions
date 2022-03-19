from heapq import heappop, heappush
import sys
input = sys.stdin.readline
inf = float('inf')

n = int(input())
m = int(input())
graph = [[inf]*n for _ in range(n)]
edge = []
dist = [inf]*n
for _ in range(m):
    start, end, cost = map(int, input().split())
    graph[start-1][end-1] = min(graph[start-1][end-1], cost)

for i in range(n):
    graph[i][i] = 0

start, end = map(int, input().split())
start -= 1
end -= 1
dist[start] = 0
heappush(edge, (dist[start], start))
while edge:
    minCost, minNode = heappop(edge)
    for node in range(n):
        if dist[node] > graph[minNode][node]+minCost:
            dist[node] = graph[minNode][node]+minCost
            heappush(edge, (dist[node], node))

print(dist[end])
