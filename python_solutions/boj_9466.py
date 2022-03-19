import sys
sys.setrecursionlimit(100001)


def dfs(start, depth):
    if visited[start]:
        return start, depth
    visited[start] = depth
    cycleStart, cycleDepth = dfs(choice[start]-1, depth+1)
    if cycleStart == start:
        teamCnt[0] += cycleDepth - visited[cycleStart]
    return cycleStart, cycleDepth


T = int(input())
for _ in range(T):
    n = int(input())
    choice = list(map(int, sys.stdin.readline().split()))
    teamCnt = [0]
    visited = [0]*n
    for node in range(n):
        if not visited[node]:
            dfs(node, 1)
    print(n-teamCnt[0])
