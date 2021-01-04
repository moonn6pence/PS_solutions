import sys

n=int(input())

names=[]
for i in range(n):
    names.append(list(sys.stdin.readline().split()))

names.sort(key=lambda x:int(x[0]))

for i in range(n):
    print(names[i][0],names[i][1])
