m,n=map(int,input().split())

result=[i for i in range(n+1)]
result[1]=0

for i in range(2,n+1):
    if result[i] and i**2<=n:
        for j in range(i**2,n+1,result[i]):
            result[j]=0

for i in result:
    if i>=m:
        print(i)
