from sys import stdin

input = stdin.readline

n, s = map(int, input().split())
num = list(map(int, input().split()))
ans = n
tmp = 0
low, high = 0, 0
flag = False
while low < n:
    if tmp >= s or high >= n:
        if tmp >= s:
            flag = True
            ans = min(high-low, ans)
        tmp -= num[low]
        low += 1
    elif tmp < s:
        tmp += num[high]
        high += 1

print(ans if flag else 0)
