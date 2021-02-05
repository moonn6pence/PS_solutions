def search(a,b,c):
  if a<=0 or b<=0 or c<=0: return 0,0,0
  elif a>20 or b>20 or c>20: return 20,20,20
  else: return a,b,c

dp=[[[0 for C in range(21)] for B in range(21)] for A in range(21)]
dp[20][20][20]=1048576

for A in range(21):
  for B in range(21):
    for C in range(21):
      if A<=0 or B<=0 or C<=0:
        dp[A][B][C]=1
      elif A<B and B<C:
        dp[A][B][C]=dp[A][B][C-1]+dp[A][B-1][C-1]-dp[A][B-1][C]
      else:
        dp[A][B][C]=dp[A-1][B][C]+dp[A-1][B-1][C]+dp[A-1][B][C-1]-dp[A-1][B-1][C-1]

while(True):
  a,b,c=map(int,input().split())
  if a==-1 and b==-1 and c==-1:
    break
  A,B,C=search(a,b,c)
  print('w(',a,', ',b,', ',c,') = ',dp[A][B][C],sep='')