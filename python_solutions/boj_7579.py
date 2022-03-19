import sys
input = sys.stdin.readline
inf = float('inf')

n, m = map(int, input().split())
mem = list(map(int, input().split()))
cost = list(map(int, input().split()))
totalCost = sum(cost)+1
dp = [[0]*totalCost for _ in range(n)]

dp[0][cost[0]] = mem[0]
for i in range(1, n):
    for j in range(totalCost):
        dp[i][j] = dp[i-1][j]
        if j >= cost[i]:
            dp[i][j] = max(dp[i][j], dp[i-1][j-cost[i]]+mem[i])

for i in range(totalCost):
    if dp[n-1][i] >= m:
        print(i)
        break
