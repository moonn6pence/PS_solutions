from collections import deque
import sys
n = int(input())
graph = [[] for j in range(n)]
stack = deque()
for _ in range(n-1):
    start, target, cost = map(int, sys.stdin.readline().split())
    graph[start-1].append((target-1, cost))
    graph[target-1].append((start-1, cost))


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
