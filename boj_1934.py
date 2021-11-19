def gcd(a, b):
    if a % b == 0:
        return b
    else:
        return gcd(b, a % b)


t = int(input())
for _ in range(t):
    a, b = map(int, input().split())
    if a >= b:
        GCD = gcd(a, b)
    else:
        GCD = gcd(b, a)
    print(a*b//GCD)
