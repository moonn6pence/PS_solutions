import sys
input = sys.stdin.readline
inf = sys.maxsize

n = int(input())
graph = [list(map(int, input().split())) for _ in range(n)]
dp = [[inf]*(1 << n) for _ in range(n)]


def solve(cur, visited):
    if visited == (1 << n) - 1:
        return graph[cur][0] or inf

    if dp[cur][visited] != inf:
        return dp[cur][visited]

    tmp = inf
    for next in range(n):
        if not visited & (1 << next) and graph[cur][next]:
            tmp = min(tmp, solve(next, visited | 1 << next)+graph[cur][next])
    dp[cur][visited] = tmp
    return tmp


print(solve(0, 1))
