import sys
input = sys.stdin.readline
A, B, C, D = [], [], [], []
n = int(input())
for _ in range(n):
    a, b, c, d = map(int, input().split())
    A.append(a)
    B.append(b)
    C.append(c)
    D.append(d)

cnt = 0
sumAB = dict()
sumCD = dict()

for a in range(n):
    for b in range(n):
        if A[a]+B[b] in sumAB:
            sumAB[A[a]+B[b]] += 1
        else:
            sumAB[A[a]+B[b]] = 1


for c in range(n):
    for d in range(n):
        if -(C[c]+D[d]) in sumAB:
            cnt += sumAB[-C[c]-D[d]]

print(cnt)
