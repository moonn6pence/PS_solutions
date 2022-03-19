import sys
input = sys.stdin.readline

n = int(input())
paper = [list(map(int, input().split())) for _ in range(n)]
color = [0, 0]
XX = [0, 1, 0, 1]
YY = [0, 0, 1, 1]


def checkColor(x, y, k):
    init = paper[x][y]
    for i in range(x, x+k):
        for j in range(y, y+k):
            if paper[i][j] != init:
                return False
    return True


def divide(x, y, k):
    if k == 1 or checkColor(x, y, k):
        color[paper[x][y]] += 1
        return
    nk = k//2
    for dx, dy in zip(XX, YY):
        divide(x+dx*nk, y+dy*nk, nk)


divide(0, 0, n)
print(*color, sep='\n')
