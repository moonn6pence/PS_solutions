from itertools import product
from functools import reduce

n = int(input())
m = int(input())
broken = list(map(int, input().split())) if m else []
unbroken = [i for i in range(10) if i not in broken]
isBroken = False


def tupleToInt(num):
    return reduce(lambda x, y: 10*x+y, num, 0)


for c in str(n):
    if int(c) in broken:
        isBroken = True
        break

if isBroken and m != 10:
    validNum = list(product(unbroken, repeat=len(str(n))+1))
    if 0 not in unbroken:
        validNum = list(product(unbroken, repeat=len(str(n))))+validNum
        if len(str(n)) > 1:
            validNum = list(product(unbroken, repeat=len(str(n))-1))+validNum
    low, high = 0, len(validNum)-1
    while low < high:
        mid = (low+high+1)//2
        if tupleToInt(validNum[mid]) <= n:
            low = mid
        else:
            high = mid-1
    closeMax = tupleToInt(validNum[low])

    low, high = 0, len(validNum)-1
    while low < high:
        mid = (low+high)//2
        if tupleToInt(validNum[mid]) >= n:
            high = mid
        else:
            low = mid+1
    closeMin = tupleToInt(validNum[high])

    closest = closeMax if n-closeMax <= closeMin-n else closeMin

    if abs(n-100) <= len(str(closest))+abs(closest-n):
        cnt = abs(n-100)
    else:
        cnt = len(str(closest))+abs(closest-n)
else:
    if m == 10 or abs(n-100) <= len(str(n)):
        cnt = abs(n-100)
    else:
        cnt = len(str(n))

print(cnt)
