import sys

rect = []
n = int(sys.stdin.readline())
for i in range(n):
    x1, y1, x2, y2 = map(int, sys.stdin.readline().split())
    rect.append(((x1, y1, x2, y2)))

parent = [i for i in range(n)]


def getParent(x):
    return x if parent[x] == x else getParent(parent[x])


def union(a, b):
    a = getParent(a)
    b = getParent(b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b


def isOverlapped(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2):
    if ax1 < bx1 and ay1 < by1 and bx2 < ax2 and by2 < ay2:
        return False
    elif bx1 < ax1 and by1 < ay1 and ax2 < bx2 and ay2 < by2:
        return False
    elif ax2 < bx1 or ax1 > bx2:
        return False
    elif ay1 > by2 or ay2 < by1:
        return False
    else:
        return True


pu = 0

for a in range(n):
    for b in range(n):
        if a == b:
            continue
        if isOverlapped(*rect[a], *rect[b]):
            union(a, b)

parent = list(map(getParent, parent))
pu = len(set(parent))

isZero = False
for i in range(n):
    x1, y1, x2, y2 = rect[i]
    if x1 <= 0 and x2 >= 0:
        if y1 == 0 or y2 == 0:
            isZero = True
            break
    if y1 <= 0 and y2 >= 0:
        if x1 == 0 or x2 == 0:
            isZero = True
            break

print(pu-1 if isZero else pu)
