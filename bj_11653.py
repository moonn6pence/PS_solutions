n=int(input())
factors=[]
num=2

while(n!=1):
  if(n%num==0):
    n=n/num
    factors.append(num)
  else:
    num+=1
print(*factors,sep='\n')