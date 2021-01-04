import sys

n=int(sys.stdin.readline())

x=[]

for i in range(n):
    tempx,tempy=map(int,sys.stdin.readline().split())
    x.append((tempy,tempx))
    
x.sort()

for i in range(n):
    print(x[i][1],x[i][0])
