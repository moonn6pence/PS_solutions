for case in range(int(input())):
    x,y=map(int,input().split())
    cnt=1
    n=1
    while True:
        if (y-x)>n**2-n and (y-x)<=n**2+n:
            if y-x<=n**2:cnt=n*2-1
            else:cnt=n*2
            break
        else:n+=1
    print(cnt)
