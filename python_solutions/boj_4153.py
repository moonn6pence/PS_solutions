while True:
    a=list(map(int,input().split()))
    a.sort()
    
    if a.count(0):break
    elif a[0]==a[1] or a[1]==a[2] or a[2]==a[0] : print('wrong')
    else :
        if a[2]**2==a[0]**2+a[1]**2:print('right')
        else : print('wrong')
