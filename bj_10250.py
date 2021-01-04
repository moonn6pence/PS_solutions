case=int(input())

for i in range(case):
    h,w,n=map(int,input().split())
    if n%h:
        print("{0}{1:0>2}".format(n%h,n//h+1))
    else:print("{0}{1:0>2}".format(h,n//h))
