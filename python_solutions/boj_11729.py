def hanoi(n,start,temp,end):

    if n==1:
        print(start,end)
        return
    else:
        hanoi(n-1,start,end,temp)
        print(start,end)
        hanoi(n-1,temp,start,end)
        return

n=int(input())

start,temp,end=1,2,3
print(2**n-1)
hanoi(n,start,temp,end)
