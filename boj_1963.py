from collections import deque

T = int(input())
case = []
for _ in range(T):
    case.append(tuple(map(int, input().split())))

num = [False]*2+[True]*9998
prime = []

for i in range(2, 10000):
    if num[i]:
        if i > 999:
            prime.append(i)
        for j in range(i+i, 10000, i):
            num[j] = False


def getNextPrime(num):
    result = []
    for i in range(4):
        for j in range(10):
            if i == 0 and j == 0:
                continue
            cand = list(str(num))
            cand[i] = str(j)
            result.append(int(''.join(cand)))
    return(result)


def bfs(start, end):
    Q = deque()
    if start == end:
        return 0
    visited = [0]*10000
    visited[start] = 1
    Q.append(start)
    while Q:
        curNode = Q.popleft()
        for next in getNextPrime(curNode):
            if next == end:
                return visited[curNode]
            elif not visited[next] and num[next]:
                Q.append(next)
                visited[next] = visited[curNode]+1
    print('Impossible')


for start, end in case:
    print(bfs(start, end))
