case = int(input())
for _ in range(case):
    n = int(input())
    board = []
    board.append(list(map(int, input().split())))
    board.append(list(map(int, input().split())))
    dp = [[0 for i in range(n)] for _ in range(2)]
    dp[0][0] = board[0][0]
    dp[1][0] = board[1][0]
    for i in range(1, n):
        if i == 1:
            dp[0][i] = dp[1][i-1]+board[0][i]
            dp[1][i] = dp[0][i-1]+board[1][i]
        else:
            dp[0][i] = max(dp[1][i-2]+board[0][i], dp[1][i-1]+board[0][i])
            dp[1][i] = max(dp[0][i-2]+board[1][i], dp[0][i-1]+board[1][i])
    print(max(dp[0][n-1], dp[1][n-1]))
