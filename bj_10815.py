from sys import stdin


n = int(stdin.readline())
card = list(map(int, stdin.readline().split()))
m = int(stdin.readline())
check = list(map(int, stdin.readline().split()))
result = [0]*m
card.sort()

for i in range(m):
    low, high = 0, n-1
    while low <= high:
        mid = (low+high+1)//2
        if card[mid] < check[i]:
            low = mid+1
        elif card[mid] == check[i]:
            result[i] = 1
            break
        else:
            high = mid-1

print(*result)
