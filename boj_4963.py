import sys
from collections import deque

while True:
    w, h = map(int, sys.stdin.readline().split())
    if not w and not h:
        sys.exit(0)
    graph = [list(map(int, sys.stdin.readline().split())) for _ in range(h)]
    visited = [[False for i in range(w)] for j in range(h)]
    bfsQ = deque()
    cnt = 0
    move = [(1, 0), (-1, 0), (0, 1), (0, -1),
            (1, 1), (1, -1), (-1, 1), (-1, -1)]

    for x in range(h):
        for y in range(w):
            if not visited[x][y] and graph[x][y] == 1:
                visited[x][y] = True
                bfsQ.append((x, y))
                cnt += 1
                while bfsQ:
                    curx, cury = bfsQ.popleft()
                    for dx, dy in move:
                        nx = curx+dx
                        ny = cury+dy
                        if 0 <= nx < h and 0 <= ny < w and graph[nx][ny] == 1 and not visited[nx][ny]:
                            bfsQ.append((nx, ny))
                            visited[nx][ny] = True
    print(cnt)
