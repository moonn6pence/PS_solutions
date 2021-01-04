N=int(input())
P=list(map(int,input().split()))
P.sort()
time=[]
for i in range(N):
  time.append(sum(P[:i+1]))
print(sum(time))