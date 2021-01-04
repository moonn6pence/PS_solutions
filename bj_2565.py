n=int(input())

line=[list(map(int,input().split())) for _ in range(n)]
line.sort()
dp=[0]*n

for i in range(n):
    for j in range(i):
        if line[i][0]>line[j][0] and line[i][1]>line[j][1] and dp[j]>dp[i]:
            dp[i]=dp[j]
    dp[i]+=1

print(n-max(dp))
