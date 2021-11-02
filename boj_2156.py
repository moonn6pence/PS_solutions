n=int(input())
wine=[int(input()) for _ in range(n)]

dp=[0]
dp.append(wine[0])
if (n>1): dp.append(wine[0]+wine[1])

for i in range(3,n+1):
    way1=wine[i-1]+dp[i-2]
    way2=wine[i-1]+wine[i-2]+dp[i-3]
    way3=dp[i-1]
    dp.append(max(way1,way2,way3))
print(dp[n])
