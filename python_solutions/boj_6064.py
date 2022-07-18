def xCRT(M, N, x, y):
    ret = 0
    g, k1, k2 = xGCD(M, N)
    lcm = M*N//g
    if (y-x) % g != 0:
        return -1
    ret = (M*((y-x)//g)*k1+x) % lcm
    while ret <= 0:
        ret += lcm
    return ret


def xGCD(a, b):
    if b == 0:
        return a, 1, 0
    g, x, y = xGCD(b, a % b)
    return g, y, x-(a//b)*y


for _ in range(int(input())):
    M, N, x, y = map(int, input().split())
    print(xCRT(M, N, x, y))
