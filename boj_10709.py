import sys
input = sys.stdin.readline

h, w = map(int, input().split())
sky = [list(input().strip()) for _ in range(h)]

ans = [[0]*w for _ in range(h)]
for i in range(h):
    tmp = -1
    for j in range(w):
        if sky[i][j] == 'c':
            tmp = 0
        elif tmp != -1:
            tmp += 1
        ans[i][j] = tmp

for _ in range(h):
    print(*ans[_])
