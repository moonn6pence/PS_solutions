n=int(input())

dp=[0]+[0]*n
way1,way2,way3=1,1,0
for i in range(2,n+1):
    if i%3==0:way1=dp[i//3]+1
    if i%2==0:way2=dp[i//2]+1
    way3=dp[i-1]+1
    dp[i]=min(way1,way2,way3)
    way1=way3+1
    way2=way3+1    
print(dp[n])
