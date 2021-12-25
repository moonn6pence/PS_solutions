from heapq import heappop, heappush
import sys
input = sys.stdin.readline

n = int(input())
star = [tuple(map(float, input().split())) for _ in range(n)]
edge = []
parent = [i for i in range(n)]
minDist = 0


def getDist(x1, y1, x2, y2):
    return ((x1-x2)**2+(y1-y2)**2)**0.5


def find(x):
    return x if parent[x] == x else find(parent[x])


def union(a, b):
    a = find(a)
    b = find(b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b


for i in range(n):
    for j in range(i+1, n):
        a, b = star[i], star[j]
        heappush(edge, (getDist(*a, *b), i, j))

while edge:
    dist, p1, p2 = heappop(edge)
    if find(p1) == find(p2):
        continue
    minDist += dist
    union(p1, p2)

print(minDist)
