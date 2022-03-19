import sys
input = sys.stdin.readline

n = int(input())
cow = [-1]*11
ans = 0
for _ in range(n):
    c, s = map(int, input().split())
    if cow[c] < 0:
        cow[c] = s
    elif cow[c] != s:
        cow[c] = s
        ans += 1
print(ans)
