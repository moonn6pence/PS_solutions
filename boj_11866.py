from collections import deque

n, k = map(int, input().split())

cand = deque(i for i in range(1, n+1))
dead = []

while cand:
    for _ in range(k-1):
        cand.append(cand.popleft())
    dead.append(cand.popleft())

print('<', end='')
print(*dead, sep=', ', end='')
print('>')
