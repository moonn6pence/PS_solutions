from collections import deque

a, b = map(int, input().split())
visited = dict()
order = deque()
order.append(a)
visited[a] = 1
while order:
    cur = order.popleft()
    if cur == b:
        break

    nx = cur*2
    if nx <= 10**9 and nx not in visited:
        order.append(nx)
        visited[nx] = visited[cur]+1
    nx = cur*10+1
    if nx <= 10**9 and nx not in visited:
        order.append(nx)
        visited[nx] = visited[cur]+1

print(-1 if b not in visited else visited[b])
