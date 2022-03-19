m=int(input())
n=int(input())

pn_list=[]

for case in range(m,n+1):
    cnt=0
    if case==1:pass
    elif case<4:pn_list.append(case)
    else:
        for n in range(2,case//2+1):
            if case%n==0:
                cnt+=1
        if not cnt:pn_list.append(case)
if len(pn_list):
    print(sum(pn_list))
    print(pn_list[0])
else: print(-1)
