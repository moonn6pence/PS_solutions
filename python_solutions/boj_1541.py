eq=input().split('-')
pos=[]
for num in eq:
  tmp=map(int,num.split('+'))
  pos.append(sum(tmp))
result=2*pos[0]
for num in pos:
  result-=num
print(result)