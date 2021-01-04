n=int(input())

result=-1
for a in range(n//3+1):
    for b in range(n//5+1):
        if((a*3+b*5)==n):
            result=a+b
            break
    if result+1:break
print(result)
