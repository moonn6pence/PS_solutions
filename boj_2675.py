case=int(input())
for i in range(case):
    a=list(input().split())
    r=int(a[0])
    result=''
    for s in a[1]:
        result+=s*r
    print(result)
