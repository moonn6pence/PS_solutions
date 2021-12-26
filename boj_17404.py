import sys
input = sys.stdin.readline
inf = float('inf')

n = int(input())
cost = [list(map(int, input().split())) for _ in range(n)]
dp = [[[0]*3 for _ in range(n)] for __ in range(3)]

for i in range(3):
    dp[i][0] = [inf, inf, inf]
    dp[i][0][i] = cost[0][i]

for i in range(1, n):
    for j in range(3):
        dp[j][i][0] = min(dp[j][i-1][1], dp[j][i-1][2])+cost[i][0]
        dp[j][i][1] = min(dp[j][i-1][0], dp[j][i-1][2])+cost[i][1]
        dp[j][i][2] = min(dp[j][i-1][0], dp[j][i-1][1])+cost[i][2]

ans = inf

for i in range(3):
    for j in range(1, 3):
        ans = min(ans, dp[i][n-1][(i+j) % 3])
print(ans)
