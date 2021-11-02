a=[True]*8

for i in range(3):
    a[i*2],a[i*2+1]=map(int,input().split())

for i in range(2):
    if a[i]==a[i+2]:a[i+6]=a[i+4]
    elif a[i+0]==a[i+4]:a[i+6]=a[i+2]
    else : a[i+6]=a[i]
print(a[6],a[7])
