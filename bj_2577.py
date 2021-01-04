mul=1
for i in range(3):
    n=int(input())
    mul=mul*n
num=str(mul)
for i in range(10):
    print(num.count(str(i)))
