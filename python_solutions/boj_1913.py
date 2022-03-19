import sys
input = sys.stdin.readline

dxdy = [(1, 0), (0, 1), (-1, 0), (0, -1)]

n = int(input())
m = int(input())

Map = [[0]*n for _ in range(n)]
x, y = -1, -1
cnt = n**2

for i in range(n-1, -1, -2):
    x += 1
    y += 1
    for dx, dy in dxdy:
        for j in range(i):
            if cnt == m:
                ans = (x, y)
            Map[x][y] = cnt
            x, y, cnt = x+dx, y+dy, cnt-1
Map[x][y] = cnt

for _ in range(n):
    print(*Map[_])

print(ans[0]+1 if m > 1 else n//2+1, ans[1]+1 if m > 1 else n//2+1)
