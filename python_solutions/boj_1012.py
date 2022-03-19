def bfsFarm(M,N,G):
  Q=[]
  visited=[[False for n in range(M)] for m in range(N)]
  UDLR=[(-1,0),(1,0),(0,-1),(0,1)]
  cnt=0

  for x in range(N):
    for y in range(M):
      if G[x][y]==1 and visited[x][y]==False:
        Q.append((x,y))
        visited[x][y]=True
        while(Q):
          curx,cury=Q.pop(0)
          for dx,dy in UDLR:
            nx=curx+dx
            ny=cury+dy
            if 0<=nx<N and 0<=ny<M and G[nx][ny]==1 and visited[nx][ny]==False:
              Q.append((nx,ny))
              visited[nx][ny]=True
        
        cnt+=1

  print(cnt)

T=int(input())

for _ in range(T):
  M,N,num=map(int,input().split())
  G=[[0 for n in range(M)] for m in range(N)]
  for _ in range(num):
    x,y=map(int,input().split())
    G[y][x]=1
  bfsFarm(M,N,G)