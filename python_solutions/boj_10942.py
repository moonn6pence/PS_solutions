import sys
input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))
m = int(input())
query = [tuple(map(int, input().split())) for _ in range(m)]
dp = [[0]*n for _ in range(n)]
for i in range(n):
    dp[i][i] = 1

for i in range(n, -1, -1):
    for j in range(i+1, n):
        if a[i] == a[j]:
            if j-i == 1:
                dp[i][j] = 1
            elif dp[i+1][j-1]:
                dp[i][j] = 1

for i, j in query:
    print(dp[i-1][j-1])
