import sys
input = sys.stdin.readline

n = int(input())
m = int(input())
arr = list(map(int, input().split()))
arr.sort()
ans = 0
low, high = 0, n-1

while low < high:
    if arr[low]+arr[high] == m:
        ans += 1
        low += 1
        high -= 1
    elif arr[low]+arr[high] < m:
        low += 1
    else:
        high -= 1

print(ans)
