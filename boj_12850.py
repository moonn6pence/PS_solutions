import sys
input = sys.stdin.readline
dxdy = [(-1, 0), (1, 0), (0, 1), (0, -1)]

graph = [[0, 1, 0, 1, 0, 0, 0, 0],
         [1, 0, 1, 1, 0, 0, 0, 0],
         [0, 1, 0, 1, 1, 1, 0, 0],
         [1, 1, 1, 0, 0, 1, 0, 0],
         [0, 0, 1, 0, 0, 1, 1, 0],
         [0, 0, 1, 1, 1, 0, 0, 1],
         [0, 0, 0, 0, 1, 0, 0, 1],
         [0, 0, 0, 0, 0, 1, 1, 0]]


def mul(a, b):
    ret = [[0]*8 for _ in range(8)]
    for i in range(8):
        for j in range(8):
            for k in range(8):
                ret[j][k] = (ret[j][k]+a[j][i]*b[i][k]) % 1000000007
    return ret


def power(mat, ex):
    ret = [[0]*8 for _ in range(8)]
    for i in range(8):
        ret[i][i] = 1

    while ex:
        if ex % 2 == 1:
            ret = mul(ret, mat)
        mat = mul(mat, mat)
        ex //= 2

    return ret


n = int(input())
print(power(graph, n)[0][0])
