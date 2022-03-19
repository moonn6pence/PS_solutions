from collections import deque
import sys
input = sys.stdin.readline
dxdy = [(1, 0), (-1, 0), (0, 1), (0, -1)]

m, n, k = map(int, input().split())

visited = [[False]*n for _ in range(m)]

for _ in range(k):
    x1, y1, x2, y2 = map(int, input().split())
    for x in range(y1, y2):
        for y in range(x1, x2):
            visited[x][y] = True


def bfs(x, y):
    cnt = 0
    q = deque()
    q.append((x, y))
    visited[x][y] = True
    while q:
        curx, cury = q.popleft()
        cnt += 1
        for dx, dy in dxdy:
            nx, ny = curx+dx, cury+dy
            if 0 <= nx < m and 0 <= ny < n and not visited[nx][ny]:
                q.append((nx, ny))
                visited[nx][ny] = True
    return cnt


def solve():
    ans = []
    for i in range(m):
        for j in range(n):
            if not visited[i][j]:
                ans.append(bfs(i, j))

    ans.sort()
    print(len(ans))
    print(*ans)


solve()
