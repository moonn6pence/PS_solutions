import sys
input = sys.stdin.readline
inf = float('inf')

string = input().strip()
n = len(string)

check = [[False]*n for _ in range(n)]
dp = [inf]*n

for i in range(n, -1, -1):
    for j in range(i, n):
        if i == j:
            check[i][i] = True
        elif i+1 == j:
            if string[i] == string[j]:
                check[i][j] = True
        else:
            if string[i] == string[j] and check[i+1][j-1]:
                check[i][j] = True

dp[0] = 1
for i in range(1, n):
    if check[0][i]:
        dp[i] = 1
    else:
        dp[i] = dp[i-1]+1
        for j in range(1, i):
            if check[j][i]:
                dp[i] = min(dp[i], dp[j-1]+1)
print(dp[n-1])
