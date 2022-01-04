import sys
input = sys.stdin.readline


def evalPoint(a, b, p):
    if not (a[1]-b[1])*(p[0]-a[0])+(b[0]-a[0])*(p[1]-a[1]):
        return 0
    elif (a[1]-b[1])*(p[0]-a[0])+(b[0]-a[0])*(p[1]-a[1]) > 0:
        return 1
    else:
        return -1


def isOverlap(z1, z2, z3, z4):
    if z1 > z2:
        z1, z2 = z2, z1
    if z3 > z4:
        z3, z4 = z4, z3
    return z1 <= z4 and z3 <= z2


def checkPartition(a, b, p1, p2):
    if not evalPoint(a, b, p1) and not evalPoint(a, b, p2):
        if a[0] == p1[0]:
            return isOverlap(a[1], b[1], p1[1], p2[1])
        else:
            return isOverlap(a[0], b[0], p1[0], p2[0])

    return evalPoint(a, b, p1) * evalPoint(a, b, p2) <= 0


def checkCross(p1, p2, p3, p4):
    if checkPartition(p1, p2, p3, p4) and checkPartition(p3, p4, p1, p2):
        return 1
    return 0


x1, y1, x2, y2 = map(int, input().split())
x3, y3, x4, y4 = map(int, input().split())


print(checkCross((x1, y1), (x2, y2), (x3, y3), (x4, y4)))
