from sys import stdin

n, m, k = map(int, stdin.readline().split())

board = [stdin.readline().rstrip() for _ in range(n)]
target = stdin.readline().rstrip()
dp = [[[-1]*len(target) for j in range(m)] for i in range(n)]
moves = []
for i in range(1, k+1):
    moves.append((i, 0))
    moves.append((-i, 0))
    moves.append((0, i))
    moves.append((0, -i))


def dfs(curx, cury, targetIdx):
    if targetIdx == len(target):
        return 1
    if dp[curx][cury][targetIdx] != -1:
        return dp[curx][cury][targetIdx]

    dp[curx][cury][targetIdx] = 0
    for dx, dy in moves:
        nx = curx+dx
        ny = cury+dy
        if 0 <= nx < n and 0 <= ny < m and board[nx][ny] == target[targetIdx]:
            dp[curx][cury][targetIdx] += dfs(nx, ny, targetIdx+1)

    return dp[curx][cury][targetIdx]


cnt = 0
for i in range(n):
    for j in range(m):
        if board[i][j] == target[0]:
            cnt += dfs(i, j, 1)

print(cnt)
