temp1=temp2=2000
for i in range(3):
    i=int(input())
    temp1=min(temp1,i)
for i in range(2):
    i=int(input())
    temp2=min(temp2,i)
print(temp1+temp2-50)
