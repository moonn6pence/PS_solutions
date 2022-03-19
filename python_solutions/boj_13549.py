from collections import deque

N, K = map(int, input().split())
visited = [0]*200001
order = deque()

order.append(N)
visited[N] = 1
while order:
    curX = order.popleft()
    if curX == K:
        break
    if curX*2 <= 100000 and not visited[curX*2]:
        order.append(curX*2)
        visited[curX*2] = visited[curX]
    if curX > 0 and not visited[curX-1]:
        order.append(curX-1)
        visited[curX-1] = visited[curX]+1
        visited[curX*2] = visited[curX]
    if curX < 100000 and not visited[curX+1]:
        order.append(curX+1)
        visited[curX+1] = visited[curX]+1

print(visited[K]-1)
