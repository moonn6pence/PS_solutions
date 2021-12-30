from heapq import heappop, heappush
import sys
input = sys.stdin.readline

n, k = map(int, input().split())
jam = [tuple(map(int, input().split())) for _ in range(n)]
bags = [int(input()) for _ in range(k)]
jam.sort()
bags.sort()
tmp = []
i, ans = 0, 0

for bag in bags:
    while i < n and bag >= jam[i][0]:
        heappush(tmp, -jam[i][1])
        i += 1
    if tmp:
        ans -= heappop(tmp)

print(ans)
