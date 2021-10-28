import sys
from collections import deque
N, M = map(int, sys.stdin.readline().split())
maze = [sys.stdin.readline().rstrip() for _ in range(N)]
visited = [[[0, 0] for i in range(M)]for j in range(N)]
Q = deque()
UDRL = [(1, 0), (-1, 0), (0, 1), (0, -1)]

Q.append((0, 0, 0))
visited[0][0][0] = 1
while Q:
    curX, curY, isBroken = Q.popleft()
    if curX == N-1 and curY == M-1:
        print(visited[curX][curY][isBroken])
        sys.exit(0)
    for dx, dy in UDRL:
        nx = curX+dx
        ny = curY+dy
        if 0 <= nx < N and 0 <= ny < M and not visited[nx][ny][isBroken]:
            if maze[nx][ny] == '0':
                Q.append((nx, ny, isBroken))
                visited[nx][ny][isBroken] = visited[curX][curY][isBroken]+1
            elif maze[nx][ny] == '1' and isBroken == 0:
                Q.append((nx, ny, 1))
                visited[nx][ny][1] = visited[curX][curY][isBroken]+1
print(-1)
