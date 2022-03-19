from collections import deque
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
board = [list(input().strip()) for _ in range(n)]
visited = [[[[False]*m for _ in range(n)] for _ in range(m)] for _ in range(n)]
dxdy = [(1, 0), (-1, 0), (0, 1), (0, -1)]
q = deque()


def init():
    for i in range(n):
        for j in range(m):
            if board[i][j] == 'R':
                red = (i, j)
            elif board[i][j] == 'B':
                blue = (i, j)
    q.append((*red, *blue, 0))
    visited[red[0]][red[1]][blue[0]][blue[1]] = True


def move(x, y, dx, dy, c):
    while board[x+dx][y+dy] != '#' and board[x][y] != 'O':
        x += dx
        y += dy
        c += 1
    return x, y, c


def bfs():
    while q:
        rx, ry, bx, by, cnt = q.popleft()
        if cnt >= 10:
            break
        for dx, dy in dxdy:
            nrx, nry, rcnt = move(rx, ry, dx, dy, 0)
            nbx, nby, bcnt = move(bx, by, dx, dy, 0)
            if board[nbx][nby] == 'O':
                continue
            if board[nrx][nry] == 'O':
                print(cnt+1)
                return
            if nbx == nrx and nby == nry:
                if rcnt < bcnt:
                    nbx, nby = nbx-dx, nby-dy
                else:
                    nrx, nry = nrx-dx, nry-dy
            if not visited[nrx][nry][nbx][nby]:
                visited[nrx][nry][nbx][nby] = True
                q.append((nrx, nry, nbx, nby, cnt+1))

    print(-1)


init()
bfs()
