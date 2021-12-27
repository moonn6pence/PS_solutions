import sys
input = sys.stdin.readline


def find(x):
    return x if parent[x] == x else find(parent[x])


def union(a, b):
    a = find(a)
    b = find(b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b


n, m = map(int, input().split())
parent = [i for i in range(n)]
ans = 0
flag = True
for i in range(1, m+1):
    a, b = map(int, input().split())
    if flag:
        if find(a) == find(b):
            ans = i
            flag = False
    union(a, b)
print(ans)
