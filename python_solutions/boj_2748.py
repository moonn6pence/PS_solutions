n=int(input())
fibo=[i for i in range(n+1)]

for i in range(2,n+1):
    fibo[i]=fibo[i-1]+fibo[i-2]
    
print(fibo[n])
