from collections import deque

move = [(2, 1), (2, -1), (-1, 2), (-1, -2),
        (1, 2), (1, -2), (-2, -1), (-2, 1)]

for _ in range(int(input())):
    n = int(input())
    start = tuple(map(int, input().split()))
    destx, desty = map(int, input().split())
    visited = [[0]*n for row in range(n)]
    order = deque()
    order.append(start)
    while order:
        curx, cury = order.popleft()
        if curx == destx and cury == desty:
            break
        for dx, dy in move:
            nx, ny = curx+dx, cury+dy
            if 0 <= nx < n and 0 <= ny < n and not visited[nx][ny]:
                order.append((nx, ny))
                visited[nx][ny] = visited[curx][cury]+1
    print(visited[destx][desty])
