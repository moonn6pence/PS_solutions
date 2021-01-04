def scan(n):
    cnt=0
    for i in range(1,n+1):
        if i<100:cnt+=1
        elif i==1000:pass
        else:
            hn=int(i%1000/100)
            tn=int(i%100/10)
            on=i%10
            if hn-tn==tn-on:cnt+=1
    print(cnt)

n=int(input())
scan(n)
