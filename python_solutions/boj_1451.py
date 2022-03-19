n, m = map(int, input().split())
rect = [list(map(int, input())) for _ in range(n)]
maxMul = 0
totalSum = 0
for i in range(n):
    for j in range(m):
        totalSum += rect[i][j]

firstPoint = [(i, j) for i in range(n)
              for j in range(m) if i != n-1 or j != m-1]


def sumRect(startX, startY, endX, endY):
    sum = 0
    for x in range(startX, endX+1):
        for y in range(startY, endY+1):
            sum += rect[x][y]
    return sum


def getSecondRect(endX, endY):
    if endY == m-1:
        start = (endX+1, 0)
        nextRange = [(i, j) for i in range(endX+1, n) for j in range(
            m) if i == n-1 or j == m-1 if i != n-1 or j != m-1]
    elif endX == n-1:
        start = (0, endY+1)
        nextRange = [(i, j) for i in range(n) for j in range(
            endY+1, m) if i == n-1 or j == m-1 if i != n-1 or j != m-1]
    else:
        start = (0, endY+1)
        nextRange = [(endX, m-1), (n-1, m-1)]
    return start, nextRange


for i, j in firstPoint:
    firtSum = sumRect(0, 0, i, j)
    nstart, nextEndRange = getSecondRect(i, j)
    nsx, nsy = nstart
    for nex, ney in nextEndRange:
        secondSum = sumRect(nsx, nsy, nex, ney)
        thirdSum = totalSum - firtSum - secondSum
        maxMul = max(maxMul, firtSum*secondSum*thirdSum)

print(maxMul)
