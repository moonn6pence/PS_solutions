def seq(depth,step,n,m):
    if depth==m:
        print(' '.join(map(str,result)))
        return
    for i in range(step,len(searched)):
       if not searched[i]:
           searched[i]=True
           result.append(i+1)
           seq(depth+1,i+1,n,m)
           searched[i]=False
           result.pop()

n,m=map(int,input().split())
searched=[False]*n
result=[]

seq(0,0,n,m)
