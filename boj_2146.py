from collections import deque
import sys


def resetVisit(n):
    for i in range(n):
        for j in range(n):
            if visited[i][j] > 1:
                visited[i][j] = 0


n = int(sys.stdin.readline())
graph = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
visited = [[0 for _ in range(n)] for __ in range(n)]
Q = deque()
distMin = 300
UD = [1, -1, 0, 0]
RL = [0, 0, 1, -1]
landNum = 0
for x in range(n):
    for y in range(n):
        if not visited[x][y] and graph[x][y]:
            visited[x][y] = 2
            Q.append((x, y))
            landNum += 1
            while Q:
                curx, cury = Q.popleft()
                graph[curx][cury] = landNum
                for dx, dy in zip(UD, RL):
                    nx = curx+dx
                    ny = cury+dy
                    if 0 <= nx < n and 0 <= ny < n and not visited[nx][ny] and graph[nx][ny]:
                        Q.append((nx, ny))
                        visited[nx][ny] = 2

resetVisit(n)

for x in range(n):
    for y in range(n):
        if not visited[x][y] and graph[x][y]:
            resetVisit(n)
            curLand = graph[x][y]
            Q.append((x, y))
            visited[x][y] = 1
            while Q:
                curx, cury = Q.popleft()
                for dx, dy in zip(UD, RL):
                    nx = curx+dx
                    ny = cury+dy
                    if 0 <= nx < n and 0 <= ny < n:
                        if not visited[nx][ny] and graph[nx][ny]:
                            if graph[curx][cury] == 1:
                                Q.append((nx, ny))
                                visited[nx][ny] = 1
                            elif graph[nx][ny] != curLand and graph[curx][cury] == 0:
                                distMin = min(distMin, visited[curx][cury]-1)
                        elif graph[nx][ny] == 0:
                            if not visited[nx][ny]:
                                Q.append((nx, ny))
                                visited[nx][ny] = visited[curx][cury]+1
                            elif visited[nx][ny]:
                                if visited[nx][ny] > visited[curx][cury]+1:
                                    Q.append((nx, ny))
                                    visited[nx][ny] = visited[curx][cury]+1
print(distMin)
