from sys import stdin, stdout

n = int(stdin.readline())
card = list(map(int, stdin.readline().split()))
m = int(stdin.readline())
check = list(map(int, stdin.readline().split()))
result = [0]*m
card.sort()
i = 0

while i < m:
    low, high = 0, n-1
    lowerBound = 0
    while low <= high:
        mid = (low+high+1)//2
        if card[mid] == check[i]:
            lowerBound = mid
            high = mid-1
        elif card[mid] < check[i]:
            low = mid+1
        else:
            high = mid-1

    low, high = 0, n-1
    upperBound = 0
    while low <= high:
        mid = (low+high+1)//2
        if card[mid] == check[i]:
            upperBound = mid+1
            low = mid+1
        elif card[mid] < check[i]:
            low = mid+1
        else:
            high = mid-1
    result[i] = upperBound - lowerBound
    i += 1

for _ in range(m):
    stdout.write(str(result[_])+' ')
