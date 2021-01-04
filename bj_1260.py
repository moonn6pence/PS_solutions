nodes,edges,start=map(int,input().split())

graph=[[0 for i in range(nodes)] for j in range(nodes)]

for _ in range(edges):
  a,b=map(int,input().split())
  graph[a-1][b-1]=1
  graph[b-1][a-1]=1

visited_dfs=[False for _ in range(nodes)]
visited_bfs=[False for _ in range(nodes)]
bfs_order=[]

def dfs(start):
  print(start+1,end=' ')
  visited_dfs[start]=True
  for node in range(nodes):
    if(graph[start][node] and visited_dfs[node]==False):
      dfs(node)

def bfs(start):
  bfs_order.append(start)
  visited_bfs[start]=True
  while(bfs_order):
    cur=bfs_order.pop(0)
    print(cur+1,end=' ')
    for node in range(nodes):
      if(graph[cur][node] and visited_bfs[node]==False):
        bfs_order.append(node)
        visited_bfs[node]=True

dfs(start-1)
print('')
bfs(start-1)