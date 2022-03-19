from collections import deque
M,N,H=map(int,input().split())
box=[[list(map(int,input().split())) for col in range(N)] for height in range(H)]
visited=[[[False for row in range(M)] for col in range(N)] for height in range(H)]
D1,D2,D3=[-1,1,0,0,0,0],[0,0,-1,1,0,0],[0,0,0,0,-1,1]
Q=deque()
cnt=-1

for h in range(H):
  for x in range(N):
    for y in range(M):
      if box[h][x][y]==1:
        Q.append((h,x,y))
        visited[h][x][y]=True

while(Q):
  cnt+=1
  for _ in range(len(Q)):
    curh,curx,cury=Q.popleft()
    for dh,dx,dy in zip(D1,D2,D3):
      nh,nx,ny=curh+dh,curx+dx,cury+dy
      if 0<=nh<H and 0<=nx<N and 0<=ny<M and visited[nh][nx][ny]==False and box[nh][nx][ny]==0:
        Q.append((nh,nx,ny))
        visited[nh][nx][ny]=True

def output(M,N,H,cnt):
  for h in range(H):
    for x in range(N):
      for y in range(M):
        if visited[h][x][y]==False and box[h][x][y]==0:
          print(-1)
          return
  print(cnt)

output(M,N,H,cnt)