def dc(n, k):
    return comb(n+k-1, k)


def fact(x):
    mul = 1
    for i in range(1, x+1):
        mul *= i
    return mul


def comb(n, r):
    return fact(n)//(fact(n-r)*fact(r))


n, k = map(int, input().split())
print(dc(n+1, k-1) % 1000000000)
