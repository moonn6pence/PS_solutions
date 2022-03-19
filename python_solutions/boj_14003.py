import sys
input = sys.stdin.readline


def binSearch(x):
    low, high = 0, len(lis)-1
    while low < high:
        mid = (low+high)//2
        if lis[mid] < x:
            low = mid+1
        else:
            high = mid
    return high


n = int(input())
num = list(map(int, input().split()))
lis = [num[0]]
index = [0]*n

for i in range(1, n):
    if lis[-1] < num[i]:
        index[i] = len(lis)
        lis.append(num[i])
    else:
        index[i] = binSearch(num[i])
        lis[index[i]] = num[i]

idx = len(lis)-1
ans = []
for i in range(n-1, -1, -1):
    if index[i] == idx:
        ans.append(num[i])
        idx -= 1
    if idx == -1:
        break
ans.reverse()
print(len(lis))
print(*ans)
