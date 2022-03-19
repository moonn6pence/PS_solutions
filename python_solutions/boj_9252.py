import sys
input = sys.stdin.readline

A = input().rstrip()
B = input().rstrip()
ALen, BLen = len(A), len(B)

dp=[[0]*(BLen+1) for _ in range(ALen+1)]
    
for i in range(1, ALen+1):
    for j in range(1, BLen+1):
        if A[i-1]==B[j-1]:
            dp[i][j] = dp[i-1][j-1] + 1
        else:
            dp[i][j] = max(dp[i-1][j], dp[i][j-1])
            
ans = dp[ALen][BLen]    
seq = []
cnt, i, j = ans, ALen, BLen
while cnt:
    if dp[i][j]==dp[i-1][j]:
        i-=1
    elif dp[i][j]==dp[i][j-1]:
        j-=1
    else:
        seq.append(A[i-1])
        cnt-=1
        i-=1
        j-=1
seq.reverse()
print(ans)
print(''.join(seq))