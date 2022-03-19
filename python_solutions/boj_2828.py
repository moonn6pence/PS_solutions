import sys
input = sys.stdin.readline

n, m = map(int, input().split())
j = int(input())
apple = [int(input()) for _ in range(j)]
start, end = 1, m

ans = 0
for pos in apple:
    if start <= pos <= end:
        continue
    elif pos < start:
        dist = start-pos
        ans += dist
        start -= dist
        end -= dist
    else:
        dist = pos-end
        ans += dist
        start += dist
        end += dist

print(ans)
