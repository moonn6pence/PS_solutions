from collections import deque
import sys
input = sys.stdin.readline

dxdy = [(1, 0), (-1, 0), (0, 1), (0, -1)]


def bfs():
    ans = 0
    door = [deque() for _ in range(26)]
    order = deque()
    order.append((0, 0))

    while order:
        x, y = order.popleft()

        for dx, dy in dxdy:
            nx, ny = x+dx, y+dy
            if 0 <= nx < h and 0 <= ny < w and not visited[nx][ny]:
                if graph[nx][ny] == '*':
                    continue
                visited[nx][ny] = True

                if graph[nx][ny] == '$':
                    ans += 1
                elif 'A' <= graph[nx][ny] <= 'Z':
                    ascii = ord(graph[nx][ny])-65
                    if not keys[ascii]:
                        door[ascii].append((nx, ny))
                        continue
                elif 'a' <= graph[nx][ny] <= 'z':
                    key = ord(graph[nx][ny])-97
                    keys[key] = True
                    while door[key]:
                        order.append(door[key].popleft())
                order.append((nx, ny))
    return ans


for case in range(int(input())):
    h, w = map(int, input().split())
    w += 2
    graph = [['.']*w]+[['.']+list(input().strip())+['.']
                       for _ in range(h)]+[['.']*w]
    h += 2
    visited = [[False]*w for _ in range(h)]
    keys = [False]*26
    tmpKeys = input().strip()
    if tmpKeys != '0':
        for key in tmpKeys:
            keys[ord(key)-97] = True

    print(bfs())
