def seq(depth,n,m):
    if depth==m:
        print(' '.join(map(str,result)))
        return
    for i in range(len(searched)):
       if not searched[i]:
           searched[i]=True
           result.append(i+1)
           seq(depth+1,n,m)
           searched[i]=False
           result.pop()

n,m=map(int,input().split())
searched=[False]*n
result=[]

seq(0,n,m)
