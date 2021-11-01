from sys import stdin


def checkRouter(dist, n, c):
    prev = house[0]
    cnt = 1
    for i in range(1, n):
        if house[i] >= prev+dist:
            prev = house[i]
            cnt += 1
    return True if cnt >= c else False


n, c = map(int, stdin.readline().split())
house = []
for _ in range(n):
    house.append(int(input()))
house.sort()

low, high = 1, house[-1]-house[0]

while low < high:
    mid = (low+high+1)//2
    if checkRouter(mid, n, c):
        low = mid
    else:
        high = mid-1

print(low)
