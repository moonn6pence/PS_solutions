n, m = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(n)]
_, k = map(int, input().split())
b = [list(map(int, input().split())) for _ in range(m)]


def binFind(n, m, k):
    minLen = max(n, m, k)
    ex = 0
    while minLen > 2**ex:
        ex += 1
    return 2**ex


size = binFind(n, m, k)
for i in range(size):
    if i < n:
        for j in range(size-m):
            a[i].append(0)
    else:
        a.append([0]*size)

for i in range(size):
    if i < m:
        for j in range(size-k):
            b[i].append(0)
    else:
        b.append([0]*size)


def Add(m1, m2):
    size = len(m1)
    res = [[0]*size for _ in range(size)]
    for i in range(size):
        for j in range(size):
            res[i][j] = m1[i][j]+m2[i][j]
    return res


def Sub(m1, m2):
    size = len(m1)
    res = [[0]*size for _ in range(size)]
    for i in range(size):
        for j in range(size):
            res[i][j] = m1[i][j]-m2[i][j]
    return res


def strassen(A, B, size):
    C = [[0]*size for _ in range(size)]
    if size == 1:
        C[0][0] = A[0][0]*B[0][0]
        return C

    nsize = size//2
    A11 = [[0]*nsize for _ in range(nsize)]
    A12 = [[0]*nsize for _ in range(nsize)]
    A21 = [[0]*nsize for _ in range(nsize)]
    A22 = [[0]*nsize for _ in range(nsize)]

    B11 = [[0]*nsize for _ in range(nsize)]
    B12 = [[0]*nsize for _ in range(nsize)]
    B21 = [[0]*nsize for _ in range(nsize)]
    B22 = [[0]*nsize for _ in range(nsize)]

    C11 = [[0]*nsize for _ in range(nsize)]
    C12 = [[0]*nsize for _ in range(nsize)]
    C21 = [[0]*nsize for _ in range(nsize)]
    C22 = [[0]*nsize for _ in range(nsize)]

    for i in range(nsize):
        for j in range(nsize):
            A11[i][j] = A[i][j]
            A12[i][j] = A[i][j+nsize]
            A21[i][j] = A[i+nsize][j]
            A22[i][j] = A[i+nsize][j+nsize]
            B11[i][j] = B[i][j]
            B12[i][j] = B[i][j+nsize]
            B21[i][j] = B[i+nsize][j]
            B22[i][j] = B[i+nsize][j+nsize]
    m1 = strassen(Add(A11, A22), Add(B11, B22), nsize)
    m2 = strassen(Add(A21, A22), B11, nsize)
    m3 = strassen(A11, Sub(B12, B22), nsize)
    m4 = strassen(A22, Sub(B21, B11), nsize)
    m5 = strassen(Add(A11, A12), B22, nsize)
    m6 = strassen(Sub(A21, A11), Add(B11, B12), nsize)
    m7 = strassen(Sub(A12, A22), Add(B21, B22), nsize)

    C11 = Add(Sub(Add(m1, m4), m5), m7)
    C12 = Add(m3, m5)
    C21 = Add(m2, m4)
    C22 = Add(Sub(Add(m1, m3), m2), m6)

    for i in range(nsize):
        for j in range(nsize):
            C[i][j] = C11[i][j]
            C[i][j+nsize] = C12[i][j]
            C[i+nsize][j] = C21[i][j]
            C[i+nsize][j+nsize] = C22[i][j]
    return C


ans = strassen(a, b, size)
for i in range(n):
    for j in range(k):
        print(ans[i][j], end=' ')
    print()
