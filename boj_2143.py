import sys
input = sys.stdin.readline

t = int(input())
a = int(input())
A = list(map(int, input().split()))
b = int(input())
B = list(map(int, input().split()))

dpA = [A[0]]+[0]*(a-1)
for i in range(1, a):
    dpA[i] = dpA[i-1]+A[i]

dpB = [B[0]]+[0]*(b-1)
for i in range(1, b):
    dpB[i] = dpB[i-1]+B[i]

subsetA = []
subsetB = []

for i in range(a):
    subsetA.append(dpA[i])
    for j in range(i):
        subsetA.append(dpA[i]-dpA[j])

for i in range(b):
    subsetB.append(dpB[i])
    for j in range(i):
        subsetB.append(dpB[i]-dpB[j])

subsetA.sort()
subsetB.sort(reverse=True)


a = len(subsetA)
b = len(subsetB)
i, j, cnt = 0, 0, 0

while i < a and j < b:
    if subsetA[i]+subsetB[j] == t:
        ca, cb = 1, 1
        i += 1
        j += 1
        while i < a and subsetA[i] == subsetA[i-1]:
            ca += 1
            i += 1
        while j < b and subsetB[j] == subsetB[j-1]:
            cb += 1
            j += 1
        cnt += ca*cb
    elif subsetA[i]+subsetB[j] < t:
        i += 1
    else:
        j += 1

print(cnt)
