for case in range(int(input())):
    n = int(input())
    num = [0]+list(map(int, input().split()))
    acc = [0]*(n+1)
    for i in range(1, n+1):
        acc[i] = acc[i-1]+num[i]
    dp = [[0]*(n+1) for _ in range(n+1)]
    for i in range(2, n+1):
        for j in range(1, n+2-i):
            dp[j][j+i-1] = min([dp[j][j+k]+dp[j+k+1][j+i-1]
                               for k in range(i-1)])+acc[j+i-1]-acc[j-1]
    print(dp[1][n])
