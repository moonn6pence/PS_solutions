from collections import deque
import sys
input = sys.stdin.readline

dxdy = [(0, 1), (0, -1), (1, 0), (-1, 0)]
n, m = map(int, input().split())
city = [list(map(int, input().split())) for _ in range(n)]
home = []
store = []
for i in range(n):
    for j in range(n):
        if city[i][j] == 1:
            home.append((i, j))
        elif city[i][j] == 2:
            store.append((i, j))


def chickenDistance(homeX, homeY, selected):
    dist = 999
    for storeX, storeY in selected:
        if dist > abs(homeX-storeX)+abs(homeY-storeY):
            dist = abs(homeX-storeX)+abs(homeY-storeY)
    return dist


def combBitmask(n, m):
    for i in range(1 << n):
        cnt = 0
        tmp = []
        for j in range(n):
            if (i & (1 << j)) > 0:
                cnt += 1
                tmp.append(j)
        if cnt == m:
            selectedStore.append(tmp)


storeCnt = len(store)
selectedStore = []
tmp = []
combBitmask(storeCnt, m)

ans = float('inf')
for stores in selectedStore:
    selection = []
    total = 0
    for i in stores:
        selection.append(store[i])
    for i, j in home:
        total += chickenDistance(i, j, selection)
    ans = min(ans, total)

print(ans)
