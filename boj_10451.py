import sys
sys.setrecursionlimit(2000)


def dfs(start):
    visited[start] = True
    if not visited[prmt[start]-1]:
        dfs(prmt[start]-1)


T = int(sys.stdin.readline())

for _ in range(T):
    n = int(sys.stdin.readline())
    visited = [False for _ in range(n)]
    cycle = 0
    prmt = list(map(int, sys.stdin.readline().split()))
    for node in range(n):
        if not visited[node]:
            dfs(node)
            cycle += 1
    print(cycle)
