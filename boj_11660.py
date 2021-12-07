import sys
input = sys.stdin.readline

n, m = map(int, input().split())
table = [[0]*(n+1)]+[[0]+list(map(int, input().split())) for _ in range(n)]

totalSum = [[0]*(n+1) for _ in range(n+1)]
for i in range(1, n+1):
    for j in range(1, n+1):
        totalSum[i][j] = totalSum[i-1][j] + \
            totalSum[i][j-1]+table[i][j]-totalSum[i-1][j-1]

for _ in range(m):
    ans = 0
    x1, y1, x2, y2 = map(int, input().split())
    print(totalSum[x2][y2]-totalSum[x2][y1-1] -
          totalSum[x1-1][y2]+totalSum[x1-1][y1-1])
