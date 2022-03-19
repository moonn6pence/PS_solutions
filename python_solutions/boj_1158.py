import collections

n, k = map(int, input().split())

table = collections.deque()
deadlist = []
i = 0

for _ in range(n):
    table.append(_+1)

while(len(table)):
    if (i+1) % k == 0:
        deadlist.append(table.popleft())
    else:
        table.append(table.popleft())
    i += 1

print("<", end='')
print(*deadlist, sep=", ", end='>')
