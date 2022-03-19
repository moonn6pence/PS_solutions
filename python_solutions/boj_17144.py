import sys
input = sys.stdin.readline

R, C, T = map(int, input().split())
room = [list(map(int, input().split())) for _ in range(R)]
cleaner = []
dxdy = [(1, 0), (-1, 0), (0, 1), (0, -1)]
for i in range(R):
    for j in range(C):
        if room[i][j] == -1:
            cleaner.append(i)


def cleanUp(pos, r, c):
    x1, x2 = pos

    antiClockwiseShift(x1, c)
    clockwiseShift(x2, r, c)


def antiClockwiseShift(x, col):
    curx, cury = x-1, 0
    for _ in range(x-1):
        room[curx][0] = room[curx-1][0]
        curx -= 1

    for _ in range(col-1):
        room[0][cury] = room[0][cury+1]
        cury += 1

    for _ in range(x):
        room[curx][col-1] = room[curx+1][col-1]
        curx += 1

    for _ in range(col-2):
        room[x][cury] = room[x][cury-1]
        cury -= 1
    room[x][1] = 0


def clockwiseShift(x, row, col):
    curx, cury = x+1, 0
    for _ in range(row-x-2):
        room[curx][0] = room[curx+1][0]
        curx += 1

    for _ in range(col-1):
        room[row-1][cury] = room[row-1][cury+1]
        cury += 1

    for _ in range(row-x-1):
        room[curx][col-1] = room[curx-1][col-1]
        curx -= 1

    for _ in range(col-2):
        room[x][cury] = room[x][cury-1]
        cury -= 1

    room[x][1] = 0


def spreadDirt(r, c):
    queue = []
    for i in range(r):
        for j in range(c):
            if room[i][j] > 0:
                cnt = 0
                for dx, dy in dxdy:
                    nx, ny = i+dx, j+dy
                    if 0 <= nx < r and 0 <= ny < c and room[nx][ny] > -1:
                        queue.append((nx, ny, room[i][j]//5))
                        cnt += 1
                room[i][j] = room[i][j]-room[i][j]//5*cnt

    for i, j, d in queue:
        room[i][j] += d


for sec in range(T):
    spreadDirt(R, C)
    cleanUp(cleaner, R, C)

ans = 0
for i in range(R):
    ans += sum(room[i])

print(ans+2)
