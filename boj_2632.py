import sys
input = sys.stdin.readline

order = int(input())
a, b = map(int, input().split())
A = [int(input()) for _ in range(a)]
B = [int(input()) for _ in range(b)]

subseqA = [1]+[0]*1000000
subseqB = [1]+[0]*1000000

subseqA[sum(A)] += 1
subseqB[sum(B)] += 1

for i in range(a):
    tmp = 0
    for j in range(a-1):
        tmp += A[(i+j) % a]
        subseqA[tmp] += 1

for i in range(b):
    tmp = 0
    for j in range(b-1):
        tmp += B[(i+j) % b]
        subseqB[tmp] += 1
cnt = 0
for i in range(order+1):
    cnt += subseqA[i]*subseqB[order-i]

print(cnt)
