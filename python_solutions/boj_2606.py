v=int(input())
e=int(input())
graph=[[0 for _ in range(v)] for _ in range(v)]
visited=[False for _ in range(v)]
for _ in range(e):
  a,b=map(int,input().split())
  graph[a-1][b-1],graph[b-1][a-1]=1,1
Q=[]

def bfs(start,cnt):
  Q.append(start)
  visited[start]=True
  while(Q):
    cur=Q.pop(0)
    for node in range(v):
      if(visited[node]==False and graph[cur][node]==1):
        Q.append(node)
        cnt+=1
        visited[node]=True
  return cnt

print(bfs(0,0))