from sys import stdin

input = stdin.readline

n, s = map(int, input().split())
init = list(map(int, input().split()))
m = n//2
n = n-m

leftSubset = [0]*(1 << n)
rightSubset = [0]*(1 << m)

for i in range(1 << n):
    for j in range(n):
        if (i & (1 << j)) > 0:
            leftSubset[i] += init[j]

for i in range(1 << m):
    for j in range(m):
        if (i & (1 << j)) > 0:
            rightSubset[i] += init[j+n]

leftSubset.sort()
rightSubset.sort(reverse=True)

n, m = (1 << n), (1 << m)
i, j, cnt = 0, 0, 0


while i < n and j < m:
    if leftSubset[i]+rightSubset[j] == s:
        l1, r1 = 1, 1
        i += 1
        j += 1
        while i < n and leftSubset[i] == leftSubset[i-1]:
            l1 += 1
            i += 1
        while j < m and rightSubset[j] == rightSubset[j-1]:
            r1 += 1
            j += 1
        cnt += l1*r1
    elif leftSubset[i]+rightSubset[j] < s:
        i += 1
    else:
        j += 1

if s == 0:
    cnt -= 1

print(cnt)
