import heapq
import sys
from collections import defaultdict

input = sys.stdin.readline

for _ in range(int(input())):
    minPQ = []
    maxPQ = []
    lookup = defaultdict(int)
    for i in range(int(input())):
        cmd = list(input().split())
        if cmd[0] == 'I':
            num = int(cmd[1])
            heapq.heappush(minPQ, num)
            heapq.heappush(maxPQ, num*-1)
            lookup[num] += 1
        else:
            if cmd[1] == '1':
                while maxPQ and lookup[-maxPQ[0]] == 0:
                    heapq.heappop(maxPQ)
                if maxPQ:
                    maxVal = heapq.heappop(maxPQ)*-1
                    lookup[maxVal] -= 1

            else:
                while minPQ and lookup[minPQ[0]] == 0:
                    heapq.heappop(minPQ)
                if minPQ:
                    minVal = heapq.heappop(minPQ)
                    lookup[minVal] -= 1
        while maxPQ and lookup[maxPQ[0]*-1] == 0:
            heapq.heappop(maxPQ)
        while minPQ and lookup[minPQ[0]] == 0:
            heapq.heappop(minPQ)

    if maxPQ and minPQ:
        print(-maxPQ[0], minPQ[0])
    else:
        print('EMPTY')
