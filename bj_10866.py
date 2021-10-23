from collections import deque
import sys

dq = deque()
n = int(input())
for _ in range(n):
    cmd = sys.stdin.readline().split()
    if cmd[0] == 'push_back':
        dq.append(int(cmd[1]))
    elif cmd[0] == 'push_front':
        dq.appendleft(int(cmd[1]))
    elif cmd[0] == 'pop_front':
        try:
            print(dq.popleft())
        except:
            print(-1)
    elif cmd[0] == 'pop_back':
        try:
            print(dq.pop())
        except:
            print(-1)
    elif cmd[0] == 'size':
        print(len(dq))
    elif cmd[0] == 'empty':
        print(0 if len(dq) else 1)
    elif cmd[0] == 'front':
        try:
            print(dq[0])
        except:
            print(-1)
    elif cmd[0] == 'back':
        try:
            print(dq[-1])
        except:
            print(-1)
