from collections import deque
import sys
input = sys.stdin.readline

n = int(input())
tank = []
isFound = False
for i in range(n):
    line = list(map(int, input().split()))
    if not isFound:
        for j in range(n):
            if line[j] == 9:
                start = (i, j)
                isFound = True
                line[j] = 0
    tank.append(line)

size, time, ate = 2, 0, 0
visited = [[-1]*n for _ in range(n)]
move = [(-1, 0), (0, -1), (0, 1), (1, 0)]
eatable = []
tmpLen = 9999

while True:
    order = deque()
    order.append(start)
    visited[start[0]][start[1]] = 0
    while order:
        curx, cury = order.popleft()
        for dx, dy in move:
            nx, ny = curx+dx, cury+dy
            if 0 <= nx < n and 0 <= ny < n and visited[nx][ny] < 0 and tank[nx][ny] <= size:
                if visited[curx][cury]+1 <= tmpLen:
                    visited[nx][ny] = visited[curx][cury]+1
                    if 0 < tank[nx][ny] < size:
                        eatable.append((nx, ny))
                        tmpLen = visited[nx][ny]
                    else:
                        order.append((nx, ny))
    if not eatable:
        break
    eatable.sort(key=lambda x: (x[0], x[1]))
    start = eatable[0]
    eatable = []
    tank[start[0]][start[1]] = 0
    ate += 1
    time += visited[start[0]][start[1]]
    visited = [[-1]*n for _ in range(n)]
    tmpLen = 99

    if ate == size:
        size += 1
        ate = 0

print(time)
