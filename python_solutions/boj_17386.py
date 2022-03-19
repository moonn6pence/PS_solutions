import sys
input = sys.stdin.readline


def evalPoint(a, b, p):
    if not (a[1]-b[1])*(p[0]-a[0])+(b[0]-a[0])*(p[1]-a[1]):
        return 0
    elif (a[1]-b[1])*(p[0]-a[0])+(b[0]-a[0])*(p[1]-a[1]) > 0:
        return 1
    else:
        return -1


def checkPartition(a, b, p1, p2):
    if evalPoint(a, b, p1) * evalPoint(a, b, p2) <= 0:
        return True
    return False


def checkCross(p1, p2, p3, p4):
    if checkPartition(p1, p2, p3, p4) and checkPartition(p3, p4, p1, p2):
        return 1
    return 0


x1, y1, x2, y2 = map(int, input().split())
x3, y3, x4, y4 = map(int, input().split())

print(checkCross((x1, y1), (x2, y2), (x3, y3), (x4, y4)))
