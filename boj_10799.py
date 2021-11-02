import sys
bars=list(sys.stdin.readline().rstrip('\n'))

total=0
stack=[]

for i in range(len(bars)):
  if(bars[i]=='('):
    stack.append(bars[i])
  elif(bars[i-1]=='(' and bars[i]==')'):
    stack.pop(-1)
    total+=len(stack)
  else:
    stack.pop(-1)
    total+=1

print(total)