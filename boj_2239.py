import sys
input = sys.stdin.readline

board = [list(map(int, input().rstrip())) for _ in range(9)]
blank = [(i, j) for i in range(9) for j in range(9) if board[i][j] == 0]


def backtrack(n):
    if n == len(blank):
        for row in board:
            print(*row, sep='')
        sys.exit(0)

    x, y = blank[n]
    sx, sy = x//3*3, y//3*3
    used = [False]*10

    for i in range(9):
        if board[x][i]:
            used[board[x][i]] = True
        if board[i][y]:
            used[board[i][y]] = True
    for i in range(sx, sx+3):
        for j in range(sy, sy+3):
            if board[i][j]:
                used[board[i][j]] = True

    for i in range(1, 10):
        if not used[i]:
            board[x][y] = i
            backtrack(n+1)
            board[x][y] = 0


backtrack(0)
