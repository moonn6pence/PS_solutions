import sys

N=sys.stdin.readline()

N=list(N.rstrip())
N.sort(reverse=True)
print(''.join(N))
