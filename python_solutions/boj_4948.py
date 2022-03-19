import math

def primelist(num):
    n_list=[True]*num
    
    for i in range(2,int(math.sqrt(num))+1):
        if n_list[i]:
            for j in range(i*2,num,i):
                n_list[j]=False
    return [i for i in range(2,num) if n_list[i]]

while True:
    n=int(input())
    if not n:break
    result=primelist(n*2+1)
    print(len([i for i in result if i>n]))
