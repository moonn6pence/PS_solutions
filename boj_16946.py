from collections import deque
import sys
input = sys.stdin.readline
dxdy = [(1, 0), (-1, 0), (0, -1), (0, 1)]

n, m = map(int, input().split())
wall = [list(map(int, input().strip())) for _ in range(n)]
ans = [[0]*m for _ in range(n)]
visited = [[0]*m for _ in range(n)]
cnt = [0]
idx = 0


def bfs(i, j):
    global idx
    idx += 1
    cnt.append(1)
    order = deque()
    order.append((i, j))
    visited[i][j] = idx
    while order:
        x, y = order.popleft()
        for dx, dy in dxdy:
            nx, ny = x+dx, y+dy
            if 0 <= nx < n and 0 <= ny < m and not wall[nx][ny] and not visited[nx][ny]:
                order.append((nx, ny))
                visited[nx][ny] = idx
                cnt[idx] += 1


def countDisjointSet():
    for i in range(n):
        for j in range(m):
            if wall[i][j] == 0 and not visited[i][j]:
                bfs(i, j)


def solve():
    countDisjointSet()
    for x in range(n):
        for y in range(m):
            if wall[x][y]:
                s = set()
                for dx, dy in dxdy:
                    nx, ny = x+dx, y+dy
                    if 0 <= nx < n and 0 <= ny < m:
                        s.add(visited[nx][ny])
                for i in s:
                    ans[x][y] += cnt[i]
                    ans[x][y] %= 10


for i in range(n):
    ans[i] = wall[i][:]

solve()
for i in range(n):
    print(''.join(map(str, ans[i])))
