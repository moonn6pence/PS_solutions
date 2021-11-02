def seq(depth,n,m):
    if depth==m:
        print(' '.join(map(str,result)))
        return
    for i in range(n):
        result.append(i+1)
        seq(depth+1,n,m)
        result.pop()

n,m=map(int,input().split())
result=[]

seq(0,n,m)
