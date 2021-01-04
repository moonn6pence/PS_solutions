n=int(input())

num=[0]+[1]*9
tmp=[0]*10
for i in range(1,n):
    for j in range(10):
        if j==0:tmp[j]=num[1]
        elif j==9:tmp[j]=num[8]
        else:tmp[j]=num[j-1]+num[j+1]
    for j in range(10):
        num[j]=tmp[j]
        
print(sum(num)%1000000000)
