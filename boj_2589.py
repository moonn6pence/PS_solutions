from collections import deque
import sys
input = sys.stdin.readline
dxdy = [(1, 0), (-1, 0), (0, 1), (0, -1)]

n, m = map(int, input().split())
graph = [list(input()) for _ in range(n)]
Map = []
for i in range(n):
    tmp = []
    for j in range(m):
        tmp.append(True if graph[i][j] == 'L' else False)
    Map.append(tmp)


def bfs(i, j):
    ret = 0
    visited = [[0]*m for _ in range(n)]
    q = deque()
    q.append((i, j))
    visited[i][j] = 1
    while q:
        x, y = q.popleft()
        ret = max(ret, visited[x][y])
        for dx, dy in dxdy:
            nx, ny = x+dx, y+dy
            if 0 <= nx < n and 0 <= ny < m and not visited[nx][ny] and Map[nx][ny]:
                q.append((nx, ny))
                visited[nx][ny] = visited[x][y]+1
    return ret-1


def solve():
    ans = 0
    for i in range(n):
        for j in range(m):
            if Map[i][j]:
                ans = max(ans, bfs(i, j))
    print(ans)


solve()
