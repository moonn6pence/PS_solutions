from collections import deque

m, n = map(int, input().split())
graph = [list(map(int, input())) for _ in range(n)]
visited = [[-1]*m for _ in range(n)]
UD, RL = [1, -1, 0, 0], [0, 0, 1, -1]
order = deque()

order.append((0, 0))
visited[0][0] = 0
while order:
    curx, cury = order.popleft()
    for dx, dy in zip(UD, RL):
        nx, ny = curx+dx, cury+dy
        if 0 <= nx < n and 0 <= ny < m and visited[nx][ny] == -1:
            if graph[nx][ny]:
                order.append((nx, ny))
                visited[nx][ny] = visited[curx][cury]+1
            else:
                order.appendleft((nx, ny))
                visited[nx][ny] = visited[curx][cury]

print(visited[n-1][m-1])
