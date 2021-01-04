case=int(input())

for i in range(case):
    x1,y1,r1,x2,y2,r2=map(int,input().split())
    d=(x1-x2)**2+(y1-y2)**2

    if x1==x2 and y1==y2 and r1==r2:print(-1)
    elif d==(r1+r2)**2:print(1)
    elif d<(r1+r2)**2 and d>(r1-r2)**2:print(2)
    elif d>(r1+r2)**2 or d<(r1-r2)**2:print(0)
    elif d==(r1-r2)**2:print(1)
