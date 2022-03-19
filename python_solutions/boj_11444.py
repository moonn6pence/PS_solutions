def mul(mat1, mat2):
    size = len(mat1)
    ret = [[0]*size for _ in range(size)]
    for m in range(size):
        for n in range(size):
            tmp = mat1[n][m]
            for k in range(size):
                ret[n][k] = (ret[n][k]+tmp*mat2[m][k]) % 1000000007
    return ret


def power(ex):
    mat = [[1, 1], [1, 0]]
    ret = [[1, 0], [0, 1]]
    while ex:
        if ex % 2 == 1:
            ret = mul(ret, mat)
        mat = mul(mat, mat)
        ex //= 2
    return ret[0][1]


n = int(input())
print(power(n))
