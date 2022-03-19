def seq(depth, n, m):
    if depth == m:
        print(' '.join(map(str, result)))
        return
    for i in range(n):
        if visited[i] < cnt[setnum[i]]:
            visited[i] += 1
            result.append(setnum[i])
            seq(depth+1, n, m)
            visited[i] -= 1
            result.pop()


n, m = map(int, input().split())
num = list(map(int, input().split()))
cnt = [0]*10001
for n in num:
    cnt[n] += 1
setnum = sorted(list(set(num)))
n = len(setnum)
visited = [0]*n
result = []
seq(0, n, m)
