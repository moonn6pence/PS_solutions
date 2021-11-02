n,k=map(int,input().split())
wv=[[0,0]]+[list(map(int,input().split())) for _ in range(n)]
dp=[[0 for _ in range(k+1)] for _ in range(n+1)]

for i in range(1,n+1):
    for j in range(1,k+1):
        if wv[i][0]<=j:
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-wv[i][0]]+wv[i][1])            
        else:
            dp[i][j]=dp[i-1][j]
    
print(dp[-1][-1])

for i in range(1,n+1):
    print("")
    for j in range(1,k+1):
        print(dp[i][j],end=' ')