import sys

n=int(sys.stdin.readline())

x=[]

for i in range(n):
    x.append(tuple(map(int,sys.stdin.readline().split())))
    
x.sort()

for i in range(n):
    print(x[i][0],x[i][1])
