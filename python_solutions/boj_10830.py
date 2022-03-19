def mul(mat1, mat2):
    size = len(mat1)
    ret = [[0]*size for _ in range(size)]
    for m in range(size):
        for n in range(size):
            tmp = mat1[n][m]
            for k in range(size):
                ret[n][k] = (ret[n][k]+tmp*mat2[m][k]) % 1000
    return ret


def power(mat, ex):
    size = len(mat)
    ret = [[0 for j in range(size)]for i in range(size)]
    for i in range(size):
        ret[i][i] = 1
    while ex:
        if ex % 2 == 1:
            ret = mul(ret, mat)
        mat = mul(mat, mat)
        ex //= 2
    return ret


n, b = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(n)]
ans = power(a, b)
for i in range(n):
    print(*ans[i], sep=' ')
