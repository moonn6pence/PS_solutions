from collections import deque

n, k = map(int, input().split())
visited = [-1]*100001
order = deque()
order.append(n)
visited[n] = 0
cnt = 0

while order:
    cur = order.popleft()
    if cur == k:
        cnt += 1

    if 0 <= cur-1 and (visited[cur-1] < 0 or visited[cur-1] >= visited[cur]+1):
        order.append(cur-1)
        visited[cur-1] = visited[cur]+1
    if cur+1 <= 100000 and (visited[cur+1] < 0 or visited[cur+1] >= visited[cur]+1):
        order.append(cur+1)
        visited[cur+1] = visited[cur]+1
    if cur*2 <= 100000 and (visited[cur*2] < 0 or visited[cur*2] >= visited[cur]+1):
        order.append(cur*2)
        visited[cur*2] = visited[cur]+1

print(visited[k], cnt, sep='\n')
