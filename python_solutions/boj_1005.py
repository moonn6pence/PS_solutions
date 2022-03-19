from collections import deque
import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n, k = map(int, input().split())
    order = []
    queue = deque()
    indegree = [0]*(n+1)
    time = [0]+list(map(int, input().split()))
    graph = [[] for _ in range(n+1)]
    parent = [[] for _ in range(n+1)]
    dp = [0]*(n+1)
    for i in range(k):
        x, y = map(int, input().split())
        graph[x].append(y)
        parent[y].append(x)
        indegree[y] += 1

    for i in range(1, n+1):
        if indegree[i] == 0:
            queue.append(i)

    while queue:
        cur = queue.popleft()
        order.append(cur)
        for i in graph[cur]:
            indegree[i] -= 1
            if indegree[i] == 0:
                queue.append(i)

    w = int(input())
    i = 0
    while True:
        cur = order[i]
        if not parent[cur]:
            dp[cur] = time[cur]
        else:
            dp[cur] = max([dp[i] for i in parent[cur]])+time[cur]
        if cur == w:
            break
        i += 1
    print(dp[w])
