from sys import stdin


def checkSum(height, m):
    result = sum(i-height if i-height > 0 else 0 for i in tree)
    return True if result >= m else False


n, m = map(int, stdin.readline().split())
tree = list(map(int, stdin.readline().split()))
low, high = 0, 2000000000

while low < high:
    mid = (low+high+1)//2
    if checkSum(mid, m):
        low = mid
    else:
        high = mid-1
print(low)
