import sys
input = sys.stdin.readline

n = int(input())
sol = sorted(list(map(int, input().split())))
minSum = 10**10

for fix in range(n-2):
    low, high = fix+1, n-1

    while low < high:
        tmp = sol[fix]+sol[low]+sol[high]
        if abs(tmp) < minSum:
            minSum = abs(tmp)
            ans = [sol[fix], sol[low], sol[high]]

        if tmp == 0:
            break
        if tmp > 0:
            high -= 1
        else:
            low += 1

print(*ans)
