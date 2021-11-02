n = int(input())
step = [int(input()) for _ in range(n)]
if n == 1:
    print(step[0])
elif n == 2:
    print(step[0]+step[1])
else:
    dp = [step[0], step[0]+step[1], max(step[0], step[1])+step[2]]+[0]*(n-3)
    for i in range(3, n):
        dp[i] = max(dp[i-3]+step[i-1]+step[i], dp[i-2]+step[i])
    print(dp[n-1])
