import sys
sys.setrecursionlimit(10**9)
M,N=map(int,sys.stdin.readline().split())
Map=[list(map(int,sys.stdin.readline().split())) for _ in range(M)]

dp=[[-1 for _ in range(N)] for _ in range(M)]
UD=[-1,1,0,0]
LR=[0,0,-1,1]

def dfs(x,y):
  if x==M-1 and y==N-1:return 1
  if dp[x][y]==-1:
    dp[x][y]=0
    for i,j in zip(UD,LR):
      nx=x+i
      ny=y+j
      if 0<=nx<M and 0<=ny<N:
        if Map[x][y]>Map[nx][ny]:
          dp[x][y]+=dfs(nx,ny)
  return dp[x][y]

print(dfs(0,0))