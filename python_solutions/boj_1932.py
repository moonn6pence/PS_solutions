n=int(input())
tree=[list(map(int,input().split())) for _ in range(n)]
k=2
for i in range(1,n):
    for j in range(k):
        if j==0: tree[i][j]+=tree[i-1][j]
        elif j==i: tree[i][j]+=tree[i-1][j-1]
        else: tree[i][j]+=max(tree[i-1][j],tree[i-1][j-1])
    k+=1
print(max(tree[n-1]))
