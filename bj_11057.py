n = int(input())
dp = [[1]*10 for _ in range(n)]

for i in range(1, n):
    for j in range(10):
        if j == 0:
            dp[i][j] = 1
        else:
            dp[i][j] = sum(dp[i-1][0:j+1])
print(sum(dp[n-1]) % 10007)
