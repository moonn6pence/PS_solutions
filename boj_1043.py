from collections import deque
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
trueN, *truth = map(int, input().split())


parties = []
for _ in range(m):
    memNum, *member = map(int, input().split())
    parties.append(list(member))

trueMember = [False]*(n+1)
order = deque()

for i in truth:
    trueMember[i] = True
    order.append(i)

while order:
    cur = order.popleft()
    for party in parties:
        if cur in party:
            for mem in party:
                if not trueMember[mem]:
                    order.append(mem)
                    trueMember[mem] = True

cnt = 0
for party in parties:
    flag = False
    for mem in party:
        if trueMember[mem]:
            flag = True
            break
    if flag:
        continue
    cnt += 1

print(cnt)
