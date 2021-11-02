n,k=map(int,input().split())
coinList=[]
for _ in range(n):
  coinList.append(int(input()))

dp=[0]*(k+1)


def recur(total,w):
  for i in range(total):
    if(w-coinList[i]>0):
      dp[w]+=recur(total,w-coinList[i])
    elif(w==coinList[i]):
      dp[w]+=1

  return dp[w]

print(dp)
# print(recur(n,k))