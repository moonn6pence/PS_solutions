def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)


n = int(input())
wheel = list(map(int, input().split()))

for i in range(1, n):
    tmp = gcd(wheel[0], wheel[i])
    print(wheel[0]//tmp, '/', wheel[i]//tmp, sep='')
