N=int(input())
times=[tuple(map(int,input().split())) for _ in range(N)]
times.sort(key=lambda x:(x[1],x[0]))
cnt,buffer=0,0
for start,end in times:
  if start>=buffer:
    buffer=end
    cnt+=1
print(cnt)