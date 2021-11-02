import sys


def GCD(a, b):
    if a % b == 0:
        return b
    else:
        return GCD(b, a % b)


T = int(sys.stdin.readline())
for _ in range(T):
    line = list(map(int, sys.stdin.readline().split()))
    length, num, sum = line[0], line[1:], 0
    for i in range(length):
        for j in range(i+1, length):
            sum += GCD(num[i], num[j])
    print(sum)
