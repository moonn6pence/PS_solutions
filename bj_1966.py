cases=int(input())

for case in range(cases):
  docs,target=map(int,input().split())
  priority=list(map(int,input().split()))
  cnt=0
  Q=[(priority[i],True) if i==target else (priority[i],False) for i in range(docs)]
  while True:
    if Q[0][0]==max(Q)[0]:
      cnt+=1
      if Q[0][1]==True:
        print(cnt)
        break
      else:
        del Q[0]
    else:
      Q.append(Q.pop(0))