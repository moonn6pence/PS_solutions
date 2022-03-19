n = int(input())
dp = [x for x in range(n+1)]
for i in range(1, n+1):
    for j in range(int(i**(1/2)), 0, -1):
        if dp[i] == 1:
            break
        if dp[i] == 2:
            break
        if dp[i] > dp[i-j*j]+1:
            dp[i] = dp[i-j*j]+1
print(dp[n])
