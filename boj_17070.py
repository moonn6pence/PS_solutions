n = int(input())
state = [list(map(int, input().split())) for _ in range(n)]
dp = [[[0, 0, 0] for j in range(n)] for i in range(n)]
dp[0][1][0] = 1
for i in range(n):
    for j in range(n):
        if j+1 < n and state[i][j+1] == 0:
            dp[i][j+1][0] += dp[i][j][0]+dp[i][j][2]
            if i+1 < n and state[i+1][j] == 0 and state[i+1][j+1] == 0:
                dp[i+1][j+1][2] += dp[i][j][0]+dp[i][j][1]+dp[i][j][2]
        if i+1 < n and state[i+1][j] == 0:
            dp[i+1][j][1] += dp[i][j][1]+dp[i][j][2]
print(sum(dp[n-1][n-1]))
