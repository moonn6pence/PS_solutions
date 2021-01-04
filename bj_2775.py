for case in range(int(input())):
    k=int(input())
    n=int(input())
    popl=[x for x in range(1,n+1)]
    for i in range(k):
        for j in range(1,n):
            popl[j]+=popl[j-1]
    print(popl[n-1])
