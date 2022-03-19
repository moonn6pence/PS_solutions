from re import L
import sys
input = sys.stdin.readline

n = int(input())
a = [[] for _ in range(n+1)]

for i in range(1, n+1):
    t, p = map(int, input().split())
    if i+t-1 <= n:
        a[i+t-1].append((i, p))

dp = [0]*(n+1)

for i in range(1, n+1):
    dp[i] = dp[i-1]
    for s, p in a[i]:
        dp[i] = max(dp[i], dp[s-1]+p)

print(dp[n])
