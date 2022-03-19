n = int(input())
for i in range(1, n):
    print(' '*(n-i), end='')
    for j in range(i*2-1):
        if j == 0 or j == i*2-2:
            print('*', end='')
        else:
            print(' ', end='')
    print('')
print('*'*(n*2-1))
