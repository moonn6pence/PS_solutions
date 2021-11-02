case=int(input())
for i in range(case):
    num=list(map(int,input().split()))
    avg=sum(num[1:])/num[0]
    cnt=0
    for j in num[1:]:
        if j>avg:cnt+=1
    print("%.3f%%"%round((cnt/num[0]*100),3))
