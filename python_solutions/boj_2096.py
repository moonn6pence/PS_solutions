import sys
input = sys.stdin.readline

dp = [[0]*3 for _ in range(2)]
tmp = [[0]*3 for _ in range(2)]

for i in range(int(input())):
    a, b, c = map(int, input().split())

    tmp[0][0] = min(dp[0][0], dp[0][1])+a
    tmp[1][0] = max(dp[1][0], dp[1][1])+a

    tmp[0][1] = min(dp[0][0], dp[0][1], dp[0][2])+b
    tmp[1][1] = max(dp[1][0], dp[1][1], dp[1][2])+b

    tmp[0][2] = min(dp[0][1], dp[0][2])+c
    tmp[1][2] = max(dp[1][1], dp[1][2])+c

    for x in range(2):
        for y in range(3):
            dp[x][y] = tmp[x][y]

print(max(dp[1]), min(dp[0]))
