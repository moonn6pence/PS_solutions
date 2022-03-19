import sys
input = sys.stdin.readline

n, c = map(int, input().split())
num = list(map(int, input().split()))
cnt = dict()
rank = dict()

for i in range(n):
    if num[i] in cnt:
        cnt[num[i]] += 1
    else:
        cnt[num[i]] = 1

    if num[i] in rank:
        rank[num[i]] = min(rank[num[i]], i)
    else:
        rank[num[i]] = i

res = [[cnt[num[i]], -rank[num[i]], num[i]] for i in range(n)]
res.sort(reverse=True)

for i in range(n):
    print(res[i][2], end=' ')
