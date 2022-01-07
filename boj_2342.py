import sys
input = sys.stdin.readline
inf = float('inf')


def energy(prev, cur):
    if prev == 0:
        return 2
    dist = abs(cur-prev)
    if dist == 0:
        return 1
    elif dist == 1 or dist == 3:
        return 3
    else:
        return 4


*step, _ = map(int, input().split())
stepLen = len(step)
dp = [[[inf]*5 for _ in range(5)] for _ in range(stepLen)]

if stepLen == 0:
    print(0)
    sys.exit(0)

dp[0][step[0]][0], dp[0][0][step[0]] = 2, 2
for i in range(1, stepLen):
    for l in range(5):
        for r in range(5):
            if dp[i-1][l][r] != inf:
                dp[i][l][step[i]] = min(
                    dp[i][l][step[i]], dp[i-1][l][r]+energy(r, step[i]))
                dp[i][step[i]][r] = min(
                    dp[i][step[i]][r], dp[i-1][l][r]+energy(l, step[i]))

ans = inf
for l in range(5):
    for r in range(5):
        ans = min(ans, dp[stepLen-1][l][r])

print(ans)
