def fastExp(b, x, p):
    res = 1
    while x:
        if x & 1:
            res = res*b % p
        b = b*b % p
        x >>= 1
    return res


ans = 0
p = 10**9+7
for _ in range(int(input())):
    b, a = map(int, input().split())
    ans += (a % p*fastExp(b, p-2, p)) % p
    ans %= p
print(ans)
