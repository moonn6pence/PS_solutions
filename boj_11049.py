import sys
input = sys.stdin.readline

n = int(input())
mat = [list(map(int, input().split())) for _ in range(n)]
dp = [[0]*n for _ in range(n)]

for l in range(1, n):
    for s in range(n-l):
        dp[s][s+l] = 500**4
        for k in range(s, s+l):
            dp[s][s+l] = min(dp[s][s+l], dp[s][k]+dp[k+1]
                             [s+l]+mat[s][0]*mat[k][1]*mat[s+l][1])

print(dp[0][n-1])
