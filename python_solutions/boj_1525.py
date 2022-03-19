from collections import deque
import sys


def getNextString(cur, curZero, idx):
    if curZero < idx:
        return cur[:curZero]+cur[idx]+cur[curZero+1:idx]+'0'+cur[idx+1:]
    else:
        return cur[:idx]+'0'+cur[idx+1:curZero]+cur[idx]+cur[curZero+1:]


init = "".join(input().replace(" ", "") for _ in range(3))
ans = '123456780'
move = [[1, 3], [0, 2, 4], [1, 5], [0, 4, 6], [
    1, 3, 5, 7], [2, 4, 8], [3, 7], [4, 6, 8], [5, 7]]
visited = dict()
orderQ = deque()

orderQ.append(init)
visited[init] = 0

while orderQ:
    curPos = orderQ.popleft()
    if curPos == ans:
        print(visited[curPos])
        sys.exit(0)
    zeroIdx = curPos.find('0')
    for next in move[zeroIdx]:
        nextPos = getNextString(curPos, zeroIdx, next)
        if not nextPos in visited:
            orderQ.append(nextPos)
            visited[nextPos] = visited[curPos]+1

print(-1)
