import sys
input = sys.stdin.readline

n = int(input())
sol = list(map(int, input().split()))

low, high = 0, n-1
ans = (low, high)

while low < high:
    if abs(sol[ans[0]]+sol[ans[1]]) >= abs(sol[low]+sol[high]):
        ans = (low, high)

    tmp = sol[low]+sol[high]
    if tmp == 0:
        break
    if tmp > 0:
        high -= 1
    else:
        low += 1

print(sol[ans[0]], sol[ans[1]])
