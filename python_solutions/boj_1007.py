import sys
from math import sqrt
input = sys.stdin.readline
inf = float('inf')


def solve(idx, cnt):
    global ans

    if idx == n:
        return
    if cnt == n//2:
        x, y = 0, 0
        for i in range(n):
            if visited[i]:
                x += p[i][0]
                y += p[i][1]
            else:
                x -= p[i][0]
                y -= p[i][1]

        ans = min(ans, sqrt(x*x+y*y))
        return

    solve(idx+1, cnt)
    visited[idx] = True
    solve(idx+1, cnt+1)
    visited[idx] = False


for i in range(int(input())):
    n = int(input())
    p = [tuple(map(int, input().split())) for _ in range(n)]
    visited = [False]*n
    ans = inf

    solve(0, 0)
    print(ans)
