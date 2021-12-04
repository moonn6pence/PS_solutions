import heapq
import sys
input = sys.stdin.readline

n = int(input().rstrip())
absheap = []
for _ in range(n):
    cmd = int(input().rstrip())
    if not cmd:
        print(0 if not absheap else heapq.heappop(absheap)[1])
        continue
    heapq.heappush(absheap, (abs(cmd), cmd))
