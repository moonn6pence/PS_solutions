from sys import stdin

n = int(stdin.readline())
paper = [list(map(int, stdin.readline().split())) for _ in range(n)]
cnt = [0, 0, 0]


def checkPaper(row, col, length):
    init = paper[row][col]
    for i in range(row, row+length):
        for j in range(col, col+length):
            if init != paper[i][j]:
                return False
    return True


def recursePaper(row, col, length):
    if length == 1:
        cnt[paper[row][col]+1] += 1
        return
    nextLen = length//3
    if checkPaper(row, col, length):
        cnt[paper[row][col]+1] += 1
    else:
        for i in range(3):
            for j in range(3):
                recursePaper(row+nextLen*i, col+nextLen*j, nextLen)


recursePaper(0, 0, n)
print(*cnt)
