cnt=0
case=int(input())
num=list(map(int,input().split()))
for x in num:
    if x==1:pass
    elif x<4:cnt+=1
    else:
        for n in range(2,x//2+1):
            if x%n==0:
                cnt-=1
                break
        cnt+=1
print(cnt)
