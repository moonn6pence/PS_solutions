import sys

table = {}
n = int(input())

for _ in range(n):
    a = int(sys.stdin.readline())
    if a in table:
        table[a] += 1
    else:
        table[a] = 1

maxlist = [key for m in [max(table.values())]
           for key, val in table.items() if val == m]
print(min(maxlist))
