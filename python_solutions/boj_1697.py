from collections import deque

visited = [False for _ in range(200001)]
bfsQ = deque()
n, k = map(int, input().split())


def bfs(start):
    depth = 0
    bfsQ.append(start)
    visited[start] = True
    while bfsQ:
        for _ in range(len(bfsQ)):
            curNode = bfsQ.popleft()
            if curNode == k:
                return depth
            if curNode-1 > 0 and not visited[curNode-1]:
                bfsQ.append(curNode-1)
                visited[curNode-1] = True
            if curNode+1 < 200001 and not visited[curNode+1]:
                bfsQ.append(curNode+1)
                visited[curNode+1] = True
            if curNode*2 < 200001 and not visited[curNode*2]:
                bfsQ.append(curNode*2)
                visited[curNode*2] = True
        depth += 1


if n >= k:
    print(n-k)
else:
    print(bfs(n))
