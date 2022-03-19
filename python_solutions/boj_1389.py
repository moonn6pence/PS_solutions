import sys
input = sys.stdin.readline

n, m = map(int, input().split())
graph = [[0]*n for _ in range(n)]
dist = [[99]*n for _ in range(n)]

for _ in range(m):
    a, b = map(int, input().split())
    graph[a-1][b-1], graph[b-1][a-1] = 1, 1
    dist[a-1][b-1], dist[b-1][a-1] = 1, 1
for i in range(n):
    dist[i][i] = 0

for via in range(n):
    for _from in range(n):
        for to in range(n):
            if dist[_from][via]+dist[via][to] < dist[_from][to]:
                dist[_from][to] = dist[_from][via]+dist[via][to]

tmpMin = (sum(dist[0]), 1)
for i in range(1, n):
    tmpSum = sum(dist[i])
    if tmpMin[0] > tmpSum:
        tmpMin = (tmpSum, i+1)
print(tmpMin[1])
