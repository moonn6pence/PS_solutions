from collections import deque

f, start, g, u, d = map(int, input().split())
visited = [0]*(f+1)
order = deque()
move = [u, -d]


def bfs(start, f, g):
    order.append(start)
    visited[start] = 1
    while order:
        curFloor = order.popleft()
        if curFloor == g:
            print(visited[curFloor]-1)
            return
        for df in move:
            nextFloor = curFloor + df
            if 1 <= nextFloor <= f and not visited[nextFloor]:
                order.append(nextFloor)
                visited[nextFloor] = visited[curFloor]+1
    print('use the stairs')


bfs(start, f, g)
