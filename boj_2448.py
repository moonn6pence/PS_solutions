def unitTriangle(row, col):
    table[row][col:col+5] = '  *  '
    table[row+1][col:col+5] = ' * * '
    table[row+2][col:col+5] = '*****'


def fractal(row, col, num):
    if num == 3:
        unitTriangle(row, col)
        return
    for i in range(row, row+num//2):
        for j in range(col, col+num//2):
            table[i][j] = ' '
        for j in range(col+num//2+num-1, col+num*2-1):
            table[i][j] = ' '
    for i in range(row+num//2, row+num):
        table[i][col+num-1] = ' '
    fractal(row, col+num//2, num//2)
    fractal(row+num//2, col, num//2)
    fractal(row+num//2, col+num, num//2)


n = int(input())
table = [['*']*(n*2-1) for _ in range(n)]
fractal(0, 0, n)
for line in table:
    print(''.join(line))
