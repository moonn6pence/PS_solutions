import sys
code = [0]+list(map(int, input()))
len = len(code)
dp = [1, 1]+[0]*(len-2)
for i in range(1, len):
    if code[i] == 0 and (code[i-1] != 1 and code[i-1] != 2):
        print(0)
        sys.exit(0)
    elif code[i] == 0:
        dp[i] = dp[i-2]
    elif code[i-1] == 1:
        dp[i] = dp[i-2]+dp[i-1]
    elif code[i-1] == 2 and code[i] < 7:
        dp[i] = dp[i-2]+dp[i-1]
    else:
        dp[i] = dp[i-1]

print(dp[len-1] % 1000000)
