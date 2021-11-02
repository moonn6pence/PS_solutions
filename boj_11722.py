n = int(input())
seq = list(map(int, input().split()))
dp = [0]*n
for i in range(n-1, -1, -1):
    for j in range(n-1, i, -1):
        if seq[i] > seq[j] and dp[i] < dp[j]:
            dp[i] = dp[j]
    dp[i] += 1
print(max(dp))
