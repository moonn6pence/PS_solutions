def pick(lst,n,m):
    total=0
    for i in range(n):
        for j in range(n-1-i):
            for k in range(n-i-j-2):
                temp=lst[n-i-1]+lst[n-i-j-2]+lst[n-i-j-k-3]
                if temp<=m:total=max(temp,total)
    return total
        
n,m=map(int,input().split())
num=list(map(int,input().split()))
num.sort()
print(pick(num,n,m))
