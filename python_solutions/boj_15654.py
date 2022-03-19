def seq(depth, n, m):
    if depth == m:
        print(' '.join(map(str, result)))
        return
    for i in range(n):
        if not visited[i]:
            visited[i] = True
            result.append(num[i])
            seq(depth+1, n, m)
            visited[i] = False
            result.pop()


n, m = map(int, input().split())
num = sorted(list(map(int, input().split())))
visited = [False]*n
result = []
seq(0, n, m)
