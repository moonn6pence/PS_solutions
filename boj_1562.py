import sys
input = sys.stdin.readline
mod = 1000000000
n = int(input())

dp = [[[0]*(1 << 10) for _ in range(10)]
      for _ in range(n)]  # dp[pos][val][state]

for val in range(1, 10):
    dp[0][val][1 << val] = 1

for pos in range(1, n):
    for val in range(10):
        for state in range(1, 1 << 10):
            if val == 0:
                dp[pos][val][state | 1 << val] += dp[pos-1][1][state] % mod
            elif val == 9:
                dp[pos][val][state | 1 << val] += dp[pos-1][8][state] % mod
            else:
                dp[pos][val][state | 1 << val] += dp[pos-1][val-1][state] % mod
                dp[pos][val][state | 1 << val] += dp[pos-1][val+1][state] % mod

ans = 0
for val in range(10):
    ans += dp[-1][val][-1] % mod
print(ans % mod)
