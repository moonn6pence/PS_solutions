def search(n):
    for i in range(1,n-1):
        num=sum(list(map(int,str(i))))+i
        if num==n :
            print(i)
            return
    print(0)
    return

n=int(input())

search(n)
