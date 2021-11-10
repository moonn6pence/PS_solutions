from sys import stdin


def countLAN(size):
    cnt = 0
    for i in range(len(cable)):
        cnt += cable[i]//size
    return cnt


k, n = map(int, stdin.readline().split())
cable = []
for _ in range(k):
    cable.append(int(stdin.readline()))
low, high = 1, 2**31-1

while low < high:
    mid = (low+high+1)//2
    cnt = countLAN(mid)
    if cnt >= n:
        low = mid
    else:
        high = mid-1
print(low)
