from heapq import heappop, heappush
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
graph = [[] for _ in range(n+1)]
indegree = [0]*(n+1)
queue = []

for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    indegree[b] += 1

for i in range(1, n+1):
    if indegree[i] == 0:
        queue.append(i)

while queue:
    cur = heappop(queue)
    print(cur, end=' ')
    for i in graph[cur]:
        indegree[i] -= 1
        if indegree[i] == 0:
            heappush(queue, i)
