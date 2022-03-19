from collections import deque
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
move = [0]*101
for _ in range(n+m):
    s, e = map(int, input().split())
    move[s] = e

visited = [0]*101
order = deque()

order.append(1)
while order:
    cur = order.popleft()
    if cur == 100:
        break
    for i in range(1, 7):
        if cur+i <= 100:
            nx = cur+i
            if move[nx]:
                nx = move[nx]
            if not visited[nx]:
                order.append(nx)
                visited[nx] = visited[cur]+1

print(visited[100])
