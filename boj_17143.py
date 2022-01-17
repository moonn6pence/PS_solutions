from heapq import heappop, heappush
import sys
input = sys.stdin.readline
dir = [(0, 0), (-1, 0), (1, 0), (0, 1), (0, -1)]
inv = [0, 2, 1, 4, 3]


r, c, m = map(int, input().split())
Map = [[-1]*(c+1) for _ in range(r+1)]
tmp = [[[]for _ in range(c+1)] for _ in range(r+1)]

sharks = []  # r,c,s,d,z
for i in range(m):
    x, y, s, d, z = map(int, input().split())
    if d <= 2:
        s %= (r-1)*2
    else:
        s %= (c-1)*2
    sharks.append([s, d, z])
    Map[x][y] = i


def update():
    for i in range(1, r+1):
        for j in range(1, c+1):
            if tmp[i][j]:
                Map[i][j] = heappop(tmp[i][j])[1]
            else:
                Map[i][j] = -1
            tmp[i][j] = []


def move(x, y):
    n, curd, curz = sharks[Map[x][y]]
    nx, ny = x, y
    while n:
        if curd == 1 and nx == 1:
            curd = 2
        elif curd == 2 and nx == r:
            curd = 1
        elif curd == 3 and ny == c:
            curd = 4
        elif curd == 4 and ny == 1:
            curd = 3
        nx, ny = nx+dir[curd][0], ny+dir[curd][1]
        n -= 1
    sharks[Map[x][y]][1] = curd
    return nx, ny


def solve():
    fish = 0
    for i in range(1, c+1):
        for x in range(1, r+1):
            if Map[x][i] >= 0:
                fish += sharks[Map[x][i]][2]
                Map[x][i] = -1
                break
        for x in range(1, r+1):
            for y in range(1, c+1):
                if Map[x][y] >= 0:
                    nx, ny = move(x, y)
                    heappush(tmp[nx][ny], (-sharks[Map[x][y]][2], Map[x][y]))
        update()
    print(fish)


solve()
