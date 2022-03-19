def seq(depth,step,n,m):
    if depth==m:
        print(' '.join(map(str,result)))
        return
    for i in range(step,n):
           result.append(i+1)
           seq(depth+1,i,n,m)
           result.pop()

n,m=map(int,input().split())
result=[]

seq(0,0,n,m)
