rest=[]
temp=0
for i in range(10):
    n=int(input())
    rest.append(n%42)
for i in range(42):
    if rest.count(i):temp=temp+1
print(temp)
