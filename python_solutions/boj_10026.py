from collections import deque
import sys
input = sys.stdin.readline

n = int(input().rstrip())
graph = [input().rstrip() for _ in range(n)]
visited = [[False]*n for _ in range(n)]
move = [(1, 0), (-1, 0), (0, 1), (0, -1)]
order = deque()
cnt, blindCnt = 0, 0

for i in range(n):
    for j in range(n):
        if not visited[i][j]:
            visited[i][j] = True
            order.append((i, j))
            curColor = graph[i][j]
            cnt += 1
            while order:
                curx, cury = order.popleft()
                for dx, dy in move:
                    nx, ny = curx+dx, cury+dy
                    if 0 <= nx < n and 0 <= ny < n and graph[nx][ny] == curColor and not visited[nx][ny]:
                        order.append((nx, ny))
                        visited[nx][ny] = True

visited = [[False]*n for _ in range(n)]
for i in range(n):
    for j in range(n):
        if not visited[i][j]:
            visited[i][j] = True
            order.append((i, j))
            curColor = graph[i][j]
            blindCnt += 1
            while order:
                curx, cury = order.popleft()
                for dx, dy in move:
                    nx, ny = curx+dx, cury+dy
                    if 0 <= nx < n and 0 <= ny < n and not visited[nx][ny]:
                        if graph[nx][ny] == curColor:
                            order.append((nx, ny))
                            visited[nx][ny] = True
                        elif graph[nx][ny] == 'R' and curColor == 'G':
                            order.append((nx, ny))
                            visited[nx][ny] = True
                        elif graph[nx][ny] == 'G' and curColor == 'R':
                            order.append((nx, ny))
                            visited[nx][ny] = True

print(cnt, blindCnt)
