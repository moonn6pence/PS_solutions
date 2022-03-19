from operator import truediv
import sys
input = sys.stdin.readline


def find(x):
    if parent[x] == x:
        return x
    parent[x] = find(parent[x])
    return parent[x]


def union(a, b):
    a = find(a)
    b = find(b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b


# a->b
def vector(a, b):
    return (b[0]-a[0], b[1]-a[1])


def cross(a, b):
    return a[0]*b[1]-a[1]*b[0]


def det(x):
    if x > 0:
        return 1
    elif x < 0:
        return -1
    return 0


def isOverlap(a, b, c):
    if min(a[0], b[0]) <= c[0] <= max(a[0], b[0]) and min(a[1], b[1]) <= c[1] <= max(a[1], b[1]):
        return True
    return False


def intersect(a1, a2, b1, b2):
    d1 = det(cross(vector(a1, b1), vector(a1, b2)))
    d2 = det(cross(vector(a2, b1), vector(a2, b2)))
    d3 = det(cross(vector(b1, a1), vector(b1, a2)))
    d4 = det(cross(vector(b2, a1), vector(b2, a2)))

    if d1*d2 < 0 and d3*d4 < 0:
        return True
    elif d1 == 0 and isOverlap(b1, b2, a1):
        return True
    elif d2 == 0 and isOverlap(b1, b2, a2):
        return True
    elif d3 == 0 and isOverlap(a1, a2, b1):
        return True
    elif d4 == 0 and isOverlap(a1, a2, b2):
        return True
    return False


n = int(input())
parent = [i for i in range(n)]
size = [1 for i in range(n)]
line = []
for i in range(n):
    x1, y1, x2, y2 = map(int, input().split())
    line.append(((x1, y1), (x2, y2)))

for i in range(n):
    for j in range(i+1, n):
        if intersect(line[i][0], line[i][1], line[j][0], line[j][1]):
            union(i, j)

for i in range(n):
    parent[i] = find(i)

size = [0 for i in range(n)]
for i in range(n):
    size[parent[i]] += 1

print(len(set(parent)))
print(max(size))
