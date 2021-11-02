import sys

n = int(sys.stdin.readline())
graph = [[] for j in range(n)]
parentOf = [0 for j in range(n)]
stack = []

for _ in range(n-1):
    n1, n2 = map(int, sys.stdin.readline().split())
    graph[n1-1].append(n2-1)
    graph[n2-1].append(n1-1)


def dfs(start):
    stack.append(start)

    while stack:
        node = stack.pop()
        for i in graph[node]:
            parentOf[i] = node+1
            stack.append(i)
            graph[i].remove(node)


dfs(0)
print(*parentOf[1:], sep='\n')
