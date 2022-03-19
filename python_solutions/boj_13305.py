n=int(input())
dist=list(map(int,input().split()))
cost=list(map(int,input().split()))
cost.pop()#마지막 도시의 기름값은 필요없음
cost=list(enumerate(cost))
cost.sort(key=lambda x:x[1])

total=0
prev=n-1

while prev != 0:
  for cur,curCost in cost:
    if cur<prev:
      total += sum(dist[cur:prev])*curCost
      prev=cur

print(total)