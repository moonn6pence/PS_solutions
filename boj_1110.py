n=int(input())
origin=n
k=1
while True:
    n=n%10*10+(n//10+n%10)%10
    if origin==n:break
    else:k=k+1
print(k)
