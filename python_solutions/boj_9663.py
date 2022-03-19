def check(depth,n):
    global cnt
    if depth==n:
        cnt+=1
        return

    for i in range(n):
        if not (y[i] or cross1[depth+i] or cross2[depth-i+n-1]):
            y[i] = cross1[depth+i] = cross2[depth-i+n-1]=True
            check(depth+1,n)
            y[i] = cross1[depth+i] = cross2[depth-i+n-1]=False

n=int(input())
cnt=0
y,cross1,cross2 = [False]*n, [False]*(n*2-1), [False]*(n*2-1)

check(0,n)
print(cnt)
