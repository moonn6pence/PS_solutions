from sys import stdin

n, m = map(int, stdin.readline().split())
a = list(map(int, stdin.readline().split()))
b = list(map(int, stdin.readline().split()))
merge = []
i, j = 0, 0

while i < n or j < m:
    if j == m:
        merge.append(a[i])
        i += 1
    elif i == n:
        merge.append(b[j])
        j += 1
    elif a[i] < b[j]:
        merge.append(a[i])
        i += 1
    else:
        merge.append(b[j])
        j += 1
print(*merge)
