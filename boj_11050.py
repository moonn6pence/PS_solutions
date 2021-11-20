n, k = map(int, input().split())


def comb(a, b):
    if b == a or b == 0:
        return 1
    return comb(a-1, b)+comb(a-1, b-1)


print(comb(n, k))
