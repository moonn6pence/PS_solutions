n = int(input())

num = [False]*2+[True]*(n-1)
prime = []

for i in range(2, n+1):
    if num[i]:
        prime.append(i)
        for j in range(i+i, n+1, i):
            num[j] = False

primeLen = len(prime)
tmp, low, high = 0, 0, 0
cnt = 0

while low < primeLen:
    if tmp == n:
        cnt += 1
        tmp -= prime[low]
        low += 1
    elif tmp > n or high >= primeLen:
        tmp -= prime[low]
        low += 1
    else:
        tmp += prime[high]
        high += 1

print(cnt)
