N=int(input())
seq=list(map(int,input().split()))
nge=[-1]

for i in range(N-2,-1,-1):
  if(seq[i]<seq[i+1]):
    nge.append(seq[i+1])
  elif(seq[i]>=seq[i+1] and nge[-1]==-1):
    nge.append(-1)
  else:
    tmp=-1
    while(seq[i]>=nge[tmp]):
      tmp-=1
      if(tmp==i-N or (seq[i]>=seq[i-tmp] and nge[tmp]==-1)):
        tmp=0
        break
    nge.append(nge[tmp])

nge.reverse()
print(*nge)