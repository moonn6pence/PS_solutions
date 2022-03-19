import sys
nodes, edges, start = map(int, sys.stdin.readline().split())

graph = [[0 for i in range(nodes)] for j in range(nodes)]

for _ in range(edges):
    a, b = map(int, sys.stdin.readline().split())
    graph[a-1][b-1], graph[b-1][a-1] = 1, 1

visitedBfs, visitedDfs = [False for _ in range(nodes)], [
    False for _ in range(nodes)]
bfsQueue = []


def dfs(start):
    print(start+1, end=' ')
    visitedDfs[start] = True
    for node in range(nodes):
        if graph[node][start] and not visitedDfs[node]:
            dfs(node)


def bfs(start):
    bfsQueue.append(start)
    visitedBfs[start] = True
    while bfsQueue:
        curNode = bfsQueue.pop(0)
        print(curNode+1, end=' ')
        for node in range(nodes):
            if graph[node][curNode] and not visitedBfs[node]:
                bfsQueue.append(node)
                visitedBfs[node] = True


dfs(start-1)
print('')
bfs(start-1)
