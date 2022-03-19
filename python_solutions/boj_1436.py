def counting(n):
    cnt=0
    x=666
    while cnt!=n:
        x_lst=list(str(x))
        for i in range(len(x_lst)-2):
            if x_lst[i]=='6' and x_lst[i+1]=='6' and x_lst[i+2]=='6':
                cnt+=1
                break
        x+=1
    return x-1
            
n=int(input())
print(counting(n))
