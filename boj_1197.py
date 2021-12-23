# Kruskal Algorithm
from heapq import heappop, heappush
import sys
input = sys.stdin.readline


def find(x):
    return x if parent[x] == x else find(parent[x])


def union(a, b):
    a = find(a)
    b = find(b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b


V, E = map(int, input().split())
parent = [i for i in range(V+1)]
edge = []
MSTCost = 0
for _ in range(E):
    a, b, c = map(int, input().split())
    heappush(edge, (c, a, b))

while edge:
    curCost, curStart, curEnd = heappop(edge)
    if find(curStart) == find(curEnd):
        continue
    MSTCost += curCost
    union(curStart, curEnd)

print(MSTCost)
