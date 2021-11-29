import sys
input = sys.stdin.readline

n, m, b = map(int, input().split())
site = [list(map(int, input().split())) for _ in range(n)]
heights = [0]*257
for i in range(n):
    for j in range(m):
        heights[site[i][j]] += 1
hdict = dict()
for i in range(257):
    if heights[i]:
        hdict[i] = heights[i]
minH = min(map(min, site))
maxH = max(map(max, site))
ans = [10**9, 0]
for height in range(minH, maxH+1):
    toDig, toFill = 0, 0
    for h, num in hdict.items():
        if h > height:
            toDig += (h-height)*num
        elif h < height:
            toFill += (height-h)*num
    if toDig+b < toFill:
        continue

    if ans[0] >= toDig*2+toFill:
        ans[0] = toDig*2+toFill
        ans[1] = height

print(*ans)
