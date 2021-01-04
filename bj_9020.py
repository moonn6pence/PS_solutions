case=int(input())

prlist=[True for i in range(10001)]
prlist[1]=False
for i in range(2,100):
    for j in range(i*2,10000,i):
        prlist[j]=False

for i in range(case):
    n=int(input())
    a=n//2
    for x in range(a,1,-1):
        if prlist[n-x] and prlist[x]:
            print(x,n-x)
            break
