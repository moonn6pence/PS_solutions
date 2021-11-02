n = int(input())
image = [list(input()) for _ in range(n)]
encoded = []


def checkBW(row, col, length):
    init = image[row][col]
    for i in range(row, row+length):
        for j in range(col, col+length):
            if image[i][j] != init:
                return False
    return True


def recurseEncode(row, col, length):
    nxtLen = length//2
    if checkBW(row, col, length):
        encoded.append(image[row][col])
    else:
        encoded.append('(')
        for i in range(2):
            for j in range(2):
                recurseEncode(row+i*nxtLen, col+j*nxtLen, nxtLen)
        encoded.append(')')


recurseEncode(0, 0, n)
print("".join(encoded))
