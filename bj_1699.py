n = int(input())
dp = [i for i in range(n+1)]
for i in range(1, n+1):
    for j in range(1, i+1):
        if j**2 == i:
            dp[i] = 1
            break
        else:
            dp[i] = min(dp[i-j]+dp[j], dp[i])
        if i-j == j or i-j == j+1:
            break
print(dp[n])
