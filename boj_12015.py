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

for i in range(1, n):
    if lis[-1] < num[i]:
        lis.append(num[i])
    else:
        lis[binSearch(num[i])] = num[i]

print(len(lis))
