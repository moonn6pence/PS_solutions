import sys
input = sys.stdin.readline

S = set()

for _ in range(int(input())):
    cmd = input().split()
    if cmd[0] == 'add':
        S.add(int(cmd[1]))
    elif cmd[0] == 'remove':
        S.discard(int(cmd[1]))
    elif cmd[0] == 'check':
        print(1 if int(cmd[1]) in S else 0)
    elif cmd[0] == 'toggle':
        if int(cmd[1]) in S:
            S.remove(int(cmd[1]))
        else:
            S.add(int(cmd[1]))
    elif cmd[0] == 'all':
        S = set({i for i in range(1, 21)})
    elif cmd[0] == 'empty':
        S.clear()
