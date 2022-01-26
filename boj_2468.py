from collections import deque
import sys
input = sys.stdin.readline
dxdy = [(1, 0), (-1, 0), (0, 1), (0, -1)]

n = int(input())
Map = [list(map(int, input().split())) for _ in range(n)]
visited = [[False]*n for _ in range(n)]

minH, maxH = 100, 2
for i in range(n):
    for j in range(n):
        minH = min(minH, Map[i][j])
        maxH = max(maxH, Map[i][j])


def init():
    for i in range(n):
        for j in range(n):
            visited[i][j] = False


def bfs(x, y, h):
    if Map[x][y] > h and not visited[x][y]:
        q = deque()
        q.append((x, y))
        visited[x][y] = True
        while q:
            curx, cury = q.popleft()
            for dx, dy in dxdy:
                nx, ny = curx+dx, cury+dy
                if 0 <= nx < n and 0 <= ny < n and Map[nx][ny] > h and not visited[nx][ny]:
                    visited[nx][ny] = True
                    q.append((nx, ny))
        return 1
    return 0


def solve():
    ans = 0
    for h in range(minH-1, maxH):
        init()
        tmp = 0
        for x in range(n):
            for y in range(n):
                tmp += bfs(x, y, h)
        ans = max(ans, tmp)
    print(ans)


solve()
