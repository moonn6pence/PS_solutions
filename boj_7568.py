n=int(input())

weight=[True]*n
height=[True]*n

for i in range(n):
    weight[i],height[i]=map(int,input().split())

for i in range(n):
    cnt=1
    for j in range(n):
        if weight[i]<weight[j] and height[i]<height[j]:cnt+=1
    print(cnt)
