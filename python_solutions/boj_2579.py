import sys

n=int(input())
step=[int(input()) for _ in range(n)]
if n==1:
    print(step[0])
    sys.exit()
elif n==2:
    print(step[0]+step[1])
    sys.exit()

cost=[step[0],step[0]+step[1],max(step[0],step[1])+step[2]]+[0]*(n-3)

for i in range(3,n):
    cost[i]=max(cost[i-3]+step[i-1]+step[i],cost[i-2]+step[i])

print(cost[n-1])
