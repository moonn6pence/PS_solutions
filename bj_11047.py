N,K=map(int,input().split())
coins=[int(input()) for _ in range(N)]
cur,cnt=K,0
while(cur):
  coin=coins.pop(-1)
  if(cur>=coin):
    cnt+=cur//coin
    cur=cur%coin
print(cnt)