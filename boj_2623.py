from collections import deque
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
graph = [[0]*(n+1) for _ in range(n+1)]
indegree = [0]*(n+1)
queue = deque()
for _ in range(m):
    x, *tmp = map(int, input().split())
    tmp = list(tmp)
    for i in range(len(tmp)-1):
        if not graph[tmp[i]][tmp[i+1]]:
            graph[tmp[i]][tmp[i+1]] = 1
            indegree[tmp[i+1]] += 1

for i in range(1, n+1):
    if indegree[i] == 0:
        queue.append(i)
order = []
while queue:
    cur = queue.popleft()
    order.append(cur)
    for i in range(1, n+1):
        if graph[cur][i]:
            indegree[i] -= 1
            if indegree[i] == 0:
                queue.append(i)

if len(order) == n:
    print(*order, sep='\n')
else:
    print(0)
