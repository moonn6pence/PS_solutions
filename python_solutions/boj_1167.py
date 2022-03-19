from collections import deque
import sys
n = int(input())
graph = [[] for j in range(n)]
stack = deque()
for _ in range(n):
    edge = list(map(int, sys.stdin.readline().split()))
    start = edge[0]-1
    for i in range(1, len(edge)-1, 2):
        graph[start].append((edge[i]-1, edge[i+1]))
        graph[edge[i]-1].append((start, edge[i+1]))


def dfs(start):
    visited = [False for i in range(n)]
    distMax, nodeMax = 0, 0
    stack.append((start, 0))
    visited[start] = True
    while stack:
        node, curDist = stack.pop()
        if distMax < curDist:
            distMax = curDist
            nodeMax = node
        for curNode, curCost in graph[node]:
            if not visited[curNode]:
                visited[node] = True
                stack.append((curNode, curDist+curCost))
    return distMax, nodeMax


xToy, nodeY = dfs(0)
yToz, nodeZ = dfs(nodeY)
print(yToz)
