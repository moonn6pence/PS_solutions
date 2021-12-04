import sys
input = sys.stdin.readline

n, m = map(int, input().split())
num = list(map(int, input().split()))
subsum = [0]*(n+1)
for i in range(1, n+1):
    subsum[i] = subsum[i-1]+num[i-1]

for _ in range(m):
    i, j = map(int, input().split())
    print(subsum[j]-subsum[i-1])
