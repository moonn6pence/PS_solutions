from sys import stdin
from collections import deque
N,M=map(int,stdin.readline().split())
maze=[stdin.readline().rstrip() for _ in range(N)]
visited=[[0 for n in range(M)] for m in range(N)]
Q=deque()
UDLR=[(-1,0),(1,0),(0,-1),(0,1)]

Q.append((0,0))
visited[0][0]=1
while Q:
  curx,cury=Q.popleft()
  for dx,dy in UDLR:
    nx=curx+dx
    ny=cury+dy
    if 0<=nx<N and 0<=ny<M and visited[nx][ny]==0 and maze[nx][ny]=='1':
      Q.append((nx,ny))
      visited[nx][ny]=visited[curx][cury]+1

print(visited[N-1][M-1])