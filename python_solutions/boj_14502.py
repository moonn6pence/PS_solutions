from collections import deque

dxdy = [(1, 0), (-1, 0), (0, 1), (0, -1)]
n, m = map(int, input().split())
lab = [list(map(int, input().split())) for _ in range(n)]
empty = []
wall = []
virus = []
for i in range(n):
    for j in range(m):
        if lab[i][j] == 0:
            empty.append((i, j))
        elif lab[i][j] == 1:
            wall.append((i, j))
        else:
            virus.append((i, j))


def seq(depth, n, m, cur):
    if depth == m:
        subsets.append(tmp[:])
        return
    for i in range(cur, n):
        tmp.append(empty[i])
        seq(depth+1, n, m, i+1)
        tmp.pop()


def bfs(n, m, subset):
    cnt = 0
    order = deque()
    visited = [[False]*m for _ in range(n)]
    for v in virus:
        order.append(v)
        visited[v[0]][v[1]] = True
    while order:
        curx, cury = order.popleft()
        cnt += 1
        for dx, dy in dxdy:
            nx, ny = curx+dx, cury+dy
            if 0 <= nx < n and 0 <= ny < m and not visited[nx][ny] and lab[nx][ny] == 0 and (nx, ny) not in subset:
                order.append((nx, ny))
                visited[nx][ny] = True
    return cnt


tmp = []
subsets = []
seq(0, len(empty), 3, 0)
totalSpace = n*m
totalWall = len(wall)+3
ans = 0
totalVirus = n*m
for subset in subsets:
    tmpVirus = bfs(n, m, subset)
    if tmpVirus < totalVirus:
        totalVirus = tmpVirus

ans = totalSpace-totalWall-totalVirus
print(ans)
