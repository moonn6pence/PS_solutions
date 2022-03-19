def calcDist(x1, y1, x2, y2):
    return ((x1-x2)**2+(y1-y2)**2)**(1/2)


ax1, ay1, ax2, ay2, cx1, cy1, cx2, cy2 = map(int, input().split())
interval = 10000000
dax, day = (ax2-ax1)/interval, (ay2-ay1)/interval
dcx, dcy = (cx2-cx1)/interval, (cy2-cy1)/interval
low, high = 0, 10000000
while low+3 <= high:
    p, q = (low*2+high)//3, (low+high*2)//3
    pDist = calcDist(ax1+dax*p, ay1+day*p, cx1+dcx*p, cy1+dcy*p)
    qDist = calcDist(ax1+dax*q, ay1+day*q, cx1+dcx*q, cy1+dcy*q)
    if pDist > qDist:
        low = p+1
    else:
        high = q-1

minDist = calcDist(ax1+dax*high, ay1+day*high, cx1+dcx*high, cy1+dcy*high)

for i in range(low, high):
    tmp = calcDist(ax1+dax*i, ay1+day*i, cx1+dcx*i, cy1+dcy*i)
    if tmp < minDist:
        minDist = tmp

print(minDist)
