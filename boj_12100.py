from collections import deque
import sys
input = sys.stdin.readline
n = int(input())
ans = 0
Q = deque()
board = [list(map(int, input().split())) for _ in range(n)]


def enqueue(x, y):
    if board[x][y]:
        Q.append(board[x][y])
        board[x][y] = 0


def dequeue(x, y, dx, dy):
    while Q:
        cur = Q.popleft()
        if not board[x][y]:
            board[x][y] = cur
        elif board[x][y] == cur:
            board[x][y] = cur*2
            x, y = x+dx, y+dy
        else:
            x, y = x+dx, y+dy
            board[x][y] = cur


def move(dir):
    if dir == 0:  # up
        for y in range(n):
            for x in range(n):
                enqueue(x, y)
            dequeue(0, y, 1, 0)
    elif dir == 1:  # down
        for y in range(n):
            for x in range(n-1, -1, -1):
                enqueue(x, y)
            dequeue(n-1, y, -1, 0)
    elif dir == 2:  # left
        for x in range(n):
            for y in range(n):
                enqueue(x, y)
            dequeue(x, 0, 0, 1)
    else:  # right
        for x in range(n):
            for y in range(n-1, -1, -1):
                enqueue(x, y)
            dequeue(x, n-1, 0, -1)


def solve(depth):
    global ans, board
    if depth == 5:
        for i in range(n):
            ans = max(ans, max(board[i]))
        return
    tmp = [row[:] for row in board]
    for dir in range(4):
        move(dir)
        solve(depth+1)
        board = [row[:] for row in tmp]


solve(0)
print(ans)
