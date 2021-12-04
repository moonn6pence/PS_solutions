import sys
input = sys.stdin.readline

n, m = map(int, input().split())
pswd = dict()
for _ in range(n):
    site, pwd = input().split()
    pswd[site] = pwd
query = [input().rstrip() for _ in range(m)]
for qry in query:
    print(pswd[qry])
