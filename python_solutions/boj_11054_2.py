n = int(input())
seq = list(map(int, input().split()))
dp, dp1, dp2 = [0]*n, [0]*n, [0]*n
for i in range(n):
    for j in range(i):
        if seq[i] > seq[j] and dp1[i] < dp1[j]:
            dp1[i] = dp1[j]
    dp1[i] += 1
for i in range(n-1, -1, -1):
    for j in range(n-1, i, -1):
        if seq[i] > seq[j] and dp2[i] < dp2[j]:
            dp2[i] = dp2[j]
    dp2[i] += 1
    dp[i] = dp1[i]+dp2[i]-1
print(max(dp))
