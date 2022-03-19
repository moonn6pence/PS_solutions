import sys
input = sys.stdin.readline


def find(x):
    if parent[x] == x:
        return x
    parent[x] = find(parent[x])
    return parent[x]


parent = [i for i in range(int(input())+1)]
gi = [int(input()) for _ in range(int(input()))]
ans = 0

for g in gi:
    tmp = find(g)
    if tmp == 0:
        break
    ans += 1
    parent[tmp] = parent[tmp-1]

print(ans)
