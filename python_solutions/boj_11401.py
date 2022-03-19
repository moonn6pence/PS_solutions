n, k = map(int, input().split())
p = 1000000007
factDp = [1]*(n+1)

for i in range(1, n+1):
    factDp[i] = (factDp[i-1]*i) % p

nf = factDp[n]
kf = factDp[k]
nskf = factDp[n-k]

# 고속 거듭제곱 알고리즘
ex = p-2
kfex = 1
while ex:
    if ex % 2:
        kfex = (kfex*kf) % p
    kf = (kf*kf) % p
    ex //= 2

# 고속 거듭제곱 알고리즘
ex = p-2
nskfex = 1
while ex:
    if ex % 2:
        nskfex = (nskfex*nskf) % p
    nskf = (nskf*nskf) % p
    ex //= 2

# [n!/{k!*(n-k)!}]mod p = [n!*{k!*(n-k)!}^-1] mod p = [n!*{k!(n-k)!}^(p-2)] mod p = [(n!%p)*[(k!%p)*{(n-k)!%p}]%p]%p
print(nf*(kfex*nskfex % p) % p)
