from sys import stdin

r, c = map(int, stdin.readline().split())
board = [list(stdin.readline().rstrip()) for _ in range(r)]
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]
ans = 1

order = set()
order.add((0, 0, board[0][0]))
while order:
    curx, cury, visited = order.pop()
    if len(visited) > ans:
        ans = len(visited)
    if ans == 26:
        break
    for i in range(4):
        nx = curx+dx[i]
        ny = cury+dy[i]
        if 0 <= nx < r and 0 <= ny < c and board[nx][ny] not in visited:
            order.add((nx, ny, visited+board[nx][ny]))

print(ans)
