A, B, C = map(int, input().split())


def DnQ(a, b):
    if b == 1:
        return a % C
    tmp = DnQ(a, b//2)
    if b % 2:
        return tmp*tmp*a % C
    else:
        return tmp*tmp % C


print(DnQ(A, B))
