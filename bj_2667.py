n=int(input())
G=[list(input()) for _ in range(n)]
visited=[[False for _ in range(n)] for _ in range(n)]
Q=[]
UD=[-1,1,0,0]
LR=[0,0,-1,1]
compNum=[]

def bfsComp(compCnt):
  for x in range(n):
    for y in range(n):
      if visited[x][y]==False and G[x][y]=='1':
        Q.append((x,y))
        visited[x][y]=True
        compNum.append(0)
        while(Q):
          curx,cury=Q.pop(0)
          compNum[compCnt]+=1
          for dx,dy in zip(UD,LR):
            nx=curx+dx
            ny=cury+dy
            if 0<=nx<n and 0<=ny<n and G[nx][ny]=='1' and visited[nx][ny]==False:
              Q.append((nx,ny))
              visited[nx][ny]=True
        compCnt+=1

bfsComp(0)
compNum.sort()
print(len(compNum))
for _ in compNum:print(_)