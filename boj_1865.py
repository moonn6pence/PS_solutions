import sys
input = sys.stdin.readline
inf = 10**9


def bellmanford(start):
    dist[start] = 0
    for v in range(n):
        for e in range(m*2+w):
            cur, dest, cost = edge[e]
            if dist[cur] > dist[dest]+cost:
                dist[cur] = dist[dest]+cost
                if v == n-1:
                    return True
    return False


for _ in range(int(input())):
    n, m, w = map(int, input().split())
    edge = []
    dist = [inf]*n
    for road in range(m):
        s, e, t = map(int, input().split())
        edge.append((s-1, e-1, t))
        edge.append((e-1, s-1, t))
    for warmhole in range(w):
        s, e, t = map(int, input().split())
        edge.append((s-1, e-1, -t))

    print('YES' if bellmanford(0) else 'NO')
