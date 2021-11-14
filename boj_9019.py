from collections import deque
import sys


def getDSLR(num):
    result = []
    d1, d2, d3, d4 = num//1000, (num % 1000)//100, (num % 100)//10, num % 10
    result.append(num*2 % 10000)
    result.append(9999 if num-1 < 0 else num-1)
    result.append(d2*1000+d3*100+d4*10+d1)
    result.append(d4*1000+d1*100+d2*10+d3)

    return result


def trackDown(end, visited):
    result = []
    curNode = end
    while visited[curNode] != -99:
        DSLR = getDSLR(visited[curNode])
        result.append('DSLR'[DSLR.index(curNode)])
        curNode = visited[curNode]
    result.reverse()
    return ''.join(result)


def bfs(start, end):
    Q = deque()
    visited = [-1 for _ in range(10000)]
    Q.append(start)
    visited[start] = -99
    while Q:
        curNode = Q.popleft()
        if curNode == end:
            break
        for node in getDSLR(curNode):
            if visited[node] == -1:
                Q.append(node)
                visited[node] = curNode
    print(trackDown(end, visited))


T = int(input())
for _ in range(T):
    a, b = map(int, sys.stdin.readline().split())
    bfs(a, b)
