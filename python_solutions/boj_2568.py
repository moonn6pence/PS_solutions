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
line = [tuple(map(int, input().split())) for _ in range(n)]
line.sort(key=lambda x: x[1])
lis = [line[0][0]]
index = [0]
top = 0

for i in range(1, n):
    if line[i][0] > lis[top]:
        lis.append(line[i][0])
        top += 1
        index.append(top)
    else:
        tmp = binSearch(line[i][0])
        lis[tmp] = line[i][0]
        index.append(tmp)

result = [0]*(top+1)
for i in range(n-1, -1, -1):
    if index[i] == top:
        result[top] = line[i][0]
        top -= 1

line.sort()

print(n-len(lis))

j = 0
for i in range(n):
    if j == len(result):
        print(line[i][0])
    elif line[i][0] == result[j]:
        j += 1
    else:
        print(line[i][0])
