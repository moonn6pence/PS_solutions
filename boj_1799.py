import sys
input = sys.stdin.readline

n = int(input())
board = [list(map(int, input().split())) for _ in range(n)]
cross1, cross2 = [False]*(n*2-1), [False]*(n*2-1)
ans = [0]*2


def backtrack(x, y, cnt, sel):
    ans[sel] = max(ans[sel], cnt)
    if y >= n:
        x += 1
        y = sel ^ (x % 2)
    if x >= n:
        return
    if board[x][y] and not cross1[x+y] and not cross2[x-y+n-1]:
        cross1[x+y] = cross2[x-y+n-1] = True
        backtrack(x, y+2, cnt+1, sel)
        cross1[x+y] = cross2[x-y+n-1] = False
    backtrack(x, y+2, cnt, sel)


backtrack(0, 0, 0, 0)
backtrack(0, 1, 0, 1)
print(sum(ans))
