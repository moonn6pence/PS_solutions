from collections import deque

A, B, C = map(int, input().split())
visited = [[[False]*(C+1) for j in range(B+1)] for k in range(A+1)]
ans = []

orderQ = deque()
orderQ.append((0, 0, C))
while orderQ:
    curA, curB, curC = orderQ.popleft()

    if visited[curA][curB][curC]:
        continue

    visited[curA][curB][curC] = True

    if curA == 0:
        ans.append(curC)

    if curA+curB > B:  # a->b
        nextA, nextB, nextC = curA+curB-B, B, curC
    else:
        nextA, nextB, nextC = 0, curA+curB, curC
    orderQ.append((nextA, nextB, nextC))

    if curA+curC > C:  # a->c
        nextA, nextB, nextC = curA+curC-C, curB, C
    else:
        nextA, nextB, nextC = 0, curB, curA+curC
    orderQ.append((nextA, nextB, nextC))

    if curA+curB > A:  # b->a
        nextA, nextB, nextC = A, curA+curB-A, curC
    else:
        nextA, nextB, nextC = curA+curB, 0, curC
    orderQ.append((nextA, nextB, nextC))

    if curB+curC > C:  # b->c
        nextA, nextB, nextC = curA, curB+curC-C, C
    else:
        nextA, nextB, nextC = curA, 0, curB+curC
    orderQ.append((nextA, nextB, nextC))

    if curA+curC > A:  # c->a
        nextA, nextB, nextC = A, curB, curA+curC-A
    else:
        nextA, nextB, nextC = curA+curC, curB, 0
    orderQ.append((nextA, nextB, nextC))

    if curB+curC > B:  # c->b
        nextA, nextB, nextC = curA, B, curB+curC-B
    else:
        nextA, nextB, nextC = curA, curB+curC, 0
    orderQ.append((nextA, nextB, nextC))

ans = list(sorted(set(ans)))
print(*ans, sep=' ')
