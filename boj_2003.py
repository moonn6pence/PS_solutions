from sys import stdin

input = stdin.readline

n, m = map(int, input().split())
num = list(map(int, input().split()))
cnt = 0
tmp = 0
high, low = 0, 0
while low < n:
    if tmp == m:
        cnt += 1
        tmp -= num[low]
        low += 1
    elif tmp > m or high >= n:
        tmp -= num[low]
        low += 1
    else:
        tmp += num[high]
        high += 1

print(cnt)
