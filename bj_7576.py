from collections import deque
M,N=map(int,input().split())
box=[list(map(int,input().split())) for _ in range(N)]
visited=[[False for row in range(M)] for col in range(N)]
UDLR=[(-1,0),(1,0),(0,-1),(0,1)]
Q=deque()
cnt=-1

for x in range(N):
  for y in range(M):
    if box[x][y]==1:
      Q.append((x,y))
      visited[x][y]=True

while(Q):
  cnt+=1
  for _ in range(len(Q)):
    curx,cury=Q.popleft()
    for dx,dy in UDLR:
      nx,ny=curx+dx,cury+dy
      if 0<=nx<N and 0<=ny<M and visited[nx][ny]==False and box[nx][ny]==0:
        Q.append((nx,ny))
        visited[nx][ny]=True

def output(M,N,cnt):
  for x in range(N):
    for y in range(M):
      if visited[x][y]==False and box[x][y]==0:
        print(-1)
        return

  print(cnt)

output(M,N,cnt)