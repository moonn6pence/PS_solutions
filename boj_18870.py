import sys

n = int(input())
num = list(map(int, sys.stdin.readline().split()))
cc = sorted(list(set(num)))
cc = {cc[i]: i for i in range(len(cc))}
print(*[cc[n] for n in num])
