from collections import deque
import sys
input = sys.stdin.readline
dxdy = [(1, 0), (-1, 0), (0, 1), (0, -1)]

N, M = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(N)]
cheese = []
for i in range(N):
    for j in range(M):
        if grid[i][j]:
            cheese.append((i, j))

visited = [[False]*M for _ in range(N)]


def spreadAir(x, y):
    order = deque()
    order.append((x, y))
    while order:
        x, y = order.popleft()
        for dx, dy in dxdy:
            nx, ny = x+dx, y+dy
            if 0 <= nx < N and 0 <= ny < M and not visited[nx][ny] and not grid[nx][ny]:
                order.append((nx, ny))
                visited[nx][ny] = True


def isExposed(x, y):
    cnt = 0
    for dx, dy in dxdy:
        nx, ny = x+dx, y+dy
        if 0 <= nx < N and 0 <= ny < M and not grid[x+dx][y+dy] and visited[x+dx][y+dy]:
            cnt += 1
            if cnt > 1:
                return True
    return False


spreadAir(0, 0)
hour = 0
while True:
    flag = True
    melt = []
    for x, y in cheese:
        if not visited[x][y]:
            if isExposed(x, y):
                visited[x][y] = True
                melt.append((x, y))
                flag = False
    for x, y in melt:
        grid[x][y] = 0
        spreadAir(x, y)
    if flag:
        break
    hour += 1
print(hour)
