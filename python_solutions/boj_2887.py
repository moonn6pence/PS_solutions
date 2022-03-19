from heapq import heappop, heappush
import sys
input = sys.stdin.readline

n = int(input())
point = []
edge = []
for i in range(n):
    x, y, z = map(int, input().split())
    point.append((x, y, z, i))

point.sort()
for i in range(n-1):
    edge.append((abs(point[i][0]-point[i+1][0]), point[i][3], point[i+1][3]))

point.sort(key=lambda x: x[1])
for i in range(n-1):
    edge.append((abs(point[i][1]-point[i+1][1]), point[i][3], point[i+1][3]))

point.sort(key=lambda x: x[2])
for i in range(n-1):
    edge.append((abs(point[i][2]-point[i+1][2]), point[i][3], point[i+1][3]))

edge.sort()

MSTcost = 0
parent = [i for i in range(n)]


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


for e in edge:
    cost, start, end = e
    if find(start) == find(end):
        continue
    MSTcost += cost
    union(start, end)

print(MSTcost)
