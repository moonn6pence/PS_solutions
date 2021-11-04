from sys import stdin, exit

n = int(input())
p = [tuple(map(int, stdin.readline().split())) for _ in range(n)]
p.sort()


def calcDist(x1, y1, x2, y2):
    return (x1-x2)**2+(y1-y2)**2


def dac(start, end):
    if start == end:
        return 8000000000
    elif end-start == 1:
        return calcDist(*p[start], *p[end])

    mid = (start+end)//2
    minDist = min(dac(start, mid), dac(mid, end))
    bandArr = []
    for i in range(start, end+1):
        if (p[mid][0]-p[i][0])**2 < minDist:
            bandArr.append(p[i])

    bandArr.sort(key=lambda x: x[1])
    bandLen = len(bandArr)
    for i in range(bandLen-1):
        for j in range(i+1, bandLen):
            if (bandArr[i][1]-bandArr[j][1])**2 < minDist:
                minDist = min(minDist, calcDist(*bandArr[i], *bandArr[j]))
            else:
                break
    return minDist


print(dac(0, n-1))
