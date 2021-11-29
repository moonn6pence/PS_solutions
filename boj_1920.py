import sys
input = sys.stdin.readline

n = int(input())
A = sorted(list(map(int, input().split())))
m = int(input())
X = list(map(int, input().split()))
ans = []

for x in X:
    flag = False
    low, high = 0, n-1
    while low <= high:
        mid = (low+high)//2
        if A[mid] == x:
            ans.append(1)
            flag = True
            break
        elif A[mid] < x:
            low = mid+1
        else:
            high = mid-1
    if not flag:
        ans.append(0)

print(*ans, sep='\n')
